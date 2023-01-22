cmake_minimum_required(VERSION 3.16)

project( typestest LANGUAGES "CXX" )

add_executable( typestest 
src/main.cpp )

target_include_directories( typestest PRIVATE include )
include(FetchContent)
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.11.2
    GIT_SHALLOW true
)
FetchContent_MakeAvailable( nlohmann_json )
target_link_libraries(typestest PUBLIC nlohmann_json)

target_compile_features( typestest PRIVATE cxx_std_20)
target_link_options( typestest PRIVATE -fsanitize=address -lcurl -lmysqlclient)
target_compile_options( typestest PRIVATE 
    -Wall -Wextra -Werror -Wl,-z,defs -fwrapv -Og
)

