#ifndef INCLUDED_GETDBTABLES_H
#define INCLUDED_GETDBTABLES_H
#include <mysql/mysql.h>

#include <string>
#include <string_view>
#include <vector>

struct Field {
    std::string name;
    enum_field_types type;
    unsigned long int flags;
    std::string externalType;
};

struct Table {
    std::string name;
    std::vector<Field> fields;
};

std::vector<Table> getDBTables( const char* HOST, const char* USER, const char* PASSWORD, const char* DATABASE );
void printDBTables( const char* HOST, const char* USER, const char* PASSWORD, const char* DATABASE );
void printDBTables( const std::vector<Table>& tables );

#endif  // INCLUDED_GETTABLES_H