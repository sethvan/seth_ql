# seth_ql
My personal in progress C++ wrapper of the [MySQL C API](https://dev.mysql.com/doc/c-api/8.0/en/)

## Current main feature
Provides a wrapper for the [MYSQL_BIND](https://dev.mysql.com/doc/c-api/8.0/en/c-api-prepared-statement-data-structures.html) structs used to make [prepared statements](https://dev.mysql.com/doc/c-api/8.0/en/c-api-prepared-statement-interface.html) and  [set query attributes](https://dev.mysql.com/doc/c-api/8.0/en/mysql-bind-param.html).  
Adding a few other wrappers as I go starting with minimal functionality.

## Dependencies/Requirements
*  A MySQL-compatible server that implements the MySQL protocol
*  Either [libmysql](https://dev.mysql.com/doc/refman/8.0/en/faqs-c-api.html#faq-mysql-c-api-download) or [libmysqlclient](https://dev.mysql.com/downloads/c-api/)
*  [CMake](https://cmake.org/download/) >= 3.21
*  C++ standard >= 17
*  gcc >= 10 (unsure as of yet about clang or MSVC)

## Installation
* ### Linux

   #### Building and Installing the Library
   ---

   _cd_ into the directory where you wish to place project and clone repo:  
   `$ git clone https://github.com/sethvan/seth_ql.git                                      `  
   
   Select and build either Debug or Release for shared or static libraries using the corresponding  
   preset from the _CMakePresets.json_ file in project directory. Debug shared lib version example :  
   `$ cmake --preset debug-linux                                                            `  
   `$ cmake --build --preset debug-linux                                                    `  
   
   If CMake is unable to find _libmysqlclient.so_ or _mysql.h_ on your machine, then add   
   your machine´s paths for them to the _PATHS_ at the end of the _find_library()_ and _find_path()_  
   functions in the top-level directory´s _CMakeLists.txt_ file.  
   
   To install first _cd_ into the folder where your chosen preset built the library.  
   For the debug shared library version it would for example be in _build/debug-linux_.   
   `$ cd build/debug-linux                                                                  `  
   
   Install using CMake install command. Default path for install on linux is _/usr/local/_,  
   if you want it installed to a different path run command as so:  
   `$ cmake --install . --prefix /path/to/custom/prefix                                     `  
   Otherwise install to default path:  
   `$ cmake --install .                                                                     `
   
   Ensure that the paths to the different include directories for _seth_ql.h_ and _mysql.h_can be  
   found in your system´s **CPLUS_INCLUDE_PATH** variable. Otherwise add the following line to  
   your _~/.bashrc_ for the missing path:  
   `export CPLUS_INCLUDE_PATH=/path/to/include:$CPLUS_INCLUDE_PATH                          `  
   
   As well ensure that the paths to the different lib directories for _seth_ql.so_ and _libmysqlclient.so_  
   can be found in your system´s **LD_LIBRARY_PATH** variable. Otherwise add the following line to  
   your _~/.bashrc_ for the missing path:  
   `export LD_LIBRARY_PATH=/path/to/lib:$LD_LIBRARY_PATH                                    ` 
   
   Now just include _<mysql.h>_ and _"seth_ql.h"_ in the source files where you want to use the library  
   and you should be good to go.

* ### Windows using Visual Studio Community 2022
   
   #### Some things to note:
   ---
   
   In windows at present just including presets for generating a static library version of library.  
   
   From my as of yet limited experience with Visual Studio, it appears that it is necessary for all  
   libraries linked in a project to be of a Debug build for there to be a Debug build built from the  
   project. Since _libmysql.lib_ and _mysqlclient.lib_ are not debug builds, it would be necessary for  
   you to build Debug builds of whichever one of them you are using from source and chose it for  
   linking to your project´s Debug build. The following instructions are for the Release version.
   
   #### Building and Installing the Library
   ---
   
   After the library is built it is your option to run the install command that would place it in your  
   programs folder. It is not necessary to do so in order to use the library but if you wish to do  
   so then you must open Visual Studio as an administrator. It is up to you.
   
   Open Visual Studio and choose _Clone a repository_.  
   In _Repository location_ paste 'https://github.com/sethvan/seth_ql' and click _çlone_.  
   In the _Solution Explorer_ right click on _Folder View_ and click _Open_.  
   CMake generation will occur in output terminal every time it detects a config selection.  
   Make sure a release config version is selected before you build.  
   Select the desired config ( _x64-release_ or _x86-release_ ) from the dropdown.  
   Click _Build_ and then _Build_ _All_.
   
   If CMake is unable to find the mysql library ( neither _libmysql.lib_ nor _mysqlclient.lib_ ) or _mysql.h_  
   on your machine, then add your machine´s paths for them to the _PATHS_ at the end of the  
   _find_library()_ and _find_path()_ functions in the top-level directory´s _CMakeLists.txt_ file.
     
   After it´s built, you may install if you wish at this point by clicking _Build_ then _Install_ _seth_ql_.  
   If installed, make a note of where it was installed and close seth_ql folder in IDE.
   
   #### Including the Library in a Project
   ---
   
   Open the solution where you want to use/include _seth_ql_.  
   In the _Solution_ _Explorer_ right click on the solution folder and click _Properties_.  
   Set the dropdown to _All_ _Configurations_ and _All_ _Platforms_.  
   In _Configuration_ _Properties_ _>_ _C/C++_ _>_ _General_ _>_ _Additional_ _Include_ _Directories_:  
   Add the paths to the include directories for _seth_ql.h_ and _mysql.h_.
   
   If you installed _seth_ql_, you made note of it´s include path earlier, if not then it will be in the repo  
   for _seth_ql_ that was created when you cloned it.  
   The path for _mysql.h_ you will have to find. On my machine it is this:  
   _"C:\Program Files\MySQL\MySQL Server 8.0\include"_  
   
   In _Configuration_ _Properties_ _>_ _Linker_ _>_ _Input_ _>_ _Additional_ _Dependencies_:  
   Add _seth_ql.lib_ and ( depending on which you are using ) _libmysql.lib_ or _mysqlclient.lib_ .  
   
   In _Configuration_ _Properties_ _>_ _Linker_ _>_ _General_ _>_ _Additional_ _Library_ _Directories_:  
   Add the paths to the directory where _seth_ql.lib_ is and the one where your MySQL library is.  
   
   If you installed the library, the lib directory for _seth_ql_ will be in the same directory as it´s  
   include directory. If not then it will be the path to the specific build´s folder inside of the  
   _seth_ql_ repo´s _out/build_ folder ( i.e., _out/build/x64-release_ ).  
   The path for your MySQL library you will have to find. On my machine it is this:  
   _"C:\Program Files\MySQL\MySQL Server 8.0\include"_  
   Save changes.
   
   Now just include _<mysql.h>_ and _"seth_ql.h"_ in the source files where you want to use the library  
   and you should be good to go.   
   
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
