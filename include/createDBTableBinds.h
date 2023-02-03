#ifndef INCLUDED_CREATEDBTABLEBINDS_H
#define INCLUDED_CREATEDBTABLEBINDS_H

#include <getDBTables.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

void createDBTableBinds( std::string_view host, std::string_view user, std::string_view password,
                         std::string_view database, std::string_view declFile, std::string_view defnFile,
                         std::string_view includeStr,
                         unsigned long buff_size );  // buff_size will be the buff size for all the
                                                     // binds created that are char[]

void replaceWord( std::string& str, const std::string& pattern, const std::string& replacement );

#endif  // INCLUDED_CREATEDBTABLEBINDS_H