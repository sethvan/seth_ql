#include "MySQLSession.h"

#include <stdexcept>

#include "common.h"

namespace seth_ql {

   MySQLSession::MySQLSession() {
      if ( mysql_library_init( 0, nullptr, nullptr ) ) {
         throw std::runtime_error( "could not initialize MySQL client library" );
      }
   }

   MySQLSession::~MySQLSession() {
      mysql_library_end();
   }

   MySQLSession& MySQLSession::init() {
      static MySQLSession session;
      return session;
   }

   Connection::Connection() {
      if ( !( conn = mysql_init( nullptr ) ) ) {
         throw std::runtime_error( std::string( "Error: " ) + mysql_error( conn ) );
      }
   }

   Connection::~Connection() {
      mysql_close( conn );
   }

   Connection::operator MYSQL*() {
      return conn;
   }

   Connection createConnection( const std::string& host, const std::string& user,
                                const std::string& password, const std::string& database ) {
      Connection conn;
      if ( !mysql_real_connect( conn, host.c_str(), user.c_str(), password.c_str(),
                                database.c_str(), 0, nullptr, 0 ) ) {
         failOut( "mysql_real_connect()", mysql_error( conn ) );
      }
      return conn;
   }

}  // namespace seth_ql