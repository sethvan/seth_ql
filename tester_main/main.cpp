#include <mysql/mysql.h>

#include <array>
#include <iostream>

#include "MySQLSession.h"
#include "Query.h"
#include "csv_parser.h"
#include "myVars.h"

using namespace seth_ql;

int main() {
   try {
      MySQLSession::init();
      auto db_conn = createConnection( HOST, USER, PASSWORD, DATABASE );

      Query query( db_conn );
      query.execute(
          "create table Data7602(anzsic06 varchar(6) not null, Area varchar(10) not null,`year` "
          "year not null, geo_count int not null, ec_count int not null, primary key(anzsic06, "
          "Area))" );

      std::array<bool, 5> quoted = { true, true, true, false, false };
      insert_csv_to_table( db_conn, "Data7602", "res/Data7602DescendingYearOrder.csv", quoted );

   } catch ( std::runtime_error& e ) { std::cerr << e.what(); }

   return 0;
}