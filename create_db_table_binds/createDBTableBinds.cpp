/*
    The createDBTableBinds()'s function gets the data for all the tables in a specified database and
    writes separate binds (from BindsArray.hpp) object builder functions for each of them to source
   code files.

    The function declarations to a .h/.hpp file and their definitions to a .cpp file using
    the paths that are specified in the function arguments.

*/

#include "createDBTableBinds.h"

#include <cctype>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

#include "BindsArray.hpp"
#include "Span.hpp"
#include "getDBTables.h"
#include "makeBinds.hpp"
#include "utilities.h"
#include <string>

namespace seth_ql {

   static void setDeclHeaderAndFooter( std::ostringstream& declaration_header,
                                       std::ostringstream& declaration_footer,
                                       std::string db_name ) {
      std::string upper_db_name;
      std::transform( db_name.begin(), db_name.end(), std::back_inserter( upper_db_name ),
                      ::toupper );
      std::string included_macro = std::string( "INCLUDED_" ) + upper_db_name + "BINDS_H";

      declaration_header << "// This file was generated by createDBTableBinds() function\n"
                         << "#ifndef " << included_macro << '\n'
                         << "#define " << included_macro << "\n\n"
                         << "#include \"BindsArray.hpp\"\n#include \"makeBinds.hpp\"\n\nusing "
                            "namespace seth_ql;\n\n\n";

      declaration_footer << "\n#endif //" << included_macro << '\n';
   }

   static std::ostringstream createDefinitionHeader( const std::string& includeStr ) {
      std::ostringstream os;
      os << "// This file was generated by createDBTableBinds() function\n#include "
            "\"makeBinds.hpp\"\n#include \""
         << includeStr << "\"\n\nusing namespace seth_ql;\n\n";
      return os;
   }

   static void setFileBodies( std::ostringstream& declaration_body,
                              std::ostringstream& definition_body, Span<Table> tables,
                              unsigned long buff_size ) {
      std::for_each( tables.begin(), tables.end(), [ & ]( const auto& table ) {
         std::string funcReq =
             std::string( "BindsArray<InputCType> " ) + table.name + "InputBindsArray()";
         std::string funcRes =
             std::string( "BindsArray<OutputCType> " ) + table.name + "OutputBindsArray()";
         declaration_body << funcReq << ";\n" << funcRes << ";\n\n";

         std::stringstream function_body;
         int count = 0;
         std::for_each( table.fields.begin(), table.fields.end(), [ & ]( const auto& field ) {
            std::string upperExternalType;
            std::transform( field.externalType.begin(), field.externalType.end(),
                            std::back_inserter( upperExternalType ), ::toupper );
            if ( ( field.flags & UNSIGNED_FLAG ) == static_cast<int>( UNSIGNED_FLAG ) &&
                 ( upperExternalType == "INT" || upperExternalType == "TINYINT" ||
                   upperExternalType == "SMALLINT" || upperExternalType == "BIGINT" ||
                   upperExternalType == "MEDIUMINT" ) ) {
               upperExternalType += "_UNSIGNED";
            }
            function_body << ( count++ < 1 ? "" : ", " ) << "Bind<" << upperExternalType << ">(\""
                          << field.name << "\"" << ( isCharArray( field.type ) ? ", " : "" )
                          << ( isCharArray( field.type ) ? std::to_string( buff_size ) : "" )
                          << ")";
         } );
         definition_body << funcReq << "{\n    return makeInputBindsArray( " << function_body.str()
                         << " );\n}\n";
         definition_body << funcRes << "{\n    return makeOutputBindsArray( "
                         << std::move( function_body.str() ) << " );\n}\n\n";
      } );
   }

   static void writeDeclarationFile( const std::ostringstream& declaration_header,
                                     const std::ostringstream& declaration_body,
                                     const std::ostringstream& declaration_footer,
                                     const std::string& fileName ) {
      std::ofstream hFile( fileName );
      hFile << declaration_header.str() << declaration_body.str() << declaration_footer.str();
   }

   static void writeDefinitionFile( const std::ostringstream& definition_header,
                                    const std::ostringstream& definition_body,
                                    const std::string& fileName ) {
      std::ofstream cppFile( fileName );
      cppFile << definition_header.str() << definition_body.str();
   }

   // In this function the term 'header' is used in the HTML sense as being the top of a page,
   // declaration_header refers to the top of a .h/.hpp file and definition_header the top of a .cpp
   // file.
   void createDBTableBinds( const std::string& host, const std::string& user,
                            const std::string& password, const std::string& database,
                            const std::string& declFile, const std::string& defnFile,
                            const std::string& includeStr, unsigned long buff_size ) {
      std::ostringstream declaration_header, declaration_footer;
      setDeclHeaderAndFooter( declaration_header, declaration_footer, database );

      std::ostringstream definition_header = createDefinitionHeader( includeStr );

      std::ostringstream declaration_body, definition_body;
      auto tables = getDBTables( host, user, password, database );
      setFileBodies( declaration_body, definition_body, tables, buff_size );

      writeDeclarationFile( declaration_header, declaration_body, declaration_footer, declFile );

      writeDefinitionFile( definition_header, definition_body, defnFile );
   }

}  // namespace seth_ql
