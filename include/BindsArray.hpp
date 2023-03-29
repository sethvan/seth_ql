#ifndef INCLUDED_BINDS_H
#define INCLUDED_BINDS_H

#include <algorithm>
#include <exception>
#include <iomanip>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

#include "SqlTypes/SqlCType.h"
#include "utilities.h"

/*
    To be used to set up a prepared statement for creating, modifying or reading.
*/

namespace seth_ql {
   enum class DisplayFields { All, Selected };

   template <typename T>
   class BindsArray {
     private:
      std::vector<std::unique_ptr<T>> columns;
      std::vector<MYSQL_BIND> selection;

      void displayFields( DisplayFields display ) const;

      // linked to BindsArray::operator[] and Points to columns' elements.
      // After object instantiated, do not want column elements added or deleted,
      // just access for selecting and modifying.
      std::unordered_map<std::string_view, T*> fieldsMap;

     public:
      std::vector<T*> fields;
      BindsArray() = delete;
      BindsArray( std::vector<std::unique_ptr<T>> _columns );  // To set once the correct order of
                                                               // MYSQL_BINDs for the prepared statement.

      void displayAllFields() const;
      void displaySelectedFields() const;

      // Sets binds for whatever fields are marked is_selected
      // By default all fields are marked is_selected during construction
      void setBinds();

      // Names given to overloaded method will be only ones marked is_selected and bound
      void setBinds( const std::vector<std::string_view>& sc );

      MYSQL_BIND* getBinds() { return selection.data(); }  // to give to bindParam()

      // size_t getBindsSize() const {  // for testing during development
      //    return selection.size();
      // }

      [[nodiscard]] T& operator[]( std::string_view fieldName );
      [[nodiscard]] T& operator[]( size_t index );
   };

   template <typename T>
   BindsArray<T>::BindsArray( std::vector<std::unique_ptr<T>> _columns ) : columns( std::move( _columns ) ) {
      std::for_each( columns.begin(), columns.end(), [ & ]( const auto& column ) {
         fieldsMap[ column->fieldName ] = column.get();
         fields.push_back( column.get() );
      } );
      BindsArray<T>::setBinds();
   }

   template <typename T>
   void BindsArray<T>::setBinds() {
      std::for_each( columns.begin(), columns.end(), [ & ]( auto& o ) {
         if ( o->is_selected ) {
            selection.emplace_back();
            o->setBind( &( selection.back() ) );
         }
      } );
   }

   template <typename T>
   void BindsArray<T>::setBinds( const std::vector<std::string_view>& sc ) {
      // to ensure arguments are valid
      std::for_each( sc.begin(), sc.end(), [ & ]( auto fieldName ) {
         auto found = std::find_if( columns.begin(), columns.end(),
                                    [ & ]( auto& column ) { return column->fieldName == fieldName; } );
         if ( found == columns.end() ) {
            std::ostringstream os;
            os << "Invalid selection \"" << fieldName << "\" not found in Binds object";
            throw std::runtime_error( std::move( os.str() ) );
         }
      } );

      // to ensure arguments are handled in the correct order
      std::for_each( columns.begin(), columns.end(), [ & ]( auto& column ) {
         auto it =
             std::find_if( sc.begin(), sc.end(), [ & ]( auto fieldName ) { return column->fieldName == fieldName; } );
         if ( it != sc.end() ) {
            column->is_selected = true;
         } else {
            column->is_selected = false;
         }
      } );

      selection.erase( selection.begin(), selection.end() );  // in case a previous selection was made
      BindsArray<T>::setBinds();
   }

   template <typename T>
   T& BindsArray<T>::operator[]( std::string_view fieldName ) {
      return *fieldsMap.at( fieldName );
   }

   template <typename T>
   T& BindsArray<T>::operator[]( size_t index ) {
      if ( index > fields.size() ) {
         throw std::out_of_range( "Index provided to operator[] greater than fields.size() of BindsArray object\n" );
      }
      return *fields[ index ];
   }

   template <typename T>
   void BindsArray<T>::displayFields( DisplayFields display ) const {
      puts( "" );
      std::cout << std::left << std::setw( 45 ) << "Field Name";
      std::cout << std::left << std::setw( 30 ) << "Field Type";
      std::cout << std::left << std::setw( 30 ) << "Field Value" << '\n';
      std::cout << std::left << std::setw( 105 ) << std::setfill( '-' ) << '-' << std::setfill( ' ' ) << '\n';

      const auto printField = [ & ]( const auto& o ) {
         std::cout << std::left << std::setw( 45 ) << o->fieldName;
         std::cout << std::left << std::setw( 30 ) << fieldTypes[ o->bufferType ];
         std::cout << std::left << o << std::endl;
      };

      if ( display == DisplayFields::All ) {
         std::for_each( columns.begin(), columns.end(), [ & ]( const auto& o ) { printField( o ); } );
      } else {
         std::for_each( columns.begin(), columns.end(), [ & ]( const auto& o ) {
            if ( o->is_selected ) {
               printField( o );
            }
         } );
      }

      puts( "" );
   }

   template <typename T>
   void BindsArray<T>::displayAllFields() const {
      displayFields( DisplayFields::All );
   }

   template <typename T>
   void BindsArray<T>::displaySelectedFields() const {
      displayFields( DisplayFields::Selected );
   }

}  // namespace seth_ql

#endif  // INCLUDED_Binds_H