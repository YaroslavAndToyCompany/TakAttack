#pragma once

#include <SFML/Graphics.hpp>

class Widget {
	virtual void HandleEvents(sf::RenderWindow& window) = 0;
	virtual void Update(sf::RenderWindow& window) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
};
