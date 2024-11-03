#include "events.h"

namespace engine::win32 {

    LRESULT Events::window_process(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        LRESULT result = 1;

        switch (uMsg) {
            case WM_DESTROY:
                PostQuitMessage (0);
                break;
            default:
                result = DefWindowProc(hwnd, uMsg, wParam, lParam);
                break;
        }

        return result;
    }

    void Events::update() {

        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (GetMessage(&msg, NULL, 0, 0)) {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
            else {
                return;
            }
        };
    }
}


