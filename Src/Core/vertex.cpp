#pragma once

#include "vertex.h"

namespace XCG
{
    namespace Core
    {
        Vertex::Vertex(double _x, double _y, double _z) : x(_x), y(_y), z(_z){}
        
        Vertex::~Vertex(){}

        void Vertex::set_handle(uint _i)
        {
            vertex_handle = _i;
        }

        uint Vertex::handle() 
        {
            return vertex_handle;
        }

        void Vertex::add_incoming_half_edge(unsigned int _i) {
            incoming_half_edges.insert(_i);
        }

        void Vertex::add_outgoing_half_edge(unsigned int _i) {
            outgoing_half_edges.insert(_i);
        }
    }
}