#pragma once

#include "Entities/Entity.hpp"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Game/Window.hpp"
#include "Components/CastleUIComponent.hpp"
#include "Game/Map.hpp"
class InputSystem
{
public:
	void Input(entt::registry& registry, Window& m_window, Map& m_map);
};

