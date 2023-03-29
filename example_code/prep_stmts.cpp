#if __linux__
#include <mysql/mysql.h>
#else
#include <mysql.h>
#endif

#include <iostream>
#include <string>
#include <string_view>

#include "seth_ql.h"

using namespace seth_ql;

// helper function
void displayResult( MYSQL_STMT* stmt, const BindsArray<OutputCType>& output, int count );

int main() {
   try {
      MySQLSession::init();
      auto db_conn = createConnection( HOST, USER, PASSWORD, DATABASE, 0, "", 0 );
      Query q( db_conn );
      q.execute( "DROP TABLE IF EXISTS test_table" );
      q.execute(
          "CREATE TABLE test_table(emp_id INT NOT NULL, name VARCHAR(50) NOT NULL, role VARCHAR(50) NOT NULL, site_id \
          INT NOT NULL)" );
      q.execute(
          "INSERT INTO test_table VALUES(100, \'John Smith\', \'Sys Admin\', 2),\
                                        (101, \'Jane Stafford\', \'HR Director\', 3),\
                                        (102, \'Fred Milton\', \'Senior Engineer\', 2),\
                                        (103, \'Veronica Lopez\', \'CEO\', 2);" );

      Statement stmt1( db_conn, "SELECT * FROM test_table WHERE site_id=?" );
      auto whereInput = makeInputBindsArray( Bind<Field::INT>( "site_id" ) );
      stmt1.bind_param( whereInput.getBinds() );
      auto tableOut = makeOutputBindsArray( Bind<Field::INT>( "emp_id" ), Bind<Field::VARCHAR>( "name", 50 ),
                                            Bind<Field::VARCHAR>( "role", 50 ), Bind<Field::INT>( "site_id" ) );
      stmt1.bind_result( tableOut.getBinds() );

      int count = 0;
      for ( int i = 2; i < 4; ++i ) {
         whereInput[ "site_id" ] = i;
         stmt1.execute();
         displayResult( stmt1, tableOut, count++ );
      }

      Statement stmt2( db_conn, "INSERT into test_table values(?,?,?,?)" );
      auto tableIn = makeInputBindsArray( Bind<Field::INT>( "emp_id" ), Bind<Field::VARCHAR>( "name", 50 ),
                                          Bind<Field::VARCHAR>( "role", 50 ), Bind<Field::INT>( "site_id" ) );
      stmt2.bind_param( tableIn.getBinds() );

      std::string str = "Jamal Thompson";
      tableIn[ "emp_id" ] = 104;
      tableIn[ "name" ] = str;
      tableIn[ "site_id" ] = 3;
      tableIn[ "role" ] = "CFO";
      stmt2.execute();

      char arr[ 20 ] = { 'L', 'y', 'n', ' ', 'Q', 'w', 'a', 'n', '\0' };
      tableIn[ 0 ] = "105";
      tableIn[ 1 ] = arr;
      tableIn[ 2 ] = "Sales Strategist";
      tableIn[ 3 ] = "2";
      stmt2.execute();

      auto it = tableIn.fields.begin();
      **it = 106;
      **++it = "Melanie Hicks";
      **++it = "3rd Party Procurement Rep";
      **++it = "3";
      stmt2.execute();

      Statement stmt3( db_conn, "SELECT * FROM test_table WHERE emp_id=?" );
      tableIn.setBinds( { "emp_id" } );  // only sets bind named "emp_id" for binding
      stmt3.bind_param( tableIn.getBinds() );
      stmt3.bind_result( tableOut.getBinds() );

      count = 0;
      for ( int i = 100; i < 107; ++i ) {
         tableIn[ "emp_id" ] = i;
         stmt3.execute();
         displayResult( stmt3, tableOut, count++ );
      }

   } catch ( std::runtime_error& e ) { std::cerr << e.what(); }

   return 0;
}

void displayResult( MYSQL_STMT* stmt, const BindsArray<OutputCType>& output, int count ) {
   MYSQL_RES* result;
   if ( ( result = mysql_stmt_result_metadata( stmt ) ) ) {
      if ( !count ) {
         MYSQL_FIELD* field;
         std::cout << '\n';
         while ( ( field = mysql_fetch_field( result ) ) ) {
            std::cout << std::left << std::setw( 30 ) << field->name;
         }
         std::cout << "\n\n";
      }
      while ( !mysql_stmt_fetch( stmt ) ) {
         std::for_each( output.fields.begin(), output.fields.end(), []( auto* ptr ) {
            if ( ptr->is_selected ) {
               std::cout << std::left << std::setw( 30 ) << *ptr;
            }
         } );
         puts( "" );
      }

      mysql_free_result( result );
   }
}
