#include "UI/Widgets/Button.hpp"
#include "Utils/Widgets.hpp"
#include "Utils/Utils.hpp"

Button::Button(ResourceManager& resManager)
    : m_resManager(resManager), m_label(resManager)
{
    m_isClicked = false;
}

void Button::ChangeCursor(sf::RenderWindow& window, CursorManager& curManager, CursorType curType)
{
    sf::Vector2f mousePos = utils::ConvertMousePixelsToCoords(
                                sf::Mouse::getPosition(window), window);

    sf::FloatRect btnRect = GetGlobalBounds();
    
    if (btnRect.contains(mousePos))
    {
        curManager.Set(curType);
    }
}

void Button::HandleEvents(const sf::Event& event, sf::RenderWindow& window)
{
    sf::Vector2f mousePos;
    switch (event.type)
    {
    case sf::Event::MouseButtonReleased:
        mousePos = utils::ConvertMousePixelsToCoords(event.mouseButton.x, event.mouseButton.y, window);

        if (event.mouseButton.button == sf::Mouse::Button::Left && GetGlobalBounds().contains(mousePos))
            m_isClicked = true;
        break;
    
    default:
        break;
    }
}

void Button::Update(sf::RenderWindow& window) 
{
    m_isClicked = false;
}

void Button::TransformText()
{
    m_label.SetFont("BoldPixels");

    m_label.AlignTextToCenter();
    
    sf::Vector2f textPos = sf::Vector2f(m_position.x, m_position.y - 2);

    m_label.SetPosition(textPos);
}
