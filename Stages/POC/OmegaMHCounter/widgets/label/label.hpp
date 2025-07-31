#pragma once

#include <string>

#include "raylib.h"

namespace Omega
{
    namespace Widget
    {
        struct Label
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
            
            void measure();
            Vector2 get_measured_size();
            
            void draw();
            
        private:
            bool should_remeasure{true};
            Vector2 measured_size{0,0};
        };
    } // namespace Widget
} // namespace Omega
