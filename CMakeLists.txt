cmake_minimum_required(VERSION 3.16)
project( seth_ql VERSION 1.0.0 LANGUAGES "CXX" )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)

find_package(LIBMYSQL NAMES mysql)

if(LIBMYSQL_FOUND)
    set(MYSQL_INCLUDE_DIR ${LIBMYSQL_INCLUDE_DIRS})
    set(MYSQL_LIBRARIES ${LIBMYSQL_LIBRARIES})
else()
    find_library(MYSQL_LIBRARY NAMES mysqlclient PATHS "/usr/lib64/mysql/" "C:\\Program Files\\MySQL\\MySQL Server 8.0\\lib")
    if(NOT MYSQL_LIBRARY)
        message(FATAL_ERROR "MySQL client library not found")
    else()
        find_path(MYSQL_INCLUDE_DIR NAMES "mysql.h" PATHS "/usr/include/mysql" "C:\\Program Files\\MySQL\\MySQL Server 8.0\\include")
        if(NOT MYSQL_INCLUDE_DIR)
            message(FATAL_ERROR "MySQL include directory not found")
        else()
            set(MYSQL_LIBRARIES ${MYSQL_LIBRARY})
        endif()
    endif()
endif()

add_library(seth_ql STATIC
    src/binds_array_wrapper/SqlTypes.cpp 
    src/binds_array_wrapper/utilities.cpp 
    src/create_db_table_binds/createDBTableBinds.cpp 
    src/create_db_table_binds/getDBTables.cpp 
    src/other_mysql_wrappers/common.cpp 
    src/other_mysql_wrappers/MySQLSession.cpp 
    src/other_mysql_wrappers/Query.cpp 
    src/other_mysql_wrappers/Statement.cpp )

target_link_libraries(seth_ql PUBLIC ${MYSQL_LIBRARIES})

target_include_directories( seth_ql PUBLIC include ${MYSQL_INCLUDE_DIR})

install(TARGETS seth_ql
    EXPORT seth_ql
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib)

install(DIRECTORY include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*")

