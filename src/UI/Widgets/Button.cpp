#include "UI/Widgets/Button.hpp"
#include "Utils/Widgets.hpp"

Button::Button(const std::string& textureName,
               ResourceManager& resManager,
               const sf::Vector2f& pos,
               const std::string& btnText,
               const sf::Vector2f& scale,
               const sf::Color& textColor,
               const std::string& fontName)
{
    
    m_button.setTexture(*resManager.GetResource<sf::Texture>(textureName));
    m_text.setFont(*resManager.GetResource<sf::Font>(fontName));

    m_text.setString(btnText);
    m_text.setFillColor(textColor);

    m_button.setPosition(pos);
    m_button.setScale(scale);

    TransformText();
}

void Button::Update(sf::RenderWindow& window)
{
    // ...
}

void Button::Draw(sf::RenderWindow& window)
{
    window.draw(m_button);
    window.draw(m_text);
}

void Button::TransformText()
{
    m_text.setOrigin(SetRectOriginToCenter(m_text.getLocalBounds()));
    m_button.setOrigin(SetRectOriginToCenter(m_button.getLocalBounds()));
    
    sf::Vector2f buttonPos = m_button.getPosition();
    sf::Vector2f textPos = sf::Vector2f(buttonPos.x, buttonPos.y - 2);

    m_text.setPosition(textPos);
}
