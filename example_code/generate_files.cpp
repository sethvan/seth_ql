#if __linux__
#include <mysql/mysql.h>
#else
#include <mysql.h>
#endif

#include <iostream>

#include "createDBTableBinds.h"

using namespace seth_ql;

int main() {
   try {
      createDBTableBinds( HOST, USER, PASSWORD, "girrafe", "sample_code/generated_files/girrafeBinds.h",
                          "sample_code/generated_files/girrafeBinds.cpp", "girrafeBinds.h", 100 );

      printf( "Success\n" );

   } catch ( std::runtime_error& e ) { std::cerr << e.what(); }

   return 0;
}