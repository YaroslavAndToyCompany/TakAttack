#include "UI/Widgets/Buttons/ButtonDefault.hpp"

ButtonDefault::ButtonDefault(ResourceManager& resManager)
    : Button(resManager)
{
    SetSize({ 60, 20 });
    m_button.setFillColor(sf::Color::White);
    m_button.setOutlineColor(sf::Color::Black);
    m_button.setOutlineThickness(4);
}

void ButtonDefault::SetPosition(const sf::Vector2f& pos)
{
    m_position = pos;
    m_button.setPosition(m_position);
    AlignTo(m_alignment);
}

void ButtonDefault::Draw(sf::RenderWindow& window)
{
    window.draw(m_button);
    m_label.Draw(window);
}
