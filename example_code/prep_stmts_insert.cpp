#if __linux__
#include <mysql/mysql.h>
#else
#include <mysql.h>
#endif

#include <iostream>
#include <string>
#include <string_view>

#include "MySQLSession.h"
#include "Statement.h"
#include "makeBinds.hpp"
#include "myVars.h"

using namespace seth_ql;

int main() {
   try {
      MySQLSession::init();
      auto db_conn = createConnection( HOST, USER, PASSWORD, "girrafe" );
      Statement stmt( db_conn, "INSERT into client values(?,?,?)" );
      auto clientIn = makeInputBindsArray( Bind<T_INT>( "client_id" ), Bind<T_VARCHAR>( "client_name", 100 ),
                                           Bind<T_INT>( "branch_id" ) );
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

   } catch ( std::runtime_error& e ) { std::cerr << e.what(); }

   return 0;
}