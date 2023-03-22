add_library(generated_code 
#girrafeBinds.cpp 
performance_schemaBinds.cpp 
)

target_link_libraries(generated_code PRIVATE 
binds_array_wrapper 
${MYSQL_LIBRARIES}
)

target_include_directories(generated_code PUBLIC include ${MYSQL_INCLUDE_DIR})