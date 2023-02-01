#ifndef INCLUDED_GIRAFFEBINDS_H
#define INCLUDED_GIRAFFEBINDS_H

#include "binds.hpp"


Binds<RequestCType> branch_request_bind();
Binds<ResponseCType> branch_response_bind();

Binds<RequestCType> branch_supplier_request_bind();
Binds<ResponseCType> branch_supplier_response_bind();

Binds<RequestCType> client_request_bind();
Binds<ResponseCType> client_response_bind();

Binds<RequestCType> employee_request_bind();
Binds<ResponseCType> employee_response_bind();

Binds<RequestCType> works_with_request_bind();
Binds<ResponseCType> works_with_response_bind();

#endif //INCLUDED_GIRAFFEBINDS_H
