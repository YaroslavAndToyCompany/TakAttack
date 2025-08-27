#include "Systems/RenderSystem.hpp"
#include "Components/SpriteComponent.hpp"
#include "Components/TransformComponent.hpp"
void RenderSystem::draw(entt::registry& registry, Window& window)
{
	auto View = registry.view<SpriteComponent, TransformComponent>();

	for(auto entity : View) 
	{
		auto& m_sprite = View.get<SpriteComponent>(entity);
		auto& transform = View.get<TransformComponent>(entity);
		m_sprite.m_sprite.setPosition(transform.m_position);
		window.Draw(m_sprite.m_sprite);
	}
}
