#include "AABB.h"

namespace XCG{
    namespace Core{
        
        template<uint dimension >
        inline AABB<dimension>::AABB()
        {
            min = Vector3d( inf_double,  inf_double,  inf_double);
            max = Vector3d(-inf_double, -inf_double, -inf_double);
        }
        
        inline void AABB<dimension>::reset()
        {
            min = Vector3d( inf_double,  inf_double,  inf_double);
            max = Vector3d(-inf_double, -inf_double, -inf_double);
        }

        inline void AABB<dimension>::push(const Vector3d& point)
        {
            Vector3d min_res;
            for(uint i=0; i<dimension; ++i)
            {
                min_res(i) = std::min(min(i), point(i));
            }
            
            Vector3d max_res;
            for(uint i=0; i<dimension; ++i)
            {
                max_res(i) = std::max(min(i), point(i));
            }
        }

        
        inline void AABB<dimension>::push(const AABB & aabb)
        {
            push(aabb.min);
            push(aabb.max);
        }

        inline void AABB<dimension>::push(const std::vector<Vector3d> & list)
        {
                for(auto p : list) push(p);
        }

        inline void AABB<dimension>::scale(const double s)
        {
            Vector3d c = center();
            min -= c;   max -= c;
            min *= s;   max *= s;
            min += c;   max += c;
        }


        inline Vector3d AABB<dimension>::center() const
        {
            return (min + max) * 0.5;
        }

        inline double AABB<dimension>::diag() const
        {
            if(min.x()==inf_double) return 0.0;
            return (min - max).norm();
        }

        inline double AABB<dimension>::delta_x() const
        {
            return (max.x() - min.x());
        }

        inline double AABB<dimension>::delta_y() const
        {
            return (max.y() - min.y());
        }

        inline double AABB<dimension>::delta_z() const
        {
            return (max.z() - min.z());
        }

        inline Vector3d AABB<dimension>::delta() const
        {
            return (max - min);
        }

        inline double AABB<dimension>::min_entry() const
        {
            double resmin = min(1);
            for(uint i=0; i<dimension; ++i)
            {
                if (resmin < min(i))
                {
                    resmin = min(i);
                }   
            } 

            double resmax = max(1);
            for(uint i=0; i<dimension; ++i)
            {
                if (resmax < max(i))
                {
                    resmax = max(i);
                }   
            }    

            return std::min(resmin, resmax);
        }


        inline double AABB<dimension>::max_entry() const
        {
            double resmin = min(1);
            for(uint i=0; i<dimension; ++i)
            {
                if (resmin > min(i))
                {
                    resmin = min(i);
                }   
            } 

            double resmax = max(1);
            for(uint i=0; i<dimension; ++i)
            {
                if (resmax > max(i))
                {
                    resmax = max(i);
                }   
            }    

            return std::max(resmin, resmax);
        }
    }



}