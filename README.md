# seth_ql

My personal in progress C++ wrapper of the [MySQL C API](https://dev.mysql.com/doc/c-api/8.0/en/).  
Currently the main feature is that it provides a wrapper for the [MYSQL_BIND](https://dev.mysql.com/doc/c-api/8.0/en/c-api-prepared-statement-data-structures.html) structs used to make  
[prepared statements](https://dev.mysql.com/doc/c-api/8.0/en/c-api-prepared-statement-interface.html) and  [set query attributes](https://dev.mysql.com/doc/c-api/8.0/en/mysql-bind-param.html). Adding a few other wrappers as I go starting with  
minimal functionality.

- [seth\_ql](#seth_ql)
  - [Dependencies and Requirements](#dependencies-and-requirements)
  - [Installation](#installation)
  - [Principal classes and functions](#principal-classes-and-functions)
  - [Prepared Statement Example](#prepared-statement-example)
  - [License](./LICENSE)

## Dependencies and Requirements

- A MySQL-compatible server that implements the MySQL protocol
- Either [libmysql](https://dev.mysql.com/doc/refman/8.0/en/faqs-c-api.html#faq-mysql-c-api-download) or [libmysqlclient](https://dev.mysql.com/downloads/c-api/)

   If you require a debug binary for the mysql client, as of yet I have only been able to find it  
   provided by [libmysql](https://dev.mysql.com/doc/refman/8.0/en/faqs-c-api.html#faq-mysql-c-api-download) unless you build a debug binary from source on your own. On my personal  
   linux distro of Fedora36 I had to use [VCPKG](https://github.com/microsoft/vcpkg) to obtain [libmysql](https://dev.mysql.com/doc/refman/8.0/en/faqs-c-api.html#faq-mysql-c-api-download).  I see a package for LIBMYSQLCLIENT  
   listed in [Conan](https://conan.io/) but do not know whether it contains debug binaries.
- [PkgConfig](https://www.freedesktop.org/wiki/Software/pkg-config/) required if not using [VCPKG](https://github.com/microsoft/vcpkg) or [Conan](https://conan.io/)
- [CMake](https://cmake.org/download/) >= 3.21
- C++ standard >= 17
- gcc >= 10 (unsure as of yet about clang or MSVC)

## Installation

- ### Linux

  - #### Building and Installing the Library
  
  If needed, here is [Documentation](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html?highlight=presets) and [Video](https://www.youtube.com/watch?v=NFbnm1t6Mc4&t=553s) for using CMake presets.  
  I am including the [CMakePresets.json](./CMakePresets.json) as I am using them. Feel free to modify them as needed or replace them  
  with your own. Currently mine are set up for a build that uses VCPKG. The build and config presets  
  share the same names of _debug_ and _release_ and they default output a shared library.  
  For obtaining a static library output, the presets of _debug-static_ and _release-static_ are also available.  
 
  After building, To install first _cd_ into the folder where your chosen preset built the library.  
  For the release shared library version it would for example be in _build/release_.   
  `$ cd build/release                                                                  `  
   
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
   
  Now just include _<mysql/mysql.h>_ and _"seth_ql.h"_ in the source files where you want to use the library  
  and you should be good to go.

- ### Windows using Visual Studio Community 2022
  
   - #### Building and Installing the Library
   
   In windows at present just including presets for generating a static library version of library.  
   You may modify this if desired by setting _STATIC_LIB_REQUIRED_ to _OFF_ for a shared library instead.  
     
   After the library is built it is your option to run the install command that would place it in your  
   programs folder. It is not necessary to do so in order to use the library but if you wish to do  
   so then you must open Visual Studio as an administrator. It is up to you.
   
   Open Visual Studio and choose _Clone a repository_.  
   In _Repository location_ paste 'https://github.com/sethvan/seth_ql' and click _çlone_.  
   In the _Solution Explorer_ right click on _Folder View_ and click _Open_.  
   CMake generation will occur in output terminal every time it detects a config selection.  
   Make sure the desired config version is selected before you build.  
   Select the desired config (i.e., _x64-release_ etc ) from the dropdown.  
   Click _Build_ and then _Build_ _All_.
        
   After it´s built, you may install if you wish at this point by clicking _Build_ then _Install_ _seth_ql_.  
   If installed, make a note of where it was installed and close seth_ql folder in IDE.
   
   - #### Including the Library in a Project
   
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
   
   Now just include _<mysql/mysql.h>_ and _"seth_ql.h"_ in the source files where you want to use the library  
   and you should be good to go.   
   
## Principal classes and functions

**_MySQLSession::init()_** 
- RAII singleton that calls _mysql_library_init()_ and destructor calls _mysql_library_end()_.	

**_Connection class_** 
- Wraps a _MYSQL*_ and can be included in parameters as a _MYSQL*_ via _Connection::operator MYSQL*()_.

**_Query class_** 
- Wraps mysql_real_query(), as of this writing only executes.

**_Statement class_** 
- Wraps _MYSQL_STMT*_ and can be included in parameters as a _MYSQL_STMT*_ via  
    _Statement::operator MYSQL_STMT*()_.
- As of this writing wraps _mysql_stmt_bind_param()_, _mysql_stmt_execute()_, _mysql_stmt_bind_result()_  
    and _mysql_stmt_close()_.
                
**_BindsArray class_** 
- Wraps _MYSQL_BIND_ struct arrays used for making prepared statements.
- The _SqlCType_ abstract class wraps these specific values of a _MYSQL BIND_ struct:
```c++    
    enum_field_types bufferType;
    bool is_null;
    bool error;
    unsigned long length;
    void* buffer;
    unsigned long long bufferLength;
```
- Depending on whether for an input or output of a prepared statement The BindsArray class  
stores a polymorphic InputCtype or OutputCType array for the different params needed.
- The BindsArray object:
    - can set param values via overloaded operator= for all of the MySQL data types
    - can select params via overloaded operator[] using name or index of param in BindsArray
      ( i.e.,  
      if you name first bind 'col1', inputBinds["col1"] is same param as inputBinds[0] )
    - can set number type params using both number types or as a string so if inputBinds["col1"]  
    is an INT, it can be set both this way:  
    inputBinds["col1"] = 323;  
    As well as this way:  
    inputBinds["col1"] = "323";  
    This is in case in case their values need to be parsed from strings.
    - can set types stored as char arrays ( i.e. VARCHAR, JSON, LONGBLOB, etc ) using input  
    values that are either const char*, char[] or constiguous char container classes.
    - can be created with multiple params and then modified to bind only certain params when  
    needed using setBinds() method.
      
**_enum class Field_**
- enum class for MySQL data types. Contains the names like INT, VARCHAR, etc. 
- Contains most MySQL Types. As far as I know only YEAR is currently missing but there may be others.
- In addition have included values INT_UNSIGNED, TINYINT_UNSIGNED etc for unsigned integers.
- Note: _using_ _enum_ _Field;_ will cause an error in MSVC due to ambiguation with _INT_, _DOUBLE_. etc.


**_makeInputBindsArray()_** 
- Outputs a custom BindsArray to be used for the input parameter values of a prepared statement.

**_makeOutputBindsArray()_**
- Outputs a custom BindsArray to be used for the rows in a prepared statements result set.

**_createDBTableBinds()_** 
- Retrieves the data for all the tables in a specified database and writes separate BindsArray builder  
functions for each of them to source files created at specified paths.
	
## Prepared Statement Example 
```c++
// taken from C API docs but done with seth_ql wrapper:
#include <mysql.h>
#include "seth_ql.h"

int main() {
   seth_ql::MySQLSession::init();
   seth_ql::Connection db_conn( HOST, USER, PASSWORD, DATABASE, 0, "", 0 );
   seth_ql::Query q( db_conn );
   q.execute( "CREATE TABLE test_table(col1 INT, col2 VARCHAR(40), col3 SMALLINT)" );

   /* Prepare an INSERT query with 3 parameters */
   seth_ql::Statement stmt( db_conn, "INSERT INTO test_table(col1,col2,col3) VALUES(?,?,?)" );

   /* Bind the data for all 3 parameters */
   auto input = seth_ql::makeInputBindsArray( seth_ql::Bind<seth_ql::Field::INT>( "col1" ), 
                                              seth_ql::Bind<seth_ql::Field::VARCHAR>( "col2", 50 ),
                                              seth_ql::Bind<seth_ql::Field::SMALLINT>( "col3" ) );
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
