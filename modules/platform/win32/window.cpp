#include "window.h"

namespace engine::win32 {

    void Window::create(const window::config& config) {

        if (!register_window_class(config.window_title)) {
            std::cerr << "Failed to register window class" << std::endl;
            return;
        }

        RECT frame {
            .right = config.width,
            .bottom = config.height,
        };

        AdjustWindowRectEx(&frame, 0, FALSE, WS_OVERLAPPED);

        if (!create_window(config)) {
            std::cerr << "Failed to create window." << std::endl;
            return;
        }

    }

    void Window::destroy() {
        DestroyWindow(hwnd);
        unregister_window_class();
    }

    void Window::show() {
        ShowWindow(hwnd, SW_SHOW);
        UpdateWindow(hwnd);
    }

    HWND Window::get_window_handle() {
        return hwnd;
    }

    bool Window::register_window_class(const char* window_title) {

        WNDCLASSEX wc;
        HINSTANCE h_instance = GetModuleHandle(nullptr);

        wc.style         = CS_VREDRAW | CS_HREDRAW | CS_OWNDC;
        wc.lpfnWndProc   = Events::window_process;
        wc.hInstance     = h_instance;
        wc.hCursor       = LoadCursor(nullptr, IDC_ARROW);
        wc.lpszClassName = window_title;

        atom = RegisterClassEx(&wc);

        if (!atom) {
            return false;
        }

        return true;
    }

    void Window::unregister_window_class() {
        UnregisterClass(MAKEINTATOM(atom), GetModuleHandleA(nullptr));
    }

    bool Window::create_window(const window::config& config) {

        hwnd = CreateWindowExA(0, MAKEINTATOM(atom), config.window_title,
                              WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT,
                              config.width, config.height,nullptr, nullptr,
                              GetModuleHandle(nullptr), nullptr);
        if (!hwnd) {
            return false;
        }

        return true;
    }
}
