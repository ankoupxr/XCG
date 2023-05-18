#pragma once

#include "../System/max_min_inf.h"
#include "vertex.h"
#include "edge.h"
#include "face.h"


namespace XCG{
    namespace Core{
        class HalfEdge
        {
            public:
                HalfEdge(Vertex *_v1, Vertex *_v2);
                ~HalfEdge();
                
                void set_vertices(Vertex *_v1, Vertex *_v2);
                std::tuple<Vertex *, Vertex *> get_vertices();
                void set_handle(uint _i);
                uint handle();
                void set_parent_edge(uint _i);
                uint get_parent_edge();
                void set_parent_face(uint _i);
                uint get_parent_face();
                void set_boundary(bool _boundariness);
                bool is_boundary();
                void set_opposing_half_edge(uint _i);
                uint get_opposing_half_edge();

            private:
                Vertex *v1, *v2;
                unsigned int half_edge_handle;
                unsigned int parent_edge_handle;
                unsigned int parent_face_handle;
                unsigned int opposing_half_edge = std::numeric_limits<unsigned int>::max();
                bool boundary_half_edge;

        };
        
        

    }

}