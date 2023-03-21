add_executable(tester 
main.cpp)

target_link_libraries(tester PRIVATE
binds_array_wrapper
create_db_table_binds
generated_code
misc
other_mysql_wrappers
${LIBMYSQLCLIENT_LIBRARIES}
)