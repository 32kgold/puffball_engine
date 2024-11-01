#include "window.h"

namespace engine::win32 {

    void Window::create(const window::config& config) {
        if (!register_window_class(config.window_title)) { return; }
        if (!create_window(config)) { return; }
    }

    void Window::destroy() {

    }

    void Window::show() {

    }

    bool Window::register_window_class(const char* window_title) {

        WNDCLASSEX wc;
        HINSTANCE h_instance = GetModuleHandleA(nullptr);

        wc.style         = 0;
        wc.lpfnWndProc   = static_cast<WNDPROC>(Events::window_process);
        wc.cbClsExtra    = 0;
        wc.cbWndExtra    = 0;
        wc.hInstance     = h_instance;
        wc.hIcon         = LoadIcon(h_instance, window_title);
        wc.hCursor       = LoadCursor(nullptr, IDC_ARROW);
        wc.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
        wc.lpszMenuName  = window_title;
        wc.lpszClassName = window_title;

        if (!RegisterClassEx(&wc)) {
            return false;
        }

        return true;
    }

    bool Window::create_window(const window::config& config) {

        hwnd = CreateWindowEx(0, config.window_title, config.window_title,
                              WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, config.width, config.height,
                              nullptr, nullptr, nullptr, nullptr);
        if (!hwnd) {
            return false;
        }

        ShowWindow(hwnd, SW_SHOWNA);
        UpdateWindow(hwnd);

        return true;
    }
}
