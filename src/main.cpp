#include <mysql/mysql.h>

#include <cstring>
#include <initializer_list>
#include <iostream>

// #include "_generated/mybankBinds.h"
// #include "_generated/performance_schemaBinds.h"
#include "binds.hpp"
#include "createDBTableBinds.h"
#include "getDBTables.h"
#include "myvars.h"
#include "sqlTypes.hpp"

using namespace binds_wrapper;

int main() {

    createDBTableBinds( HOST, USER, PASSWORD, "performance_schema", "include/_generated/performance_schemaBinds.h",
                        "src/_generated/performance_schemaBinds.cpp", "_generated/performance_schemaBinds.h", 100 );
    createDBTableBinds( HOST, USER, PASSWORD, "mybank", "include/_generated/myBankBinds.h",
                        "src/_generated/myBankBinds.cpp", "_generated/myBankBinds.h", 100 );
    createDBTableBinds( HOST, USER, PASSWORD, "giraffe", "include/_generated/giraffeBinds.h",
                        "src/_generated/giraffeBinds.cpp", "_generated/giraffeBinds.h", 100 );

    return 0;
}
