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
            WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
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
            std::cerr << "wglChoosePixelFormatARB failed" << std::endl;
            return;
        }

        PIXELFORMATDESCRIPTOR pfd = {
            .nSize = sizeof(pfd)
        };

        if (DescribePixelFormat(hdc, formats, sizeof(pfd), &pfd) == FALSE) {
            std::cerr << "Failed to describe OpenGL pixel format" << std::endl;
            return;
        }

        if (SetPixelFormat(hdc, pixel_format, &pfd) == FALSE) {
            std::cerr << "Failed to set pixel format" << std::endl;
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
            std::cerr << "wglCreateContextAttribsARB failed" << std::endl;
        }

        wglMakeCurrent(hdc, hrc);

    }

    void Context::update() {
        SwapBuffers(hdc);
    }

    void Context::destroy(const std::any hwnd) {
        wglMakeCurrent(nullptr, nullptr);
        ReleaseDC(std::any_cast<HWND>(hwnd), hdc);
        wglDeleteContext(hrc);
    }

    void Context::init_functions() {

        WNDCLASSEX wc = {
            .cbSize = sizeof(WNDCLASSEX),
            .lpfnWndProc = DefWindowProcA,
            .hInstance = GetModuleHandle(nullptr),
            .lpszClassName = "dummy"
        };

        if (!RegisterClassEx(&wc)) {
            std::cerr << "Dummy RegisterClassEx failed" << std::endl;
            return;
        }

        HWND dummy_window = CreateWindowExA(0, wc.lpszClassName, "dummy win",
                              0, CW_USEDEFAULT, CW_USEDEFAULT,
                              CW_USEDEFAULT, CW_USEDEFAULT,nullptr, nullptr,
                              GetModuleHandle(nullptr), nullptr);

        if (!dummy_window) {
            std::cerr << "Dummy CreateWindowExA failed" << std::endl;
        }

        HDC hdc = GetDC(dummy_window);

        PIXELFORMATDESCRIPTOR pfd = {
            .nSize = sizeof(pfd),
            .nVersion = 1,
            .dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
            .iPixelType = PFD_TYPE_RGBA,
            .cColorBits = 24,
            .cDepthBits = 24,
            .cStencilBits = 8,
            .iLayerType = PFD_MAIN_PLANE,
        };

        int pixel_format = ChoosePixelFormat(hdc, &pfd);
        if (!pixel_format) {
            std::cerr << "Dummy ChoosePixelFormat failed" << std::endl;
        }

        if (!SetPixelFormat(hdc, pixel_format, &pfd)) {
            std::cerr << "Dummy SetPixelFormat failed" << std::endl;
        }

        HGLRC hrc = wglCreateContext(hdc);
        if (!hrc) {
            std::cerr << "Dummy wglCreateContext failed" << std::endl;
        }

        wglMakeCurrent(hdc, hrc);

        wglCreateContextAttribsARB = reinterpret_cast<FUNCCREATECONTEXTATTRIBSARB>(wglGetProcAddress("wglCreateContextAttribsARB"));
        wglChoosePixelFormatARB = reinterpret_cast<FUNCCHOOSEPIXELFORMATARB>(wglGetProcAddress("wglChoosePixelFormatARB"));

        wglMakeCurrent(hdc, nullptr);
        wglDeleteContext(hrc);
        ReleaseDC(dummy_window, hdc);
        DestroyWindow(dummy_window);
    }
}


