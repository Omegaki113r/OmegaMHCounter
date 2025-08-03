#include "input/input.hpp"

#include <vector>

#include "base/base.hpp"

namespace Omega
{
    namespace Widget
    {
        namespace Input
        {
            void process(std::vector<Base*> widgets)
            {
                const auto mouse_left_released{IsMouseButtonReleased(MOUSE_LEFT_BUTTON)};
                const auto mouse_left_not_pressed{IsMouseButtonUp(MOUSE_LEFT_BUTTON)};
                const auto mouse_position{GetMousePosition()};
                for(auto widget : widgets)
                {
                    const Rectangle widget_rect{ widget->m_position.x, widget->m_position.y, widget->m_size.x, widget->m_size.y };
                    const auto is_inside{CheckCollisionPointRec(mouse_position, widget_rect)};
                    if(mouse_left_released && is_inside)
                    {
                        if(nullptr != widget->m_on_pressed_handler && widget->active)
                        {
                            widget->m_on_pressed_handler();
                        }
                    }else if(mouse_left_not_pressed && is_inside)
                    {
                        if(nullptr != widget->m_on_hover_handler && widget->active)
                        {
                            widget->m_on_hover_handler();
                        }
                    }
                }
            }
        } // namespace Input
    } // namespace Widget
} // namespace Omega
