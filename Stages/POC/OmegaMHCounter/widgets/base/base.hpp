#pragma once

#include <functional>

#include <raylib.h>

namespace Omega
{
    namespace Widget
    {
        struct Base
        {
            bool active{false};
            Vector2 m_position{0.0f, 0.0f};
            Vector2 m_size{0.0f, 0.0f};
            
            std::function<void(void)> m_on_hover_handler;
            std::function<void(void)> m_on_pressed_handler;
            
            virtual Base& on_hover(std::function<void(void)> on_hover_handler) = 0;
            virtual Base& on_pressed(std::function<void(void)> on_pressed_handler) = 0;
        };
    } // namespace Widget
} // namespace Omega
