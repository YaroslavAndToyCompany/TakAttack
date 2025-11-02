#include "UI/Widgets/Buttons/ButtonSprite.hpp"
#include "Utils/Widgets.hpp"
#include "Debug/Debug.hpp"

ButtonSprite::ButtonSprite(ResourceManager& resManager, const std::string& textureName)
    : Button(resManager)
{
    m_button.setTexture(*m_resManager.GetResource<sf::Texture>(textureName));
}

void ButtonSprite::AlignTo(Alignment alignment)
{
    sf::Vector2f texPos;
    sf::Vector2f halfSize = GetSize() * 0.5f;

    switch (alignment)
    {
    case Alignment::TopLeft:
        texPos = { (m_position.x + halfSize.x + m_textOffset.x), (m_position.y + halfSize.y + m_textOffset.y) };
        break;

    case Alignment::Center:
        m_button.setOrigin(CalcRectOriginCenter(GetLocalBounds()));
        texPos = { m_position.x + m_textOffset.x, m_position.y + m_textOffset.y }; 
        break;
    
    default:
        throw std::runtime_error("You specify a wrong alignment type!");
    }

    m_label.AlignTo(Alignment::Center);
    m_label.SetPosition(texPos);
    m_alignment = alignment;
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

    if (m_isDisplayBordersSet)
    {
        DrawBounds(window);
    }
}