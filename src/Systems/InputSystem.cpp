#include "Systems/InputSystem.hpp"

void InputSystem::Input(entt::registry& regsitry)
{
	auto view = regsitry.view<InputComponent>();
	for (auto entity : view) {
		auto& input = view.get<InputComponent>(entity);
		bool wasmousePressed = input.mousePressed;
		input.mousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	
			if (input.mousePressed && !wasmousePressed) {
				std::cout << "Left mouse button pressed!" << "\n";
			}
	}
}
