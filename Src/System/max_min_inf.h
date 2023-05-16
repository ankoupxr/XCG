#ifndef XCG_MAX_MIN_INF
#define XCG_MAX_MIN_INF

#ifndef _WIN32
#include <sys/types.h>
#else
typedef unsigned int uint;
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