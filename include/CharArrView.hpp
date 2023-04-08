// Class written with help of ChatGPT so as to not need C++20 for use case of std::span in InputCType.hpp

#ifndef INCLUDED_CHARARRVIEW_H
#define INCLUDED_CHARARRVIEW_H

#include <cstddef>
#include <cstring>
#include <type_traits>

namespace seth_ql {

   class CharArrView {
     public:
      using element_type = char;
      using value_type = char;
      using index_type = std::ptrdiff_t;
      using pointer = char*;
      using reference = char&;
      using iterator = pointer;

      constexpr CharArrView() : data_( nullptr ), size_( 0 ) {}
      constexpr CharArrView( pointer ptr, std::size_t count ) : data_( ptr ), size_( count ) {}

      template <std::size_t N>
      constexpr CharArrView( char ( &arr )[ N ] ) : data_( arr ), size_( N ) {}

      constexpr CharArrView( const char* str ) : data_( const_cast<char*>( str ) ), size_( std::strlen( str ) ) {}

      template <typename Container, typename = std::enable_if_t<std::is_same_v<typename Container::value_type, char>>>
      constexpr CharArrView( Container& container )
          : data_( const_cast<char*>( container.data() ) ), size_( container.size() ) {}

      template <typename Container, typename = std::enable_if_t<std::is_same_v<typename Container::value_type, char>>>
      constexpr CharArrView( const Container& container )
          : data_( const_cast<char*>( container.data() ) ), size_( container.size() ) {}

      constexpr pointer data() const noexcept { return data_; }
      constexpr std::size_t size() const noexcept { return size_; }
      constexpr bool empty() const noexcept { return size_ == 0; }

      constexpr reference operator[]( std::size_t idx ) const noexcept { return data_[ idx ]; }
      constexpr reference front() const noexcept { return data_[ 0 ]; }
      constexpr reference back() const noexcept { return data_[ size_ - 1 ]; }

      constexpr iterator begin() const noexcept { return data_; }
      constexpr iterator end() const noexcept { return data_ + size_; }
      constexpr iterator cbegin() const noexcept { return data_; }
      constexpr iterator cend() const noexcept { return data_ + size_; }

     private:
      pointer data_;
      std::size_t size_;
   };

}  // namespace seth_ql

#endif  // INCLUDED_CHARARRVIEW_H