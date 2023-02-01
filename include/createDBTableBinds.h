#ifndef INCLUDED_CREATEDBTABLEBINDS_H
#define INCLUDED_CREATEDBTABLEBINDS_H

#include <getDBTables.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void createDBTableBinds( const char* HOST, const char* USER, const char* PASSWORD,
                         const char* DATABASE );

#endif  // INCLUDED_CREATEDBTABLEBINDS_H