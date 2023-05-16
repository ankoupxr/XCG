#pragma once


#include <set>
#include <unordered_set>
#include <stack>
#include <vector> // for typedefs
#include <string>
#include <limits>

namespace xcg{
    namespace core{

        enum class CoordinateType  : std::uint8_t 
        {
            XY,
            XYW,
            XYZ,
            XYZW,
        };
        
        enum class Ordinate : std::uint8_t 
        {
            X,
            Y,
            Z,
            M
        };

        class Coordinate
        {
        private:
            /* data */
        public:
            Coordinate(/* args */);
            ~Coordinate();
        };
        
        

    }
}