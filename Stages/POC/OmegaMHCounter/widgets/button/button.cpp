#include "button/button.hpp"

namespace Omega
{
    namespace Widget
    {
        Button& Button::position(Vector2 position)
        {
            m_position = position;
            m_container.set_position(position);
            m_should_recalculate = true;
            return *this;
        }
        Button& Button::size(Vector2 size)
        {
            m_size = size;
            m_container.set_size(size);
            m_should_recalculate = true;
            return *this;
        }
        Button& Button::background_color(Color background_color)
        {
            m_container.set_color(background_color);
            return  *this;
        }
        Button& Button::text(const std::string& text)
        {
            m_label.m_text = text;
            m_should_recalculate = true;
            return *this;
        }
        Button& Button::font_size(int font_size)
        {
            m_label.m_font_size = font_size;
            m_should_recalculate = true;
            return *this;
        }
        Button& Button::foreground_color(Color foreground_color)
        {
            m_label.m_color = foreground_color;
            return *this;
        }
        Button& Button::on_pressed(std::function<void(void)> on_pressed_handler)
        {
            m_on_pressed_handler = on_pressed_handler;
            return *this;
        }
        Button& Button::on_hover(std::function<void(void)> on_hover_handler)
        {
            m_on_hover_handler = on_hover_handler;
            return *this;
        }
        void Button::draw()
        {
            if(m_should_recalculate)
            {
                const auto measured_text_width{::MeasureText(m_label.m_text.c_str(), m_label.m_font_size)};
                m_label.m_position = { m_container.m_position.x + m_container.m_size.x / 2 - measured_text_width/2, m_container.m_position.y + m_container.m_size.y / 2 - m_label.m_font_size/2 };
                m_should_recalculate = false;
            }
            m_container.draw();
            m_label.draw();
        }
    } // namespace Widget
} // namespace Omega
