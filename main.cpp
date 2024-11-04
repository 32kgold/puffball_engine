#include <iostream>

#include "modules/platform/window_manager.h"

int main() {

    engine::base::WindowManager window_manager;
    window_manager.init_window();

    bool is_running = true;

    while (is_running) {
        window_manager.update();
    }

    window_manager.destroy_window();

    return 0;
}
