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
      MYSQL* conn = nullptr;
      Connection( const std::string& host, const std::string& user, const std::string& password,
                  const std::string& database, unsigned int port, const std::string& unix_socket,
                  unsigned long client_flag );
      ~Connection();
      Connection( const Connection& ) = delete;
      Connection& operator=( const Connection& ) = delete;
      Connection( Connection&& rhs ) = delete;
      Connection& operator=( Connection&& rhs ) = delete;

      operator MYSQL*();
   };

}  // namespace seth_ql

#endif  // INCLUDED_MYSQLSESSION_H