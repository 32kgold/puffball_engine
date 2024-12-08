#pragma once

namespace Graphics::Base {

    struct Vector2 {
        float x, y;
    };

    struct Vector3 {
        float x, y, z;
    };

    struct Vector4 {
        float x, y, z, w;
    };

    struct Color {
      int r, g, b, a;
    };

    struct Vertex {
        Vector4 position;
        unsigned int u, v;
        Color color;
    };

    enum DRAW_MODE { STATIC_DRAW = GL_STATIC_DRAW, DYNAMIC_DRAW = GL_DYNAMIC_DRAW };

};
