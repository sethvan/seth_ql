#include "SqlTypes/SqlTypes.h"

namespace seth_ql {

// File created for following overloads to be only defined once
std::ostream& operator<<( std::ostream& os, const std::unique_ptr<InputCType>& obj ) {
   return obj->print_value( os );
}

std::ostream& operator<<( std::ostream& os, const std::unique_ptr<OutputCType>& obj ) {
   return obj->print_value( os );
}

std::ostream& operator<<( std::ostream& os, const InputCType& obj ) {
   return obj.print_value( os );
}

std::ostream& operator<<( std::ostream& os, const OutputCType& obj ) {
   return obj.print_value( os );
}

}  // namespace seth_ql
