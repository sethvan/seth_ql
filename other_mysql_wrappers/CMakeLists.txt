add_library(other_mysql_wrappers 
MySQLSession.cpp 
Statement.cpp
common.cpp
Query.cpp
)

target_link_libraries(other_mysql_wrappers PUBLIC ${LIBMYSQLCLIENT_LIBRARIES})
target_include_directories(other_mysql_wrappers PUBLIC include ${LIBMYSQLCLIENT_INCLUDE_DIRS})