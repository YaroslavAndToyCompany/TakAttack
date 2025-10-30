#include "UI/Widgets/Button.hpp"
#include "Utils/Widgets.hpp"
#include "Utils/Utils.hpp"

Button::Button(ResourceManager& resManager)
    : m_resManager(resManager), m_label(resManager)
{
    m_isClicked = false;
    m_alignment = Alignment::TopLeft;
    m_textOffset = { 0, 0 };
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

void Button::AlignTo(Alignment alignment)
{
    sf::Vector2f texPos;
    sf::Vector2f halfSize = GetSize() * 0.5f;

    switch (alignment)
    {
    case Alignment::TopLeft:
        texPos = { (m_position.x + halfSize.x + m_textOffset.x), (m_position.y + halfSize.y + m_textOffset.y) };
        break;

    case Alignment::Center:
        SetOrigin(CalcRectOriginCenter(GetLocalBounds()));
        texPos = { m_position.x + m_textOffset.x, m_position.y + m_textOffset.y }; 
        break;
    
    default:
        throw std::runtime_error("You specify a wrong alignment type!");
    }

    m_label.AlignTextToCenter();
    m_label.SetPosition(texPos);
    m_alignment = alignment;
}

void Button::MoveText(const sf::Vector2f& value)
{
    m_textOffset = value;
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
