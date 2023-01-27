#ifndef INCLUDED_SQLTYPES_H
#define INCLUDED_SQLTYPES_H

#include <mysql/mysql.h>

#include <any>
#include <cstring>
#include <iomanip>
#include <stdexcept>
#include <string_view>
#include <vector>

#include "utilities.h"

/*
    These are all classes meant to be used in a wrapper for MYSQL_BIND arrays found in
   binds.hpp. These classes are composed of the data types and the enum_field_types ( used to
   populate the ENUM_BINDS buffer_type field ) that are permitted to be used in prepared
   statements. There are 8 C types and 1 MYSQL type used (char, short, int, long long, float,
   double, MYSQL_TIME and char[]). However in the case of char[], various enum_field_types that
   are valid for receiving data as char[] are not permitted to be used for requesting data. This
   is why I decided to amplify this class hierarchy using interfaces RequestCType and
   ResponseCType and as well change the wrapper to a template class.
*/

class SqlCType {
   protected:
    std::vector<char> charVec;

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

    SqlCType( const char* _fieldName, enum_field_types type, void* _buffer,
              unsigned long long _bufferLength = 0 )
        : fieldName( _fieldName ),
          bufferType( type ),
          isNull( 0 ),
          error( 0 ),
          length( 0 ),
          bind( nullptr ),
          buffer( _buffer ),
          bufferLength( _bufferLength ),
          is_selected( true ) {
        if ( isCharArray( bufferType ) ) {

            for ( unsigned long long i = 0; i < bufferLength; ++i ) {
                charVec.push_back( '\0' );
            }
            buffer = charVec.data();
        }
    }

    void setBind( MYSQL_BIND* targetBind ) {
        bind = targetBind;
        std::memset( bind, 0, sizeof( *bind ) );
        bind->buffer_type = bufferType;
        bind->buffer = (char*)buffer;
        bind->is_null = &isNull;
        bind->length = &length;
        bind->error = &error;
        if ( isCharArray( bufferType ) ) {
            bind->buffer_length = bufferLength;
        }
    }

    virtual ~SqlCType() = default;

    virtual void printValue() const = 0;  // mostly to make base class not instantiable
};

class RequestCType : public SqlCType {
   public:
    RequestCType( const char* _fieldName, enum_field_types type, void* _buffer,
                  unsigned long long _bufferLength = 0 )
        : SqlCType( _fieldName, type, _buffer, _bufferLength ) {
    }
    virtual ~RequestCType() = default;
    virtual void set_value( const std::any& a ) = 0;
};

// The idea for these templates from reddit user u/IyeOnline
template <typename T, enum_field_types Type>
class TypeRequestImpl : public RequestCType {
    T value;

   public:
    TypeRequestImpl() = delete;
    TypeRequestImpl( const char* _fieldName ) : RequestCType( _fieldName, Type, &value ) {
    }

    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << value;
    }

    void set_value( const std::any& a ) override {
        value = std::any_cast<T>( a );
    }
};

class ResponseCType : public SqlCType {
   public:
    ResponseCType( const char* _fieldName, enum_field_types type, void* _buffer,
                   unsigned long long _bufferLength = 0 )
        : SqlCType( _fieldName, type, _buffer, _bufferLength ) {
    }
    virtual ~ResponseCType() = default;
};

template <typename T, enum_field_types Type>
class TypeResponseImpl : public ResponseCType {
    T value;

   public:
    TypeResponseImpl() = delete;
    TypeResponseImpl( const char* _fieldName ) : ResponseCType( _fieldName, Type, &value ) {
    }

    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << value;
    }
};

using TypeCharRequest = TypeRequestImpl<signed char, MYSQL_TYPE_TINY>;
using TypeCharResponse = TypeResponseImpl<signed char, MYSQL_TYPE_TINY>;

using TypeShortRequest = TypeRequestImpl<short, MYSQL_TYPE_SHORT>;
using TypeShortResponse = TypeResponseImpl<short, MYSQL_TYPE_SHORT>;

using TypeIntRequest = TypeRequestImpl<int, MYSQL_TYPE_LONG>;
using TypeIntResponse = TypeResponseImpl<int, MYSQL_TYPE_LONG>;

using TypeLLRequest = TypeRequestImpl<long long, MYSQL_TYPE_LONGLONG>;
using TypeLLResponse = TypeResponseImpl<long long, MYSQL_TYPE_LONGLONG>;

using TypeFloatRequest = TypeRequestImpl<float, MYSQL_TYPE_FLOAT>;
using TypeFloatResponse = TypeResponseImpl<float, MYSQL_TYPE_FLOAT>;

using TypeDoubleRequest = TypeRequestImpl<double, MYSQL_TYPE_DOUBLE>;
using TypeDoubleResponse = TypeResponseImpl<double, MYSQL_TYPE_DOUBLE>;

class TypeMysqlTimeRequest : public RequestCType {
   private:
    MYSQL_TIME value;

   public:
    TypeMysqlTimeRequest() = delete;
    TypeMysqlTimeRequest( const char* _fieldName, enum_field_types type )
        : RequestCType( _fieldName, type, &value ) {
        if ( !isTimeType( type ) ) {
            throw std::runtime_error( "Invalid buffer type given for TypeMysqlTimeRequest" );
        }
    }
    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << "MYSQL_TIME Value";  // needs to be set
    }
    void set_value( const std::any& a ) override {
        value = std::any_cast<MYSQL_TIME>( a );
    }
};

class TypeMysqlTimeResponse : public ResponseCType {
   private:
    MYSQL_TIME value;

   public:
    TypeMysqlTimeResponse() = delete;
    TypeMysqlTimeResponse( const char* _fieldName, enum_field_types type )
        : ResponseCType( _fieldName, type, &value ) {
        if ( !isTimeType( type ) ) {
            throw std::runtime_error( "Invalid buffer type given for TypeMysqlTimeResponse" );
        }
    }
    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << "MYSQL_TIME Value";  // needs to be set
    }
};

class TypeCharArrayRequest : public RequestCType {

   public:
    TypeCharArrayRequest() = delete;
    TypeCharArrayRequest( const char* _fieldName, enum_field_types type,
                          unsigned long long _bufferLength )
        : RequestCType( _fieldName, type, nullptr, _bufferLength ) {
        if ( !isCharArrayReq( type ) ) {
            throw std::runtime_error( "Invalid buffer type given for TypeCharArrayRequest" );
        }
    }

    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << charVec.data();
    }
    void set_value( const std::any& a ) override {
        const char* newValue = std::any_cast<const char*>( a );
        std::strcpy( charVec.data(), newValue );
        length = std::strlen( charVec.data() );
    }
};

class TypeCharArrayResponse : public ResponseCType {

   public:
    TypeCharArrayResponse() = delete;
    TypeCharArrayResponse( const char* _fieldName, enum_field_types type,
                           unsigned long long _bufferLength )
        : ResponseCType( _fieldName, type, nullptr, _bufferLength ) {
        if ( !isCharArray( type ) ) {
            throw std::runtime_error( "Invalid buffer type given for TypeCharArrayResponse" );
        }
    }
    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << charVec.data();
    }
};

#endif  // INCLUDED_SQLTYPES_H