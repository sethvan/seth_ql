# seth_ql
My personal in progress C++ wrapper of the [MySQL C API](https://dev.mysql.com/doc/c-api/8.0/en/)

## Current main feature
Provides a wrapper for the [MYSQL_BIND](https://dev.mysql.com/doc/c-api/8.0/en/c-api-prepared-statement-data-structures.html) structs used to make [prepared statements](https://dev.mysql.com/doc/c-api/8.0/en/c-api-prepared-statement-interface.html) and  [set query attributes](https://dev.mysql.com/doc/c-api/8.0/en/mysql-bind-param.html).  
Adding a few other wrappers as I go starting with minimal functionality.

## Dependencies
*  A MySQL-compatible server that implements the MySQL protocol
*  Either [libmysql](https://dev.mysql.com/doc/refman/8.0/en/faqs-c-api.html#faq-mysql-c-api-download) or [libmysqlclient](https://dev.mysql.com/downloads/c-api/)
*  [CMake]([https://cmake.org/](https://cmake.org/download/)) >= 3.21
*  C++ standard >= 17
*  gcc >= 10 (unsure as of yet about clang or MSVC)

## Installation
* ### Linux

   _cd_ into the directory where you wish to place project and clone repo:  
   `$ git clone https://github.com/sethvan/seth_ql.git                                      `  
   
   Select and build either Debug or Release for shared or static libraries using the corresponding  
   preset from the _CMakePresets.json_ file in project directory:  
   `$ cmake --preset debug-linux                                                            `  
   `$ cmake --build --preset debug-linux                                                    `  
   
   If CMake is unable to find _'libmysqlclient.so'_ or _'mysql.h'_ on your machine, then add   
   your machine´s paths for them to the _PATHS_ at the end of the _find_library()_ and _find_path()_  
   functions in the top-level directory´s _CMakeLists.txt_ file.  
   
   To install first _cd_ into the folder where your chosen preset built the library.  
   For the release version it will be in _'build/debug-linux'_.   
   `$ cd build/debug-linux                                                                  `  
   
   Install using CMake install command. Default path for install on linux is _'/usr/local/'_,  
   if you want it installed to a different path run command as so:  
   `$ cmake --install . --prefix /path/to/custom/prefix                                     `  
   Otherwise install to default path:  
   `$ cmake --install .                                                                     `
   
   Ensure that the paths to the different include directories for _'seth_ql.h'_ and _'mysql.h'_can be  
   found in your system´s **CPLUS_INCLUDE_PATH** variable. Otherwise add the following line to  
   your _'~/.bashrc'_ for the missing path:  
   `export CPLUS_INCLUDE_PATH=/path/to/include:$CPLUS_INCLUDE_PATH                          `  
   
   As well ensure that the paths to the different lib directories for _'seth_ql.so'_ and _'libmysqlclient.so'_  
   can be found in your system´s **LD_LIBRARY_PATH** variable. Otherwise add the following line to  
   your _'~/.bashrc'_ for the missing path:  
   `export LD_LIBRARY_PATH=/path/to/lib:$LD_LIBRARY_PATH                                    `  

* ### Windows with Visual Studio
   (To be filled out)
   
## Principal classes and functions
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

using namespace seth_ql;

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
