#include "UI/Widgets/Button.hpp"
#include "Utils/Widgets.hpp"
#include "Utils/Utils.hpp"

Button::Button(ResourceManager& resManager, const std::string& textureName)
    : m_resManager(resManager), m_label(resManager)
{
    m_buttonSpr.setTexture(*m_resManager.GetResource<sf::Texture>(textureName));

    TransformText();
    m_isButtonDefault = false;
}

Button::Button(ResourceManager& resManager, const sf::Vector2f& size)
    : m_resManager(resManager), m_label(resManager)
{
    m_buttonDefault.setSize(size);
    m_buttonDefault.setFillColor(sf::Color::White);
    m_buttonDefault.setOutlineColor(sf::Color::Black);
    m_buttonDefault.setOutlineThickness(4);

    TransformText();
    m_isButtonDefault = true;
}

void Button::ChangeCursor(sf::RenderWindow& window, CursorManager& curManager, CursorType curType)
{
    sf::Vector2f mousePos = utils::ConvertMousePixelsToCoords(
                                sf::Mouse::getPosition(window), window);

    sf::FloatRect btnRect;
    if (m_isButtonDefault)
        btnRect = m_buttonDefault.getGlobalBounds();
    else
        btnRect = m_buttonSpr.getGlobalBounds();
    
    if (btnRect.contains(mousePos))
    {
        curManager.Set(curType);
    }
}

void Button::Draw(sf::RenderWindow& window)
{
    m_isButtonDefault ? window.draw(m_buttonDefault) : window.draw(m_buttonSpr);
    m_label.Draw(window);
}

sf::Sprite Button::GetSprite() const
{
    if (!m_isButtonDefault) return m_buttonSpr;
    throw std::runtime_error("Can't get a sprite from button that doesn't hava a spite!");
}

void Button::SetPosition(const sf::Vector2f& pos)
{
    m_position = pos;
    m_isButtonDefault ? m_buttonDefault.setPosition(m_position) : m_buttonSpr.setPosition(m_position);
    TransformText();
}

void Button::TransformText()
{
    m_label.SetFont("BoldPixels");

    m_label.AlignTextToCenter();
    if (m_isButtonDefault)
        m_buttonDefault.setOrigin(CalcRectOriginCenter(m_buttonDefault.getLocalBounds()));
    else
        m_buttonSpr.setOrigin(CalcRectOriginCenter(m_buttonSpr.getLocalBounds()));
    
    sf::Vector2f textPos = sf::Vector2f(m_position.x, m_position.y - 2);

    m_label.SetPosition(textPos);
}
