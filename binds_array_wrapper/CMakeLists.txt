add_library(binds_array_wrapper 
SqlTypes.cpp
utilities.cpp
)
target_link_libraries(binds_array_wrapper PUBLIC ${MYSQL_LIBRARIES})
target_include_directories( binds_array_wrapper PUBLIC include ${MYSQL_INCLUDE_DIR})

