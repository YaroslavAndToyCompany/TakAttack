#include <UI/Widgets/CheckBox.hpp>
#include "Utils/Widgets.hpp"

CheckBox::CheckBox(ResourceManager& resManager, bool state, const std::string& text)
    : m_label(resManager)
{
    m_outerBox.setSize({ CHECKBOX_SIZE, CHECKBOX_SIZE });
    m_innerBox.setSize({ CHECKBOX_SIZE / 2.0f, CHECKBOX_SIZE / 2.0f });

    m_outerBox.setFillColor(sf::Color::Black);
    m_innerBox.setFillColor(sf::Color::White);
       
    m_label.SetFont("BoldPixels");
    m_label.AddText(text);
    m_label.SetPosition({20, m_label.GetPosition().y});

    m_outerBox.setOrigin(CalcRectOriginCenter(m_outerBox.getLocalBounds()));
    m_innerBox.setOrigin(CalcRectOriginCenter(m_innerBox.getLocalBounds()));
    m_label.AlignTextToLeft();
}

void CheckBox::SetPosition(const sf::Vector2f& pos) 
{
    m_position = pos;

    m_outerBox.setPosition(m_position);
    m_innerBox.setPosition(m_position);
    m_label.SetPosition({m_position.x + 30, m_position.y});
}

void CheckBox::HandleEvents(sf::RenderWindow& window) {}
void CheckBox::Update(sf::RenderWindow& window) {}

void CheckBox::Draw(sf::RenderWindow& window)
{
    window.draw(m_outerBox);
    window.draw(m_innerBox);
    m_label.Draw(window);
}
