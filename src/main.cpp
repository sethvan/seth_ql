#include <mysql/mysql.h>

#include <cstring>
#include <initializer_list>
#include <iostream>

#include "myvars.h"
#include "sqlTypes.hpp"
#include "tablerow.h"
#include "utilities.h"

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

                        TableRow bank_account_request( make_vector<SqlCType>(
                            std::make_unique<TypeInt>( "acc_no" ),
                            std::make_unique<TypeCharArray>( "fname", MYSQL_TYPE_STRING ),
                            std::make_unique<TypeCharArray>( "lname", MYSQL_TYPE_STRING ),
                            std::make_unique<TypeCharArray>( "balance", MYSQL_TYPE_STRING ) ) );

                        bank_account_request.setBinds(
                            std::initializer_list<bool>( { true, false, false, false } ) );

                        if ( !mysql_stmt_bind_param( stmt, bank_account_request.getBinds() ) ) {

                            TableRow bank_account_response( make_vector<SqlCType>(
                                std::make_unique<TypeInt>( "acc_no" ),
                                std::make_unique<TypeCharArray>( "fname", MYSQL_TYPE_VAR_STRING ),
                                std::make_unique<TypeCharArray>( "lname", MYSQL_TYPE_VAR_STRING ),
                                std::make_unique<TypeCharArray>( "balance",
                                                                 MYSQL_TYPE_NEWDECIMAL ) ) );

                            bank_account_response.setBinds(
                                std::initializer_list<bool>( { true, true, true, true } ) );

                            for ( int i = 100; i < 109; ++i ) {
                                bank_account_request.fields[0]->set_value( i );

                                if ( !mysql_stmt_execute( stmt ) ) {

                                    if ( !mysql_stmt_bind_result(
                                             stmt, bank_account_response.getBinds() ) ) {

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
                                                    bank_account_response.fields.begin(),
                                                    bank_account_response.fields.end(),
                                                    []( SqlCType* ptr ) { ptr->printValue(); } );
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

    return retval;
}
