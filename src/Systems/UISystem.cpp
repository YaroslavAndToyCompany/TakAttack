#include "Systems/UISystem.hpp" 

void UISystem::Draw(entt::registry& registry, Window& m_window, ResourceManager& resManager)
{
	auto view = registry.view<InputComponent, CastleUIComponent>();
	InterfaceSprite.setTexture(*resManager.GetResource<sf::Texture>("UpgradeInterface"));
	InterfaceSprite.setScale(sf::Vector2f(0.08f, 0.08f));
	InterfaceSprite.setPosition(sf::Vector2f(76.0f, -80.0f));
	sf::Color m_transpency = InterfaceSprite.getColor();
	m_transpency.a = 230;
	InterfaceSprite.setColor(m_transpency);
	for(auto entity : view) 
	{
		auto& castleUi = view.get<CastleUIComponent>(entity);
		auto& input = view.get<InputComponent>(entity);
		if (castleUi.m_castleUIactive == true) {
			m_window.Draw(InterfaceSprite);
		
	}
	
	}
}
