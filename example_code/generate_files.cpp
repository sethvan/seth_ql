#include <mysql/mysql.h>

#include <iostream>

#include "seth_ql.h"

/*
    The createDBTableBinds()'s function gets the data for all the tables in a specified database and
    writes separate binds (from BindsArray.hpp) object builder functions for each of them to source
   code files.

    The function declarations to a .h/.hpp file and their definitions to a .cpp file using
    the paths that are specified in the function arguments.

    For examples of what this function outputs see the generated_files folder.

*/

using namespace seth_ql;

int main() {
   try {
      createDBTableBinds( HOST, USER, PASSWORD, DATABASE, "path_to_create_your_database_binds.h",
                          "path_to_create_your_databse_binds.cpp", "header_include_as_appears_in_cpp_file",
                          /*default buffer size for all char array types here, can be individually modified later*/ );

   } catch ( std::runtime_error& e ) { std::cerr << e.what(); }

   return 0;
}