#include "Systems/InputSystem.hpp"
#include "Components/CastleUIComponent.hpp"
void InputSystem::Input(entt::registry& regsitry, Window& m_window, Map& m_map)
{
	auto view = regsitry.view<InputComponent, CastleUIComponent>();
	
	for (auto entity : view) {
		auto& input = view.get<InputComponent>(entity);
		auto& castleUi = view.get<CastleUIComponent>(entity);
		bool wasmousePressed = input.mousePressed;
		input.mousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

		if (input.mousePressed && !wasmousePressed) {
            std::cout << "Left mouse button pressed!" << "\n";
			sf::Vector2i pixelPos = sf::Mouse::getPosition(*m_window.GetRenderWindowPtr());
			sf::Vector2f worldPos = m_window.MapPixelToCoords(pixelPos, false); //ui = false
			std::cout << "Mouse world pos: (" << worldPos.x << ", " << worldPos.y << ")\n";

			GridCell* clickedCell = m_map.GetCellPosition(worldPos);
			
			if (clickedCell && clickedCell->type == CellType::Castle) {
				std::cout << "Castle cell clicked at (" << clickedCell->gridX << ", " << clickedCell->gridY << ")\n";
				castleUi.m_castleUIactive = true;
				if(castleUi.m_castleUIactive) 
				{
					std::cout << "CASTLE UI VISIABLE!!!!!!!" << std::endl;
				}
			}
			else 
			{
				castleUi.m_castleUIactive = false;
			}
		}
	}
}