#pragma once

#include "base/context.h"
#include "base/headers.h"
#include "base/definitions.h"

// implementation of context functions and initializing device context and rendering context

namespace engine::win32 {

    class Context final : public platform::base::Context {
    public:
        void create(const std::any hwnd) override;
        void destroy(const std::any hwnd) override;
    private:
        HDC hdc   = 0;
        HGLRC hrc = 0;
    };

}
