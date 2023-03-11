#include <mysql/mysql.h>

#include <iostream>
#include <string>
#include <string_view>

#include "giraffeBinds.h"
#include "makeBinds.hpp"
#include "myVars.h"

namespace seth_ql {

void failOut( const char* functionName, const char* errMsg ) {
   throw std::runtime_error( std::string( functionName ) + " failed\n" + errMsg + "\n" );
}

class MySQLSession {
  private:
   MySQLSession() {
      if ( mysql_library_init( 0, nullptr, nullptr ) ) {
         throw std::runtime_error( "could not initialize MySQL client library" );
      }
   }
   ~MySQLSession() { mysql_library_end(); }

  public:
   MySQLSession( const MySQLSession& ) = delete;
   MySQLSession& operator=( const MySQLSession& ) = delete;

   static MySQLSession& init() {
      static MySQLSession session;
      return session;
   }
};

struct Connection {
   MYSQL* conn;
   Connection() {
      if ( !( conn = mysql_init( nullptr ) ) ) {
         throw std::runtime_error( std::string( "Error: " ) + mysql_error( conn ) );
      }
   }
   ~Connection() { mysql_close( conn ); }
   operator MYSQL*() { return conn; }
};

[[nodiscard]] Connection createConnection( const std::string& host, const std::string& user,
                                           const std::string& password,
                                           const std::string& database ) {
   Connection conn;
   if ( !mysql_real_connect( conn, host.c_str(), user.c_str(), password.c_str(), database.c_str(),
                             0, nullptr, 0 ) ) {
      failOut( "mysql_real_connect()", mysql_error( conn ) );
   }
   return conn;
}

class Statement {
  private:
   MYSQL* conn;  // for the close() method
   bool closed;

  public:
   MYSQL_STMT* stmt;
   Statement() = delete;
   Statement( const Statement& ) = delete;
   Statement& operator=( const Statement& ) = delete;
   ~Statement() {
      if ( !closed ) {
         close();
      }
   }
   Statement( MYSQL* _conn, std::string_view statement ) : conn( _conn ), closed( false ) {
      if ( !( stmt = mysql_stmt_init( conn ) ) ) {
         failOut( "mysql_stmt_init()", "out of memory" );
      }
      if ( mysql_stmt_prepare( stmt, statement.data(), statement.length() ) ) {
         failOut( "mysql_stmt_prepare()", mysql_stmt_error( stmt ) );
      }
   }
   operator MYSQL_STMT*() { return stmt; }
   void bind_param( MYSQL_BIND* bind ) {
      if ( mysql_stmt_bind_param( stmt, bind ) ) {
         failOut( "mysql_stmt_bind_param()", mysql_stmt_error( stmt ) );
      }
   }
   void execute() {
      if ( mysql_stmt_execute( stmt ) ) {
         failOut( "mysql_stmt_execute()", mysql_stmt_error( stmt ) );
      }
   }
   void bind_result( MYSQL_BIND* bind ) {
      if ( mysql_stmt_bind_result( stmt, bind ) ) {
         failOut( "mysql_stmt_bind_result()", mysql_stmt_error( stmt ) );
      }
   }
   void close() {
      if ( mysql_stmt_close( stmt ) ) {
         /* mysql_stmt_close() invalidates stmt, so call          */
         /* mysql_error(mysql) rather than mysql_stmt_error(stmt) */
         failOut( "mysql_stmt_close()", mysql_error( conn ) );
      }
      closed = true;
   }
};

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

}  // namespace seth_ql

using namespace seth_ql;
using enum seth_ql::MysqlInputType;

int main() {
   try {
      MySQLSession::init();  // singleton
      auto db_conn = createConnection( HOST, USER, PASSWORD, DATABASE );
      Statement stmt1( db_conn, "SELECT * FROM client WHERE branch_id=?" );
      auto whereInput = makeInputBindsArray( Bind<INT>( "branch_id" ) );
      stmt1.bind_param( whereInput.getBinds() );
      auto clientOut = clientOutputBindsArray();

      int count = 0;
      for ( int i = 2; i < 4; ++i ) {
         whereInput[ "branch_id" ] = i;
         stmt1.execute();
         stmt1.bind_result( clientOut.getBinds() );

         displayResult( stmt1, clientOut, count++ );
      }
      puts( "" );

      Statement stmt2( db_conn, "INSERT into client values(?,?,?)" );
      auto clientIn = clientInputBindsArray();
      stmt2.bind_param( clientIn.getBinds() );

      std::string str = "Chicago Tribune";

      clientIn[ "client_id" ] = "407";
      clientIn[ "client_name" ] = str;
      clientIn[ "branch_id" ] = "3";
      stmt2.execute();

      char arr[ 20 ] = { 'F', 'D', 'A', '\0' };

      clientIn[ 0 ] = "408";
      clientIn[ 1 ] = arr;
      clientIn[ 2 ] = "2";
      stmt2.execute();

      auto it = clientIn.fields.begin();
      **it = "409";
      **++it = "Global Gas";
      **++it = "3";
      stmt2.execute();

      Statement stmt3( db_conn, "SELECT * FROM client WHERE client_id=?" );
      whereInput = makeInputBindsArray( Bind<INT>( "client_id" ) );
      stmt3.bind_param( whereInput.getBinds() );

      count = 0;
      for ( int i = 400; i < 410; ++i ) {
         whereInput[ "client_id" ] = i;
         stmt3.execute();
         stmt3.bind_result( clientOut.getBinds() );

         displayResult( stmt3, clientOut, count++ );
      }
      puts( "" );

   } catch ( std::runtime_error& e ) { std::cerr << e.what(); }

   return 0;
}