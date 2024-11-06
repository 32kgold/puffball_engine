#include "window_manager.h"

#include <iostream>

namespace engine::base {

    void WindowManager::init_window() {

        engine::window::config config = {
            .window_title = "game",
            .width = 800,
            .height = 600,
        };

        window.create(config);
        window.show();

        context.init_functions();
        context.create(window.get_window_handle());
    }

    void WindowManager::update() {
        events.update();
        context.update();
    }

    void WindowManager::destroy_window() {
        window.destroy();
        context.destroy(window.get_window_handle());
    }
}


