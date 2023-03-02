#include <mysql/mysql.h>

#include <iostream>
#include <string>
#include <string_view>

#include "_generated/giraffeBinds.h"
#include "myVars.h"
#include "set_mysql_binds.h"

using namespace set_mysql_binds;
using enum set_mysql_binds::MysqlInputType;

int main() {
   //    createDBTableBinds(
   //        HOST, USER, PASSWORD, DATABASE, "include/_generated/performance_schemaBinds.h",
   //        "src/_generated/performance_schemaBinds.cpp", "_generated/performance_schemaBinds.h",
   //        100 );

   // printDBTables( HOST, USER, PASSWORD, DATABASE );

   auto branch = branchInputBindsArray();
   branch[ "branch_id" ]->set_value( 12 );
   branch[ "branch_name" ]->set_value( "Hayward" );
   branch[ "mgr_id" ]->set_value( 342 );
   auto& strtDate = branch[ "mgr_start_date" ]->Value<DATE>();
   strtDate.year = 2002;
   strtDate.month = 6;
   strtDate.day = 17;
   strtDate.hour = 3;
   strtDate.minute = 33;
   strtDate.second = 9;
   branch.displayFields();

   return 0;
}