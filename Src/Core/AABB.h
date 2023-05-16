#ifndef XCG_AABB_H
#define XCG_AABB_H

#include "point.h"
#include <vector>
#include "../System/max_min_inf.h"
#include "../System/vec_mat.h"

namespace XCG
{
    namespace Core
    {
        template<uint dimension>
        class AABB
        {
        private:
            /* data */
        public:
            AABB(const std::vector<Point> &list,const double scalar = 1.0);
            AABB(const std::vector<AABB> &list,const double scalar = 1.0);
            AABB(const Point& p0,const Point& p1);
            AABB();


            void set_min();
            void set_max();

            void push(const Vector3d& point);
            void push(const AABB& aabb);
            void push(const std::vector<Vector3d>& list);
            void push(const std::vector<AABB>& list);


            void reset();
            void scale(const double s);


            double diag()    const;
            Vector3d  center()  const;
            Vector3d  delta()   const;
            double delta_x() const;
            double delta_y() const;
            double delta_z() const;


            double min_entry() const;
            double max_entry() const;

            Vector3d  point_closest_to(const Point & p) const;
            double dist_sqrd       (const Point & p) const;
            double dist            (const Point & p) const;


            bool contains(const Point & p, const bool strict = false) const;
            bool intersects_box(const AABB  & box, const bool strict = false) const;
            bool intersects_ray(const Point & p, const Point & dir, double & t_min, Point & pos) const;
            bool intersects_triangle(const Point t[3]) const;
            bool intersects_plane(const Point & n, const double d) const;


            std::vector<Vector3f> corners(const double scaling_factor = 1.0) const;
            std::vector<uint>  tris()  const;
            std::vector<uint>  quads() const;
            std::vector<uint>  edges() const;


            Vector3d min, max;

            ~AABB();
        };   
    }
}


#endif