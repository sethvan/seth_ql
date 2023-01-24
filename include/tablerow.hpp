#ifndef INCLUDED_TABLEROW_H
#define INCLUDED_TABLEROW_H

#include <algorithm>
#include <exception>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <memory>
#include <optional>
#include <vector>

#include "fieldTypes.hpp"
#include "sqlTypes.hpp"

/*
    Was thinking something like this class could be used to set up a prepared statement
   for a row in a table for creating, modifying or reading. Statement will be prepared in
   another class. Once it is constructed, It's MYSQL_BIND array parameter can be bound
   with a prepared statement that could be executed. If it is a write/modify statement
   then the values of each field could be updated between statement executions. If it is a
   read statement, then updated values could be read between executions if they have
   changed.

   May decide to make separate classes for rows that are meant to read or write.
*/

template <typename... Ptrs>
class TableRow {
   private:
    std::vector<std::unique_ptr<SqlType>> columns;
    std::vector<MYSQL_BIND> selection;

   public:
    // Points to columns' elements. After object instantiated, do not want column elements
    // added or deleted, just access for selecting ad modifying.
    std::vector<SqlType*> fields;

    TableRow() = delete;
    TableRow( Ptrs&&... ptrs );  // to set once the correct order of columns
    void displayFields();
    void setBinds( const std::optional<std::initializer_list<bool>>& selectedColumns =
                       std::nullopt );
    MYSQL_BIND* getBinds() {
        return selection.data();
    }
    size_t getBindsSize() {
        return selection.size();
    }
};

template <typename... Ptrs>
TableRow<Ptrs...>::TableRow( Ptrs&&... ptrs ) {
    ( columns.emplace_back( std::forward<Ptrs>( ptrs ) ), ... );
    for ( size_t i = 0; i < columns.size(); ++i ) {
        fields.emplace_back( columns[i].get() );
    }
}

template <typename... Ptrs>
void TableRow<Ptrs...>::displayFields() {
    puts( "" );
    std::cout << std::left << std::setw( 30 ) << "Field Name";
    std::cout << std::left << std::setw( 30 ) << "Field Type";
    std::cout << std::left << std::setw( 30 ) << "Field Value" << '\n';
    std::cout << std::left << std::setw( 90 ) << std::setfill( '-' ) << '-'
              << std::setfill( ' ' ) << '\n';
    std::for_each( fields.begin(), fields.end(), [&]( const auto& o ) {
        std::cout << std::left << std::setw( 30 ) << o->fieldName;
        std::cout << std::left << std::setw( 30 ) << fieldTypes[o->bufferType];
        o->printValue();
    } );
    puts( "" );
}

template <typename... Ptrs>
void TableRow<Ptrs...>::setBinds(
    const std::optional<std::initializer_list<bool>>& selectedColumns ) {
    if ( selectedColumns.has_value() ) {

        auto& sc = selectedColumns.value();
        if ( sc.size() != columns.size() ) {
            throw std::runtime_error(
                "Incorrect qty of bools given to setBinds() method, must match the "
                "qty of table columns\n" );
        }
        int i = 0;
        std::for_each( sc.begin(), sc.end(),
                       [&]( const bool b ) { columns[i++]->is_selected = b; } );
    }
    selection.erase( selection.begin(), selection.end() );

    std::for_each( columns.begin(), columns.end(), [&]( auto& o ) {
        if ( o->is_selected ) {
            selection.emplace_back();
            o->setBind( &( *std::next( selection.end(), -1 ) ) );
        }
    } );
}

#endif  // INCLUDED_TABLEROW_H