#pragma once

#include "halfedge.h"

namespace XCG{
    namespace Core{
        HalfEdge::HalfEdge(Vertex *_v1, Vertex *_v2) :
         v1(_v1), v2(_v2) {};

        HalfEdge::~HalfEdge() {};

        void HalfEdge::set_vertices(Vertex *_v1,Vertex *_v2)
        {
            v1 = _v1;
            v2 = _v2;
        }

        std::tuple<Vertex *, Vertex *> HalfEdge::get_vertices()
        {
            return std::tuple<Vertex *, Vertex *>(v1,v2);
        }

        void HalfEdge::set_handle(uint _i)
        {
            half_edge_handle = _i;
        }
         
        uint HalfEdge::handle()
        {
            return half_edge_handle;
        }
         
        void HalfEdge::set_parent_edge(uint _i)
        {
            parent_edge_handle = _i;
        }
        
        uint HalfEdge::get_parent_edge()
        {
            return parent_edge_handle;
        }

        void HalfEdge::set_parent_face(uint _i)
        {
            parent_face_handle = _i;
        }
        
        uint HalfEdge::get_parent_face()
        {
            return parent_face_handle;
        }
        
        void HalfEdge::set_boundary(bool _boundariness)
        {
            boundary_half_edge = _boundariness;
        }
        
        bool HalfEdge::is_boundary()
        {
            return boundary_half_edge;
        }
        
        void HalfEdge::set_opposing_half_edge(uint _i)
        {
            opposing_half_edge = _i;
        }
        
        uint HalfEdge::get_opposing_half_edge()
        {
            return opposing_half_edge;
        }

    }
}