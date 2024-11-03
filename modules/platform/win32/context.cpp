#include "context.h"

namespace engine::win32 {

    void Context::create(const std::any hwnd) {

        // get the handle of window device context
        hdc = GetDC(std::any_cast<HWND>(hwnd));

        static int visual_attribs[] =
        {
            WGL_DRAW_TO_WINDOW_ARB, 1,
            WGL_SUPPORT_OPENGL_ARB, 1,
            WGL_DOUBLE_BUFFER_ARB, 1,
            WGL_FULL_ACCELERATION_ARB, 1,
            WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
            WGL_COLOR_BITS_ARB, 24,
            WGL_DEPTH_BITS_ARB, 24,
            WGL_STENCIL_BITS_ARB, 8,
            WGL_ACCUM_BITS_ARB, 0, // if needed 32
            WGL_SAMPLE_BUFFERS_ARB, 1, // sampling on
            WGL_SAMPLES_ARB, 4, // 4x MSAA
            0
        };

        int pixel_format = 0;
        unsigned int formats = 0;
        if (!wglChoosePixelFormatARB(hdc, visual_attribs, nullptr, 1, &pixel_format, &formats) || formats == 0) {
            MessageBox(nullptr, "ChoosePixelFormatARB failed", "Error", MB_OK);
            return;
        }

        PIXELFORMATDESCRIPTOR pfd = {
            .nSize = sizeof(pfd)
        };

        if (DescribePixelFormat(hdc, formats, sizeof(pfd), &pfd) == FALSE) {
            MessageBox(nullptr, "Failed to describe OpenGL pixel format", "Error", MB_OK);
            return;
        }

        if (SetPixelFormat(hdc, pixel_format, &pfd) == FALSE) {
            MessageBox(nullptr, "SetPixelFormat failed", "Error", MB_OK);
            return;
        }

        static int attrib[] = {
            // OpenGL 4.6
            WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
            WGL_CONTEXT_MINOR_VERSION_ARB, 6,
            WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
            0
        };

        // get the handle of the rendering context
        hrc = wglCreateContextAttribsARB(hdc, nullptr, attrib);

        if (!hrc) {
            MessageBox(nullptr, "Failed to create OpenGL context", "Error", MB_OK);
        }

        wglMakeCurrent(hdc, hrc);

    }

    void Context::destroy(const std::any hwnd) {
        wglMakeCurrent(nullptr, nullptr);
        ReleaseDC(std::any_cast<HWND>(hwnd), hdc);
        wglDeleteContext(hrc);
    }

}


