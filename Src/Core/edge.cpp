#include "edge.h"


namespace XCG{
    namespace Core{
        Edge::Edge()
        {
            m_halfedge[0] = NULL; 
            m_halfedge[1] = NULL;
        }

        Edge::~Edge()
        {

        }

    }
}