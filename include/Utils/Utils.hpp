#pragma once
#include <SFML/Graphics.hpp>

namespace utils
{
    sf::Vector2f ConvertMousePixelsToCoords(int mouseX, int mouseY, sf::RenderWindow& window);
    sf::Vector2f ConvertMousePixelsToCoords(float mouseX, float mouseY, sf::RenderWindow& window);
}