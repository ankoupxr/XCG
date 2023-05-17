#include "face.h"


namespace XCG
{
    namespace Core
    {
       void Face::set_handle(uint _i)
       {
            face_handle = _i;
       }

        uint Face::handle() 
        {
            return face_handle;
        }

        std::tuple<Vertex *, Vertex *, Vertex *> Face::get_vertices() 
        {
            return std::make_tuple(v1, v2, v3);
        }
    }

}

