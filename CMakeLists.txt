cmake_minimum_required(VERSION 3.16)

project( typestest LANGUAGES "CXX" )

add_executable( typestest 
src/main.cpp )

target_compile_features( typestest PRIVATE cxx_std_20)

find_library(MYSQLCLIENT_LIBRARY NAMES mysqlclient)

if(MYSQLCLIENT_LIBRARY)
  target_link_libraries(typestest PRIVATE ${MYSQLCLIENT_LIBRARY})
else()
  message(FATAL_ERROR "mysqlclient library not found")
endif()

include(FetchContent)
FetchContent_Declare(
    set_mysql_binds
    GIT_REPOSITORY https://github.com/sethvan/set_mysql_binds
    GIT_TAG HEAD
    GIT_SHALLOW true
)
FetchContent_GetProperties(set_mysql_binds)
if(NOT set_mysql_binds_POPULATED)
    FetchContent_Populate(set_mysql_binds)
endif()

add_subdirectory(${set_mysql_binds_SOURCE_DIR} ${set_mysql_binds_BINARY_DIR})

target_link_libraries(typestest PRIVATE set_mysql_binds)
target_include_directories( typestest PRIVATE include)
target_link_options( typestest PRIVATE -fsanitize=address)
target_compile_options( typestest PRIVATE 
    -Wall -Wextra -Werror -Wl,-z,defs -fwrapv -O3
)