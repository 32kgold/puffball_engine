#include "events.h"

namespace engine::win32 {

    LRESULT Events::window_process(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

        switch (uMsg) {
            case WM_CLOSE:
                PostQuitMessage (0);
                Window::should_close = true;
                break;
            case WM_SIZE:
                return 0;
            case WM_ERASEBKGND:
                return 1;
            case WM_SYSCOMMAND:
            {
                switch (wParam)
                {
                    case SC_SCREENSAVE:
                    case SC_MONITORPOWER:
                    {
                        return 0;
                    }
                    default:
                        break;
                }
            }
            default:
                return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }

        return 0;
    }

    void Events::update() {

        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (GetMessage(&msg, NULL, 0, 0)) {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        };
    }
}


