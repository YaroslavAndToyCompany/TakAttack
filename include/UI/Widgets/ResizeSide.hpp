#pragma once

#include <SFML/Graphics.hpp>

class ResizeSide
{
public:
	enum class ResizeSideType
	{
		Top, Bottom, Left, Right, Count
	};

	ResizeSide(const sf::Vector2f& size, ResizeSideType sideType);

	sf::RectangleShape GetSideRecShape() { return m_side; }
	ResizeSideType GetType() { return m_sideType; }

	void SetType(ResizeSideType type) { m_sideType = type; }
	
	void Update(const sf::FloatRect panelGlobalBounds);
	void Draw(sf::RenderWindow& window);
private:
	sf::RectangleShape m_side;
	ResizeSideType m_sideType;
};
