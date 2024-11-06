#pragma once

#include "base/context.h"
#include "base/headers.h"
#include "base/definitions.h"

// implementation of context functions and initializing device context and rendering context

namespace engine::win32 {

    class Context final : public platform::base::Context {
    public:
        void create(const std::any hwnd) override;
        void update() override;
        void destroy(const std::any hwnd) override;

        // Have to create dummy window just do get wgl functions to work
        // Deleted after because only one pixel format per window can be used
        void init_functions();
    private:
        HDC hdc   = 0;
        HGLRC hrc = 0;
    };

}
