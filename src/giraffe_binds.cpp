#include "giraffe_binds.h"

Binds<InputCType> branch_request_binds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "branch_id" ),
        std::make_unique<TypeCharArrayInput>( "branch_name", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "mgr_id" ),
        std::make_unique<TypeMysqlTimeInput>( "mgr_start_date", MYSQL_TYPE_DATE ) ) );
}
Binds<OutputCType> branch_response_binds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "branch_id" ),
        std::make_unique<TypeCharArrayOutput>( "branch_name", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "mgr_id" ),
        std::make_unique<TypeMysqlTimeOutput>( "mgr_start_date", MYSQL_TYPE_DATE ) ) );
}

Binds<InputCType> branch_supplier_request_binds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "branch_id" ),
        std::make_unique<TypeCharArrayInput>( "supplier_name", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "supply_type", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> branch_supplier_response_binds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "branch_id" ),
        std::make_unique<TypeCharArrayOutput>( "supplier_name", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "supply_type", MYSQL_TYPE_VAR_STRING, 100 ) ) );
}

Binds<InputCType> client_request_binds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "client_id" ),
        std::make_unique<TypeCharArrayInput>( "client_name", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "branch_id" ) ) );
}
Binds<OutputCType> client_response_binds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "client_id" ),
        std::make_unique<TypeCharArrayOutput>( "client_name", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "branch_id" ) ) );
}

Binds<InputCType> employee_request_binds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "emp_id" ),
        std::make_unique<TypeCharArrayInput>( "first_name", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "last_name", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeInput>( "birth_day", MYSQL_TYPE_DATE ),
        std::make_unique<TypeCharArrayInput>( "sex", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "salary" ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "super_id" ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "branch_id" ) ) );
}
Binds<OutputCType> employee_response_binds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "emp_id" ),
        std::make_unique<TypeCharArrayOutput>( "first_name", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "last_name", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeMysqlTimeOutput>( "birth_day", MYSQL_TYPE_DATE ),
        std::make_unique<TypeCharArrayOutput>( "sex", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "salary" ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "super_id" ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "branch_id" ) ) );
}

Binds<InputCType> works_with_request_binds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "emp_id" ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "client_id" ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "total_sales" ) ) );
}
Binds<OutputCType> works_with_response_binds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "emp_id" ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "client_id" ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "total_sales" ) ) );
}
