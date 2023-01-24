#include <initializer_list>
#include <iostream>

#include "fieldTypes.hpp"
#include "sqlTypes.hpp"
#include "tablerow.hpp"

const std::array<std::string_view, 256> fieldTypes =
    getFieldTypesArray();  // extern variable used in TableRow class as well

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
    puts( "" );

    row.setBinds( std::initializer_list<bool>( { true, false, true, false } ) );

    binds = row.getBinds();
    size = row.getBindsSize();

    for ( size_t i = 0; i < size; ++i ) {
        std::cout << "binds[" << i
                  << "]->buffer_type:   " << fieldTypes[binds[i].buffer_type] << '\n';
    }
    puts( "" );

    return 0;
}