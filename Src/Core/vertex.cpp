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
    }
}