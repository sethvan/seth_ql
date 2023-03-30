# seth_ql
My personal in progress C++ wrapper of the [MySQL C API](https://dev.mysql.com/doc/c-api/8.0/en/)

## Current main feature
Provides a wrapper for the [MYSQL_BIND](https://dev.mysql.com/doc/c-api/8.0/en/c-api-prepared-statement-data-structures.html) structs used to make [prepared statements](https://dev.mysql.com/doc/c-api/8.0/en/c-api-prepared-statement-interface.html) and  [set query attributes](https://dev.mysql.com/doc/c-api/8.0/en/mysql-bind-param.html).  
Adding a few other wrappers as I go starting with minimal functionality.

```c++
MySQLSession::init() /* RAII singleton that calls mysql_library_init() and destructor calls 
    mysql_library_end().*/	

Connection class /* Wraps a MYSQL* and can be included in parameters as a MYSQL* 
    via Connection::operator MYSQL*().*/

createConnection() /* Wraps mysql_real_connect() and returns a Connection object. */

Query class /* Wraps mysql_real_query(), as of this writing only executes. */

Statement class /* Wraps MYSQL_STMT* and can be included in parameters as a MYSQL_STMT* via 
    Statement::operator MYSQL_STMT*(). As of this writing wraps mysql_stmt_bind_param(), 
    mysql_stmt_execute(), mysql_stmt_bind_result() and mysql_stmt_close(). */
                
BindsArray class /* Wraps MYSQL_BIND struct arrays used for making prepared statements. */

makeInputBindsArray() /* Outputs a custom BindsArray to be used for the input parameter values
    of a prepared statement. */

makeOutputBindsArray() /* Outputs a custom BindsArray to be used for the rows in a prepared 
    statements result set. */

createDBTableBinds() /* Retrieves the data for all the tables in a specified database and 
    writes separate BindsArray builder functions for each of them to source files created at 
    specified paths. */
```
	
#### 'INSERT INTO' prepared statement example taken from C API docs but done with seth_ql wrapper:
```c++
#include <mysql.h>
#include "seth_ql.h"

int main(){
    MySQLSession::init();
    auto db_conn = createConnection( HOST, USER, PASSWORD, DATABASE, 0, "", 0 );
    Query q( db_conn );
    q.execute( "CREATE TABLE test_table(col1 INT, col2 VARCHAR(40), col3 SMALLINT)" );

    /* Prepare an INSERT query with 3 parameters */
    Statement stmt( db_conn, "INSERT INTO test_table(col1,col2,col3) VALUES(?,?,?)" );

    /* Bind the data for all 3 parameters */
    auto input = makeInputBindsArray( Bind<Field::INT>( "col1" ), 
                                      Bind<Field::VARCHAR>( "col2", 50 ), 
				      Bind<Field::SMALLINT>( "col3" ) );
    /* Bind the buffers */
    stmt.bind_param( input.getBinds() );

    /* Specify the data values for the first row */
    input[ "col1" ] = 10;          /* integer */
    input[ "col2" ] = "MySQL";     /* string  */
    input[ "col3" ].isNull = true; /* INSERT SMALLINT data as NULL */

    /* Execute the INSERT statement - 1*/
    stmt.execute();

    /* Specify data values for second row, then re-execute the statement */
    input[ "col1" ] = 1000;
    input[ "col2" ] = "The most popular Open Source database ";
    input[ "col3" ] = 1000;         /* smallint */
    input[ "col3" ].isNull = false; /* reset */

    /* Execute the INSERT statement - 2*/
    stmt.execute();

    /* RAII closes the statement, connection and session*/
    return 0;
}
