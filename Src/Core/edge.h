#pragma once

#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <string>

namespace XCG
{
    namespace Core
    {
        class HalfEdge;
        class Vertex;

        class Edge
        {
            public:
                Edge();
                ~Edge();

	            int & id() { return m_id; };

                HalfEdge * & halfedge( int id ) { assert( 0<=id && id < 2 ); return m_halfedge[id];};
            protected:
                HalfEdge * m_halfedge[2];
                int m_id;

        };
    }
}