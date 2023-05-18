#pragma once

#include <vector>
#include "../System/max_min_inf.h"
#include <unordered_set>
#include <unordered_map>

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

            void add_incoming_half_edge(uint _i);

            void add_outgoing_half_edge(uint _i);

            //Point get_position();

        protected:
              uint vertex_handle;
              std::unordered_set<unsigned int> incoming_half_edges;
              std::unordered_set<unsigned int> outgoing_half_edges;
        };
  }
}
