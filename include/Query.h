#ifndef INCLUDED_QUERY_H
#define INCLUDED_QUERY_H

#include <mysql/mysql.h>

#include <string_view>

namespace seth_ql {

   class Query {
     private:
      MYSQL* conn;

     public:
      Query() = delete;
      Query( const Query& ) = delete;
      Query& operator=( const Query& ) = delete;
      Query( MYSQL* _conn );
      void execute( std::string_view q );
   };

}  // namespace seth_ql

#endif  // INCLUDED_QUERY_H