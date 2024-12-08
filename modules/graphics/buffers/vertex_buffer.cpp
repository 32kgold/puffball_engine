#include "vertex_buffer.h"

namespace Graphics::Buffers {

    void VertexBuffer::create() {
        glGenBuffers(1, &vboID);
    }

    void VertexBuffer::data(Base::DRAW_MODE draw_mode, std::span<Base::Vertex> vertex_data) {
        glNamedBufferData(vboID, vertex_data.size() * sizeof(Base::Vertex), vertex_data.data(), draw_mode);
    }

    void VertexBuffer::subdata(GLintptr offset, std::span<Base::Vertex> vertex_data) {
        glNamedBufferSubData(vboID, offset, vertex_data.size() * sizeof(Base::Vertex), vertex_data.data());
    }

    void VertexBuffer::destroy() {
        glDeleteBuffers(1, &vboID);
    }

}


