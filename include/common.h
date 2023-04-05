#ifndef INCLUDED_COMMON_H
#define INCLUDED_COMMON_H

#include <mysql/mysql.h>

namespace seth_ql {

   void failOut( const char* functionName, const char* errMsg );

}  // namespace seth_ql

#endif  // INCLUDED_COMMON_H