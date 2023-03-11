#include "csv_parser.h"

#include <stdexcept>

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
   if ( ( last = c ) == '\n' ) {  // in case first line is empty
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

      if ( c == '\n' ) {
         if ( last == '\n' ) {
            continue;

         } else {
            rows.push_back( { "" } );
            quotationCount = 0;
            last = c;
            continue;
         }
      }
      rows.back().back().push_back( c );
      last = c;
   }
   if ( rows.back().size() == 1 ) {
      rows.pop_back();
   }

   return rows;
}

}  // namespace seth_ql