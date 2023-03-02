cmake_minimum_required(VERSION 3.16)

project( sql_study LANGUAGES "CXX" )

add_executable( sql_study 
src/_generated/giraffeBinds.cpp
src/main.cpp )

target_compile_features( sql_study PRIVATE cxx_std_20)

find_library(MYSQLCLIENT_LIBRARY NAMES mysqlclient HINTS "/usr/lib64/mysql/")

if(MYSQLCLIENT_LIBRARY)
  target_link_libraries(sql_study PRIVATE ${MYSQLCLIENT_LIBRARY})
else()
  message(FATAL_ERROR "mysqlclient library not found")
endif()

include(FetchContent)
FetchContent_Declare(
    set_mysql_binds
    GIT_REPOSITORY https://github.com/sethvan/set_mysql_binds
    GIT_TAG master
    GIT_SHALLOW true
)
FetchContent_GetProperties(set_mysql_binds)
if(NOT set_mysql_binds_POPULATED)
    FetchContent_Populate(set_mysql_binds)
endif()

add_subdirectory(${set_mysql_binds_SOURCE_DIR} ${set_mysql_binds_BINARY_DIR})

target_link_libraries(sql_study PRIVATE set_mysql_binds)
target_include_directories( sql_study PRIVATE include)
target_link_options( sql_study PRIVATE -fsanitize=address)
target_compile_options( sql_study PRIVATE 
    -Wall -Wextra -Wl,-z,defs -fwrapv -O3
)