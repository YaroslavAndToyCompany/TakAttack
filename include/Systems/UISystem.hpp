#pragma once
#include "InputSystem.hpp"
#include "Managers/ResourceManager.hpp"

class UISystem 
{
private:
	sf::Sprite InterfaceSprite;
public:
	void Draw(entt::registry& registry, Window& m_window, ResourceManager& resManager);
};
