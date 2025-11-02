#include "Systems/InputSystem.hpp"

void InputSystem::Input(entt::registry& registry, Window& m_window, Map& m_map)
{
	registry.view<InputComponent, CastleUIComponent>().each(
		[&](auto entity, InputComponent& input, CastleUIComponent& castleUI)
		{
		for (auto& CurrentButton : input.ButtonList)
		{
			if (sf::Mouse::isButtonPressed(CurrentButton) && CurrentButton == sf::Mouse::Left)
			{
				std::cout << "Left mouse button pressed!" << "\n";
				sf::Vector2i pixelPos = sf::Mouse::getPosition(*m_window.GetRenderWindowPtr());
				sf::Vector2f worldPos = m_window.MapPixelToCoords(pixelPos, false); 
				std::cout << "Mouse world pos: (" << worldPos.x << ", " << worldPos.y << ")\n";

				GridCell* clickedCell = m_map.GetCellPosition(worldPos);

				if (clickedCell && clickedCell->type == CellType::Castle)
				{
					std::cout << "Castle cell clicked at (" << clickedCell->gridX << ", " << clickedCell->gridY << ")\n";
					castleUI.m_castleUIactive = true;
				}
			}
		}

		for(auto& CurrentKey : input.KeyList) 
		{
		if(sf::Keyboard::isKeyPressed(CurrentKey) && CurrentKey == sf::Keyboard::Escape)
		{
			std::cout << "KEY PRESSED";
			castleUI.m_castleUIactive = false;
		}
		}
	}
	);
}
