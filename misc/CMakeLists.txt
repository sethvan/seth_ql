add_library(misc
csv_parser.cpp
)

target_link_libraries(misc PUBLIC other_mysql_wrappers)
target_include_directories(misc PUBLIC include)