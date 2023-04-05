#ifndef INCLUDED_GETDBTABLES_H
#define INCLUDED_GETDBTABLES_H

#include <mysql/mysql.h>

#include <string>
#include <vector>

#include "Span.hpp"

namespace seth_ql {

   struct TableField {
      std::string name;
      enum_field_types type;
      unsigned long int flags;
      std::string externalType;
      TableField( const std::string& _name, enum_field_types _type, unsigned long int _flags,
                  const std::string& _externalType )
          : name( _name ), type( _type ), flags( _flags ), externalType( _externalType ) {}
   };

   struct Table {
      std::string name;
      std::vector<TableField> fields;
      Table() = default;
      Table( const std::string& _name, const std::vector<TableField> _fields ) : name( _name ), fields( _fields ) {}
   };

   std::vector<Table> getDBTables( const std::string& host, const std::string& user, const std::string& password,
                                   const std::string& database );
   void printDBTables( Span<const Table> tables );
   void printDBTables( const std::string& host, const std::string& user, const std::string& password,
                       const std::string& database );

}  // namespace seth_ql

#endif  // INCLUDED_GETTABLES_H