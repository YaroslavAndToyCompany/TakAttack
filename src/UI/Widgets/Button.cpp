#include "UI/Widgets/Button.hpp"
#include "Utils/Widgets.hpp"
#include "Utils/Utils.hpp"

Button::Button(ResourceManager& resManager)
    : m_resManager(resManager), m_label(resManager)
{
    m_isClicked = false;
    m_alignment = Alignment::TopLeft;
    m_textOffset = { 0, 0 };
    m_isDisplayBordersSet = false;

    m_originPoint.setFillColor(sf::Color::Blue);
    m_originPoint.setRadius(5);
    m_originPoint.SetOriginToCenter();
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

void Button::MoveText(const sf::Vector2f& value)
{
    m_textOffset = value;
}

void Button::ToggleDisplayBorders()
{
    m_isDisplayBordersSet = !m_isDisplayBordersSet;
    m_label.ToggleDisplayBorders();
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

void Button::DrawBounds(sf::RenderWindow& window)
{
    m_originPoint.setPosition(GetPosition());
    window.draw(m_originPoint);
}
