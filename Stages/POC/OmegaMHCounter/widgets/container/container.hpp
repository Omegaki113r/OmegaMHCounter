#pragma once

#include "raylib.h"

namespace Omega
{
    namespace Widget
    {
        struct Container
        {
            Vector2 m_position {0.0f, 0.0f};
            Vector2 m_size {0.0f, 0.0f};
            Color m_color {BLACK};
            
            Container() = default;
            Container& position(Vector2 position);
            Container& size(Vector2 size);
            Container& color(Color color);
            
            void draw() const;
        };
    } // namespace Widget
} // namespace Omega
