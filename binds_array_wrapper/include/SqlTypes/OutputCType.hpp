#ifndef INCLUDED_OUTPUTCTYPE_H
#define INCLUDED_OUTPUTCTYPE_H

#include <iostream>
#include <iterator>
#include <sstream>

#include "SqlTypes/SqlCType.h"

namespace seth_ql {
   class OutputCType : public SqlCType {
     public:
      OutputCType( std::string_view _fieldName, enum_field_types type, void* _buffer,
                   unsigned long long _bufferLength = 0 )
          : SqlCType( _fieldName, type, _buffer, _bufferLength ) {}
      virtual ~OutputCType() = default;

      template <Field type>
      const auto* Value() {
         if constexpr ( type == Field::DECIMAL ) {
            return static_cast<unsigned char*>( buffer );
         } else {
            return static_cast<typename ValType<type>::type*>( buffer );
         }
      }
   };

   template <typename T, enum_field_types Type>
   class OutImpl : public OutputCType {
      T value;

     public:
      OutImpl() = delete;
      OutImpl( std::string_view _fieldName, unsigned long long _bufferLength = 0 )
          : OutputCType( _fieldName, ( Type == MYSQL_TYPE_BOOL ? MYSQL_TYPE_TINY : Type ),
                         ( std::is_same_v<T, std::basic_string<unsigned char>> ? nullptr : &value ),
                         _bufferLength ) {
         static_assert( is_approved_type<T>::value,
                        "Value type given to InputCType is not an approved type" );
         if constexpr ( std::is_same_v<T, std::basic_string<unsigned char>> ) {
            value.resize( _bufferLength, '\0' );
            buffer = value.data();
         }
      }

      std::ostream& print_value( std::ostream& os ) const override {
         os << std::boolalpha << std::setprecision( 15 );
         if ( isNull ) {
            os << "NULL";
         } else if constexpr ( std::is_same_v<T, std::basic_string<unsigned char>> ) {
            if ( value.size() ) {
               std::string out;
               out.reserve( length );
               std::copy( value.begin(), std::next( value.begin(), length ),
                          std::back_inserter( out ) );
               os << out;
            } else {
               os << "NULL";
            }
         } else if constexpr ( Type == MYSQL_TYPE_TINY ) {
            os << static_cast<int>( value );
         } else if constexpr ( Type == MYSQL_TYPE_BOOL ) {
            os << static_cast<bool>( value );
         } else if constexpr ( std::is_same_v<T, MYSQL_TIME> ) {
            std::ostringstream _os;
            _os << value.year << "-" << ( value.month > 9 ? "" : "0" )
                << std::to_string( value.month ) << "-" << ( value.day > 9 ? "" : "0" )
                << std::to_string( value.day ) << " " << ( value.hour > 9 ? "" : "0" )
                << std::to_string( value.hour ) << ":" << ( value.minute > 9 ? "" : "0" )
                << std::to_string( value.minute ) << ":" << ( value.second > 9 ? "" : "0" )
                << std::to_string( value.second );
            os << std::move( _os.str() );
         } else {
            os << value;
         }
         return os;
      }
   };

}  // namespace seth_ql
#endif  // INCLUDED_OUTPUTCTYPE_H