add_library(other_mysql_wrappers 
MySQLSession.cpp 
Statement.cpp
common.cpp
)

target_link_libraries(other_mysql_wrappers PUBLIC ${MYSQLCLIENT_LIBRARY})
target_include_directories(other_mysql_wrappers PUBLIC include)