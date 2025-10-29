#include "Systems/UISystem.hpp" 


void UISystem::DrawMainInterface(entt::registry& registry, Window& m_window, ResourceManager& resManager)
{
    auto view = registry.view<TagCastle, CastleUIComponent>();
    if (view.begin() != view.end()) {
        entt::entity castleEntity = view.front();
        auto& castleUi = view.get<CastleUIComponent>(castleEntity);

        if (castleUi.m_castleUIactive) {
            InterfaceSprite.setTexture(*resManager.GetResource<sf::Texture>("UpgradeInterface"));
            InterfaceSprite.setScale({ 0.08f, 0.08f });
            InterfaceSprite.setPosition({ 76.f, -80.f });
            sf::Color color = InterfaceSprite.getColor();
            color.a = 230; 
            InterfaceSprite.setColor(color);
            m_window.Draw(InterfaceSprite);
        }
    }
}
