// Class written by ChatGPT so as to not need C++20 for use cases of span in project

#ifndef INCLUDED_SPAN_H
#define INCLUDED_SPAN_H

#include <cstddef>
#include <type_traits>

namespace seth_ql {

   template <typename T, typename = std::void_t<>>
   struct has_data_member : std::false_type {};

   template <typename T>
   struct has_data_member<T, std::void_t<decltype( std::declval<T>().data() )>> : std::true_type {};

   template <typename T, std::size_t Extent = std::size_t( -1 )>
   class Span {
     public:
      using element_type = T;
      using value_type = std::remove_cv_t<T>;
      using index_type = std::ptrdiff_t;
      using pointer = T*;
      using reference = T&;
      using iterator = pointer;

      constexpr Span() noexcept : data_( nullptr ), size_( 0 ) {}
      constexpr Span( pointer ptr, std::size_t count ) noexcept : data_( ptr ), size_( count ) {}
      template <std::size_t N>
      constexpr Span( T ( &arr )[ N ] ) noexcept : data_( arr ), size_( N ) {}

      template <typename U, std::size_t N>
      constexpr Span( Span<U, N> other ) noexcept : data_( other.data() ), size_( other.size() ) {}

      template <typename Container, typename = std::enable_if_t<
                                        has_data_member<Container>::value &&
                                        !std::is_same_v<std::remove_cv_t<Container>, std::string>>>
      Span( Container& container ) : data_( container.data() ), size_( container.size() ) {
         static_assert(
             std::is_same_v<std::remove_pointer_t<std::remove_cv_t<
                                std::remove_reference_t<decltype( container.data() )>>>,
                            T> ||
                 std::is_convertible_v<
                     std::remove_cv_t<std::remove_reference_t<decltype( container.data()[ 0 ] )>>,
                     T>,
             "Container element type must be compatible with Span element type." );
      }
      template <typename Container, typename = std::enable_if_t<
                                        has_data_member<Container>::value &&
                                        !std::is_same_v<std::remove_cv_t<Container>, std::string>>>
      Span( const Container& container ) : data_( container.data() ), size_( container.size() ) {
         static_assert(
             std::is_same_v<std::remove_pointer_t<std::remove_cv_t<
                                std::remove_reference_t<decltype( container.data() )>>>,
                            T> ||
                 std::is_convertible_v<
                     std::remove_cv_t<std::remove_reference_t<decltype( container.data()[ 0 ] )>>,
                     T>,
             "Container element type must be compatible with Span element type." );
      }

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

#endif  // INCLUDED_SPAN_H