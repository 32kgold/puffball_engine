#pragma once

#include "win32/context.h"
#include "win32/window.h"

// main role of this class is to use factory to create the window
// also it should update and destroy the window

namespace engine::base {

    class WindowManager {
    public:
        void init_window();
        void update();
        void destroy_window();
    private:
        engine::win32::Window window;
        engine::win32::Context context;
        engine::win32::Events events;
    };

}
