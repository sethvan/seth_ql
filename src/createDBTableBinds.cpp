#include "createDBTableBinds.h"

#include <cassert>
#include <cctype>
#include <iterator>

#include "binds.hpp"
#include "typeCreationStrings.h"

void replaceWord( std::string& str, const std::string& pattern, const std::string& replacement ) {
    size_t pos = str.find( pattern );
    if ( pos != std::string::npos ) {
        size_t size = pattern.size();
        str.replace( pos, size, replacement );
    }
};

void createDBTableBinds( const char* HOST, const char* USER, const char* PASSWORD,
                         const char* DATABASE, unsigned long buff_size ) {
    std::string db_name = DATABASE;
    std::string upper_db_name;
    std::transform( db_name.begin(), db_name.end(), std::back_inserter( upper_db_name ),
                    ::toupper );
    std::string included_macro = std::string( "INCLUDED_" ) + upper_db_name + "BINDS_H";

    std::ostringstream declaration_header;
    declaration_header << "#ifndef " << included_macro << '\n'
                       << "#define " << included_macro << "\n\n"
                       << "#include \"binds.hpp\"\n\n\n";

    std::string fileNameBase = db_name + "Binds";
    std::ostringstream definition_header;
    definition_header << "#include \"_generated/" << fileNameBase << ".h\"\n\n";

    std::ostringstream declaration_body, definition_body;

    auto tables = getDBTables( HOST, USER, PASSWORD, DATABASE );

    std::for_each( tables.begin(), tables.end(), [&]( const auto& table ) {
        std::string funcReq = std::string( "Binds<InputCType> " ) + table.name + "InputBinds()";
        std::string funcRes = std::string( "Binds<OutputCType> " ) + table.name + "OutputBinds()";
        declaration_body << funcReq << ";\n" << funcRes << ";\n\n";

        std::ostringstream requestStream;
        requestStream << funcReq
                      << "{\n    return Binds<InputCType>( make_vector<InputCType>( \n        ";
        std::ostringstream responseStream;
        responseStream << funcRes
                       << "{\n    return Binds<OutputCType>( make_vector<OutputCType>( \n        ";
        int count = 0;
        std::for_each( table.fields.begin(), table.fields.end(), [&]( const auto& field ) {
            auto typeVariations = typeCreationStrings.at( field.externalType );
            std::string makeInputStr, makeOutputStr;
            if ( ( field.flags & UNSIGNED_FLAG ) == static_cast<int>( UNSIGNED_FLAG ) ) {
                makeInputStr = typeVariations.cTypeInputUnsigned;
                makeOutputStr = typeVariations.cTypeOutputUnsigned;
            }
            else {
                makeInputStr = typeVariations.cTypeInputSigned;
                makeOutputStr = typeVariations.cTypeOutputSigned;
            }
            replaceWord( makeInputStr, "NAME", field.name );
            replaceWord( makeOutputStr, "NAME", field.name );
            replaceWord( makeInputStr, "BUFF_SIZE", std::to_string( buff_size ) );
            replaceWord( makeOutputStr, "BUFF_SIZE", std::to_string( buff_size ) );
            requestStream << ( count++ < 2 ? "" : ",\n        " ) << makeInputStr;
            responseStream << ( count++ < 2 ? "" : ",\n        " ) << makeOutputStr;
        } );
        requestStream << " ));\n}\n";
        responseStream << " ));\n}\n\n";
        definition_body << requestStream.str() << responseStream.str();
    } );

    std::string hFileName = std::string( "include/_generated/" ) + fileNameBase + ".h";
    std::ofstream hFile( hFileName );
    std::ostringstream declaration_footer;
    declaration_footer << "#endif //" << included_macro << '\n';
    hFile << declaration_header.str() << declaration_body.str() << declaration_footer.str();
    hFile.close();

    std::string cppFileName = std::string( "src/_generated/" ) + fileNameBase + ".cpp";
    std::ofstream cppFile( cppFileName );
    cppFile << definition_header.str() << definition_body.str();
    cppFile.close();
}