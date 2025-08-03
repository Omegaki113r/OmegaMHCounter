#pragma once

#include <raylib.h>

#include "container/container.hpp"
#include "label/label.hpp"
#include "base/base.hpp"

namespace Omega
{
    namespace Widget
    {
        struct Button : public Base
        {
            bool m_should_recalculate{true};
            Container m_container{};
            Label m_label{};
            
            Button(){ active = true; }
            Button& position(Vector2 position);
            Button& size(Vector2 size);
            Button& background_color(Color background_color);
            Button& text(const std::string& text);
            Button& font_size(int font_size);
            Button& foreground_color(Color foreground_color);
            // i feel like there should be a way to handle this from the base class instead of here.. 
            Button& on_hover(std::function<void(void)> on_hover_handler) override;
            Button& on_pressed(std::function<void(void)> on_pressed_handler) override;
            
            void draw();
        };
    } // namespace Widget
} // namespace Omega
