#include <algorithm>
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

#include "fieldTypes.hpp"
#include "sqlTypes.hpp"

const auto fieldTypes = getFieldTypesArray();
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
    TableRow( Ptrs&&... ptrs ) {  // to set once the correct order of columns
        ( columns.emplace_back( std::forward<Ptrs>( ptrs ) ), ... );
        for ( size_t i = 0; i < columns.size(); ++i ) {
            fields.emplace_back( columns[i].get() );
        }
    }
    void displayFields() {
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

    void setBinds() {
        selection.erase( selection.begin(), selection.end() );

        std::for_each( columns.begin(), columns.end(), [&]( auto& o ) {
            if ( o->is_selected ) {
                selection.emplace_back();
                o->bind = &( *std::next( selection.end(), -1 ) );
                std::memset( &( *o->bind ), 0, sizeof( *o->bind ) );
                o->bind->buffer_type = o->bufferType;
                o->bind->buffer = (char*)o->buffer;
                o->bind->is_null = &o->isNull;
                o->bind->length = &o->length;
                o->bind->error = &o->error;
                if ( o->bufferType == MYSQL_TYPE_STRING ) {
                    o->bind->buffer_length = o->bufferLength;
                }
            }
        } );
    }

    MYSQL_BIND* getBinds() {
        return selection.data();
    }
    size_t getBindsSize() {
        return selection.size();
    }
};

int main() {

    TableRow row(
        std::make_unique<TinyInt>( "tiny" ), std::make_unique<SmallInt>( "small" ),
        std::make_unique<BigInt>( "big" ), std::make_unique<TextType>( "first_name" ) );

    row.fields[0]->set_value( static_cast<signed char>( 90 ) );
    row.fields[1]->set_value( static_cast<short>( 12 ) );
    row.fields[2]->set_value( static_cast<long long>( 786543123 ) );
    row.fields[3]->set_value( "John" );

    row.fields[3]->is_selected = true;
    row.fields[0]->is_selected = true;
    row.fields[1]->is_selected = true;

    row.displayFields();

    row.setBinds();

    auto* binds = row.getBinds();
    auto size = row.getBindsSize();

    for ( size_t i = 0; i < size; ++i ) {
        std::cout << "binds[" << i
                  << "]->buffer_type:   " << fieldTypes[binds[i].buffer_type] << '\n';
    }

    return 0;
}