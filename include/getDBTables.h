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

std::vector<Table> getDBTables( std::string_view host, std::string_view user, std::string_view password,
                                std::string_view database );
void printDBTables( std::string_view host, std::string_view user, std::string_view password,
                    std::string_view database );
void printDBTables( const std::vector<Table>& tables );

#endif  // INCLUDED_GETTABLES_H