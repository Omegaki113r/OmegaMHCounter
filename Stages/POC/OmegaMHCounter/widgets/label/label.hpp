#pragma once

#include <string>

#include "raylib.h"

#include "base/base.hpp"

namespace Omega
{
    namespace Widget
    {
        struct Label : public Base
        {
            std::string m_text{""};
            Vector2 m_position{0.0f,0.0f};
            Color m_color{BLACK};
            int m_font_size{8};
            
            Label() = default;
            Label& text(const std::string& text);
            Label& position(Vector2 position);
            Label& color(Color color);
            Label& font_size(int font_size);
            Label& on_hover(std::function<void(void)> on_hover_handler) override { return *this; }
            Label& on_pressed(std::function<void(void)> on_pressed_handler) override{ return *this; }
            
            void measure();
            Vector2 get_measured_size();
            
            void draw();
            
        private:
            bool should_remeasure{true};
            Vector2 measured_size{0,0};
        };
    } // namespace Widget
} // namespace Omega
