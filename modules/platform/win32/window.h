#pragma once

#include "base/window.h"
#include "events.h"

#include "../graphics/glad/glad.h"

// this file is the implementation for windows platform using base window.h functions

namespace engine::win32 {

    class Window final : public platform::base::Window {
    public:
        void create(const window::config& config) override;
        void destroy() override;
        void show() override;

    private:

        bool register_window_class(const char* window_title);
        void unregister_window_class();

        bool create_window(const window::config& config);

        ATOM atom = 0;
        HWND hwnd = 0;
    };

}