#ifndef INCLUDED_MYBANKBINDS_H
#define INCLUDED_MYBANKBINDS_H

#include "binds.hpp"

Binds<RequestCType> bank_account_request_bind();
Binds<ResponseCType> bank_account_response_bind();

#endif  // INCLUDED_MYBANKBINDS_H
