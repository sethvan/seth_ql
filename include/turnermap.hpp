#ifndef INCLUDED_TURNERMAP_H
#define INCLUDED_TURNERMAP_H

#include <algorithm>
#include <stdexcept>
#include <utility>

// Taken from Jason Turner YT video
// https://www.youtube.com/watch?v=INn3xa4pMfg&list=PLs3KjaCtOwSaqPapPV4pc1SRjypnwrXYV&index=8

template <typename Key, typename Value, std::size_t Size>
struct TurnerMap {
    std::array<std::pair<Key, Value>, Size> data;

    [[nodiscard]] constexpr Value at( const Key& key ) const {
        const auto it = std::find_if( data.begin(), data.end(),
                                      [&key]( const auto& v ) { return v.first == key; } );
        if ( it != data.end() ) {
            return it->second;
        }
        else {
            throw std::range_error( "Not Found" );
        }
    }
};

#endif  // INCLUDED_TURNERMAP_H