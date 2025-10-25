#pragma once

#include <SFML/Graphics.hpp>

class IWidget {
public:
	virtual void SetPosition(const sf::Vector2f& pos) = 0;

	virtual void HandleEvents(sf::RenderWindow& window) = 0;
	virtual void Update(sf::RenderWindow& window) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
};
