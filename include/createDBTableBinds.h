#ifndef INCLUDED_CREATEDBTABLEBINDS_H
#define INCLUDED_CREATEDBTABLEBINDS_H

#include <getDBTables.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void createDBTableBinds( const char* HOST, const char* USER, const char* PASSWORD,
                         const char* DATABASE,
                         unsigned long buff_size );  // buff_size will be the buff size for all the
                                                     // binds created that are char[]

void replaceWord( std::string& str, const std::string& pattern, const std::string& replacement );

#endif  // INCLUDED_CREATEDBTABLEBINDS_H