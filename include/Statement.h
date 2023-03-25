#ifndef INCLUDED_STATEMENT_H
#define INCLUDED_STATEMENT_H

#if __linux__
#include <mysql/mysql.h>
#else
#include <mysql.h>
#endif

#include <string_view>

namespace seth_ql {
   class Statement {
     private:
      MYSQL* conn;  // for the close() method
      bool closed;

     public:
      MYSQL_STMT* stmt;
      Statement() = delete;
      Statement( const Statement& ) = delete;
      Statement& operator=( const Statement& ) = delete;
      ~Statement();
      Statement( MYSQL* _conn, std::string_view statement );
      operator MYSQL_STMT*();
      void bind_param( MYSQL_BIND* bind );
      void execute();
      void bind_result( MYSQL_BIND* bind );
      void close();
   };
}  // namespace seth_ql

#endif  // INCLUDED_STATEMENT_H