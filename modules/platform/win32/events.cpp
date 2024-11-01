#include "events.h"

namespace engine::win32 {

    LRESULT Events::window_process(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        LRESULT result = 1;

        switch (uMsg) {
            case WM_CREATE:

                break;
            default: break;
        }

        return result;
    }

}


