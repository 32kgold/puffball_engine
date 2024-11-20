#include <iostream>

#include "modules/platform/window_manager.h"

int main() {

    engine::base::WindowManager window_manager;
    window_manager.init_window();

    while (!engine::win32::Window::should_close) {
        window_manager.update();
    }

    window_manager.destroy_window();

    return 0;
}
