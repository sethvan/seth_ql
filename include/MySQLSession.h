#ifndef INCLUDED_MYSQLSESSION_H
#define INCLUDED_MYSQLSESSION_H

#include <mysql/mysql.h>

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
                                              const std::string& password, const std::string& database,
                                              unsigned int port, const std::string& unix_socket,
                                              unsigned long client_flag );

}  // namespace seth_ql

#endif  // INCLUDED_MYSQLSESSION_H