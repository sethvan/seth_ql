add_library(create_db_table_binds
getDBTables.cpp 
createDBTableBinds.cpp
)
target_link_libraries(create_db_table_binds PUBLIC 
binds_array_wrapper
${MYSQL_LIBRARIES}
)
target_include_directories( create_db_table_binds PUBLIC include ${MYSQL_INCLUDE_DIR})
target_link_options(create_db_table_binds PUBLIC -lstdc++)
add_subdirectory(generated_code)
