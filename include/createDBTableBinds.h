#ifndef INCLUDED_CREATEDBTABLEBINDS_H
#define INCLUDED_CREATEDBTABLEBINDS_H

#include <getDBTables.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

namespace binds_wrapper {

    void createDBTableBinds( const std::string& host, const std::string& user, const std::string& password,
                             const std::string& database, const std::string& declFile, const std::string& defnFile,
                             const std::string& includeStr,
                             unsigned long buff_size );  // buff_size will be the buff size for all the
                                                         // binds created that are char[]

    void replaceWord( std::string& str, const std::string& pattern, const std::string& replacement );

    void setDeclHeaderAndFooter( std::ostringstream& declaration_header, std::ostringstream& declaration_footer,
                                 std::string db_name );

    std::ostringstream createDefinitionHeader( const std::string& includeStr );

    void setFileBodies( std::ostringstream& declaration_body, std::ostringstream& definition_body,
                        std::span<const Table> tables, unsigned long buff_size );

    void writeDeclarationFile( const std::ostringstream& declaration_header, const std::ostringstream& declaration_body,
                               const std::ostringstream& declaration_footer, const std::string& fileName );

    void writeDefinitionFile( const std::ostringstream& definition_header, const std::ostringstream& definition_body,
                              const std::string& fileName );

}  // namespace binds_wrapper

#endif  // INCLUDED_CREATEDBTABLEBINDS_H