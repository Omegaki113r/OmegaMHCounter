#pragma once

#include "raylib.h"

#include "base/base.hpp"

namespace Omega
{
    namespace Widget
    {
        struct Container : public Base
        {
            Color m_color {BLACK};
            
            Container() = default;
            Container& position(Vector2 in_position);
            Container& size(Vector2 in_size);
            Container& color(Color in_color);
            Container& on_hover(std::function<void(void)> on_pressed_handler) override{}
            Container& on_pressed(std::function<void(void)> on_pressed_handler) override{}
            
            inline void set_position(Vector2 in_position) { m_position = in_position; }
            inline void set_size(Vector2 in_size) { m_size = in_size; }
            inline void set_color(Color in_color) { m_color = in_color; }
            
            void draw() const;
        };
    } // namespace Widget
} // namespace Omega
