add_library(generated_code 
giraffeBinds.cpp 
performance_schemaBinds.cpp 
)

target_link_libraries(generated_code PRIVATE 
binds_array_wrapper 
${MYSQLCLIENT_LIBRARY}
)

target_include_directories(generated_code PUBLIC include)