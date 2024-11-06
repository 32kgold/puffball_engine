#pragma once

#include "base/window.h"
#include "window/config.h"
#include "events.h"
#include "base/headers.h"

// this file is the implementation for windows platform using base window.h functions

namespace engine::win32 {

    class Window final : public platform::base::Window {
    public:
        void create(const window::config& config) override;
        void destroy() override;
        void show() override;

        HWND get_window_handle();

    private:

        bool register_window_class(const char* window_title);
        void unregister_window_class();

        bool create_window(const window::config& config);

        static bool should_close;

        ATOM atom = 0;
        HWND hwnd = 0;
    };

}