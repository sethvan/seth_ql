#include <mysql/mysql.h>

#include <iostream>

#include "MySQLSession.h"

#include "createDBTableBinds.h"
#include "myVars.h"

using namespace seth_ql;

int main() {
   try {
      MySQLSession::init();
      auto db_conn = createConnection( HOST, USER, PASSWORD, "girrafe" );

      createDBTableBinds( HOST, USER, PASSWORD, "girrafe",
                          "create_db_table_binds/generated_code/include/girrafeBinds.h",
                          "create_db_table_binds/generated_code/girrafeBinds.cpp", "girrafeBinds.h",
                          100 );

      printf( "Success\n" );

   } catch ( std::runtime_error& e ) { std::cerr << e.what(); }

   return 0;
}