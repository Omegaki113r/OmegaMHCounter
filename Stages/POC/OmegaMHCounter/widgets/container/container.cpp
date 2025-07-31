#include "container/container.hpp"

#include <raylib.h>

namespace Omega
{
    namespace Widget
    {
        Container& Container::position(Vector2 position)
        {
            m_position = position;
            return *this;
        }
        
        Container& Container::size(Vector2 size)
        {
            m_size = size;
            return *this;
        }
    
        Container& Container::color(Color color)
        {
            m_color = color;
            return *this;
        }
    
        void Container::draw() const
        {
            DrawRectangleV(m_position, m_size, m_color);
        }
    } // namespace Widget
} // namespace Omega
