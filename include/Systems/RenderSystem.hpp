#pragma once
#include "Entities/Entity.hpp"
#include "Game/Window.hpp"
class RenderSystem
{
public:
	void draw(entt::registry& registry, sf::RenderWindow& m_window);
};

