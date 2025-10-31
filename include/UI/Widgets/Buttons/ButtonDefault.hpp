#pragma once
#include <SFML/Graphics.hpp>
#include "UI/Widgets/Button.hpp"

class ButtonDefault : public Button
{
public:
    ButtonDefault(ResourceManager& resManager);
    void AlignTo(Alignment alignment) override;

    sf::Vector2f GetSize() override;
    sf::FloatRect GetGlobalBounds() override { return m_button.getGlobalBounds(); }
    sf::FloatRect GetLocalBounds() override { return m_button.getLocalBounds(); }

    void SetSize(const sf::Vector2f& size);
    void SetPosition(const sf::Vector2f& pos) override;
    void SetOrigin(const sf::Vector2f& newOrigin) override;
    
    void Draw(sf::RenderWindow& window) override;

private:
    sf::RectangleShape m_button;
    sf::RectangleShape m_buttonCanvas;

    Circle m_origiButtonnCanvas;
};