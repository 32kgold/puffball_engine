#include "window.h"

namespace engine::win32 {

    void Window::create() {

    }

    void Window::destroy() {

    }

    void Window::show() {

    }

    WNDCLASS Window::register_window_class(const char* window_name) {

        WNDCLASSEX wc;

        HINSTANCE h_instance = GetModuleHandleA(nullptr);

        wc.style = 0;
        wc.lpfnWndProc   = static_cast<WNDPROC>(WindowProc);
        wc.cbClsExtra    = 0;
        wc.cbWndExtra    = 0;
        wc.hInstance     = h_instance;
        wc.hIcon         = LoadIcon(h_instance, window_name);
        wc.hCursor       = LoadCursor(nullptr, IDC_ARROW);
        wc.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
        wc.lpszMenuName  = window_name;
        wc.lpszClassName = window_name;

        return wc;
    }

    LRESULT Window::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)  {

    }

}
