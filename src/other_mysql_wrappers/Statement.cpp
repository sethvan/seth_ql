#include "Statement.h"

#include <mysql/mysql.h>

#include "common.h"

namespace seth_ql {
   Statement::Statement( MYSQL* _conn, std::string_view statement ) : conn( _conn ), closed( false ) {
      if ( !( stmt = mysql_stmt_init( conn ) ) ) {
         failOut( "mysql_stmt_init()", "out of memory" );
      }
      if ( mysql_stmt_prepare( stmt, statement.data(), statement.length() ) ) {
         failOut( "mysql_stmt_prepare()", mysql_stmt_error( stmt ) );
      }
   }

   Statement::~Statement() {
      if ( !closed ) {
         close();
      }
   }

   Statement::operator MYSQL_STMT*() {
      return stmt;
   }

   void Statement::bind_param( MYSQL_BIND* bind ) {
      if ( mysql_stmt_bind_param( stmt, bind ) ) {
         failOut( "mysql_stmt_bind_param()", mysql_stmt_error( stmt ) );
      }
   }

   void Statement::execute() {
      if ( mysql_stmt_execute( stmt ) ) {
         failOut( "mysql_stmt_execute()", mysql_stmt_error( stmt ) );
      }
   }

   void Statement::bind_result( MYSQL_BIND* bind ) {
      if ( mysql_stmt_bind_result( stmt, bind ) ) {
         failOut( "mysql_stmt_bind_result()", mysql_stmt_error( stmt ) );
      }
   }

   void Statement::close() {
      if ( mysql_stmt_close( stmt ) ) {
         /* mysql_stmt_close() invalidates stmt, so call          */
         /* mysql_error(mysql) rather than mysql_stmt_error(stmt) */
         failOut( "mysql_stmt_close()", mysql_error( conn ) );
      }
      closed = true;
   }

}  // namespace seth_ql