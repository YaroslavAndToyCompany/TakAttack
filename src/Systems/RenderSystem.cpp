#include "Systems/RenderSystem.hpp"
#include "Components/SpriteComponent.hpp"
#include "Components/TransformComponent.hpp"
void RenderSystem::draw(entt::registry& registry, Window& window, ResourceManager& resmaneger)
{
	auto View = registry.view<SpriteComponent, TransformComponent, CastleUIComponent>();

	for(auto entity : View) 
	{
		auto& m_sprite = View.get<SpriteComponent>(entity);
		auto& transform = View.get<TransformComponent>(entity);
		if (!m_sprite.m_sprite.getTexture())
			std::cout << "Sprite without texture!!!\n";
		m_sprite.m_sprite.setPosition(transform.m_position);
		m_sprite.m_sprite.setScale(transform.m_scale);
		m_sprite.m_sprite.setRotation(transform.m_rotation);
		window.Draw(m_sprite.m_sprite);
		m_interface.DrawMainInterface(registry, window, resmaneger);
	}
}
