#ifndef INCLUDED_MAKEBINDS_H
#define INCLUDED_MAKEBINDS_H

#include <memory>

#include "BindsArray.hpp"
#include "SqlTypes/SqlTypes.h"

namespace seth_ql {

   // BindType *******************************************************
   template <Field T>
   struct BindType {};

   template <typename T>
   struct is_BindType : std::false_type {};

   template <>
   struct BindType<Field::INT> {
      using inType = InImpl<int, MYSQL_TYPE_LONG>;
      using outType = OutImpl<int, MYSQL_TYPE_LONG>;
   };
   using T_INT = BindType<Field::INT>;
   template <>
   struct is_BindType<T_INT> : std::true_type {};

   template <>
   struct BindType<Field::INT_UNSIGNED> {
      using inType = InImpl<unsigned int, MYSQL_TYPE_LONG>;
      using outType = OutImpl<unsigned int, MYSQL_TYPE_LONG>;
   };
   using T_INT_UNSIGNED = BindType<Field::INT_UNSIGNED>;
   template <>
   struct is_BindType<T_INT_UNSIGNED> : std::true_type {};

   template <>
   struct BindType<Field::CHAR> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
   };
   using T_CHAR = BindType<Field::CHAR>;
   template <>
   struct is_BindType<T_CHAR> : std::true_type {};

   template <>
   struct BindType<Field::VARCHAR> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_VAR_STRING>;
   };
   using T_VARCHAR = BindType<Field::VARCHAR>;
   template <>
   struct is_BindType<T_VARCHAR> : std::true_type {};

   template <>
   struct BindType<Field::TINYTEXT> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_TINY_BLOB>;
   };
   using T_TINYTEXT = BindType<Field::TINYTEXT>;
   template <>
   struct is_BindType<T_TINYTEXT> : std::true_type {};

   template <>
   struct BindType<Field::TEXT> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_BLOB>;
   };
   using T_TEXT = BindType<Field::TEXT>;
   template <>
   struct is_BindType<T_TEXT> : std::true_type {};

   template <>
   struct BindType<Field::BLOB> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_BLOB>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_BLOB>;
   };
   using T_BLOB = BindType<Field::BLOB>;
   template <>
   struct is_BindType<T_BLOB> : std::true_type {};

   template <>
   struct BindType<Field::MEDIUMTEXT> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_MEDIUM_BLOB>;
   };
   using T_MEDIUMTEXT = BindType<Field::MEDIUMTEXT>;
   template <>
   struct is_BindType<T_MEDIUMTEXT> : std::true_type {};

   template <>
   struct BindType<Field::MEDIUMBLOB> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_BLOB>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_MEDIUM_BLOB>;
   };
   using T_MEDIUMBLOB = BindType<Field::MEDIUMBLOB>;
   template <>
   struct is_BindType<T_MEDIUMBLOB> : std::true_type {};

   template <>
   struct BindType<Field::LONGTEXT> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_MEDIUM_BLOB>;
   };
   using T_LONGTEXT = BindType<Field::LONGTEXT>;
   template <>
   struct is_BindType<T_LONGTEXT> : std::true_type {};

   template <>
   struct BindType<Field::LONGBLOB> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_BLOB>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_LONG_BLOB>;
   };
   using T_LONGBLOB = BindType<Field::LONGBLOB>;
   template <>
   struct is_BindType<T_LONGBLOB> : std::true_type {};

   template <>
   struct BindType<Field::TINYINT> {
      using inType = InImpl<signed char, MYSQL_TYPE_TINY>;
      using outType = OutImpl<signed char, MYSQL_TYPE_TINY>;
   };
   using T_TINYINT = BindType<Field::TINYINT>;
   template <>
   struct is_BindType<T_TINYINT> : std::true_type {};

   template <>
   struct BindType<Field::TINYINT_UNSIGNED> {
      using inType = InImpl<unsigned char, MYSQL_TYPE_TINY>;
      using outType = OutImpl<unsigned char, MYSQL_TYPE_TINY>;
   };
   using T_TINYINT_UNSIGNED = BindType<Field::TINYINT_UNSIGNED>;
   template <>
   struct is_BindType<T_TINYINT_UNSIGNED> : std::true_type {};

   template <>
   struct BindType<Field::SMALLINT> {
      using inType = InImpl<short, MYSQL_TYPE_SHORT>;
      using outType = OutImpl<short, MYSQL_TYPE_SHORT>;
   };
   using T_SMALLINT = BindType<Field::SMALLINT>;
   template <>
   struct is_BindType<T_SMALLINT> : std::true_type {};

   template <>
   struct BindType<Field::SMALLINT_UNSIGNED> {
      using inType = InImpl<unsigned short, MYSQL_TYPE_SHORT>;
      using outType = OutImpl<unsigned short, MYSQL_TYPE_SHORT>;
   };
   using T_SMALLINT_UNSIGNED = BindType<Field::SMALLINT_UNSIGNED>;
   template <>
   struct is_BindType<T_SMALLINT_UNSIGNED> : std::true_type {};

   template <>
   struct BindType<Field::BIGINT> {
      using inType = InImpl<long, MYSQL_TYPE_LONGLONG>;
      using outType = OutImpl<long, MYSQL_TYPE_LONGLONG>;
   };
   using T_BIGINT = BindType<Field::BIGINT>;
   template <>
   struct is_BindType<T_BIGINT> : std::true_type {};

   template <>
   struct BindType<Field::BIGINT_UNSIGNED> {
      using inType = InImpl<unsigned long, MYSQL_TYPE_LONGLONG>;
      using outType = OutImpl<unsigned long, MYSQL_TYPE_LONGLONG>;
   };
   using T_BIGINT_UNSIGNED = BindType<Field::BIGINT_UNSIGNED>;
   template <>
   struct is_BindType<T_BIGINT_UNSIGNED> : std::true_type {};

   template <>
   struct BindType<Field::FLOAT> {
      using inType = InImpl<float, MYSQL_TYPE_FLOAT>;
      using outType = OutImpl<float, MYSQL_TYPE_FLOAT>;
   };
   using T_FLOAT = BindType<Field::FLOAT>;
   template <>
   struct is_BindType<T_FLOAT> : std::true_type {};

   template <>
   struct BindType<Field::DOUBLE> {
      using inType = InImpl<double, MYSQL_TYPE_DOUBLE>;
      using outType = OutImpl<double, MYSQL_TYPE_DOUBLE>;
   };
   using T_DOUBLE = BindType<Field::DOUBLE>;
   template <>
   struct is_BindType<T_DOUBLE> : std::true_type {};

   template <>
   struct BindType<Field::DECIMAL> {
      using inType = InImpl<double, MYSQL_TYPE_DOUBLE>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_NEWDECIMAL>;
   };
   using T_DECIMAL = BindType<Field::DECIMAL>;
   template <>
   struct is_BindType<T_DECIMAL> : std::true_type {};

   template <>
   struct BindType<Field::DATE> {
      using inType = InImpl<MYSQL_TIME, MYSQL_TYPE_DATE>;
      using outType = OutImpl<MYSQL_TIME, MYSQL_TYPE_DATE>;
   };
   using T_DATE = BindType<Field::DATE>;
   template <>
   struct is_BindType<T_DATE> : std::true_type {};

   template <>
   struct BindType<Field::DATETIME> {
      using inType = InImpl<MYSQL_TIME, MYSQL_TYPE_DATETIME>;
      using outType = OutImpl<MYSQL_TIME, MYSQL_TYPE_DATETIME>;
   };
   using T_DATETIME = BindType<Field::DATETIME>;
   template <>
   struct is_BindType<T_DATETIME> : std::true_type {};

   template <>
   struct BindType<Field::TIMESTAMP> {
      using inType = InImpl<MYSQL_TIME, MYSQL_TYPE_TIMESTAMP>;
      using outType = OutImpl<MYSQL_TIME, MYSQL_TYPE_TIMESTAMP>;
   };
   using T_TIMESTAMP = BindType<Field::TIMESTAMP>;
   template <>
   struct is_BindType<T_TIMESTAMP> : std::true_type {};

   template <>
   struct BindType<Field::TIME> {
      using inType = InImpl<MYSQL_TIME, MYSQL_TYPE_TIME>;
      using outType = OutImpl<MYSQL_TIME, MYSQL_TYPE_TIME>;
   };
   using T_TIME = BindType<Field::TIME>;
   template <>
   struct is_BindType<T_TIME> : std::true_type {};

   template <>
   struct BindType<Field::ENUM> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
   };
   using T_ENUM = BindType<Field::ENUM>;
   template <>
   struct is_BindType<T_ENUM> : std::true_type {};

   template <>
   struct BindType<Field::SET> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
   };
   using T_SET = BindType<Field::SET>;
   template <>
   struct is_BindType<T_SET> : std::true_type {};

   template <>
   struct BindType<Field::BOOLEAN> {
      using inType = InImpl<signed char, MYSQL_TYPE_BOOL>;
      using outType = OutImpl<signed char, MYSQL_TYPE_BOOL>;
   };
   using T_BOOLEAN = BindType<Field::BOOLEAN>;
   template <>
   struct is_BindType<T_BOOLEAN> : std::true_type {};

   template <>
   struct BindType<Field::BIT> {
      using inType = OutImpl<unsigned long, MYSQL_TYPE_BIT>;
      using outType = OutImpl<unsigned long, MYSQL_TYPE_BIT>;
   };
   using T_BIT = BindType<Field::BIT>;
   template <>
   struct is_BindType<T_BIT> : std::true_type {};

   template <>
   struct BindType<Field::GEOMETRY> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_BLOB>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_BLOB>;
   };
   using T_GEOMETRY = BindType<Field::GEOMETRY>;
   template <>
   struct is_BindType<T_GEOMETRY> : std::true_type {};

   template <>
   struct BindType<Field::JSON> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_JSON>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_JSON>;
   };
   using T_JSON = BindType<Field::JSON>;
   template <>
   struct is_BindType<T_JSON> : std::true_type {};

   template <>
   struct BindType<Field::BINARY> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_BLOB>;
   };
   using T_BINARY = BindType<Field::BINARY>;
   template <>
   struct is_BindType<T_BINARY> : std::true_type {};

   template <>
   struct BindType<Field::VARBINARY> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_BLOB>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_VAR_STRING>;
   };
   using T_VARBINARY = BindType<Field::VARBINARY>;
   template <>
   struct is_BindType<T_VARBINARY> : std::true_type {};

   template <>
   struct BindType<Field::TINYBLOB> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_TINY_BLOB>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_TINY_BLOB>;
   };
   using T_TINYBLOB = BindType<Field::TINYBLOB>;
   template <>
   struct is_BindType<T_TINYBLOB> : std::true_type {};

   template <typename T>
   struct Bind {
      using inType = typename T::inType;
      using outType = typename T::outType;

      std::string_view name;
      unsigned long buffer_size;

      Bind( std::string_view _name, unsigned long _buffer_size = 0 ) : name( _name ), buffer_size( _buffer_size ) {
         static_assert( is_BindType<T>::value, "Invalid value given to Bind struct" );
      }

      std::unique_ptr<InputCType> makeInput() { return std::make_unique<inType>( name, buffer_size ); }

      std::unique_ptr<OutputCType> makeOutput() { return std::make_unique<outType>( name, buffer_size ); }
   };

   template <typename... Ts>
   BindsArray<InputCType> makeInputBindsArray( Bind<Ts>... objects ) {
      std::vector<std::unique_ptr<InputCType>> vec;
      vec.reserve( sizeof...( objects ) );
      ( vec.emplace_back( objects.makeInput() ), ... );
      return BindsArray<InputCType>( std::move( vec ) );
   }

   template <typename... Ts>
   BindsArray<OutputCType> makeOutputBindsArray( Bind<Ts>... objects ) {
      std::vector<std::unique_ptr<OutputCType>> vec;
      vec.reserve( sizeof...( objects ) );
      ( vec.emplace_back( objects.makeOutput() ), ... );
      return BindsArray<OutputCType>( std::move( vec ) );
   }

}  // namespace seth_ql

#endif  // INCLUDED_MAKEBINDS_H