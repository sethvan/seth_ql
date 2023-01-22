#include <iomanip>
#include <iostream>
#include <tuple>
#include <vector>

#include "fieldTypes.hpp"
#include "sqlTypes.hpp"

const auto fieldTypes = getFieldTypesArray();
/*
    Was thinking something like this class could be used to set up a prepared statement
   for a row in a table for creating, modifying or reading (which would be in another
   class). Once it is constructed, It's MYSQL_BIND array parameter can be bound with a
   prepared statement that could be executed. If it is a write/modify statement then the
   values of each field could be updated between statement executions. If it is a read
   statement, then updated values could be read between executions if they have changed.

   May decide to make separate classes for rows that are meant to read or write.
   Need to also consider case where only certain fields are updated.
*/
class IntsTableRow {
   private:
    std::tuple<TinyInt, SmallInt, BigInt, TextType> fields;

   public:
    TinyInt* tiny;
    SmallInt* small;
    BigInt* big;
    TextType* firstName;
    MYSQL_BIND binds[4];
    IntsTableRow()
        : fields( std::make_tuple( TinyInt( "tiny" ), SmallInt( "small" ),
                                   BigInt( "big" ), TextType( "first_name" ) ) ),
          tiny( &std::get<0>( fields ) ),
          small( &std::get<1>( fields ) ),
          big( &std::get<2>( fields ) ),
          firstName( &std::get<3>( fields ) ) {
        std::memset( binds, 0, sizeof( binds ) );
        std::apply(
            [&]( auto&... tupleArgs ) {
                int i = 0;
                auto bindFieldsToBindsArray = [&]( auto& o ) {
                    o.bind = &binds[i++];
                    o.bind->buffer_type = o.bufferType;
                    o.bind->buffer = (char*)o.buffer;
                    o.bind->is_null = &o.isNull;
                    o.bind->length = &o.length;
                    o.bind->error = &o.error;
                    if ( o.bufferType == MYSQL_TYPE_STRING ) {
                        o.bind->buffer_length = o.bufferLength;
                    }
                };
                ( bindFieldsToBindsArray( tupleArgs ), ... );
            },
            fields );
    }
    void displayFields() {
        std::apply(
            []( auto&... tupleArgs ) {
                std::cout << std::left << std::setw( 30 ) << "\nField Name";
                std::cout << std::left << std::setw( 30 ) << "Field Type";
                std::cout << std::left << std::setw( 30 ) << "Field Value" << '\n';
                std::cout << std::left << std::setw( 90 ) << std::setfill( '-' ) << '-'
                          << std::setfill( ' ' ) << '\n';
                auto display = []( auto& o ) {
                    std::cout << std::left << std::setw( 30 ) << o.fieldName;
                    std::cout << std::left << std::setw( 30 ) << fieldTypes[o.bufferType];
                    std::cout << std::left << std::setw( 30 ) << o.getValue() << '\n';
                };
                ( display( tupleArgs ), ... );
                puts( "" );
            },
            fields );
    }
};

int main() {

    IntsTableRow row;
    row.tiny->setValue( 90 );
    row.big->setValue( 89 );
    row.small->setValue( 100 );
    row.firstName->setValue( "John" );

    puts( "" );
    for ( int i = 0; i < 4; ++i ) {
        std::cout << "row.binds[" << i
                  << "].buffer_type:   " << fieldTypes[row.binds[i].buffer_type] << '\n';
    }

    row.displayFields();

    puts( "" );

    return 0;
}