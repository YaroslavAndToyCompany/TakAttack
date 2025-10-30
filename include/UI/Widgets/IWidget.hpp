#pragma once

#include <SFML/Graphics.hpp>

class IWidget {
public:
	virtual sf::Vector2f GetPosition() = 0;
	virtual sf::Vector2f GetSize() = 0;
	virtual sf::FloatRect GetGlobalBounds() = 0;

	virtual void SetPosition(const sf::Vector2f& pos) = 0;

	virtual void HandleEvents(const sf::Event& event, sf::RenderWindow& window) = 0;
	virtual void Update(sf::RenderWindow& window) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
};
