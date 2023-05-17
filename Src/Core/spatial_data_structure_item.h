#pragma once

#include "aabb.h"

namespace XCG{
    namespace Core{
        typedef enum
        {
            ABSTRACT,
            POINT,
            SEGMENT,
            TRIANGLE,
            QUAD
        } ItemType;

        template<uint dimension>
        class SpatialDataStructureItem
        {
            explicit SpatialDataStructureItem() {}
            virtual ~SpatialDataStructureItem() {}

            uint m_id;
            AABB aabb;
            ItemType item_type = ABSTRACT;

            virtual Point point_closest_to(const Point & p) const = 0;


            virtual void barycentric_coordinates(const Point & p, double bc[]) const = 0;

            double dist     (const Point & p) const;
            double dist_sqrd(const Point & p) const;


            virtual bool contains           (const Point & p, const bool strict) const = 0;
            virtual bool intersects_segment (const Point s[], const bool ignore_if_valid_complex) const = 0;
            virtual bool intersects_triangle(const Point t[], const bool ignore_if_valid_complex) const = 0;
            virtual bool intersects_ray     (const Point & p, const Vector3d & dir, double & t, Vector3d & pos) const = 0;

        };
        

    }

}