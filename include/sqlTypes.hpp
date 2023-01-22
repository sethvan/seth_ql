#ifndef INCLUDED_SQLTYPES_H
#define INCLUDED_SQLTYPES_H

#include <mysql/mysql.h>

#include <cstring>
#include <string_view>
#include <vector>

class SqlType {

   public:
    std::string_view fieldName;
    bool isNull;
    bool error;
    unsigned long length;
    MYSQL_BIND* bind;
    enum_field_types bufferType;
    void* buffer;
    unsigned long long bufferLength;

    SqlType( const char* _fieldName, enum_field_types type, void* _buffer,
             unsigned long long _bufferLength = 0 )
        : fieldName( _fieldName ),
          isNull( 0 ),
          error( 0 ),
          length( 0 ),
          bind( nullptr ),
          bufferType( type ),
          buffer( _buffer ),
          bufferLength( _bufferLength ) {
    }
    virtual ~SqlType() = default;

    virtual void printValue()
        const = 0;  // just to make base class not instantiable, was written before
                    // deciding for uniformity's sake to add getters and setters to all
                    // derived classes for uniformity due to TextType's need for them.
};

class TinyInt : public SqlType {
   private:
    signed char value;

   public:
    TinyInt() = delete;
    TinyInt( const char* _fieldName, signed char rhs = 0 )
        : SqlType( _fieldName, MYSQL_TYPE_TINY, &value ), value( rhs ) {
    }
    signed char getValue() const {
        return value;
    }
    void setValue( signed char sc ) {
        value = sc;
    }
    virtual void printValue() const override {
        std::cout << value << std::endl;
    }
};

class SmallInt : public SqlType {
   private:
    short int value;

   public:
    SmallInt() = delete;
    SmallInt( const char* _fieldName, short int rhs = 0 )
        : SqlType( _fieldName, MYSQL_TYPE_SHORT, &value ), value( rhs ) {
    }
    short getValue() const {
        return value;
    }
    void setValue( short sh ) {
        value = sh;
    }
    virtual void printValue() const override {
        std::cout << value << std::endl;
    }
};

class BigInt : public SqlType {
   private:
    long long value;

   public:
    BigInt() = delete;
    BigInt( const char* _fieldName, long long rhs = 0 )
        : SqlType( _fieldName, MYSQL_TYPE_LONGLONG, &value ), value( rhs ) {
    }
    long long getValue() const {
        return value;
    }
    void setValue( long long ll ) {
        value = ll;
    }
    virtual void printValue() const override {
        std::cout << value << std::endl;
    }
};

class TextType : public SqlType {
   private:
    std::vector<char> charVec;

   public:
    TextType() = delete;
    TextType( const char* _fieldName, const char* _value = "" )
        : SqlType( _fieldName, MYSQL_TYPE_STRING, charVec.data(), 100 ) {
        charVec.reserve( bufferLength );
        std::strcpy( charVec.data(), _value );
        length = std::strlen( charVec.data() );
    }
    const char* getValue() {
        return charVec.data();
    }
    void setValue( const char* newValue ) {
        std::strcpy( charVec.data(), newValue );
        length = std::strlen( charVec.data() );
    }
    std::vector<char>& getCharVec() {  // placeholder because I think I maybe need a
                                       // method to change reserve size
        return charVec;
    }
    virtual void printValue() const override {
        std::cout << charVec.data() << std::endl;
    }
};

#endif  // INCLUDED_SQLTYPES_H