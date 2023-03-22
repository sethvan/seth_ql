cmake_minimum_required(VERSION 3.16)
project( seth_ql VERSION 1.0.0 LANGUAGES "CXX" )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)

# Try to find LIBMYSQLCLIENT using find_package
find_package(LIBMYSQLCLIENT NAMES mysqlclient)

if(LIBMYSQLCLIENT_FOUND)
    # If LIBMYSQLCLIENT is found, set the include directory and library variables
    set(MYSQL_INCLUDE_DIR ${LIBMYSQLCLIENT_INCLUDE_DIRS})
    set(MYSQL_LIBRARIES ${LIBMYSQLCLIENT_LIBRARIES})
else()
    # If LIBMYSQLCLIENT is not found using find_package, try to find the libraries manually
    find_library(MYSQL_LIBRARY NAMES mysqlclient PATHS "/usr/lib64/mysql/")

    if(NOT MYSQL_LIBRARY)
        # If the library is not found, print an error message and stop the configuration process
        message(FATAL_ERROR "MySQL client library not found")
    else()
        # If the library is found, set the include directory and library variables
        find_path(MYSQL_INCLUDE_DIR NAMES "mysql.h" PATHS "/usr/include/mysql")
        if(NOT MYSQL_INCLUDE_DIR)
            message(FATAL_ERROR "MySQL include directory not found")
        else()
            set(MYSQL_LIBRARIES ${MYSQL_LIBRARY})
        endif()
    endif()
endif()

# Print the include directory and library variables for debugging purposes
message("MYSQL_INCLUDE_DIR: ${MYSQL_INCLUDE_DIR}")
message("MYSQL_LIBRARIES: ${MYSQL_LIBRARIES}")

add_subdirectory(binds_array_wrapper)
add_subdirectory(create_db_table_binds)
add_subdirectory(other_mysql_wrappers)
add_subdirectory(misc)
add_subdirectory(tester_main)

target_compile_features( tester PRIVATE cxx_std_17)
target_link_options( tester PRIVATE -fsanitize=address)
target_compile_options( tester PRIVATE
    -Wall -Wextra -pedantic -Wconversion -Wl,-z,defs -fwrapv -O3 
)