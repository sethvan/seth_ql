#ifndef INCLUDED_CREATEDBTABLEBINDS_H
#define INCLUDED_CREATEDBTABLEBINDS_H

#include <getDBTables.h>

#include <string>

namespace seth_ql {

   void createDBTableBinds(
       const std::string& host, const std::string& user, const std::string& password, const std::string& database,
       const std::string& declFile, const std::string& defnFile, const std::string& includeStr,
       unsigned long buff_size =
           0 );  // buff_size will be the buff size for all the binds created that are char[], if set to 0 then all
                 // char[] field type buffer sizes will default to their max limits. After files are generated, the
                 // functions can be individually modified as needed.

}  // namespace seth_ql

#endif  // INCLUDED_CREATEDBTABLEBINDS_H