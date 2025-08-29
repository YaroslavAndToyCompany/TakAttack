#pragma once
#include "SFML/Graphics.hpp"
enum class CellType
{
	Empty,
	TowerPlaceAble,
	Castle,
	Blocked,
};

struct GridCell
{
	sf::FloatRect bounds;
	CellType type;
	int gridX, gridY;
};