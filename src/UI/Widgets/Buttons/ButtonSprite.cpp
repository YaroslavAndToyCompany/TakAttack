#include "UI/Widgets/Buttons/ButtonSprite.hpp"
#include "Utils/Widgets.hpp"
#include "Debug/Debug.hpp"

ButtonSprite::ButtonSprite(ResourceManager& resManager, const std::string& textureName)
    : Button(resManager)
{
    m_button.setTexture(*m_resManager.GetResource<sf::Texture>(textureName));
    testPoint.setRadius(5);
}

sf::Vector2f ButtonSprite::GetSize()
{
    sf::Vector2f buttonSize = { m_button.getLocalBounds().width, m_button.getLocalBounds().height };
    return { buttonSize.x * m_button.getScale().x, buttonSize.y * m_button.getScale().y };
}

void ButtonSprite::SetPosition(const sf::Vector2f& pos)
{
    m_position = pos;
    m_button.setPosition(m_position);
    AlignTo(m_alignment);
}

void ButtonSprite::Draw(sf::RenderWindow& window)
{
    window.draw(m_button);
    m_label.Draw(window);

    testPoint.setFillColor(sf::Color::Red);
    testPoint.setPosition(m_label.GetPosition());
    window.draw(testPoint);

    testPoint.setFillColor(sf::Color::Blue);
    testPoint.setPosition(m_button.getPosition());
    window.draw(testPoint);
}