#pragma once

#include "point.h"

namespace XCG{
    namespace Core{
        template <int dimension>
        class BoundingBox
        {
        private:
            /* data */
        public:
            BoundingBox();
            BoundingBox(const BoundingBox& otherbox);
            ~BoundingBox();


            void add_box(const BoundingBox<dimension>&box);
            void add_point(const Point<>);

            const Point& min() const;
            const Point& max() const;
        };            


    }

}