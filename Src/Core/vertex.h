#pragma once

#include <vector>
#include "../System/max_min_inf.h"

namespace XCG{
  namespace Core{
    class Vertex
    {
        private:
            double x,y,z;
        public:
            Vertex(double _x, double _y, double _z);

            ~Vertex() {};

            void set_handle(uint _i);
            
            uint handle();

            void set_position(double _x,double _y,double _z);

            //Point get_position();

        protected:
                uint vertex_handle;
        };
  }
}
