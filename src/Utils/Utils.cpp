#include "Utils/Utils.hpp"

namespace utils
{
    sf::Vector2f ConvertMousePixelsToCoords(int mouseX, int mouseY, sf::RenderWindow& window)
    {
        sf::Vector2i mousePos = sf::Vector2i(mouseX, mouseY);
        return window.mapPixelToCoords(mousePos);
    }
    sf::Vector2f ConvertMousePixelsToCoords(float mouseX, float mouseY, sf::RenderWindow& window)
    {
        sf::Vector2i mousePos = sf::Vector2i(static_cast<int>(mouseX), static_cast<int>(mouseY));
        return window.mapPixelToCoords(static_cast<sf::Vector2i>(mousePos));
    }
    sf::Vector2f ConvertMousePixelsToCoords(const sf::Vector2i& mousePos, sf::RenderWindow& window)
    {
        return window.mapPixelToCoords(mousePos);
    }
}