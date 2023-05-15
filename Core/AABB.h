#ifndef XCG_AABB_H
#define XCG_AABB_H

#include "point.h"
#include <vector>


namespace XCG
{
    namespace Core
    {
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

            void push(const Point& point);
            void push(const AABB& aabb);
            void push(const std::vector<Point>& list);
            void push(const std::vector<AABB>& list);


            void reset();
            void scale(const double s);

            //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

            double diag()    const;
            Point  center()  const;
            Point  delta()   const;
            double delta_x() const;
            double delta_y() const;
            double delta_z() const;

            //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

            double min_entry() const;
            double max_entry() const;

            //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

            Point  point_closest_to(const Point & p) const;
            double dist_sqrd       (const Point & p) const;
            double dist            (const Point & p) const;

            //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

            bool contains(const Point & p, const bool strict = false) const;
            bool intersects_box(const AABB  & box, const bool strict = false) const;
            bool intersects_ray(const Point & p, const Point & dir, double & t_min, Point & pos) const;
            bool intersects_triangle(const Point t[3]) const;
            bool intersects_plane(const Point & n, const double d) const;

            //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

            std::vector<Point> corners(const double scaling_factor = 1.0) const;
            std::vector<uint>  tris()  const;
            std::vector<uint>  quads() const;
            std::vector<uint>  edges() const;

            //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

            Point min, max;

            ~AABB();
        };   
    }
}


#endif