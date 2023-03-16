#ifndef INCLUDED_MAKEBINDS_H
#define INCLUDED_MAKEBINDS_H

#include <memory>

#include "SqlTypes/SqlTypes.h"

namespace seth_ql {

   using enum Field;

   // BindType *******************************************************
   template <Field T>
   struct BindType {};

   template <>
   struct BindType<INT> {
      using inType = InImpl<int, MYSQL_TYPE_LONG>;
      using outType = OutImpl<int, MYSQL_TYPE_LONG>;
   };
   template <>
   struct BindType<INT_UNSIGNED> {
      using inType = InImpl<unsigned int, MYSQL_TYPE_LONG>;
      using outType = OutImpl<unsigned int, MYSQL_TYPE_LONG>;
   };
   template <>
   struct BindType<CHAR> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
   };
   template <>
   struct BindType<VARCHAR> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_VAR_STRING>;
   };
   template <>
   struct BindType<TINYTEXT> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_TINY_BLOB>;
   };
   template <>
   struct BindType<TEXT> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_BLOB>;
   };
   template <>
   struct BindType<BLOB> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_BLOB>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_BLOB>;
   };
   template <>
   struct BindType<MEDIUMTEXT> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_MEDIUM_BLOB>;
   };
   template <>
   struct BindType<MEDIUMBLOB> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_BLOB>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_MEDIUM_BLOB>;
   };
   template <>
   struct BindType<LONGTEXT> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_MEDIUM_BLOB>;
   };
   template <>
   struct BindType<LONGBLOB> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_BLOB>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_LONG_BLOB>;
   };
   template <>
   struct BindType<TINYINT> {
      using inType = InImpl<signed char, MYSQL_TYPE_TINY>;
      using outType = OutImpl<signed char, MYSQL_TYPE_TINY>;
   };
   template <>
   struct BindType<TINYINT_UNSIGNED> {
      using inType = InImpl<unsigned char, MYSQL_TYPE_TINY>;
      using outType = OutImpl<unsigned char, MYSQL_TYPE_TINY>;
   };
   template <>
   struct BindType<SMALLINT> {
      using inType = InImpl<short, MYSQL_TYPE_SHORT>;
      using outType = OutImpl<short, MYSQL_TYPE_SHORT>;
   };
   template <>
   struct BindType<SMALLINT_UNSIGNED> {
      using inType = InImpl<unsigned short, MYSQL_TYPE_SHORT>;
      using outType = OutImpl<unsigned short, MYSQL_TYPE_SHORT>;
   };
   template <>
   struct BindType<BIGINT> {
      using inType = InImpl<long, MYSQL_TYPE_LONGLONG>;
      using outType = OutImpl<long, MYSQL_TYPE_LONGLONG>;
   };
   template <>
   struct BindType<BIGINT_UNSIGNED> {
      using inType = InImpl<unsigned long, MYSQL_TYPE_LONGLONG>;
      using outType = OutImpl<unsigned long, MYSQL_TYPE_LONGLONG>;
   };
   template <>
   struct BindType<FLOAT> {
      using inType = InImpl<float, MYSQL_TYPE_FLOAT>;
      using outType = OutImpl<float, MYSQL_TYPE_FLOAT>;
   };
   template <>
   struct BindType<DOUBLE> {
      using inType = InImpl<double, MYSQL_TYPE_DOUBLE>;
      using outType = OutImpl<double, MYSQL_TYPE_DOUBLE>;
   };
   template <>
   struct BindType<DECIMAL> {
      using inType = InImpl<double, MYSQL_TYPE_DOUBLE>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_NEWDECIMAL>;
   };
   template <>
   struct BindType<DATE> {
      using inType = InImpl<MYSQL_TIME, MYSQL_TYPE_DATE>;
      using outType = OutImpl<MYSQL_TIME, MYSQL_TYPE_DATE>;
   };
   template <>
   struct BindType<DATETIME> {
      using inType = InImpl<MYSQL_TIME, MYSQL_TYPE_DATETIME>;
      using outType = OutImpl<MYSQL_TIME, MYSQL_TYPE_DATETIME>;
   };
   template <>
   struct BindType<TIMESTAMP> {
      using inType = InImpl<MYSQL_TIME, MYSQL_TYPE_TIMESTAMP>;
      using outType = OutImpl<MYSQL_TIME, MYSQL_TYPE_TIMESTAMP>;
   };
   template <>
   struct BindType<TIME> {
      using inType = InImpl<MYSQL_TIME, MYSQL_TYPE_TIME>;
      using outType = OutImpl<MYSQL_TIME, MYSQL_TYPE_TIME>;
   };
   template <>
   struct BindType<ENUM> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
   };
   template <>
   struct BindType<SET> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
   };
   template <>
   struct BindType<BOOLEAN> {
      using inType = InImpl<signed char, MYSQL_TYPE_BOOL>;
      using outType = OutImpl<signed char, MYSQL_TYPE_BOOL>;
   };
   template <>
   struct BindType<BIT> {
      using inType = OutImpl<unsigned long, MYSQL_TYPE_BIT>;
      using outType = OutImpl<unsigned long, MYSQL_TYPE_BIT>;
   };
   template <>
   struct BindType<GEOMETRY> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_BLOB>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_BLOB>;
   };
   template <>
   struct BindType<JSON> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_JSON>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_JSON>;
   };
   template <>
   struct BindType<BINARY> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_BLOB>;
   };
   template <>
   struct BindType<VARBINARY> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_BLOB>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_VAR_STRING>;
   };
   template <>
   struct BindType<TINYBLOB> {
      using inType = InImpl<std::basic_string<unsigned char>, MYSQL_TYPE_TINY_BLOB>;
      using outType = OutImpl<std::basic_string<unsigned char>, MYSQL_TYPE_TINY_BLOB>;
   };

   template <Field T>
   struct Bind {
      using inType = BindType<T>::inType;
      using outType = BindType<T>::outType;

      std::string_view name;
      unsigned long buffer_size;

      Bind( std::string_view _name, unsigned long _buffer_size = 0 )
          : name( _name ), buffer_size( _buffer_size ) {}

      std::unique_ptr<InputCType> makeInput() {
         return std::make_unique<inType>( name, buffer_size );
      }

      std::unique_ptr<OutputCType> makeOutput() {
         return std::make_unique<outType>( name, buffer_size );
      }
   };

   template <Field... Ts>
   BindsArray<InputCType> makeInputBindsArray( Bind<Ts>... objects ) {
      std::vector<std::unique_ptr<InputCType>> vec;
      vec.reserve( sizeof...( objects ) );
      ( vec.emplace_back( objects.makeInput() ), ... );
      return BindsArray<InputCType>( std::move( vec ) );
   }

   template <Field... Ts>
   BindsArray<OutputCType> makeOutputBindsArray( Bind<Ts>... objects ) {
      std::vector<std::unique_ptr<OutputCType>> vec;
      vec.reserve( sizeof...( objects ) );
      ( vec.emplace_back( objects.makeOutput() ), ... );
      return BindsArray<OutputCType>( std::move( vec ) );
   }

}  // namespace seth_ql

#endif  // INCLUDED_MAKEBINDS_H