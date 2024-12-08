#pragma once

#include <span>

//#include "glad/glad.h"
#include "base/definitions.h"

namespace Graphics::Buffers {

    class VertexBuffer {

    public:
        void create();
        void data(Base::DRAW_MODE draw_mode, std::span<Base::Vertex> vertex_data);
        void subdata(GLintptr offset, std::span<Base::Vertex> vertex_data);
        void destroy();
    private:
        GLuint vboID = 0;
    };

};
