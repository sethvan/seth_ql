#ifndef INCLUDED_GIRAFFEBINDS_H
#define INCLUDED_GIRAFFEBINDS_H

#include "binds.hpp"

Binds<InputCType> branch_request_binds();
Binds<OutputCType> branch_response_binds();

Binds<InputCType> branch_supplier_request_binds();
Binds<OutputCType> branch_supplier_response_binds();

Binds<InputCType> client_request_binds();
Binds<OutputCType> client_response_binds();

Binds<InputCType> employee_request_binds();
Binds<OutputCType> employee_response_binds();

Binds<InputCType> works_with_request_binds();
Binds<OutputCType> works_with_response_binds();

#endif  // INCLUDED_GIRAFFEBINDS_H
