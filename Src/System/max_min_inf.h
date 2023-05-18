#ifndef XCG_MAX_MIN_INF
#define XCG_MAX_MIN_INF

#ifndef _WIN32
#include <sys/types.h>
#else
#include <algorithm>

typedef unsigned int uint;

typedef std::tuple<unsigned int, unsigned int, unsigned int> three_type_t;

struct three_key_hash : public std::unary_function<three_type_t, std::size_t> {
        std::size_t operator()(const three_type_t &k) const {
            return std::get<0>(k) ^ std::get<1>(k) ^ std::get<2>(k);
        }
    };

struct three_key_equal : public std::binary_function<three_type_t, three_type_t, bool> {
        bool operator()(const three_type_t &v0, const three_type_t &v1) const {
            return (
                    std::get<0>(v0) == std::get<0>(v1) &&
                    std::get<1>(v0) == std::get<1>(v1) &&
                    std::get<2>(v0) == std::get<2>(v1)
            );
        }
    };

typedef std::unordered_map<const three_type_t, unsigned int, three_key_hash, three_key_equal> special_map_three;


typedef std::tuple<unsigned int, unsigned int> twin_type_t;
struct twin_key_hash : public std::unary_function<twin_type_t, std::size_t> {
        std::size_t operator()(const twin_type_t &k) const {
            return std::get<0>(k) ^ std::get<1>(k);
        }
    };

struct twin_key_equal : public std::binary_function<twin_type_t, twin_type_t, bool> {
        bool operator()(const twin_type_t &v0, const twin_type_t &v1) const {
            return (
                    std::get<0>(v0) == std::get<0>(v1) &&
                    std::get<1>(v0) == std::get<1>(v1)
            );
        }
    };
#endif
#include <limits>

namespace XCG
{
    const double min_double = std::numeric_limits<double>::min();
    const float  min_float  = std::numeric_limits<float>::min();
    const int    min_int    = std::numeric_limits<int>::min();
    const uint   min_uint   = std::numeric_limits<uint>::min();

    const double max_double = std::numeric_limits<double>::max();
    const float  max_float  = std::numeric_limits<float>::max();
    const int    max_int    = std::numeric_limits<int>::max();
    const uint   max_uint   = std::numeric_limits<uint>::max();

    const double inf_double = std::numeric_limits<double>::infinity();
    const float  inf_float  = std::numeric_limits<float>::infinity();
    // NOTE: std::numeric_limits<T>::has_infinity is false for T=int,uint
}

#endif // XCG_MAX_MIN_INF