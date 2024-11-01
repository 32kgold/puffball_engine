#pragma once
#include <base/headers.h>

// should have a base class for linux to use as well
// processes events

namespace engine::win32 {

    class Events {
    public:
        static LRESULT WINAPI window_process(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    private:

    };

}
