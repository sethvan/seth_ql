add_library(binds_array_wrapper 
SqlTypes.cpp
utilities.cpp
)
target_link_libraries(binds_array_wrapper PUBLIC ${MYSQLCLIENT_LIBRARY})
target_include_directories( binds_array_wrapper PUBLIC include )

