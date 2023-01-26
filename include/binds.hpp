#ifndef INCLUDED_Binds_H
#define INCLUDED_Binds_H

#include <algorithm>
#include <exception>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <memory>
#include <optional>
#include <vector>

#include "sqlTypes.hpp"
#include "utilities.h"

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

template <typename T>
class Binds {
   private:
    std::vector<std::unique_ptr<T>> columns;
    std::vector<MYSQL_BIND> selection;

   public:
    // Points to columns' elements. After object instantiated, do not want column elements
    // added or deleted, just access for selecting and modifying.
    std::vector<T*> fields;

    Binds() = delete;
    Binds( std::vector<std::unique_ptr<T>> _columns );  // To set once the correct order of
                                                        // MYSQL_BINDs for the prepared statement.

    void displayFields();
    void setBinds(
        const std::optional<std::initializer_list<bool>>& selectedColumns = std::nullopt );
    MYSQL_BIND* getBinds() {
        return selection.data();
    }
    size_t getBindsSize() {  // for testing during development
        return selection.size();
    }
};

template <typename T>
Binds<T>::Binds( std::vector<std::unique_ptr<T>> _columns ) : columns( std::move( _columns ) ) {

    for ( size_t i = 0; i < columns.size(); ++i ) {
        fields.emplace_back( columns[i].get() );
    }
}

template <typename T>
void Binds<T>::displayFields() {
    puts( "" );
    std::cout << std::left << std::setw( 30 ) << "Field Name";
    std::cout << std::left << std::setw( 30 ) << "Field Type";
    std::cout << std::left << std::setw( 30 ) << "Field Value" << '\n';
    std::cout << std::left << std::setw( 90 ) << std::setfill( '-' ) << '-' << std::setfill( ' ' )
              << '\n';
    std::for_each( fields.begin(), fields.end(), [&]( const auto& o ) {
        std::cout << std::left << std::setw( 30 ) << o->fieldName;
        std::cout << std::left << std::setw( 30 ) << fieldTypes[o->bufferType];
        o->printValue();
        std::cout << std::endl;
    } );
    puts( "" );
}

template <typename T>
void Binds<T>::setBinds( const std::optional<std::initializer_list<bool>>& selectedColumns ) {
    if ( selectedColumns.has_value() ) {

        auto& sc = selectedColumns.value();
        if ( sc.size() != columns.size() ) {
            throw std::runtime_error(
                "Incorrect qty of bools given to setBinds() method, must match the "
                "qty of elements in columns vector\n" );
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

#endif  // INCLUDED_Binds_H