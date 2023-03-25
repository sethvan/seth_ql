#ifndef INCLUDED_QUERY_H
#define INCLUDED_QUERY_H

#if __linux__
#include <mysql/mysql.h>
#else
#include <mysql.h>
#endif

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