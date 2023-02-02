#include <mysql/mysql.h>

#include <cstring>
#include <initializer_list>
#include <iostream>

#include "_generated/mybankBinds.h"
#include "_generated/performance_schemaBinds.h"
#include "binds.hpp"
#include "createDBTableBinds.h"
#include "getDBTables.h"
#include "myvars.h"
#include "sqlTypes.hpp"

int main() {

    // createDBTableBinds( HOST, USER, PASSWORD, DATABASE, 100 );

    int retval = 0;
    int count = 0;
    MYSQL* db_conn;
    MYSQL_STMT* stmt;
    std::string_view getRow( "select * from events_statements_current where thread_id=?" );

    if ( !mysql_library_init( 0, nullptr, nullptr ) ) {

        if ( ( db_conn = mysql_init( nullptr ) ) ) {

            if ( mysql_real_connect( db_conn, HOST, USER, PASSWORD, DATABASE, 0, nullptr, 0 ) ) {

                if ( ( stmt = mysql_stmt_init( db_conn ) ) ) {

                    if ( !mysql_stmt_prepare( stmt, getRow.data(), getRow.length() ) ) {

                        Binds<InputCType> requestBinds( make_vector<InputCType>(
                            std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ) ) );
                        requestBinds.setBinds();

                        if ( !mysql_stmt_bind_param( stmt, requestBinds.getBinds() ) ) {

                            auto responseBinds = events_statements_currentOutputBinds();
                            responseBinds.setBinds();

                            for ( int i = 100; i < 101; ++i ) {
                                requestBinds.fields[0]->set_value( static_cast<unsigned long long>( 56 ) );

                                if ( !mysql_stmt_execute( stmt ) ) {

                                    if ( !mysql_stmt_bind_result( stmt, responseBinds.getBinds() ) ) {

                                        MYSQL_RES* result;
                                        if ( ( result = mysql_stmt_result_metadata( stmt ) ) ) {

                                            if ( !count++ ) {
                                                MYSQL_FIELD* field;
                                                std::cout << '\n';
                                                while ( ( field = mysql_fetch_field( result ) ) ) {

                                                    // std::cout << std::left << std::setw( 30 )
                                                    //           << field->name;
                                                }
                                                // std::cout << '\n';
                                                // std::cout << std::setw( 120 ) <<
                                                // std::setfill( '-' )
                                                //           << '-' << '\n'
                                                //           << std::setfill( ' ' );
                                            }

                                            while ( !mysql_stmt_fetch( stmt ) ) {
                                                printf( "Inside fetch!\n" );
                                                // std::for_each(
                                                //     responseBinds.fields.begin(),
                                                //     responseBinds.fields.end(),
                                                //     []( auto* ptr ) { ptr->printValue(); } );
                                                // puts( "" );
                                            }
                                            responseBinds.displayFields();

                                            mysql_free_result( result );
                                        }
                                    }
                                    else {
                                        std::cerr << " Could not bind result!\n";
                                        std::cerr << mysql_stmt_error( stmt ) << '\n';
                                        retval = 2;
                                    }
                                }
                                else {
                                    std::cerr << " mysql_stmt_execute() failed\n";
                                    std::cerr << mysql_stmt_error( stmt ) << '\n';
                                    retval = 2;
                                }
                            }
                        }
                        else {
                            std::cerr << " mysql_stmt_bind_param() failed\n";
                            std::cerr << mysql_stmt_error( stmt ) << '\n';
                            retval = 2;
                        }
                    }
                    else {
                        std::cerr << "STMT query failed!\n";
                        std::cerr << mysql_stmt_error( stmt ) << '\n';
                        retval = 1;
                    }
                }
                else {
                    std::cerr << " mysql_stmt_init(), out of memory\n";
                    retval = 1;
                }
            }
            else {
                std::cerr << "Error: " << mysql_error( db_conn ) << '\n';
                retval = 1;
            }
        }
        else {
            std::cerr << "Error: " << mysql_error( db_conn ) << '\n';
            mysql_library_end();
            return 1;
        }
    }
    else {
        std::cerr << "could not initialize MySQL client library\n";
        return 1;
    }
    std::cout << '\n';

    if ( retval != 1 ) {
        if ( mysql_stmt_close( stmt ) ) {
            /* mysql_stmt_close() invalidates stmt, so call          */
            /* mysql_error(mysql) rather than mysql_stmt_error(stmt) */
            std::cerr << " failed while closing the statement\n";
            std::cerr << mysql_error( db_conn ) << '\n';
        }
    }

    mysql_close( db_conn );
    mysql_library_end();

    return 0;
}
