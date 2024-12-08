#include "vertex_array.h"

namespace Graphics::Buffers {

    void VertexArray::create() {
        glGenVertexArrays(1, &vaoID);
    }

    void VertexArray::bind() {
        glBindVertexArray(vaoID);
    }

    void VertexArray::unbind() {
        glBindVertexArray(0);
    }

    void VertexArray::attach_vertices(GLuint vboID, GLsizei stride) {
        glVertexArrayVertexBuffer(vaoID, 0, vboID, 0, stride);
    }

    void VertexArray::attrib_pointer(/*std::any attribute*/) {

        //glVertexAttribFormat();

        //glEnableVertexAttribArray(attributeCount);

        //glVertexAttribPointer(attributeCount, 4, GL_FLOAT, GL_FALSE, 0, 0);

        //attributeCount++;
    }

    void VertexArray::destroy() {
        glDeleteVertexArrays(1, &vaoID);
    }
}


