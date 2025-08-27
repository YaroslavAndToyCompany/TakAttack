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
		if (!m_sprite.m_sprite.getTexture())
			std::cout << "Спрайт без текстури!\n";
		m_sprite.m_sprite.setPosition(transform.m_position);
		m_sprite.m_sprite.setScale(transform.m_scale);
		m_sprite.m_sprite.setRotation(transform.m_rotation);

		
		auto bounds = m_sprite.m_sprite.getGlobalBounds();
		std::cout << "Sprite bounds: " << bounds.left << ", " << bounds.top
			<< ", size: " << bounds.width << "x" << bounds.height << std::endl;
		window.Draw(m_sprite.m_sprite);
	}
}
