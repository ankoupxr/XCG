#pragma once

#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include "vertex.h"
#include "../System/max_min_inf.h"

namespace XCG
{
    namespace Core
    {
        class Edge
        {
            public:
                Edge(Vertex *_v1, Vertex *_v2) : v1(_v1), v2(_v2) {};

                ~Edge() {};

                std::tuple<Vertex *, Vertex *> get_vertices();

                void set_vertex();

                uint handle();

                void set_handle(uint _i);

                void set_boundary(bool boundariness);

                bool is_boundary();

        private:
            Vertex *v1, *v2;
            unsigned int edge_handle;
            bool boundary_edge = false;

        };
    }
}