#include "InputSystem.h"

void InputSystem::Input(entt::registry& regsitry)
{
	auto view = regsitry.view<InputComponent>();
	for (auto entity : view) {
		auto& input = view.get<InputComponent>(entity);
		input.mousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
		if (input.mousePressed) {
			std::cout << "Left mouse button pressed!";
		}
	}
}
