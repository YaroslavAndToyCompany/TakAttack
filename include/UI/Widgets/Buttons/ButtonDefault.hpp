#pragma once
#include <SFML/Graphics.hpp>
#include "UI/Widgets/Button.hpp"

class ButtonDefault : public Button
{
public:
    ButtonDefault(ResourceManager& resManager);

    sf::Vector2f GetSize() override { return m_button.getSize(); }
    sf::FloatRect GetGlobalBounds() override { return m_button.getGlobalBounds(); }
    sf::FloatRect GetLocalBounds() override { return m_button.getLocalBounds(); }

    void SetSize(const sf::Vector2f& size) { m_button.setSize(size); AlignTo(m_alignment); }
    void SetPosition(const sf::Vector2f& pos) override;
    void SetOrigin(const sf::Vector2f& newOrigin) override { m_button.setOrigin(newOrigin); }

    void Draw(sf::RenderWindow& window) override;

private:
    sf::RectangleShape m_button;
};