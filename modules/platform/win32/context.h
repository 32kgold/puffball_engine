#pragma once

#include "base/context.h"
#include "base/window.h"

// implementation of context functions and initializing device contexts

namespace engine::win32 {

    class Context final : public platform::base::Context {
    public:
        void create(const std::any hwnd) override;

    private:
        HDC hdc   = 0;
        HGLRC hrc = 0;
    };

}
