cmake_minimum_required(VERSION 3.16)

project( seth_ql VERSION 1.0.0 LANGUAGES "CXX" )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)

find_library(MYSQLCLIENT_LIBRARY NAMES mysqlclient HINTS "/usr/lib64/mysql/")

if(NOT MYSQLCLIENT_LIBRARY)
  message(FATAL_ERROR "mysqlclient library not found")
endif()

add_subdirectory(binds_array_wrapper)
add_subdirectory(create_db_table_binds)
add_subdirectory(misc)
add_subdirectory(other_mysql_wrappers)
add_subdirectory(tester_main)

target_compile_features( tester PRIVATE cxx_std_20)
target_link_options( tester PRIVATE -fsanitize=address)
target_compile_options( tester PRIVATE
    -Wall -Wextra -Wconversion -Wl,-z,defs -fwrapv -O3 
)