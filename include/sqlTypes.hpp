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

#define BUFF_SIZE 100

/*
    These are all classes meant to be used in a wrapper for MYSQL_BIND arrays found in binds.hpp.
   These classes are composed of the data types and the enum_field_types ( used to populate the
   ENUM_BINDS buffer_type field ) that are permitted to be used in prepared statements. There are 8
   C types and 1 MYSQL type used (char, short, int, long long, float, double, MYSQL_TIME and
   char[]). However in the case of char[], various enum_field_types that are valid for receiving
   data as char[] are not permitted to be used for requesting data. This is why I decided to amplify
   this class hierarchy using interfaces RequestCType and ResponseCType and as well change the
   wrapper to a template class.
*/

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

class ResponseCType : public SqlCType {
   public:
    ResponseCType( const char* _fieldName, enum_field_types type, void* _buffer,
                   unsigned long long _bufferLength = 0 )
        : SqlCType( _fieldName, type, _buffer, _bufferLength ) {
    }
    virtual ~ResponseCType() = default;
};

class TypeCharRequest : public RequestCType {
   private:
    signed char value;

   public:
    TypeCharRequest() = delete;
    TypeCharRequest( const char* _fieldName )
        : RequestCType( _fieldName, MYSQL_TYPE_TINY, &value ) {
    }

    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << value;
    }

    void set_value( const std::any& a ) override {
        value = std::any_cast<signed char>( a );
    }
};

class TypeCharResponse : public ResponseCType {
   private:
    signed char value;

   public:
    TypeCharResponse() = delete;
    TypeCharResponse( const char* _fieldName )
        : ResponseCType( _fieldName, MYSQL_TYPE_TINY, &value ) {
    }

    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << value;
    }
};

class TypeShortRequest : public RequestCType {
   private:
    short int value;

   public:
    TypeShortRequest() = delete;
    TypeShortRequest( const char* _fieldName )
        : RequestCType( _fieldName, MYSQL_TYPE_SHORT, &value ) {
    }

    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << value;
    }

    void set_value( const std::any& a ) override {
        value = std::any_cast<short>( a );
    }
};

class TypeShortResponse : public ResponseCType {
   private:
    short int value;

   public:
    TypeShortResponse() = delete;
    TypeShortResponse( const char* _fieldName )
        : ResponseCType( _fieldName, MYSQL_TYPE_SHORT, &value ) {
    }

    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << value;
    }
};

class TypeIntRequest : public RequestCType {
   private:
    int value;

   public:
    TypeIntRequest() = delete;
    TypeIntRequest( const char* _fieldName ) : RequestCType( _fieldName, MYSQL_TYPE_LONG, &value ) {
    }

    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << value;
    }

    void set_value( const std::any& a ) override {
        value = std::any_cast<int>( a );
    }
};

class TypeIntResponse : public ResponseCType {
   private:
    int value;

   public:
    TypeIntResponse() = delete;
    TypeIntResponse( const char* _fieldName )
        : ResponseCType( _fieldName, MYSQL_TYPE_LONG, &value ) {
    }
    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << value;
    }
};

class TypeLLRequest : public RequestCType {
   private:
    long long value;

   public:
    TypeLLRequest() = delete;
    TypeLLRequest( const char* _fieldName )
        : RequestCType( _fieldName, MYSQL_TYPE_LONGLONG, &value ) {
    }

    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << value;
    }

    void set_value( const std::any& a ) override {
        value = std::any_cast<long long>( a );
    }
};

class TypeLLResponse : public ResponseCType {
   private:
    long long value;

   public:
    TypeLLResponse() = delete;
    TypeLLResponse( const char* _fieldName )
        : ResponseCType( _fieldName, MYSQL_TYPE_LONGLONG, &value ) {
    }

    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << value;
    }
};

class TypeFloatRequest : public RequestCType {
   private:
    float value;

   public:
    TypeFloatRequest() = delete;
    TypeFloatRequest( const char* _fieldName )
        : RequestCType( _fieldName, MYSQL_TYPE_FLOAT, &value ) {
    }

    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << value;
    }

    void set_value( const std::any& a ) override {
        value = std::any_cast<float>( a );
    }
};

class TypeFloatResponse : public ResponseCType {
   private:
    float value;

   public:
    TypeFloatResponse() = delete;
    TypeFloatResponse( const char* _fieldName )
        : ResponseCType( _fieldName, MYSQL_TYPE_FLOAT, &value ) {
    }

    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << value;
    }
};

class TypeDoubleRequest : public RequestCType {
   private:
    double value;

   public:
    TypeDoubleRequest() = delete;
    TypeDoubleRequest( const char* _fieldName )
        : RequestCType( _fieldName, MYSQL_TYPE_DOUBLE, &value ) {
    }

    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << value;
    }
    void set_value( const std::any& a ) override {
        value = std::any_cast<double>( a );
    }
};

class TypeDoubleResponse : public ResponseCType {
   private:
    double value;

   public:
    TypeDoubleResponse() = delete;
    TypeDoubleResponse( const char* _fieldName )
        : ResponseCType( _fieldName, MYSQL_TYPE_DOUBLE, &value ) {
    }

    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << value;
    }
};

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
   private:
    char value[BUFF_SIZE];

   public:
    TypeCharArrayRequest() = delete;
    TypeCharArrayRequest( const char* _fieldName, enum_field_types type )
        : RequestCType( _fieldName, type, value, BUFF_SIZE ) {
        if ( !isCharArrayReq( type ) ) {
            throw std::runtime_error( "Invalid buffer type given for TypeCharArrayRequest" );
        }
    }

    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << value;
    }
    void set_value( const std::any& a ) override {
        const char* newValue = std::any_cast<const char*>( a );
        std::strcpy( value, newValue );
        length = std::strlen( value );
    }
};

class TypeCharArrayResponse : public ResponseCType {
   private:
    char value[BUFF_SIZE];

   public:
    TypeCharArrayResponse() = delete;
    TypeCharArrayResponse( const char* _fieldName, enum_field_types type )
        : ResponseCType( _fieldName, type, value, BUFF_SIZE ) {
        if ( !isCharArray( type ) ) {
            throw std::runtime_error( "Invalid buffer type given for TypeCharArrayResponse" );
        }
    }
    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << value;
    }
};

#endif  // INCLUDED_SQLTYPES_H