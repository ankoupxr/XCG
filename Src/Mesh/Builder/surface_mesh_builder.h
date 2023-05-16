#pragma once

#include "../Common/common.h"

namespace XCG{
    namespace Builder{
        template <int dimension>
        class SurfaceMeshBuilder
        {
        private:
            /* data */
        public:
            SurfaceMeshBuilder(/* args */);
            virtual ~SurfaceMeshBuilder();

            static std::unique_ptr<SurfaceMeshBuilder<dimension>> create(SurfaceMesh<dimension>& mesh);

            
        };
    
        


    }

}