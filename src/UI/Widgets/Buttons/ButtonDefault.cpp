#include "UI/Widgets/Buttons/ButtonDefault.hpp"
#include "Utils/Widgets.hpp"

ButtonDefault::ButtonDefault(ResourceManager& resManager)
    : Button(resManager)
{
    m_button.setFillColor(sf::Color::Black);
    m_buttonCanvas.setFillColor(sf::Color::White);
    SetSize({ 60, 20 });

    m_origiButtonnCanvas.setFillColor(sf::Color::Green);
    m_origiButtonnCanvas.setRadius(6);
    m_origiButtonnCanvas.SetOriginToCenter();
}

void ButtonDefault::AlignTo(Alignment alignment)
{
    sf::Vector2f texPos;
    sf::Vector2f halfSize = GetSize() * 0.5f;
    // std::cout << "halfSize: " << halfSize.x << ", " << halfSize.y << std::endl;
    // std::cout << "m_button: " << m_button.getPosition().x << ", " << m_button.getPosition().y << std::endl;
    // std::cout << "m_buttonCanvasPos: " << m_buttonCanvas.getPosition().x << ", " << m_buttonCanvas.getPosition().y << std::endl;

    switch (alignment)
    {
    case Alignment::TopLeft:
        m_buttonCanvas.setOrigin(CalcRectOriginCenter(m_buttonCanvas.getLocalBounds()));
        m_buttonCanvas.setPosition(m_buttonCanvas.getPosition() + halfSize);
        texPos = { (m_position.x + halfSize.x + m_textOffset.x), (m_position.y + halfSize.y + m_textOffset.y) };
        break;

    case Alignment::Center:
        m_button.setOrigin(CalcRectOriginCenter(m_button.getLocalBounds()));
        m_buttonCanvas.setOrigin(CalcRectOriginCenter(m_buttonCanvas.getLocalBounds()));
        texPos = { m_position.x + m_textOffset.x, m_position.y + m_textOffset.y }; 
        break;
    
    default:
        throw std::runtime_error("You specify a wrong alignment type!");
    }

    m_label.AlignTo(Alignment::Center);
    m_label.SetPosition(texPos);
    m_alignment = alignment;
}

sf::Vector2f ButtonDefault::GetSize()
{
    return m_button.getSize();
}

void ButtonDefault::SetSize(const sf::Vector2f& size)
{
    m_button.setSize({ size.x, size.y });
    float scaledHeight = size.y * 0.25f;

    m_buttonCanvas.setSize({ size.x - scaledHeight, size.y - scaledHeight});
    m_buttonCanvas.setPosition(m_button.getPosition());
    AlignTo(m_alignment); 
}

void ButtonDefault::SetPosition(const sf::Vector2f& pos)
{
    m_position = pos;
    m_button.setPosition(m_position);
    m_buttonCanvas.setPosition(m_position);
    AlignTo(m_alignment);
}

void ButtonDefault::SetOrigin(const sf::Vector2f& newOrigin)
{
    m_button.setOrigin(newOrigin);
    m_buttonCanvas.setOrigin(CalcRectOriginCenter(m_buttonCanvas.getLocalBounds()));
}

void ButtonDefault::Draw(sf::RenderWindow& window)
{
    window.draw(m_button);
    window.draw(m_buttonCanvas);
    m_label.Draw(window);

    if (m_isDisplayBordersSet)
    {
        DrawBounds(window);
        m_origiButtonnCanvas.setPosition(m_buttonCanvas.getPosition());
        window.draw(m_origiButtonnCanvas);
    }
}
