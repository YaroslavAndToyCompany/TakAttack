#pragma once
#include <SFML/Graphics.hpp>
#include "UI/Widgets/Button.hpp"

class ButtonDefault : public Button
{
public:
    ButtonDefault(ResourceManager& resManager);

    sf::Vector2f GetSize() override { return m_button.getSize(); }
    sf::FloatRect GetGlobalBounds() override { return m_button.getGlobalBounds(); }

    void SetSize(const sf::Vector2f& size) { return m_button.setSize(size); }
    void SetPosition(const sf::Vector2f& pos) override;

    void Draw(sf::RenderWindow& window) override;

private:
    sf::RectangleShape m_button;
};