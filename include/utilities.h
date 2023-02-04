#ifndef INCLUDED_UTILITIES_H
#define INCLUDED_UTILITIES_H

#include <mysql/mysql.h>

#include <array>
#include <memory>
#include <string_view>
#include <utility>
#include <vector>

namespace binds_wrapper {

    // from reddit user u/IyeOnline
    template <typename T, typename... Ptrs>
    auto make_vector( Ptrs&&... ptrs ) {
        std::vector<std::unique_ptr<T>> vec;
        ( vec.emplace_back( std::forward<Ptrs>( ptrs ) ), ... );
        return vec;
    }

    extern const std::array<std::string_view, 256> fieldTypes;

    bool isCharArray( enum_field_types type );
    bool isCharArrayReq( enum_field_types type );
    bool isTimeType( enum_field_types type );

}  // namespace binds_wrapper

#endif  // INCLUDED_UTILITIES_H