#ifndef INCLUDED_UTILITIES_H
#define INCLUDED_UTILITIES_H

#if __linux__
#include <mysql/mysql.h>
#else
#include <mysql.h>
#endif

#include <array>
#include <string_view>
#include <utility>

namespace seth_ql {

   extern const std::array<std::string_view, 256> fieldTypes;

   extern bool strict_fundamental_type_checking;

   bool isCharArray( enum_field_types type );

}  // namespace seth_ql

#endif  // INCLUDED_UTILITIES_H