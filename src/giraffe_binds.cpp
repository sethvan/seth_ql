#include "giraffe_binds.h"

Binds<RequestCType> branch_request_bind(){
    return Binds<RequestCType>( make_vector<RequestCType>( 
        std::make_unique<TypeRequestImpl<int, MYSQL_TYPE_LONG>>("branch_id"),
        std::make_unique<TypeCharArrayRequest>( "branch_name", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeRequestImpl<int, MYSQL_TYPE_LONG>>("mgr_id"),
        std::make_unique<TypeMysqlTimeRequest>( "mgr_start_date", MYSQL_TYPE_DATE ) ));
}
Binds<ResponseCType> branch_response_bind(){
    return Binds<ResponseCType>( make_vector<ResponseCType>( 
        std::make_unique<TypeResponseImpl<int, MYSQL_TYPE_LONG>>("branch_id"),
        std::make_unique<TypeCharArrayResponse>( "branch_name", MYSQL_TYPE_VAR_STRING, 100),
        std::make_unique<TypeResponseImpl<int, MYSQL_TYPE_LONG>>("mgr_id"),
        std::make_unique<TypeMysqlTimeResponse>( "mgr_start_date", MYSQL_TYPE_DATE) ));
}

Binds<RequestCType> branch_supplier_request_bind(){
    return Binds<RequestCType>( make_vector<RequestCType>( 
        std::make_unique<TypeRequestImpl<int, MYSQL_TYPE_LONG>>("branch_id"),
        std::make_unique<TypeCharArrayRequest>( "supplier_name", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayRequest>( "supply_type", MYSQL_TYPE_STRING, 100 ) ));
}
Binds<ResponseCType> branch_supplier_response_bind(){
    return Binds<ResponseCType>( make_vector<ResponseCType>( 
        std::make_unique<TypeResponseImpl<int, MYSQL_TYPE_LONG>>("branch_id"),
        std::make_unique<TypeCharArrayResponse>( "supplier_name", MYSQL_TYPE_VAR_STRING, 100),
        std::make_unique<TypeCharArrayResponse>( "supply_type", MYSQL_TYPE_VAR_STRING, 100) ));
}

Binds<RequestCType> client_request_bind(){
    return Binds<RequestCType>( make_vector<RequestCType>( 
        std::make_unique<TypeRequestImpl<int, MYSQL_TYPE_LONG>>("client_id"),
        std::make_unique<TypeCharArrayRequest>( "client_name", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeRequestImpl<int, MYSQL_TYPE_LONG>>("branch_id") ));
}
Binds<ResponseCType> client_response_bind(){
    return Binds<ResponseCType>( make_vector<ResponseCType>( 
        std::make_unique<TypeResponseImpl<int, MYSQL_TYPE_LONG>>("client_id"),
        std::make_unique<TypeCharArrayResponse>( "client_name", MYSQL_TYPE_VAR_STRING, 100),
        std::make_unique<TypeResponseImpl<int, MYSQL_TYPE_LONG>>("branch_id") ));
}

Binds<RequestCType> employee_request_bind(){
    return Binds<RequestCType>( make_vector<RequestCType>( 
        std::make_unique<TypeRequestImpl<int, MYSQL_TYPE_LONG>>("emp_id"),
        std::make_unique<TypeCharArrayRequest>( "first_name", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayRequest>( "last_name", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeRequest>( "birth_day", MYSQL_TYPE_DATE ),
        std::make_unique<TypeCharArrayRequest>( "sex", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeRequestImpl<int, MYSQL_TYPE_LONG>>("salary"),
        std::make_unique<TypeRequestImpl<int, MYSQL_TYPE_LONG>>("super_id"),
        std::make_unique<TypeRequestImpl<int, MYSQL_TYPE_LONG>>("branch_id") ));
}
Binds<ResponseCType> employee_response_bind(){
    return Binds<ResponseCType>( make_vector<ResponseCType>( 
        std::make_unique<TypeResponseImpl<int, MYSQL_TYPE_LONG>>("emp_id"),
        std::make_unique<TypeCharArrayResponse>( "first_name", MYSQL_TYPE_VAR_STRING, 100),
        std::make_unique<TypeCharArrayResponse>( "last_name", MYSQL_TYPE_VAR_STRING, 100),
        std::make_unique<TypeMysqlTimeResponse>( "birth_day", MYSQL_TYPE_DATE),
        std::make_unique<TypeCharArrayResponse>( "sex", MYSQL_TYPE_VAR_STRING, 100),
        std::make_unique<TypeResponseImpl<int, MYSQL_TYPE_LONG>>("salary"),
        std::make_unique<TypeResponseImpl<int, MYSQL_TYPE_LONG>>("super_id"),
        std::make_unique<TypeResponseImpl<int, MYSQL_TYPE_LONG>>("branch_id") ));
}

Binds<RequestCType> works_with_request_bind(){
    return Binds<RequestCType>( make_vector<RequestCType>( 
        std::make_unique<TypeRequestImpl<int, MYSQL_TYPE_LONG>>("emp_id"),
        std::make_unique<TypeRequestImpl<int, MYSQL_TYPE_LONG>>("client_id"),
        std::make_unique<TypeRequestImpl<int, MYSQL_TYPE_LONG>>("total_sales") ));
}
Binds<ResponseCType> works_with_response_bind(){
    return Binds<ResponseCType>( make_vector<ResponseCType>( 
        std::make_unique<TypeResponseImpl<int, MYSQL_TYPE_LONG>>("emp_id"),
        std::make_unique<TypeResponseImpl<int, MYSQL_TYPE_LONG>>("client_id"),
        std::make_unique<TypeResponseImpl<int, MYSQL_TYPE_LONG>>("total_sales") ));
}

