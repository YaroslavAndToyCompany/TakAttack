#include "Utils/Widgets.hpp"

sf::Vector2f SetRectOriginToCenter(const sf::FloatRect& rect)
{
    return { rect.left + (rect.width / 2.0f), rect.top + (rect.height / 2.0f) };
}