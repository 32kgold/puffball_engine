#pragma once

#include "base/window.h"

// this file is the implementation for windows platform using base window.h functions

namespace engine::win32 {

    class Window final : public platform::base::Window {
    public:
        void create() override;
        void destroy() override;
        void show() override;

    private:

        WNDCLASS register_window_class(const char* window_name);
        LONG_PTR WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

        ATOM atom;
        HWND hwnd;
    };

}