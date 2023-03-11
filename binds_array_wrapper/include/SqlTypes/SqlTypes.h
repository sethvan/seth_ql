#ifndef INCLUDED_SQLTYPES_H
#define INCLUDED_SQLTYPES_H

#include <memory>

#include "SqlTypes/InputCType.hpp"
#include "SqlTypes/OutputCType.hpp"

namespace seth_ql {

// these next two here so only defined once
std::ostream& operator<<( std::ostream& os, const std::unique_ptr<InputCType>& obj );

std::ostream& operator<<( std::ostream& os, const std::unique_ptr<OutputCType>& obj );

std::ostream& operator<<( std::ostream& os, const InputCType& obj );

std::ostream& operator<<( std::ostream& os, const OutputCType& obj );

}  // namespace seth_ql

#endif  // INCLUDED_SQLTYPES_H