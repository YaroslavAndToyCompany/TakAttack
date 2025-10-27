#pragma once
#include "Entities/Entity.hpp"
#include "Systems/UISystem.hpp"
#include "Game/Window.hpp"
class RenderSystem
{
protected:
	UISystem m_interface;
public:
	void draw(entt::registry& registry, Window& m_window, ResourceManager& resmaneger);
};

