#pragma once

#include "glad/glad.h"

namespace Graphics::Buffers {

    class VertexBuffer {

    public:
        VertexBuffer create();
        void destroy();
    private:
        int vboID = 0;
    };

};
