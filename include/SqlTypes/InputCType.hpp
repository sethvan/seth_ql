#ifndef INCLUDED_INPUTCTYPE_H
#define INCLUDED_INPUTCTYPE_H

#include <iostream>
#include <string_view>
#include <type_traits>

#include "CharArrView.hpp"
#include "SqlTypes/SqlCType.h"

namespace seth_ql {

   class InputCType : public SqlCType {
     public:
      InputCType( std::string_view _fieldName, enum_field_types type, void* _buffer, unsigned long long _bufferLength,
                  bool isUnsigned )
          : SqlCType( _fieldName, type, _buffer, _bufferLength, isUnsigned ) {}
      virtual ~InputCType() = default;
      InputCType& operator=( const InputCType& ) = delete;
      virtual void operator=( long double newValue ) = 0;
      // virtual void operator=( const std::string_view newValue ) = 0;
      virtual void operator=( CharArrView newValue ) = 0;
      virtual void operator=( const MYSQL_TIME& newValue ) = 0;

      template <Field Type>
      std::enable_if_t<( !ValType<Type>::is_char_array ||
                         !std::is_same_v<typename ValType<Type>::type, char> /*For struct ValType<Field::DECIMAL>*/ ),
                       typename ValType<Type>::type&>
      Value() {
         return *static_cast<typename ValType<Type>::type*>( buffer );
      }

      template <Field Type>
      std::enable_if_t<ValType<Type>::is_char_array, std::string> Value() {
         char* ptr = static_cast<char*>( buffer );
         std::string str( ptr, ptr + length );
         return str;
      }
   };

   // The original idea for these templates from reddit user u/IyeOnline
   template <typename T, enum_field_types Type>
   class InImpl : public InputCType {
      static constexpr const char* mismatch =
          "\'value member type\' does not match argument given to operator=() method\n";
      T value;

     public:
      InImpl() = delete;
      InImpl( std::string_view _fieldName, unsigned long long _bufferLength = 0 )
          : InputCType(
                _fieldName, ( ( Type == MYSQL_TYPE_BLOB && std::is_same_v<T, signed char> ) ? MYSQL_TYPE_TINY : Type /*Jury rig put in due to not all versions of headers for library contain placeholder MYSQL_TYPE_BOOL */ ),
                ( std::is_same_v<T, std::string> ? nullptr : &value ), _bufferLength,
                ( std::is_unsigned<T>::value ? true : false ) ) {
         static_assert( is_approved_type<T>::value, "Value type given to InputCType is not an approved type" );
         if constexpr ( std::is_same_v<T, std::string> ) {
            value.resize( _bufferLength, '\0' );
            buffer = value.data();
         }
         if constexpr ( std::is_same_v<T, MYSQL_TIME> ) {
            std::memset( &value, 0, sizeof( value ) );
         }
      }

      void operator=( long double newValue ) override {
         if constexpr ( std::is_integral_v<T> || std::is_floating_point_v<T> ) {
            T x = static_cast<T>( newValue );
            if ( strict_fundamental_type_checking ) {
               if ( static_cast<long double>( x ) != newValue ) {
                  throw std::runtime_error( mismatch );
               }
            }
            value = x;
         } else {
            throw std::runtime_error( mismatch );
         }
      }

      void operator=( CharArrView newValue ) override {
         if ( !newValue.size() ) {
            isNull = true;
            return;
         }
         if constexpr ( std::is_same_v<T, std::string> ) {
            std::copy( newValue.begin(), newValue.end(), value.begin() );
            length = newValue.size();
         } else if constexpr ( std::is_integral_v<T> ) {
            value = std::stol( std::string( newValue.data() ) );
         } else if constexpr ( std::is_same_v<T, float> ) {
            value = std::stof( std::string( newValue.data() ) );
         } else if constexpr ( std::is_same_v<T, double> ) {
            value = std::stod( std::string( newValue.data() ) );
         } else {
            throw std::runtime_error( mismatch );
         }
      }
      void operator=( const MYSQL_TIME& newValue ) override {
         if constexpr ( std::is_same_v<T, MYSQL_TIME> ) {
            value = newValue;
         } else {
            throw std::runtime_error( mismatch );
         }
      }
      std::ostream& print_value( std::ostream& os ) const override {
         os << std::boolalpha << std::setprecision( 15 );
         if ( isNull ) {
            os << "NULL";
         } else if constexpr ( std::is_same_v<T, std::string> ) {
            std::copy( value.begin(), value.end(), std::ostream_iterator<char>{ os } );
         } else if constexpr ( Type == MYSQL_TYPE_TINY ) {
            os << static_cast<int>( value );
         } else if constexpr ( Type == MYSQL_TYPE_BLOB && std::is_same_v<T, signed char> ) {
            os << static_cast<bool>( value );
         } else if constexpr ( std::is_same_v<T, MYSQL_TIME> ) {
            os << value.year << "-" << ( value.month > 9 ? "" : "0" ) << std::to_string( value.month ) << "-"
               << ( value.day > 9 ? "" : "0" ) << std::to_string( value.day ) << " " << ( value.hour > 9 ? "" : "0" )
               << std::to_string( value.hour ) << ":" << ( value.minute > 9 ? "" : "0" )
               << std::to_string( value.minute ) << ":" << ( value.second > 9 ? "" : "0" )
               << std::to_string( value.second );
         } else {
            os << value;
         }
         return os;
      }
   };

}  // namespace seth_ql
#endif  // INCLUDED_INPUTCTYPE_H