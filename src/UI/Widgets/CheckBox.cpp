#include <UI/Widgets/CheckBox.hpp>
#include "Utils/Widgets.hpp"

CheckBox::CheckBox(ResourceManager& resManager, bool state, const std::string& text) 
{
    m_outerBox.setSize({ 50, 50 });
    m_innerBox.setSize({ 30, 30 });

    m_outerBox.setFillColor(sf::Color::Black);
    m_innerBox.setFillColor(sf::Color::White);
       
    m_text.setFont(*resManager.GetResource<sf::Font>("BoldPixels"));
    m_text.setString(text);
    m_text.setFillColor(sf::Color::Black);
    m_text.setCharacterSize(28);
    m_text.setPosition({20, m_text.getPosition().y});

    m_outerBox.setOrigin(CalcRectOriginCenter(m_outerBox.getLocalBounds()));
    m_innerBox.setOrigin(CalcRectOriginCenter(m_innerBox.getLocalBounds()));
    m_text.setOrigin(CalcRectOriginCenter(m_text.getLocalBounds()));
}

void CheckBox::SetPosition(const sf::Vector2f& pos) 
{
    m_position = pos;

    m_outerBox.setPosition(m_position);
    m_innerBox.setPosition(m_position);
    m_text.setPosition({m_position.x + 60, m_position.y});
}

void CheckBox::HandleEvents(sf::RenderWindow& window) {}
void CheckBox::Update(sf::RenderWindow& window) {}

void CheckBox::Draw(sf::RenderWindow& window)
{
    window.draw(m_outerBox);
    window.draw(m_innerBox);
    window.draw(m_text);
}
