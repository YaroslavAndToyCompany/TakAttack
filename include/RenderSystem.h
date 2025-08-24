#pragma once
#include "Entity.h"
#include "Window.h"
class RenderSystem
{
public:
	void draw(entt::registry& registry, sf::RenderWindow& m_window);
};

