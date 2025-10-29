#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
struct InputComponent
{
public:
	std::vector<sf::Keyboard::Key> KeyList
	{sf::Keyboard::Escape};
	std::vector<sf::Mouse::Button> ButtonList
	{sf::Mouse::Button::Left};
	float mouseX = 0.0f;
	float mouseY = 0.0f;
};

