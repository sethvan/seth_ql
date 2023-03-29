#ifndef INCLUDED_COMMON_H
#define INCLUDED_COMMON_H

#if __linux__
#include <mysql/mysql.h>
#else
#include <mysql.h>
#endif

namespace seth_ql {

   void failOut( const char* functionName, const char* errMsg );

}  // namespace seth_ql

#endif  // INCLUDED_COMMON_H