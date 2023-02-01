#include <mysql/mysql.h>

#include <cstring>
#include <initializer_list>
#include <iostream>

#include "binds.hpp"
#include "createDBTableBinds.h"
#include "getDBTables.h"
#include "mybank_binds.h"
#include "myvars.h"
#include "sqlTypes.hpp"

int main() {

    int retval = 0;
    int count = 0;
    MYSQL* db_conn;
    MYSQL_STMT* stmt;
    std::string_view getRow( "SELECT * FROM bank_account WHERE acc_no=?" );

    if ( !mysql_library_init( 0, nullptr, nullptr ) ) {

        if ( ( db_conn = mysql_init( nullptr ) ) ) {

            if ( mysql_real_connect( db_conn, HOST, USER, PASSWORD, DATABASE, 0, nullptr, 0 ) ) {

                if ( ( stmt = mysql_stmt_init( db_conn ) ) ) {

                    if ( !mysql_stmt_prepare( stmt, getRow.data(), getRow.length() ) ) {

                        auto requestBinds = bank_account_request_bind();
                        requestBinds.setBinds(
                            std::initializer_list<bool>{ true, false, false, false } );

                        if ( !mysql_stmt_bind_param( stmt, requestBinds.getBinds() ) ) {

                            auto responseBinds = bank_account_response_bind();
                            responseBinds.setBinds();

                            for ( int i = 100; i < 109; ++i ) {
                                requestBinds.fields[0]->set_value( i );

                                if ( !mysql_stmt_execute( stmt ) ) {

                                    if ( !mysql_stmt_bind_result( stmt,
                                                                  responseBinds.getBinds() ) ) {

                                        MYSQL_RES* result;
                                        if ( ( result = mysql_stmt_result_metadata( stmt ) ) ) {

                                            if ( !count++ ) {
                                                MYSQL_FIELD* field;
                                                std::cout << '\n';
                                                while ( ( field = mysql_fetch_field( result ) ) ) {

                                                    std::cout << std::left << std::setw( 30 )
                                                              << field->name;
                                                }
                                                std::cout << '\n';
                                                std::cout << std::setw( 120 ) << std::setfill( '-' )
                                                          << '-' << '\n'
                                                          << std::setfill( ' ' );
                                            }

                                            while ( !mysql_stmt_fetch( stmt ) ) {
                                                std::for_each(
                                                    responseBinds.fields.begin(),
                                                    responseBinds.fields.end(),
                                                    []( auto* ptr ) { ptr->printValue(); } );
                                                puts( "" );
                                            }

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

    // Clean up and close the connection

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
    // createDBTableBinds( HOST, USER, PASSWORD, DATABASE );

    return 0;
}
