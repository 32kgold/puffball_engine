#pragma once
#include <any>

// the role of this class is to be a base that has functions to override for
// context creation and destruction. That includes context devices, pixel format

namespace engine::platform::base {

    class Context {
    public:
        virtual ~Context() = default;

        virtual void create(const std::any hwnd);
        virtual void destroy(const std::any hwnd);
    private:

    };

}
