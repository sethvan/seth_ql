#include "mybank_binds.h"

Binds<RequestCType> bank_account_request_bind() {
    return Binds<RequestCType>( make_vector<RequestCType>(
        std::make_unique<TypeRequestImpl<int, MYSQL_TYPE_LONG>>( "acc_no" ),
        std::make_unique<TypeCharArrayRequest>( "fname", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayRequest>( "lname", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeRequestImpl<double, MYSQL_TYPE_DOUBLE>>( "balance" ) ) );
}
Binds<ResponseCType> bank_account_response_bind() {
    return Binds<ResponseCType>( make_vector<ResponseCType>(
        std::make_unique<TypeResponseImpl<int, MYSQL_TYPE_LONG>>( "acc_no" ),
        std::make_unique<TypeCharArrayResponse>( "fname", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayResponse>( "lname", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayResponse>( "balance", MYSQL_TYPE_NEWDECIMAL, 100 ) ) );
}
