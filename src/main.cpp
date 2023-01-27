#include <mysql/mysql.h>

#include <cstring>
#include <initializer_list>
#include <iostream>

#include "binds.hpp"
#include "myvars.h"
#include "sqlTypes.hpp"
#include "utilities.h"

int main() {

    int retval = 0;
    int count = 0;
    MYSQL* db_conn;
    MYSQL_STMT* stmt;
    std::string_view getRow( "SELECT * FROM bank_account WHERE lname=? AND acc_no > ?" );

    if ( !mysql_library_init( 0, nullptr, nullptr ) ) {

        if ( ( db_conn = mysql_init( nullptr ) ) ) {

            if ( mysql_real_connect( db_conn, HOST, USER, PASSWORD, DATABASE, 0, nullptr, 0 ) ) {

                if ( ( stmt = mysql_stmt_init( db_conn ) ) ) {

                    if ( !mysql_stmt_prepare( stmt, getRow.data(), getRow.length() ) ) {

                        Binds<RequestCType> requestBinds( make_vector<RequestCType>(
                            std::make_unique<TypeCharArrayRequest>( "lname", MYSQL_TYPE_STRING,
                                                                    100 ),
                            std::make_unique<TypeIntRequest>( "acc_no" ) ) );
                        requestBinds.setBinds();

                        if ( !mysql_stmt_bind_param( stmt, requestBinds.getBinds() ) ) {

                            Binds<ResponseCType> responseBinds( make_vector<ResponseCType>(
                                std::make_unique<TypeIntResponse>( "acc_no" ),
                                std::make_unique<TypeCharArrayResponse>(
                                    "fname", MYSQL_TYPE_VAR_STRING, 100 ),
                                std::make_unique<TypeCharArrayResponse>(
                                    "lname", MYSQL_TYPE_VAR_STRING, 100 ),
                                std::make_unique<TypeCharArrayResponse>(
                                    "balance", MYSQL_TYPE_NEWDECIMAL, 100 ) ) );
                            responseBinds.setBinds();

                            for ( int i = 100; i < 102; ++i ) {
                                requestBinds.fields[0]->set_value( "Hankins" );
                                requestBinds.fields[1]->set_value( i );
                                count = 0;

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
                                            puts( "" );
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

    return retval;
}
