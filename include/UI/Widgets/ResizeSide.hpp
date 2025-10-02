#pragma once

#include <SFML/Graphics.hpp>
#include "Managers/CursorManager.hpp"

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

	void Update(const sf::FloatRect panelGlobalBounds);
	void Draw(sf::RenderWindow& window);
	
	void ChangeCursor(CursorManager& curManager, const sf::Vector2f& mousePos);

	void SetType(ResizeSideType type) { m_sideType = type; }
private:
	sf::RectangleShape m_side;
	ResizeSideType m_sideType;
};
