#ifndef INCLUDED_SQLTYPES_H
#define INCLUDED_SQLTYPES_H

#include <mysql/mysql.h>

#include <any>
#include <cstring>
#include <iomanip>
#include <string_view>
#include <vector>

#define BUFF_SIZE 100

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
          is_selected( false ) {
    }

    void setBind( MYSQL_BIND* targetBind ) {
        bind = targetBind;
        std::memset( bind, 0, sizeof( *bind ) );
        bind->buffer_type = bufferType;
        bind->buffer = (char*)buffer;
        bind->is_null = &isNull;
        bind->length = &length;
        bind->error = &error;
        if ( bufferType == MYSQL_TYPE_VAR_STRING || bufferType == MYSQL_TYPE_STRING ||
             bufferType == MYSQL_TYPE_NEWDECIMAL ) {
            bind->buffer_length = bufferLength;
        }
    }

    // MYSQL_TIME* timeStruct() {

    //     return bufferType ==
    // }

    virtual ~SqlCType() = default;

    virtual void set_value( const std::any& a ) = 0;

    virtual void printValue()
        const = 0;  // just to make base class not instantiable, was written before
                    // deciding for uniformity's sake to add setters to all derived
                    // classes for uniformity due to TextType's need for them.
};

class TypeChar : public SqlCType {
   private:
    signed char value;

   public:
    TypeChar() = delete;
    TypeChar( const char* _fieldName ) : SqlCType( _fieldName, MYSQL_TYPE_TINY, &value ) {
    }
    signed char getValue() const {
        return value;
    }
    void setValue( signed char sc ) {
        value = sc;
    }
    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << value;
    }

    void set_value( const std::any& a ) override {
        value = std::any_cast<signed char>( a );
    }
};

class TypeShort : public SqlCType {
   private:
    short int value;

   public:
    TypeShort() = delete;
    TypeShort( const char* _fieldName ) : SqlCType( _fieldName, MYSQL_TYPE_SHORT, &value ) {
    }
    short getValue() const {
        return value;
    }
    void setValue( short sh ) {
        value = sh;
    }
    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << value;
    }

    void set_value( const std::any& a ) override {
        value = std::any_cast<short>( a );
    }
};

class TypeInt : public SqlCType {
   private:
    int value;

   public:
    TypeInt() = delete;
    TypeInt( const char* _fieldName ) : SqlCType( _fieldName, MYSQL_TYPE_LONG, &value ) {
    }
    short getValue() const {
        return value;
    }
    void setValue( int i ) {
        value = i;
    }
    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << value;
    }

    void set_value( const std::any& a ) override {
        value = std::any_cast<int>( a );
    }
};

class TypeLL : public SqlCType {
   private:
    long long value;

   public:
    TypeLL() = delete;
    TypeLL( const char* _fieldName ) : SqlCType( _fieldName, MYSQL_TYPE_LONGLONG, &value ) {
    }
    long long getValue() const {
        return value;
    }
    void setValue( long long ll ) {
        value = ll;
    }
    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << value;
    }

    void set_value( const std::any& a ) override {
        value = std::any_cast<long long>( a );
    }
};

class TypeFloat : public SqlCType {
   private:
    float value;

   public:
    TypeFloat() = delete;
    TypeFloat( const char* _fieldName ) : SqlCType( _fieldName, MYSQL_TYPE_FLOAT, &value ) {
    }
    float getValue() const {
        return value;
    }
    void setValue( float f ) {
        value = f;
    }
    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << value;
    }

    void set_value( const std::any& a ) override {
        value = std::any_cast<float>( a );
    }
};

class TypeDouble : public SqlCType {
   private:
    double value;

   public:
    TypeDouble() = delete;
    TypeDouble( const char* _fieldName ) : SqlCType( _fieldName, MYSQL_TYPE_FLOAT, &value ) {
    }
    double getValue() const {
        return value;
    }
    void setValue( double f ) {
        value = f;
    }
    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << value;
    }
    void set_value( const std::any& a ) override {
        value = std::any_cast<double>( a );
    }
};

class TypeMysqlTime : public SqlCType {
   private:
    MYSQL_TIME value;

   public:
    TypeMysqlTime() = delete;
    TypeMysqlTime( const char* _fieldName ) : SqlCType( _fieldName, MYSQL_TYPE_TIME, &value ) {
    }
    void printValue() const override {
        std::cout << std::left << std::setw( 30 ) << "MYSQL_TIME Value";
    }
    void set_value( const std::any& a ) override {
        value = std::any_cast<MYSQL_TIME>( a );
    }
};

class TypeCharArray : public SqlCType {
   private:
    char value[BUFF_SIZE];

   public:
    TypeCharArray() = delete;
    TypeCharArray( const char* _fieldName,
                   enum_field_types type )  // will be set better than this later, meanwhile be
                                            // careful to set correct type when creating
        : SqlCType( _fieldName, type, value, BUFF_SIZE ) {
    }
    const char* getValue() {
        return value;
    }
    void setValue( const char* newValue ) {
        std::strcpy( value, newValue );
        length = std::strlen( value );
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

#endif  // INCLUDED_SQLTYPES_H