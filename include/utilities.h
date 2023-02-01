#ifndef INCLUDED_UTILITIES_H
#define INCLUDED_UTILITIES_H

#include <mysql/mysql.h>

#include <array>
#include <memory>
#include <optional>
#include <string_view>
#include <utility>
#include <vector>

#include "turnermap.hpp"

// from reddit user u/IyeOnline
template <typename T, typename... Ptrs>
auto make_vector( Ptrs&&... ptrs ) {
    std::vector<std::unique_ptr<T>> vec;
    ( vec.emplace_back( std::forward<Ptrs>( ptrs ) ), ... );
    return vec;
}

struct DataType {
    std::string_view cTypeRequestSigned;
    std::string_view cTypeRequestUnsigned;
    std::string_view cTypeResponseSigned;
    std::string_view cTypeResponseUnsigned;
};

extern const std::array<std::string_view, 256> fieldTypes;

// need to add a couple of types such as 'year' and maybe some spatial ones, need to check
constexpr std::array<std::pair<std::string_view, DataType>, 30> userInputTypes = {
    { { "char",
        { "std::make_unique<TypeCharArrayRequest>( \"NAME\", MYSQL_TYPE_STRING, 100 )", "",
          "std::make_unique<TypeCharArrayResponse>( \"NAME\", MYSQL_TYPE_STRING, 100)", "" } },
      { "varchar",
        { "std::make_unique<TypeCharArrayRequest>( \"NAME\", MYSQL_TYPE_STRING, 100 )", "",
          "std::make_unique<TypeCharArrayResponse>( \"NAME\", MYSQL_TYPE_VAR_STRING, 100)", "" } },
      { "tinytext",
        { "std::make_unique<TypeCharArrayRequest>( \"NAME\", MYSQL_TYPE_STRING, 100 )", "",
          "std::make_unique<TypeCharArrayResponse>( \"NAME\", MYSQL_TYPE_TINY_BLOB, 100)", "" } },
      { "text",
        { "std::make_unique<TypeCharArrayRequest>( \"NAME\", MYSQL_TYPE_STRING, 100 )", "",
          "std::make_unique<TypeCharArrayResponse>( \"NAME\", MYSQL_TYPE_BLOB, 100)", "" } },
      { "blob",
        { "std::make_unique<TypeCharArrayRequest>( \"NAME\", MYSQL_TYPE_BLOB, 100 )", "",
          "std::make_unique<TypeCharArrayResponse>( \"NAME\", MYSQL_TYPE_BLOB, 100)", "" } },
      { "mediumtext",
        { "std::make_unique<TypeCharArrayRequest>( \"NAME\", MYSQL_TYPE_STRING, 100 )", "",
          "std::make_unique<TypeCharArrayResponse>( \"NAME\", MYSQL_TYPE_MEDIUM_BLOB, 100)", "" } },
      { "mediumblob",
        { "std::make_unique<TypeCharArrayRequest>( \"NAME\", MYSQL_TYPE_BLOB, 100 )", "",
          "std::make_unique<TypeCharArrayResponse>( \"NAME\", MYSQL_TYPE_MEDIUM_BLOB, 100)", "" } },
      { "longtext",
        { "std::make_unique<TypeCharArrayRequest>( \"NAME\", MYSQL_TYPE_STRING, 100 )", "",
          "std::make_unique<TypeCharArrayResponse>( \"NAME\", MYSQL_TYPE_MEDIUM_BLOB, 100)", "" } },
      { "longblob",
        { "std::make_unique<TypeCharArrayRequest>( \"NAME\", MYSQL_TYPE_BLOB, 100 )", "",
          "std::make_unique<TypeCharArrayResponse>( \"NAME\", MYSQL_TYPE_LONG_BLOB, 100)", "" } },
      { "tinyint",
        { "std::make_unique<TypeRequestImpl<signed char, MYSQL_TYPE_TINY>>(\"NAME\")",
          "std::make_unique<TypeRequestImpl<unsigned char, MYSQL_TYPE_TINY>>(\"NAME\")",
          "std::make_unique<TypeResponseImpl<signed char, MYSQL_TYPE_TINY>>(\"NAME\")",
          "std::make_unique<TypeResponseImpl<unsigned char, MYSQL_TYPE_TINY>>(\"NAME\")" } },
      { "smallint",
        { "std::make_unique<TypeRequestImpl<short, MYSQL_TYPE_SHORT>>(\"NAME\")",
          "std::make_unique<TypeRequestImpl<unsigned short, MYSQL_TYPE_SHORT>>(\"NAME\")",
          "std::make_unique<TypeResponseImpl<short, MYSQL_TYPE_SHORT>>(\"NAME\")",
          "std::make_unique<TypeResponseImpl<unsigned short, MYSQL_TYPE_SHORT>>(\"NAME\")" } },
      { "mediumint",
        { "std::make_unique<TypeRequestImpl<int, MYSQL_TYPE_LONG>>(\"NAME\")",
          "std::make_unique<TypeRequestImpl<unsigned int, MYSQL_TYPE_LONG>>(\"NAME\")",
          "std::make_unique<TypeResponseImpl<int MYSQL_TYPE_INT24>>(\"NAME\")",
          "std::make_unique<TypeResponseImpl<unsigned int, MYSQL_TYPE_INT24>>(\"NAME\")" } },
      { "int",
        { "std::make_unique<TypeRequestImpl<int, MYSQL_TYPE_LONG>>(\"NAME\")",
          "std::make_unique<TypeRequestImpl<unsigned int, MYSQL_TYPE_LONG>>(\"NAME\")",
          "std::make_unique<TypeResponseImpl<int, MYSQL_TYPE_LONG>>(\"NAME\")",
          "std::make_unique<TypeResponseImpl<unsigned int, MYSQL_TYPE_LONG>>(\"NAME\")" } },
      { "bigint",
        { "std::make_unique<TypeRequestImpl<long long, MYSQL_TYPE_LONGLONG>>(\"NAME\")",
          "std::make_unique<TypeRequestImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(\"NAME\")",
          "std::make_unique<TypeResponseImpl<long long, MYSQL_TYPE_LONGLONG>>(\"NAME\")",
          "std::make_unique<TypeResponseImpl<unsigned long long, "
          "MYSQL_TYPE_LONGLONG>>(\"NAME\")" } },
      { "float",
        { "std::make_unique<TypeRequestImpl<float, MYSQL_TYPE_FLOAT>>(\"NAME\")", "",
          "std::make_unique<TypeResponseImpl<float, MYSQL_TYPE_FLOAT>>(\"NAME\")", "" } },
      { "double",
        { "std::make_unique<TypeRequestImpl<double, MYSQL_TYPE_DOUBLE>>(\"NAME\")", "",
          "std::make_unique<TypeResponseImpl<double, MYSQL_TYPE_DOUBLE>>(\"NAME\")", "" } },
      { "decimal",
        { "std::make_unique<TypeRequestImpl<double, MYSQL_TYPE_DOUBLE>>(\"NAME\")", "",
          "std::make_unique<TypeCharArrayResponse>( \"NAME\", MYSQL_TYPE_NEWDECIMAL, 100)", "" } },
      { "date",
        { "std::make_unique<TypeMysqlTimeRequest>( \"NAME\", MYSQL_TYPE_DATE )", "",
          "std::make_unique<TypeMysqlTimeResponse>( \"NAME\", MYSQL_TYPE_DATE)", "" } },
      { "datetime",
        { "std::make_unique<TypeMysqlTimeRequest>( \"NAME\", MYSQL_TYPE_DATETIME )", "",
          "std::make_unique<TypeMysqlTimeResponse>( \"NAME\", MYSQL_TYPE_DATETIME)", "" } },
      { "timestamp",
        { "std::make_unique<TypeMysqlTimeRequest>( \"NAME\", MYSQL_TYPE_TIMESTAMP )", "",
          "std::make_unique<TypeMysqlTimeResponse>( \"NAME\", MYSQL_TYPE_TIMESTAMP)", "" } },
      { "time",
        { "std::make_unique<TypeMysqlTimeRequest>( \"NAME\", MYSQL_TYPE_TIME )", "",
          "std::make_unique<TypeMysqlTimeResponse>( \"NAME\", MYSQL_TYPE_TIME)", "" } },
      { "enum",
        { "std::make_unique<TypeCharArrayRequest>( \"NAME\", MYSQL_TYPE_STRING, 100 )", "",
          "std::make_unique<TypeCharArrayResponse>( \"NAME\", MYSQL_TYPE_STRING, 100)", "" } },
      { "set",
        { "std::make_unique<TypeCharArrayRequest>( \"NAME\", MYSQL_TYPE_STRING, 100 )", "",
          "std::make_unique<TypeCharArrayResponse>( \"NAME\", MYSQL_TYPE_STRING, 100)", "" } },
      { "boolean",
        { "std::make_unique<TypeRequestImpl<signed char, MYSQL_TYPE_TINY>>(\"NAME\")", "",
          "std::make_unique<TypeResponseImpl<signed char, MYSQL_TYPE_TINY>>(\"NAME\")", "" } },
      { "bit",
        { "std::make_unique<TypeResponseImpl<unsigned long, MYSQL_TYPE_BIT>>(\"NAME\")", "",
          "std::make_unique<TypeResponseImpl<unsigned long, MYSQL_TYPE_BIT>>(\"NAME\")", "" } },
      { "geometry",
        { "std::make_unique<TypeCharArrayRequest>( \"NAME\", MYSQL_TYPE_BLOB, 100 )", "",
          "std::make_unique<TypeCharArrayResponse>( \"NAME\", MYSQL_TYPE_BLOB, 100)", "" } },
      { "json",
        { "std::make_unique<TypeCharArrayRequest>( \"NAME\", MYSQL_TYPE_JSON, 100 )", "",
          "std::make_unique<TypeCharArrayResponse>( \"NAME\", MYSQL_TYPE_JSON, 100)", "" } },
      { "binary",
        { "std::make_unique<TypeCharArrayRequest>( \"NAME\", MYSQL_TYPE_STRING, 100 )", "",
          "std::make_unique<TypeCharArrayResponse>( \"NAME\", MYSQL_TYPE_BLOB, 100)", "" } },
      { "varbinary",
        { "std::make_unique<TypeCharArrayRequest>( \"NAME\", MYSQL_TYPE_BLOB, 100 )", "",
          "std::make_unique<TypeCharArrayResponse>( \"NAME\", MYSQL_TYPE_VAR_STRING, 100)", "" } },
      { "tinyblob",
        { "std::make_unique<TypeCharArrayRequest>( \"NAME\", MYSQL_TYPE_TINY_BLOB, 100 )", "",
          "std::make_unique<TypeCharArrayResponse>( \"NAME\", MYSQL_TYPE_TINY_BLOB, 100)",
          "" } } } };

bool isCharArray( enum_field_types type );
bool isCharArrayReq( enum_field_types type );
bool isTimeType( enum_field_types type );

#endif  // INCLUDED_UTILITIES_H