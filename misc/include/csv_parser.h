#ifndef INCLUDED_CSV_PARSER_H
#define INCLUDED_CSV_PARSER_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace seth_ql {
std::vector<std::vector<std::string>> get_csv_rows( const std::string& csv_path );
}

#endif  // INCLUDED_CSV_PARSER_H