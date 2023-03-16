#include <mysql/mysql.h>

#include <iostream>
#include <string>
#include <string_view>

#include "MySQLSession.h"
#include "Statement.h"
#include "giraffeBinds.h"
#include "makeBinds.hpp"
#include "myVars.h"

using namespace seth_ql;

int main() {
   try {
      MySQLSession::init();
      Span<const bool> quoted auto db_conn = createConnection( HOST, USER, PASSWORD, DATABASE );
      Statement stmt( db_conn, "INSERT into client values(?,?,?)" );
      auto clientIn = makeInputBindsArray(
          Bind<INT>( "client_id" ), Bind<VARCHAR>( "client_name", 100 ), Bind<INT>( "branch_id" ) );
      stmt.bind_param( clientIn.getBinds() );

      std::string str = "Chicago Tribune";
      clientIn[ "client_id" ] = 407;
      clientIn[ "client_name" ] = str;
      clientIn[ "branch_id" ] = 3;
      stmt.execute();

      char arr[ 20 ] = { 'F', 'D', 'A', '\0' };
      clientIn[ 0 ] = "408";
      clientIn[ 1 ] = arr;
      clientIn[ 2 ] = "2";
      stmt.execute();

      auto it = clientIn.fields.begin();
      **it = "409";
      **++it = "Global Gas";
      **++it = "3";
      stmt.execute();

      printf( "Success\n" );

   } catch ( std::runtime_error& e ) { std::cerr << e.what(); }

   return 0;
}