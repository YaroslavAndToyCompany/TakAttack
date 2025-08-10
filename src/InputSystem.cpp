#include "InputSystem.h"

void InputSystem::Input(entt::registry& regsitry)
{
	auto view = regsitry.view<InputComponent>();
	for (auto entity : view) {
		auto& input = view.get<InputComponent>(entity);
		input.mousepressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
		if (input.mousepressed) {
			std::cout << "Left mouse button pressed!";
		}
	}
}
