#include "common.h"

#include <stdexcept>

namespace seth_ql {

   void failOut( const char* functionName, const char* errMsg ) {
      throw std::runtime_error( std::string( functionName ) + " failed\n" + errMsg + "\n" );
   }

}  // namespace seth_ql