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
      constexpr static unsigned long max_buff_size = 0;
   };
   template <>
   struct is_BindType<BindType<Field::INT>> : std::true_type {};

   template <>
   struct BindType<Field::INT_UNSIGNED> {
      using inType = InImpl<unsigned int, MYSQL_TYPE_LONG>;
      using outType = OutImpl<unsigned int, MYSQL_TYPE_LONG>;
      constexpr static unsigned long max_buff_size = 0;
   };
   template <>
   struct is_BindType<BindType<Field::INT_UNSIGNED>> : std::true_type {};

   template <>
   struct BindType<Field::CHAR> {
      using inType = InImpl<std::string, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::string, MYSQL_TYPE_STRING>;
      constexpr static unsigned long max_buff_size = 255;
   };
   template <>
   struct is_BindType<BindType<Field::CHAR>> : std::true_type {};

   template <>
   struct BindType<Field::VARCHAR> {
      using inType = InImpl<std::string, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::string, MYSQL_TYPE_VAR_STRING>;
      constexpr static unsigned long max_buff_size = 65535;
   };
   template <>
   struct is_BindType<BindType<Field::VARCHAR>> : std::true_type {};

   template <>
   struct BindType<Field::TINYTEXT> {
      using inType = InImpl<std::string, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::string, MYSQL_TYPE_TINY_BLOB>;
      constexpr static unsigned long max_buff_size = 255;
   };
   template <>
   struct is_BindType<BindType<Field::TINYTEXT>> : std::true_type {};

   template <>
   struct BindType<Field::TEXT> {
      using inType = InImpl<std::string, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::string, MYSQL_TYPE_BLOB>;
      constexpr static unsigned long max_buff_size = 65535;
   };
   template <>
   struct is_BindType<BindType<Field::TEXT>> : std::true_type {};

   template <>
   struct BindType<Field::BLOB> {
      using inType = InImpl<std::string, MYSQL_TYPE_BLOB>;
      using outType = OutImpl<std::string, MYSQL_TYPE_BLOB>;
      constexpr static unsigned long max_buff_size = 65535;
   };
   template <>
   struct is_BindType<BindType<Field::BLOB>> : std::true_type {};

   template <>
   struct BindType<Field::MEDIUMTEXT> {
      using inType = InImpl<std::string, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::string, MYSQL_TYPE_MEDIUM_BLOB>;
      constexpr static unsigned long max_buff_size = 16777215;
   };
   template <>
   struct is_BindType<BindType<Field::MEDIUMTEXT>> : std::true_type {};

   template <>
   struct BindType<Field::MEDIUMBLOB> {
      using inType = InImpl<std::string, MYSQL_TYPE_BLOB>;
      using outType = OutImpl<std::string, MYSQL_TYPE_MEDIUM_BLOB>;
      constexpr static unsigned long max_buff_size = 16777215;
   };
   template <>
   struct is_BindType<BindType<Field::MEDIUMBLOB>> : std::true_type {};

   template <>
   struct BindType<Field::LONGTEXT> {
      using inType = InImpl<std::string, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::string, MYSQL_TYPE_MEDIUM_BLOB>;
      constexpr static unsigned long max_buff_size = 4294967295;
   };
   template <>
   struct is_BindType<BindType<Field::LONGTEXT>> : std::true_type {};

   template <>
   struct BindType<Field::LONGBLOB> {
      using inType = InImpl<std::string, MYSQL_TYPE_BLOB>;
      using outType = OutImpl<std::string, MYSQL_TYPE_LONG_BLOB>;
      constexpr static unsigned long max_buff_size = 4294967295;
   };
   template <>
   struct is_BindType<BindType<Field::LONGBLOB>> : std::true_type {};

   template <>
   struct BindType<Field::TINYINT> {
      using inType = InImpl<signed char, MYSQL_TYPE_TINY>;
      using outType = OutImpl<signed char, MYSQL_TYPE_TINY>;
      constexpr static unsigned long max_buff_size = 0;
   };
   template <>
   struct is_BindType<BindType<Field::TINYINT>> : std::true_type {};

   template <>
   struct BindType<Field::TINYINT_UNSIGNED> {
      using inType = InImpl<unsigned char, MYSQL_TYPE_TINY>;
      using outType = OutImpl<unsigned char, MYSQL_TYPE_TINY>;
      constexpr static unsigned long max_buff_size = 0;
   };
   template <>
   struct is_BindType<BindType<Field::TINYINT_UNSIGNED>> : std::true_type {};

   template <>
   struct BindType<Field::SMALLINT> {
      using inType = InImpl<short, MYSQL_TYPE_SHORT>;
      using outType = OutImpl<short, MYSQL_TYPE_SHORT>;
      constexpr static unsigned long max_buff_size = 0;
   };
   template <>
   struct is_BindType<BindType<Field::SMALLINT>> : std::true_type {};

   template <>
   struct BindType<Field::SMALLINT_UNSIGNED> {
      using inType = InImpl<unsigned short, MYSQL_TYPE_SHORT>;
      using outType = OutImpl<unsigned short, MYSQL_TYPE_SHORT>;
      constexpr static unsigned long max_buff_size = 0;
   };
   template <>
   struct is_BindType<BindType<Field::SMALLINT_UNSIGNED>> : std::true_type {};

   template <>
   struct BindType<Field::BIGINT> {
      using inType = InImpl<long, MYSQL_TYPE_LONGLONG>;
      using outType = OutImpl<long, MYSQL_TYPE_LONGLONG>;
      constexpr static unsigned long max_buff_size = 0;
   };
   template <>
   struct is_BindType<BindType<Field::BIGINT>> : std::true_type {};

   template <>
   struct BindType<Field::BIGINT_UNSIGNED> {
      using inType = InImpl<unsigned long, MYSQL_TYPE_LONGLONG>;
      using outType = OutImpl<unsigned long, MYSQL_TYPE_LONGLONG>;
      constexpr static unsigned long max_buff_size = 0;
   };
   template <>
   struct is_BindType<BindType<Field::BIGINT_UNSIGNED>> : std::true_type {};

   template <>
   struct BindType<Field::FLOAT> {
      using inType = InImpl<float, MYSQL_TYPE_FLOAT>;
      using outType = OutImpl<float, MYSQL_TYPE_FLOAT>;
      constexpr static unsigned long max_buff_size = 0;
   };
   template <>
   struct is_BindType<BindType<Field::FLOAT>> : std::true_type {};

   template <>
   struct BindType<Field::DOUBLE> {
      using inType = InImpl<double, MYSQL_TYPE_DOUBLE>;
      using outType = OutImpl<double, MYSQL_TYPE_DOUBLE>;
      constexpr static unsigned long max_buff_size = 0;
   };
   template <>
   struct is_BindType<BindType<Field::DOUBLE>> : std::true_type {};

   template <>
   struct BindType<Field::DECIMAL> {
      using inType = InImpl<double, MYSQL_TYPE_DOUBLE>;
      using outType = OutImpl<std::string, MYSQL_TYPE_NEWDECIMAL>;
      constexpr static unsigned long max_buff_size = 400;
   };
   template <>
   struct is_BindType<BindType<Field::DECIMAL>> : std::true_type {};

   template <>
   struct BindType<Field::DATE> {
      using inType = InImpl<MYSQL_TIME, MYSQL_TYPE_DATE>;
      using outType = OutImpl<MYSQL_TIME, MYSQL_TYPE_DATE>;
      constexpr static unsigned long max_buff_size = 0;
   };
   template <>
   struct is_BindType<BindType<Field::DATE>> : std::true_type {};

   template <>
   struct BindType<Field::DATETIME> {
      using inType = InImpl<MYSQL_TIME, MYSQL_TYPE_DATETIME>;
      using outType = OutImpl<MYSQL_TIME, MYSQL_TYPE_DATETIME>;
      constexpr static unsigned long max_buff_size = 0;
   };
   template <>
   struct is_BindType<BindType<Field::DATETIME>> : std::true_type {};

   template <>
   struct BindType<Field::TIMESTAMP> {
      using inType = InImpl<MYSQL_TIME, MYSQL_TYPE_TIMESTAMP>;
      using outType = OutImpl<MYSQL_TIME, MYSQL_TYPE_TIMESTAMP>;
      constexpr static unsigned long max_buff_size = 0;
   };
   template <>
   struct is_BindType<BindType<Field::TIMESTAMP>> : std::true_type {};

   template <>
   struct BindType<Field::TIME> {
      using inType = InImpl<MYSQL_TIME, MYSQL_TYPE_TIME>;
      using outType = OutImpl<MYSQL_TIME, MYSQL_TYPE_TIME>;
      constexpr static unsigned long max_buff_size = 0;
   };
   template <>
   struct is_BindType<BindType<Field::TIME>> : std::true_type {};

   template <>
   struct BindType<Field::ENUM> {
      using inType = InImpl<std::string, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::string, MYSQL_TYPE_STRING>;
      constexpr static unsigned long max_buff_size = 0;
   };
   template <>
   struct is_BindType<BindType<Field::ENUM>> : std::true_type {};

   template <>
   struct BindType<Field::SET> {
      using inType = InImpl<std::string, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::string, MYSQL_TYPE_STRING>;
      constexpr static unsigned long max_buff_size = 0;
   };
   template <>
   struct is_BindType<BindType<Field::SET>> : std::true_type {};

   template <>
   struct BindType<Field::BOOLEAN> {
      using inType = InImpl<signed char, MYSQL_TYPE_BLOB>;
      using outType = OutImpl<signed char, MYSQL_TYPE_BLOB>;
      constexpr static unsigned long max_buff_size = 0;
   };
   template <>
   struct is_BindType<BindType<Field::BOOLEAN>> : std::true_type {};

   template <>
   struct BindType<Field::BIT> {
      using inType = OutImpl<unsigned long, MYSQL_TYPE_BIT>;
      using outType = OutImpl<unsigned long, MYSQL_TYPE_BIT>;
      constexpr static unsigned long max_buff_size = 0;
   };
   template <>
   struct is_BindType<BindType<Field::BIT>> : std::true_type {};

   template <>
   struct BindType<Field::GEOMETRY> {
      using inType = InImpl<std::string, MYSQL_TYPE_BLOB>;
      using outType = OutImpl<std::string, MYSQL_TYPE_BLOB>;
      constexpr static unsigned long max_buff_size = 65535;
   };
   template <>
   struct is_BindType<BindType<Field::GEOMETRY>> : std::true_type {};

   template <>
   struct BindType<Field::JSON> {
      using inType = InImpl<std::string, MYSQL_TYPE_JSON>;
      using outType = OutImpl<std::string, MYSQL_TYPE_JSON>;
      constexpr static unsigned long max_buff_size = MYSQL_OPT_MAX_ALLOWED_PACKET;
   };
   template <>
   struct is_BindType<BindType<Field::JSON>> : std::true_type {};

   template <>
   struct BindType<Field::BINARY> {
      using inType = InImpl<std::string, MYSQL_TYPE_STRING>;
      using outType = OutImpl<std::string, MYSQL_TYPE_BLOB>;
      constexpr static unsigned long max_buff_size = 255;
   };
   template <>
   struct is_BindType<BindType<Field::BINARY>> : std::true_type {};

   template <>
   struct BindType<Field::VARBINARY> {
      using inType = InImpl<std::string, MYSQL_TYPE_BLOB>;
      using outType = OutImpl<std::string, MYSQL_TYPE_VAR_STRING>;
      constexpr static unsigned long max_buff_size = 65535;
   };
   template <>
   struct is_BindType<BindType<Field::VARBINARY>> : std::true_type {};

   template <>
   struct BindType<Field::TINYBLOB> {
      using inType = InImpl<std::string, MYSQL_TYPE_TINY_BLOB>;
      using outType = OutImpl<std::string, MYSQL_TYPE_TINY_BLOB>;
      constexpr static unsigned long max_buff_size = 255;
   };
   template <>
   struct is_BindType<BindType<Field::TINYBLOB>> : std::true_type {};

   template <Field field>
   struct Bind {
      using inType = typename BindType<field>::inType;
      using outType = typename BindType<field>::outType;

      std::string_view name;
      unsigned long buffer_size;

      Bind( std::string_view _name, unsigned long _buffer_size = BindType<field>::max_buff_size )
          : name( _name ), buffer_size( _buffer_size ) {
         static_assert( is_BindType<BindType<field>>::value, "Invalid value given to Bind struct" );
      }

      std::unique_ptr<InputCType> makeInput() {
         return std::make_unique<inType>( name, ( field == Field::DECIMAL ? 0 : buffer_size ) );
      }

      std::unique_ptr<OutputCType> makeOutput() { return std::make_unique<outType>( name, buffer_size ); }
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