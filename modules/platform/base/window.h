#pragma once
#include "headers.h"

namespace engine::platform::base {

    class Window {
    public:
        virtual ~Window() = default;

        virtual void create() = 0;
        virtual void destroy() = 0;
        virtual void show() = 0;
    private:

    };

}
