#pragma once
#include "UI/Widgets/Button.hpp"

class ButtonSprite : public Button
{
public:
    ButtonSprite(ResourceManager& resManager, const std::string& textureName);

    sf::Vector2f GetSize() override;
    sf::FloatRect GetGlobalBounds() override { return m_button.getGlobalBounds(); }
    sf::FloatRect GetLocalBounds() override { return m_button.getLocalBounds(); }
    sf::Sprite GetSprite() { return m_button; }

    void SetScale(const sf::Vector2f& scale) { m_button.setScale(scale); AlignTo(m_alignment); }
    void SetPosition(const sf::Vector2f& pos) override;
    void SetOrigin(const sf::Vector2f& newOrigin) override { m_button.setOrigin(newOrigin); }

    void Draw(sf::RenderWindow& window) override;

private:
    sf::Sprite m_button;
};