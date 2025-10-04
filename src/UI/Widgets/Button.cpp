#include "UI/Widgets/Button.hpp"
#include "Utils/Widgets.hpp"
#include "Utils/Utils.hpp"

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

void Button::ChangeCursor(sf::RenderWindow& window, CursorManager& curManager, CursorType curType)
{
    sf::Vector2f mousePos = utils::ConvertMousePixelsToCoords(
                                sf::Mouse::getPosition(window), window);

    sf::FloatRect btnRect = m_button.getGlobalBounds();
    if (btnRect.contains(mousePos))
    {
        curManager.Set(curType);
    }
}

void Button::Draw(sf::RenderWindow& window)
{
    window.draw(m_button);
    window.draw(m_text);
}

// void Button::SetOnPressed(std::function<void()> event)
// {
//     m_callbacks.find()

//     m_callbacks.emplace(std::move(event), ButtonEventType::Pressed);
// }

void Button::TransformText()
{
    m_text.setOrigin(CalcRectOriginCenter(m_text.getLocalBounds()));
    m_button.setOrigin(CalcRectOriginCenter(m_button.getLocalBounds()));
    
    sf::Vector2f buttonPos = m_button.getPosition();
    sf::Vector2f textPos = sf::Vector2f(buttonPos.x, buttonPos.y - 2);

    m_text.setPosition(textPos);
}
