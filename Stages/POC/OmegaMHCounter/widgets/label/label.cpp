#include "label/label.hpp"

#include <string>

#include <raylib.h>

namespace Omega
{
    namespace Widget
    {
        Label& Label::text(const std::string& text)
        {
            m_text = text;
            should_remeasure = true;
            return *this;
        }
        Label& Label::position(Vector2 position)
        {
            m_position = position;
            should_remeasure = true;
            return  *this;
        }
        Label& Label::color(Color color)
        {
            m_color = color;
            return *this;
        }
        Label& Label::font_size(int font_size)
        {
            m_font_size = font_size;
            should_remeasure = true;
            return *this;
        }
        void Label::draw()
        {
            if(should_remeasure)
            {
                measure();
                should_remeasure = false;
            }
            DrawText(m_text.c_str(), m_position.x, m_position.y, m_font_size, m_color);
        }
    
        void Label::measure()
        {
            measured_size = {(float)::MeasureText(m_text.c_str(), m_font_size), (float)m_font_size};
        }
    
        Vector2 Label::get_measured_size()
        {
            if(should_remeasure)
            {
                measure();
            }
            return measured_size;
        }
    } // namespace Widget
} // namespace Omega
