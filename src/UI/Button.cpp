#include "UI/Button.h"
#include "ResourceManager.h"

Button::Button(const std::string& textureName, 
               const sf::Vector2f& pos,
               const std::string& btnText,
               const sf::Vector2f& scale,
               const sf::Color& textColor,
               const std::string& fontName)
{
    sf::Texture* texture = ResourceManager::GetResource<sf::Texture>(textureName);
    m_button.setTexture(*texture);

    sf::Font* font = ResourceManager::GetResource<sf::Font>(fontName);
    m_text.setFont(*font);

    m_text.setPosition(m_button.getPosition() + sf::Vector2f(15, -7));
}

void Button::Draw(sf::RenderWindow& window)
{
    window.draw(m_button);
    window.draw(m_text);
}


