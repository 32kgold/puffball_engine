#pragma once

namespace Graphics::Buffers {

    class VertexArray {

    public:
        void create();
        void bind();
        void unbind();
        void attach_vertices(GLuint vboID, GLsizei stride);
        void attrib_pointer();
        void destroy();
    private:
        GLuint vaoID = 0;
        int attributeCount = 0;
    };

}