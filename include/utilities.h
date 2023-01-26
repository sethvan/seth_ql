#ifndef INCLUDED_UTILITIES_H
#define INCLUDED_UTILITIES_H

#include <memory>
#include <vector>

// from reddit user u/IyeOnline
template <typename T, typename... Ptrs>
auto make_vector( Ptrs&&... ptrs ) {
    std::vector<std::unique_ptr<T>> vec;
    ( vec.emplace_back( std::forward<Ptrs>( ptrs ) ), ... );
    return vec;
}

extern const std::array<std::string_view, 256> fieldTypes;

#endif  // INCLUDED_UTILITIES_H