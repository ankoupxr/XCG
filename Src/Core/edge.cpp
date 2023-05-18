#include "edge.h"


namespace XCG{
    namespace Core{
        Edge::Edge(Vertex *_v1, Vertex *_v2) : v1(_v1), v2(_v2) {}

        Edge::~Edge() {}


        std::tuple<Vertex *, Vertex *> Edge::get_vertices()
        {
            return std::tuple<Vertex *, Vertex *>(v1,v2);
        }


        void Edge::set_handle(uint _i)
        {
            edge_handle = _i;
        }

        uint Edge::handle()
        {
            return edge_handle;
        }
    }
}