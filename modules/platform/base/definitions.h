#pragma once

#define WGL_CONTEXT_MAJOR_VERSION_ARB             0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB             0x2092
#define WGL_CONTEXT_PROFILE_MASK_ARB              0x9126
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB          0x00000001

#define WGL_DRAW_TO_WINDOW_ARB                    0x2001
#define WGL_ACCELERATION_ARB                      0x2003
#define WGL_FULL_ACCELERATION_ARB                 0x2027
#define WGL_SUPPORT_OPENGL_ARB                    0x2010
#define WGL_DOUBLE_BUFFER_ARB                     0x2011
#define WGL_PIXEL_TYPE_ARB                        0x2013
#define WGL_TYPE_RGBA_ARB                         0x202B
#define WGL_COLOR_BITS_ARB                        0x2014
#define WGL_DEPTH_BITS_ARB                        0x2022
#define WGL_ACCUM_BITS_ARB                        0x201D
#define WGL_STENCIL_BITS_ARB                      0x2023

#define WGL_SAMPLE_BUFFERS_ARB                    0x2041
#define WGL_SAMPLES_ARB                           0x2042

namespace engine::win32 {

    using FUNCCREATECONTEXTATTRIBSARB = HGLRC(WINAPI*)(HDC, HGLRC, const int*);
    using FUNCCHOOSEPIXELFORMATARB = BOOL(WINAPI*)(HDC, const int*, const float*, unsigned int, int*, unsigned int*);

    inline FUNCCREATECONTEXTATTRIBSARB wglCreateContextAttribsARB;
    inline FUNCCHOOSEPIXELFORMATARB wglChoosePixelFormatARB;

}
