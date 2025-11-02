#pragma once
#include <SFML/Graphics.hpp>

class Circle : public sf::CircleShape
{
public:
    Circle();
    void SetOriginToCenter();

private:
};