#include "getDBTables.h"

#include <algorithm>
#include <array>
#include <cstring>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "utilities.h"

std::vector<Table> getDBTables( const char* HOST, const char* USER, const char* PASSWORD,
                                const char* DATABASE ) {

    std::vector<Table> tables;

    if ( mysql_library_init( 0, nullptr, nullptr ) ) {
        std::cerr << "could not initialize MySQL client library\n";
        exit( 1 );
    }

    MYSQL* db_conn = mysql_init( nullptr );
    if ( db_conn == nullptr ) {
        std::cerr << "Error: " << mysql_error( db_conn ) << '\n';
        mysql_library_end();
        exit( 1 );
    }

    if ( mysql_real_connect( db_conn, HOST, USER, PASSWORD, DATABASE, 0, nullptr, 0 ) == nullptr ) {
        std::cerr << "Error: " << mysql_error( db_conn ) << '\n';
        mysql_close( db_conn );
        mysql_library_end();
        exit( 1 );
    }

    // Get a list of all tables in the selected database
    MYSQL_RES* res = mysql_list_tables( db_conn, nullptr );
    if ( res == nullptr ) {
        std::cerr << "Error: " << mysql_error( db_conn ) << std::endl;
        mysql_close( db_conn );
        mysql_library_end();
        exit( 1 );
    }

    // Tables in database
    for ( long unsigned int i = 0; i < mysql_num_rows( res ); i++ ) {
        tables.emplace_back();
        MYSQL_ROW row = mysql_fetch_row( res );
        std::next( tables.end(), -1 )->name = row[0];

        // Get the fields and field types of the current table
        MYSQL_RES* fields = mysql_list_fields( db_conn, row[0], nullptr );
        if ( fields == nullptr ) {
            std::cerr << "Error: " << mysql_error( db_conn ) << std::endl;
            mysql_free_result( res );
            mysql_close( db_conn );
            mysql_library_end();

            exit( 1 );
        }

        std::stringstream ss;
        ss << "SELECT column_name, data_type FROM information_schema.columns "
              "WHERE table_name = "
           << std::quoted( std::next( tables.end(), -1 )->name, '\'' );
        std::string query = ss.str();

        if ( mysql_query( db_conn, query.c_str() ) ) {
            std::cerr << "Error: " << mysql_error( db_conn ) << std::endl;
            mysql_free_result( res );
            mysql_close( db_conn );
            mysql_library_end();

            exit( 1 );
        }
        MYSQL_RES* userInputtedData;
        userInputtedData = mysql_store_result( db_conn );
        if ( !userInputtedData ) {
            std::cerr << "Error: " << mysql_error( db_conn ) << std::endl;
            mysql_free_result( res );
            mysql_close( db_conn );
            mysql_library_end();

            exit( 1 );
        }

        // "Fields in table "
        for ( unsigned int j = 0; j < mysql_num_fields( fields ); j++ ) {
            MYSQL_FIELD* field = mysql_fetch_field_direct( fields, j );
            MYSQL_ROW dataTypeRow = mysql_fetch_row( userInputtedData );

            std::next( tables.end(), -1 )
                ->fields.emplace_back( field->name, field->type, field->flags, dataTypeRow[1] );
        }

        mysql_free_result( fields );
        mysql_free_result( userInputtedData );
    }

    // Clean up and close the connection
    mysql_free_result( res );
    mysql_close( db_conn );
    mysql_library_end();
    return tables;
}

void printDBTables( const char* HOST, const char* USER, const char* PASSWORD,
                    const char* DATABASE ) {
    std::vector<Table> tables = getDBTables( HOST, USER, PASSWORD, DATABASE );
    std::for_each( tables.begin(), tables.end(), [&]( const auto& table ) {
        std::cout << "\n\nTable: " << table.name << '\n';
        puts( "" );
        std::cout << std::left << std::setw( 30 ) << "Field Name";
        std::cout << std::left << std::setw( 30 ) << "Internal Field Type";
        std::cout << std::left << std::setw( 30 ) << "External Field Type";
        std::cout << std::left << std::setw( 30 ) << "Unsigned" << '\n';
        std::cout << std::left << std::setw( 100 ) << std::setfill( '-' ) << '-'
                  << std::setfill( ' ' ) << '\n';

        puts( "" );
        std::for_each( table.fields.begin(), table.fields.end(), [&]( const auto& field ) {
            std::cout << std::left << std::setw( 30 ) << field.name;
            std::cout << std::left << std::setw( 30 ) << fieldTypes[field.type];
            std::cout << std::left << std::setw( 30 ) << field.externalType;
            std::cout << std::boolalpha << std::left << std::setw( 10 )
                      << ( ( field.flags & UNSIGNED_FLAG ) == static_cast<int>( UNSIGNED_FLAG ) );
            std::cout << std::endl;
        } );
    } );

    puts( "" );
}

void printDBTables( const std::vector<Table>& tables ) {
    std::for_each( tables.begin(), tables.end(), [&]( const auto& table ) {
        std::cout << "\n\nTable: " << table.name << '\n';
        puts( "" );
        std::cout << std::left << std::setw( 30 ) << "Field Name";
        std::cout << std::left << std::setw( 30 ) << "Internal Field Type";
        std::cout << std::left << std::setw( 30 ) << "External Field Type";
        std::cout << std::left << std::setw( 30 ) << "Unsigned" << '\n';
        std::cout << std::left << std::setw( 100 ) << std::setfill( '-' ) << '-'
                  << std::setfill( ' ' ) << '\n';

        puts( "" );
        std::for_each( table.fields.begin(), table.fields.end(), [&]( const auto& field ) {
            std::cout << std::left << std::setw( 30 ) << field.name;
            std::cout << std::left << std::setw( 30 ) << fieldTypes[field.type];
            std::cout << std::left << std::setw( 30 ) << field.externalType;
            std::cout << std::boolalpha << std::left << std::setw( 10 )
                      << ( ( field.flags & UNSIGNED_FLAG ) == static_cast<int>( UNSIGNED_FLAG ) );
            std::cout << std::endl;
        } );
    } );

    puts( "" );
}
