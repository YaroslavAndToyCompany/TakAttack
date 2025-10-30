#pragma once
#include "UI/Widgets/Button.hpp"

class ButtonSprite : public Button
{
public:
    ButtonSprite(ResourceManager& resManager, const std::string& textureName);

    sf::Vector2f GetSize() override;
    sf::FloatRect GetGlobalBounds() override { return m_button.getGlobalBounds(); }
    sf::Sprite GetSprite() { return m_button; }

    void SetScale(const sf::Vector2f& scale) { m_button.setScale(scale); }
    void SetPosition(const sf::Vector2f& pos) override;

    void Draw(sf::RenderWindow& window) override;

private:
    sf::Sprite m_button;
};