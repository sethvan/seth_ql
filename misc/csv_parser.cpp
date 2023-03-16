#include "csv_parser.h"

#include <mysql/mysql.h>

#include <sstream>
#include <stdexcept>
#include <vector>

#include "Query.h"
#include "Span.hpp"

namespace seth_ql {
   std::vector<std::vector<std::string>> get_csv_rows( const std::string& csv_path ) {
      std::ifstream stream( csv_path );
      if ( !stream ) {
         throw std::runtime_error( csv_path + " failed to open successfully\n" );
      }

      std::vector<std::vector<std::string>> rows;
      rows.push_back( { "" } );

      int quotationCount = 0;
      bool countQuotations = false;
      char c, last;

      stream.get( c );
      if ( ( last = c ) == '\n' || c == '\r' ) {  // in case first line is empty
      } else {
         if ( c == '"' ) {
            ++quotationCount;
            countQuotations = true;
         }
         rows.back().back().push_back( c );
      }

      while ( stream.get( c ) ) {
         if ( c == ',' ) {
            if ( ( quotationCount % 2 ) && countQuotations ) {
               rows.back().back().push_back( c );
            } else {
               countQuotations = false;
               quotationCount = 0;
               rows.back().push_back( "" );
            }
            last = c;
            continue;
         }
         if ( c == '"' ) {
            if ( !countQuotations ) {
               if ( !rows.back().back().size() || last == ',' ) {
                  ++quotationCount;
                  countQuotations = true;
                  last = c;
                  continue;
               }
            }
            if ( last == '"' ) {
               if ( !( quotationCount % 2 ) ) {
                  ++quotationCount;
               } else {
                  ++quotationCount;
                  last = c;
                  continue;
               }
            } else {
               ++quotationCount;
               last = c;
               continue;
            }
         }

         if ( c == '\n' || c == '\r' ) {
            if ( last == '\n' || last == '\r' )
               continue;
            if ( last != '\n' && last != '\r' ) {
               rows.push_back( { "" } );
               quotationCount = 0;
               last = c;
               continue;
            }
         }

         if ( c == '\'' || c == '\\' ) {
            rows.back().back().push_back( '\\' );
            last = c;
         }
         rows.back().back().push_back( c );
         last = c;
      }
      while ( rows.back().size() == 1 ) {
         rows.pop_back();
      }

      return rows;
   }

   void insert_csv_to_table( MYSQL* conn, const std::string& table_name,
                             const std::string& csv_path, Span<const bool> quoted ) {
      auto rows = get_csv_rows( csv_path );
      std::ostringstream os;

      std::for_each( std::next( rows.begin(), 1 ), rows.end(), [ & ]( const auto& vec ) {
         os << "( ";
         auto needs_quoting = quoted.begin();
         std::for_each( vec.begin(), std::next( vec.end(), -1 ), [ & ]( const auto& str ) {
            if ( *needs_quoting++ ) {
               os << "\'" << str << "\'";
            } else if ( !str.size() ) {
               os << "NULL";
            } else {
               os << str;
            }
            os << ", ";
         } );
         if ( *needs_quoting++ ) {
            os << "\'" << vec.back() << "\'";
         } else if ( !vec.back().size() ) {
            os << "NULL";
         } else {
            os << vec.back();
         }
         os << " ),\n";
      } );

      std::string str = std::move( os.str() );
      str.pop_back();
      str.pop_back();
      std::string q = "INSERT into ";
      q += table_name + " values " + str;
      Query query( conn );
      query.execute( q );
      std::cerr << static_cast<long>( mysql_affected_rows( conn ) ) << " rows were inserted to "
                << table_name << " from file \'" << csv_path << "\' \n";
   }

}  // namespace seth_ql