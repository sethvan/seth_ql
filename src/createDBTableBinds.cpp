#include "createDBTableBinds.h"

#include <cassert>
#include <cctype>
#include <iterator>

#include "binds.hpp"

void createDBTableBinds( const char* HOST, const char* USER, const char* PASSWORD,
                         const char* DATABASE ) {
    std::string db_name = DATABASE;
    std::string upper_db_name;
    std::cout << upper_db_name;
    std::transform( db_name.begin(), db_name.end(), std::back_inserter( upper_db_name ),
                    ::toupper );
    std::string included_macro = std::string( "INCLUDED_" ) + upper_db_name + "BINDS_H";

    std::ostringstream declaration_header;
    declaration_header << "#ifndef " << included_macro << '\n'
                       << "#define " << included_macro << "\n\n"
                       << "#include \"binds.hpp\"\n\n\n";

    std::string fileNameBase = db_name + "_binds";
    std::ostringstream definition_header;
    definition_header << "#include \"" << fileNameBase << ".h\"\n\n";

    std::ostringstream declaration_footer;
    declaration_footer << "#endif //" << included_macro << '\n';

    std::ostringstream declaration_body, definition_body;

    auto tables = getDBTables( HOST, USER, PASSWORD, DATABASE );

    constexpr auto typeCreationStrings =
        TurnerMap<std::string_view, DataType, userInputTypes.size()>{ { userInputTypes } };

    const auto fillInName = [&]( std::string& str, const std::string& name ) {
        size_t pos = str.find( "NAME" );
        assert( pos != std::string::npos );  // because if fails means I set up the array wrong
        str.replace( pos, 4, name );
    };

    std::for_each( tables.begin(), tables.end(), [&]( const auto& table ) {
        std::string funcReq =
            std::string( "Binds<RequestCType> " ) + table.name + "_request_bind()";
        std::string funcRes =
            std::string( "Binds<ResponseCType> " ) + table.name + "_response_bind()";
        declaration_body << funcReq << ";\n" << funcRes << ";\n\n";

        std::ostringstream requestStream;
        requestStream << funcReq
                      << "{\n    return Binds<RequestCType>( make_vector<RequestCType>( \n        ";
        std::ostringstream responseStream;
        responseStream
            << funcRes
            << "{\n    return Binds<ResponseCType>( make_vector<ResponseCType>( \n        ";
        int count = 0;
        std::for_each( table.fields.begin(), table.fields.end(), [&]( const auto& field ) {
            auto typeVariations = typeCreationStrings.at( field.externalType );
            std::string makeRequestStr, makeResponseStr;
            if ( ( field.flags & UNSIGNED_FLAG ) == static_cast<int>( UNSIGNED_FLAG ) ) {
                makeRequestStr = typeVariations.cTypeRequestUnsigned;
                makeResponseStr = typeVariations.cTypeResponseUnsigned;
            }
            else {
                makeRequestStr = typeVariations.cTypeRequestSigned;
                makeResponseStr = typeVariations.cTypeResponseSigned;
            }
            fillInName( makeRequestStr, field.name );
            fillInName( makeResponseStr, field.name );
            requestStream << ( count++ < 2 ? "" : ",\n        " ) << makeRequestStr;
            responseStream << ( count++ < 2 ? "" : ",\n        " ) << makeResponseStr;
        } );
        requestStream << " ));\n}\n";
        responseStream << " ));\n}\n\n";
        definition_body << requestStream.str() << responseStream.str();
    } );
    std::string hFileName = std::string( "include/" ) + fileNameBase + ".h";
    std::ofstream hFile( hFileName );
    hFile << declaration_header.str() << declaration_body.str() << declaration_footer.str();
    hFile.close();

    std::string cppFileName = std::string( "src/" ) + fileNameBase + ".cpp";
    std::ofstream cppFile( cppFileName );
    cppFile << definition_header.str() << definition_body.str();
    cppFile.close();
}