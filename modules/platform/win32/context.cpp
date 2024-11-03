#include "context.h"

namespace engine::win32 {

    void Context::create(const std::any hwnd) {

        // get the handle of window device context
        hdc = GetDC(std::any_cast<HWND>(hwnd));

        PIXELFORMATDESCRIPTOR pfd {
            .nSize = sizeof(PIXELFORMATDESCRIPTOR),
            .dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
            .dwLayerMask = PFD_MAIN_PLANE,
            .iPixelType = PFD_TYPE_RGBA,
            .cColorBits = 24,
            .cDepthBits = 24,
            .cAccumBits = 0, // 32
            .cStencilBits = 8
        };

        int pixel_format = ChoosePixelFormat(hdc, &pfd); ;

        if (pixel_format == 0) {
            MessageBox(nullptr, "ChoosePixelFormat failed", "Error", MB_OK);
            return;
        }

        if (SetPixelFormat(hdc, pixel_format, &pfd) == FALSE) {
            MessageBox(nullptr, "SetPixelFormat failed", "Error", MB_OK);
            return;
        }

        // get the handle of the rendering context
        hrc = wglCreateContext(hdc);
        wglMakeCurrent(hdc, hrc);

    }

    void Context::destroy(const std::any hwnd) {
        wglMakeCurrent(nullptr, nullptr);
        ReleaseDC(std::any_cast<HWND>(hwnd), hdc);
        wglDeleteContext(hrc);
    }

}


