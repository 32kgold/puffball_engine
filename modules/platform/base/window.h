#pragma once

#include "headers.h"
#include <window/config.h>

namespace engine::platform::base {

    class Window {
    public:
        virtual ~Window() = default;

        virtual void create(const window::config& config) = 0;
        virtual void destroy() = 0;
        virtual void show() = 0;

    private:

    };

}
