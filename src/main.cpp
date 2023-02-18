#include <mysql/mysql.h>

#include <iostream>

#include "set_mysql_binds.h"

using namespace set_mysql_binds;
using enum set_mysql_binds::MysqlInputType;

int main() {

    std::string salary( "salary" );
    std::string_view flags( "flags" );

    auto table = makeInputBindsArray( Bind<VARCHAR>( "name", 100 ), Bind<INT>( "id" ), Bind<TINYINT>( "age" ),
                                      Bind<VARCHAR>( "location", 100 ), Bind<DECIMAL>( salary ),
                                      Bind<BOOLEAN>( "married" ), Bind<BINARY>( flags, 100 ) );
    table["name"]->set_value( "John Wayne" );
    table["id"]->isNull = true;
    table["age"]->set_value( 32 );
    table["married"]->set_value( false );
    table["location"]->set_value( "Brownsville, TX" );
    table[salary]->set_value( 678.93 );
    table[flags]->set_value( "0b10100010" );

    table.displayFields();
    return 0;
}
