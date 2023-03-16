#ifndef INCLUDED_GETDBTABLES_H
#define INCLUDED_GETDBTABLES_H
#include <mysql/mysql.h>

#include <span>
#include <string>
#include <vector>

namespace seth_ql {

   struct TableField {
      std::string name;
      enum_field_types type;
      unsigned long int flags;
      std::string externalType;
   };

   struct Table {
      std::string name;
      std::vector<TableField> fields;
   };

   std::vector<Table> getDBTables( const std::string& host, const std::string& user,
                                   const std::string& password, const std::string& database );
   void printDBTables( std::span<const Table> tables );
   void printDBTables( const std::string& host, const std::string& user,
                       const std::string& password, const std::string& database );

}  // namespace seth_ql

#endif  // INCLUDED_GETTABLES_H