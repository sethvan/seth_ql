#ifndef INCLUDED_MYSQLSESSION_H
#define INCLUDED_MYSQLSESSION_H

#if __linux__
#include <mysql/mysql.h>
#else
#include <mysql.h>
#endif

#include <string>

namespace seth_ql {

   class MySQLSession {
     private:
      MySQLSession();
      ~MySQLSession();

     public:
      MySQLSession( const MySQLSession& ) = delete;
      MySQLSession& operator=( const MySQLSession& ) = delete;
      static MySQLSession& init();
   };

   struct Connection {
      MYSQL* conn;
      Connection();
      ~Connection();
      operator MYSQL*();
   };

   [[nodiscard]] Connection createConnection( const std::string& host, const std::string& user,
                                              const std::string& password, const std::string& database );

}  // namespace seth_ql

#endif  // INCLUDED_MYSQLSESSION_H