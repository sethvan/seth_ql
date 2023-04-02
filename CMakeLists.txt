cmake_minimum_required(VERSION 3.16)
project( seth_ql VERSION 1.0.0 LANGUAGES "CXX" )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)

if(WIN32)
    set(STATIC_LIB_REQUIRED on)
endif()

find_package(LIBMYSQL NAMES libmysql)

if(LIBMYSQL_FOUND)
    set(MYSQL_INCLUDE_DIR ${LIBMYSQL_INCLUDE_DIRS})
    set(MYSQL_LIBRARIES ${LIBMYSQL_LIBRARIES})
else()
    include(FindPkgConfig)
    pkg_check_modules(LIBMYSQLCLIENT REQUIRED mysqlclient)
    link_directories(${LIBMYSQLCLIENT_LIBRARY_DIRS})
    set(MYSQL_INCLUDE_DIR ${LIBMYSQLCLIENT_INCLUDE_DIRS})
    set(MYSQL_LIBRARIES ${LIBMYSQLCLIENT_LIBRARIES})
endif()

if(STATIC_LIB_REQUIRED)
    add_library(seth_ql STATIC 
    src/binds_array_wrapper/SqlTypes.cpp 
    src/binds_array_wrapper/utilities.cpp 
    src/create_db_table_binds/createDBTableBinds.cpp 
    src/create_db_table_binds/getDBTables.cpp 
    src/other_mysql_wrappers/common.cpp 
    src/other_mysql_wrappers/MySQLSession.cpp 
    src/other_mysql_wrappers/Query.cpp 
    src/other_mysql_wrappers/Statement.cpp 
    )
else()
add_library(seth_ql SHARED
    src/binds_array_wrapper/SqlTypes.cpp 
    src/binds_array_wrapper/utilities.cpp 
    src/create_db_table_binds/createDBTableBinds.cpp 
    src/create_db_table_binds/getDBTables.cpp 
    src/other_mysql_wrappers/common.cpp 
    src/other_mysql_wrappers/MySQLSession.cpp 
    src/other_mysql_wrappers/Query.cpp 
    src/other_mysql_wrappers/Statement.cpp 
    )
endif()

target_link_libraries(seth_ql PUBLIC ${MYSQL_LIBRARIES})

target_include_directories( seth_ql PUBLIC include ${MYSQL_INCLUDE_DIR})

install(TARGETS seth_ql
    EXPORT seth_ql
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib)

install(DIRECTORY include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*")

