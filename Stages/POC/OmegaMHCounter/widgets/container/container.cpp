#include "container/container.hpp"

#include <raylib.h>

namespace Omega
{
    namespace Widget
    {
        Container& Container::position(Vector2 in_position)
        {
            m_position = in_position;
            return *this;
        }
        
        Container& Container::size(Vector2 in_size)
        {
            m_size = in_size;
            return *this;
        }
    
        Container& Container::color(Color in_color)
        {
            m_color = in_color;
            return *this;
        }
    
        void Container::draw() const
        {
            DrawRectangleV(m_position, m_size, m_color);
        }
    } // namespace Widget
} // namespace Omega
