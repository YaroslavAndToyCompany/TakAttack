#include "Utils/Widgets.hpp"

sf::Vector2f SetRectOriginToCenter(const sf::FloatRect& textRect)
{
    return { textRect.left + (textRect.width / 2.0f), textRect.top + (textRect.height / 2.0f) };
}