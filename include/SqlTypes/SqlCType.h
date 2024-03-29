#ifndef INCLUDED_SQLCTYPE_H
#define INCLUDED_SQLCTYPE_H

#include <mysql/mysql.h>

#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iterator>
#include <stdexcept>
#include <string>
#include <string_view>
#include <type_traits>
#include <vector>

#include "utilities.h"

/*
    This is the base class meant to be used in a wrapper for MYSQL_BIND arrays found in
   BindsArray.hpp. An enum and some type traits all related to MySQL and C type information are
   placed here as well.

   There are 8 C types and 1 MYSQL type used (char, short, int, long long, float, double, MYSQL_TIME
   and char[]). However in the case of char[], various enum_field_types that are valid for receiving
   data as char[] are not permitted to be used for requesting data. This is why I decided to amplify
   this class hierarchy using interfaces InputCType and OutputCType in their respective hpp files.
   Also have opted for using Long instead of Long Long for design reasons.
*/

namespace seth_ql {

   class SqlCType {
     public:
      const std::string_view fieldName;
      const enum_field_types bufferType;
      bool isNull;
      bool error;
      unsigned long length;
      MYSQL_BIND* bind;
      void* buffer;
      unsigned long long bufferLength;
      bool is_selected;
      bool isUnsigned;

      SqlCType( std::string_view _fieldName, enum_field_types type, void* _buffer, unsigned long long _bufferLength,
                bool _isUnsigned )
          : fieldName( _fieldName ),
            bufferType( type ),
            isNull( 0 ),
            error( 0 ),
            length( 0 ),
            bind( nullptr ),
            buffer( _buffer ),
            bufferLength( _bufferLength ),
            is_selected( true ),
            isUnsigned( _isUnsigned ) {}

      void setBind( MYSQL_BIND* targetBind ) {
         bind = targetBind;
         std::memset( bind, 0, sizeof( *bind ) );
         bind->buffer_type = bufferType;
         bind->buffer = (char*)buffer;
         bind->is_null = &isNull;
         bind->length = &length;
         bind->error = &error;
         bind->buffer_length = bufferLength;
         bind->is_unsigned = isUnsigned;
      }

      virtual ~SqlCType() = default;

      virtual std::ostream& print_value( std::ostream& os ) const = 0;  // mostly to make base class not instantiable
   };

   // is_approved_type*********************************************
   template <typename T>
   struct is_approved_type : std::false_type {};
   template <>
   struct is_approved_type<bool> : std::true_type {};
   template <>
   struct is_approved_type<signed char> : std::true_type {};
   template <>
   struct is_approved_type<char> : std::true_type {};
   template <>
   struct is_approved_type<short> : std::true_type {};
   template <>
   struct is_approved_type<unsigned short> : std::true_type {};
   template <>
   struct is_approved_type<int> : std::true_type {};
   template <>
   struct is_approved_type<unsigned int> : std::true_type {};
   template <>
   struct is_approved_type<long> : std::true_type {};
   template <>
   struct is_approved_type<unsigned long> : std::true_type {};
   template <>
   struct is_approved_type<float> : std::true_type {};
   template <>
   struct is_approved_type<double> : std::true_type {};
   template <>
   struct is_approved_type<std::string> : std::true_type {};
   template <>
   struct is_approved_type<MYSQL_TIME> : std::true_type {};

   /*Commened out code from when ran using C++20*/
   // template <typename T>
   // concept ApprovedType = is_approved_type<T>::value;

   enum class Field {
      INT,
      INT_UNSIGNED,
      CHAR,
      VARCHAR,
      TINYTEXT,
      TEXT,
      BLOB,
      MEDIUMTEXT,
      MEDIUMBLOB,
      LONGTEXT,
      LONGBLOB,
      TINYINT,
      TINYINT_UNSIGNED,
      SMALLINT,
      SMALLINT_UNSIGNED,
      MEDIUMINT,
      MEDIUMINT_UNSIGNED,
      BIGINT,
      BIGINT_UNSIGNED,
      FLOAT,
      DOUBLE,
      DECIMAL,
      DATE,
      DATETIME,
      TIMESTAMP,
      TIME,
      ENUM,
      SET,
      BOOLEAN,
      BIT,
      GEOMETRY,
      JSON,
      BINARY,
      VARBINARY,
      TINYBLOB
   };

   // To facilitate Value() methods of InputCType and OutputCType which return references to the
   // derived class's value members.

