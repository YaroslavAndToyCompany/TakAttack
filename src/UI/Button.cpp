#include "UI/Button.h"
#include "ResourceManager.h"
#include "UI/DebugPanel.h"
#include "Managers/CursorManager.h"

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

    m_text.setString(btnText);
    m_text.setFillColor(textColor);

    m_button.setPosition(pos);
    m_button.setScale(scale);

    TransformText();
}

void Button::Update(sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    // DebugPanel::SetString(std::to_string(mousePos.x) + ", " + std::to_string(mousePos.y)); TEMP

    if (m_button.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
        CursorManager::SetHand(window);
        std::cout << "hand" << std::endl;
    }
    else {
        CursorManager::SetArrow(window);
    }
}

void Button::Draw(sf::RenderWindow& window)
{
    window.draw(m_button);
    window.draw(m_text);
}

void Button::TransformText()
{
    
    sf::FloatRect textRect = m_text.getLocalBounds();
    sf::Vector2f textCenter(textRect.left + (textRect.width / 2.0f), (textRect.top + (textRect.height / 2.0f)));
    m_text.setOrigin(textCenter);

    
    sf::FloatRect buttonRect = m_button.getLocalBounds();
    sf::Vector2f buttonCenter(buttonRect.width / 2.0f, buttonRect.height / 2.0f);
    m_button.setOrigin(buttonCenter);
    
    sf::Vector2f buttonPos = m_button.getPosition();
    sf::Vector2f textPos = sf::Vector2f(buttonPos.x, buttonPos.y - 2);

    m_text.setPosition(textPos);
}
