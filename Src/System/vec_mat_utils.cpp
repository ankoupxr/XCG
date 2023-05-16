#include "vec_mat_utils.h"


namespace XCG{

template<uint d, typename T>
inline void vec_max(const T * v0, const T * v1, T * v2)
{
    for(uint i=0; i<d; ++i)
    {
        v2[i] = std::max(v0[i], v1[i]);
    }
}

}