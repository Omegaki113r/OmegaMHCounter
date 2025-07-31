#pragma once

#include <raylib.h>

#include "container/container.hpp"
#include "label/label.hpp"

namespace Omega
{
    namespace Widget
    {
        struct Button
        {
            bool m_should_recalculate{true};
            Container m_container{};
            Label m_label{};
            
            Button() = default;
            Button& position(Vector2 position);
            Button& size(Vector2 size);
            Button& background_color(Color background_color);
            Button& text(const std::string& text);
            Button& font_size(int font_size);
            Button& foreground_color(Color foreground_color);
            
            void draw();
        };
    } // namespace Widget
} // namespace Omega
