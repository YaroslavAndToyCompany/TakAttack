#include "Systems/RenderSystem.hpp"
#include "Components/SpriteComponent.hpp"
void RenderSystem::draw(entt::registry& registry, sf::RenderWindow& m_window)
{
	auto View = registry.view<SpriteComponent>();
	for(auto entity : View) 
	{
		auto& m_sprite = View.get<SpriteComponent>(entity);
		m_window.draw(m_sprite.m_sprite);
	}
}
