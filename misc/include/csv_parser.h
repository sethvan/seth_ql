#ifndef INCLUDED_CSV_PARSER_H
#define INCLUDED_CSV_PARSER_H

#include <mysql/mysql.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <span>
#include <string>
#include <vector>

namespace seth_ql {

   std::vector<std::vector<std::string>> get_csv_rows( const std::string& csv_path );
   void insert_csv_to_table( MYSQL* conn, const std::string& table_name,
                             const std::string& csv_path, std::span<const bool> quoted );

}  // namespace seth_ql

#endif  // INCLUDED_CSV_PARSER_H