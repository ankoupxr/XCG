#pragma once

#include <vector>
#include "../Core/halfedge.h"
#include "../Core/vertex.h"
#include "../System/max_min_inf.h"
#include "../System/vec_mat.h"

namespace XCG{
    namespace Core{
        class Face
        {
        private:
            Vertex *v1,*v2,*v3;
            uint face_handle;
        public:
            Face(Vertex *_v1, Vertex *_v2, Vertex *_v3) : v1(_v1), v2(_v2), v3(_v3) {};

            ~Face() {};

        public:
            void set_handle(uint _i);

            uint handle();

            std::tuple<Vertex *, Vertex *, Vertex *> get_vertices();

        };
        

    }

}