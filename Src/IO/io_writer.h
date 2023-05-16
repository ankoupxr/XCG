#pragma once

namespace XMesh{
    namespace IO{
        class Writer
        {
        private:
            /* data */
        public:
            virtual ~Writer() = default;
            virtual bool transfer() = 0;
        };

    }
}