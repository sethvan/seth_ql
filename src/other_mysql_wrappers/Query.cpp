#include "Query.h"

#include "common.h"

namespace seth_ql {
   Query::Query( MYSQL* _conn ) : conn( _conn ) {
   }

   void Query::execute( std::string_view q ) {
      if ( mysql_real_query( conn, q.data(), q.length() ) ) {
         failOut( "mysql_real_query()", mysql_error( conn ) );
      }
   }
}  // namespace seth_ql
