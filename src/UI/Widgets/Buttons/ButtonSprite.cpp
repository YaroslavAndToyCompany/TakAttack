#include "UI/Widgets/Buttons/ButtonSprite.hpp"
#include "Utils/Widgets.hpp"
#include "Debug/Debug.hpp"

ButtonSprite::ButtonSprite(ResourceManager& resManager, const std::string& textureName)
    : Button(resManager)
{
    m_button.setTexture(*m_resManager.GetResource<sf::Texture>(textureName));
    m_alignment = Alignment::TopLeft;
    testPoint.setRadius(5);
}

void ButtonSprite::AlignTo(Alignment alignment)
{
    sf::Vector2f texPos;
    sf::Vector2f halfSize = { m_button.getLocalBounds().width * 0.5f, m_button.getLocalBounds().height * 0.5f};
    halfSize = { halfSize.x * m_button.getScale().x, halfSize.y * m_button.getScale().y };

    switch (alignment)
    {
    case Alignment::TopLeft:
        texPos = { (m_position.x + halfSize.x - 6), (m_position.y + halfSize.y - 6)};
        break;

    case Alignment::Center:
        m_button.setOrigin(CalcRectOriginCenter(m_button.getLocalBounds()));
        texPos = { m_position.x - 6, m_position.y - 6}; 
        break;
    
    default:
        throw std::runtime_error("You specify a wrong alignment type!");
    }

    m_label.AlignTextToCenter();
    m_label.SetPosition(texPos);
    m_alignment = alignment;
}

sf::Vector2f ButtonSprite::GetSize()
{
    sf::FloatRect localBounds = m_button.getLocalBounds();
    return { localBounds.width, localBounds.height };
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