   template <Field T>
   struct ValType {};
   template <>
   struct ValType<Field::INT> {
      static constexpr bool is_char_array = false;
      using type = int;
   };
   template <>
   struct ValType<Field::INT_UNSIGNED> {
      static constexpr bool is_char_array = false;
      using type = unsigned int;
   };
   template <>
   struct ValType<Field::CHAR> {
      static constexpr bool is_char_array = true;
      using type = char;
   };
   template <>
   struct ValType<Field::VARCHAR> {
      static constexpr bool is_char_array = true;
      using type = char;
   };
   template <>
   struct ValType<Field::TINYTEXT> {
      static constexpr bool is_char_array = true;
      using type = char;
   };
   template <>
   struct ValType<Field::TEXT> {
      static constexpr bool is_char_array = true;
      using type = char;
   };
   template <>
   struct ValType<Field::BLOB> {
      static constexpr bool is_char_array = true;
      using type = char;
   };
   template <>
   struct ValType<Field::MEDIUMTEXT> {
      static constexpr bool is_char_array = true;
      using type = char;
   };
   template <>
   struct ValType<Field::MEDIUMBLOB> {
      static constexpr bool is_char_array = true;
      using type = char;
   };
   template <>
   struct ValType<Field::LONGTEXT> {
      static constexpr bool is_char_array = true;
      using type = char;
   };
   template <>
   struct ValType<Field::LONGBLOB> {
      static constexpr bool is_char_array = true;
      using type = char;
   };
   template <>
   struct ValType<Field::TINYINT> {
      static constexpr bool is_char_array = false;
      using type = signed char;
   };
   template <>
   struct ValType<Field::TINYINT_UNSIGNED> {
      static constexpr bool is_char_array = false;
      using type = unsigned char;
   };
   template <>
   struct ValType<Field::SMALLINT> {
      static constexpr bool is_char_array = false;
      using type = short;
   };
   template <>
   struct ValType<Field::SMALLINT_UNSIGNED> {
      static constexpr bool is_char_array = false;
      using type = unsigned short;
   };
   template <>
   struct ValType<Field::BIGINT> {
      static constexpr bool is_char_array = false;
      using type = long;
   };
   template <>
   struct ValType<Field::BIGINT_UNSIGNED> {
      static constexpr bool is_char_array = false;
      using type = unsigned long;
   };
   template <>
   struct ValType<Field::FLOAT> {
      static constexpr bool is_char_array = false;
      using type = float;
   };
   template <>
   struct ValType<Field::DOUBLE> {
      static constexpr bool is_char_array = false;
      using type = double;
   };
   template <>
   struct ValType<Field::DECIMAL> {  // this one is special
      static constexpr bool is_char_array = true;
      using type = double;
   };
   template <>
   struct ValType<Field::DATE> {
      static constexpr bool is_char_array = false;
      using type = MYSQL_TIME;
   };
   template <>
   struct ValType<Field::DATETIME> {
      static constexpr bool is_char_array = false;
      using type = MYSQL_TIME;
   };
   template <>
   struct ValType<Field::TIMESTAMP> {
      static constexpr bool is_char_array = false;
      using type = MYSQL_TIME;
   };
   template <>
   struct ValType<Field::TIME> {
      static constexpr bool is_char_array = false;
      using type = MYSQL_TIME;
   };
   template <>
   struct ValType<Field::ENUM> {
      static constexpr bool is_char_array = true;
      using type = char;
   };
   template <>
   struct ValType<Field::SET> {
      static constexpr bool is_char_array = true;
      using type = char;
   };
   template <>
   struct ValType<Field::BOOLEAN> {
      static constexpr bool is_char_array = false;
      using type = signed char;
   };
   template <>
   struct ValType<Field::BIT> {
      static constexpr bool is_char_array = false;
      using type = unsigned long;
   };
   template <>
   struct ValType<Field::GEOMETRY> {
      static constexpr bool is_char_array = true;
      using type = char;
   };
   template <>
   struct ValType<Field::JSON> {
      static constexpr bool is_char_array = true;
      using type = char;
   };
   template <>
   struct ValType<Field::BINARY> {
      static constexpr bool is_char_array = true;
      using type = char;
   };
   template <>
   struct ValType<Field::VARBINARY> {
      static constexpr bool is_char_array = true;
      using type = char;
   };
   template <>
   struct ValType<Field::TINYBLOB> {
      static constexpr bool is_char_array = true;
      using type = char;
   };

}  // namespace seth_ql

#endif  // INCLUDED_SQLCTYPE_H