#include "UI/Widgets/Buttons/ButtonSprite.hpp"

ButtonSprite::ButtonSprite(ResourceManager& resManager, const std::string& textureName)
    : Button(resManager)
{
    m_button.setTexture(*m_resManager.GetResource<sf::Texture>(textureName));
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
}

void ButtonSprite::Draw(sf::RenderWindow& window)
{
    window.draw(m_button);
    m_label.Draw(window);
}