cmake_minimum_required(VERSION 3.16)

project( typestest LANGUAGES "CXX" )

add_executable( typestest 
src/utilities.cpp
src/getDBTables.cpp
src/createDBTableBinds.cpp
src/mybank_binds.cpp
src/main.cpp )

target_include_directories( typestest PRIVATE include )

target_compile_features( typestest PRIVATE cxx_std_20)
target_link_options( typestest PRIVATE -fsanitize=address -lmysqlclient)
target_compile_options( typestest PRIVATE 
    -Wall -Wextra -Werror -Wl,-z,defs -fwrapv -Og -lmysqlclient
)