/*
   Third commit note: Unfinished idea, abandoning as I believe I could make a better more
   practical/extensible version using polymorphism now that I have acquainted myself more
   with my options. Committing this as it for future reference and will immediately change
   to a polymorphic version after commit.

*/

#include <algorithm>
#include <concepts>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string_view>
#include <tuple>
#include <type_traits>
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

   Theoretically, class name would be the table name with word row at end and the tuple
   would have the table's fields.

   May decide to make separate classes for rows that are meant to read or write.
   Need to also consider case where only certain fields are updated.
*/

enum class RowField { TINY, SMALL, BIG, FIRST_NAME };

class IntsTableRow {

   private:
    std::tuple<TinyInt, SmallInt, BigInt, TextType> fields;

   public:
    TinyInt* tiny;
    SmallInt* small;
    BigInt* big;
    TextType* firstName;
    std::vector<MYSQL_BIND> binds;
    IntsTableRow()
        : fields( std::make_tuple( TinyInt( "tiny" ), SmallInt( "small" ),
                                   BigInt( "big" ), TextType( "first_name" ) ) ),
          tiny( &std::get<0>( fields ) ),
          small( &std::get<1>( fields ) ),
          big( &std::get<2>( fields ) ),
          firstName( &std::get<3>( fields ) ) {
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

    // template <typename T>
    // void setFieldValue( const char* name, const T& t ) {

    //     auto setIt = [&]( auto&... object ) {
    //         ( ( object.fieldName == name && ( object.setValue( t ), 1 ) ) || ... );
    //     };

    //     std::apply( setIt, fields );
    // }

    template <typename... Ts>
    using AllRfs = typename std::conjunction<std::is_same<Ts, RowField>...>::type;

    template <typename... Ts>

    void selectFields( Ts... ts ) {
        auto bindFieldsToBindsArray = [&]( auto* o ) {
            o->bind = &( *std::next( binds.end(), -1 ) );
            std::memset( &( *o->bind ), 0, sizeof( *o->bind ) );
            o->bind->buffer_type = o->bufferType;
            o->bind->buffer = (char*)o->buffer;
            o->bind->is_null = &o->isNull;
            o->bind->length = &o->length;
            o->bind->error = &o->error;
            if ( o->bufferType == MYSQL_TYPE_STRING ) {
                o->bind->buffer_length = o->bufferLength;
            }
        };

        // does not maintain correct sequence, idea unfinished
        const auto makeSelection = [&]( RowField& selection ) {
            binds.emplace_back();
            switch ( selection ) {
                case RowField::TINY:
                    bindFieldsToBindsArray( tiny );
                    break;
                case RowField::SMALL:
                    bindFieldsToBindsArray( small );
                    break;
                case RowField::BIG:
                    bindFieldsToBindsArray( big );
                    break;
                case RowField::FIRST_NAME:
                    bindFieldsToBindsArray( firstName );
                    break;
                default:
                    /*Code to select all here*/
                    break;
            }
        };
        ( makeSelection( ts ), ... );
    }
};

int main() {

    IntsTableRow row;
    row.tiny->setValue( 90 );
    row.big->setValue( 8912345 );
    row.small->setValue( 3 );
    row.firstName->setValue( "John" );

    puts( "" );

    row.displayFields();

    row.selectFields( RowField::TINY, RowField::SMALL, RowField::BIG );

    int i = 0;
    std::for_each( row.binds.begin(), row.binds.end(), [&]( const auto& bind ) {
        std::cout << "row.binds[" << i++
                  << "].buffer_type:   " << fieldTypes[bind.buffer_type] << '\n';
    } );

    puts( "" );

    return 0;
}