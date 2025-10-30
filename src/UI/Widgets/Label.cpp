#include "UI/Widgets/Label.hpp"
#include "Utils/Widgets.hpp"
#include "Debug/Debug.hpp"

Label::Label(ResourceManager& resManager)
    : m_resManager(resManager)
{
    m_text.setCharacterSize(28);
    m_text.setFillColor(sf::Color::Black);
    m_text.setFont(*m_resManager.GetResource<sf::Font>("BoldPixels"));
    m_text.setString("Text");
}

void Label::AlignTo(Alignment alignment)
{
    sf::FloatRect rect = m_text.getLocalBounds();
    sf::Vector2f newOrigin;

    switch (alignment)
    {
    case Alignment::TopLeft:
        return;

    case Alignment::Left:
        newOrigin = { rect.left, rect.top + (rect.height / 2.0f) };
        break;
    case Alignment::Center:
        newOrigin = { rect.left + (rect.width / 2.0f), rect.top + (rect.height / 2.0f) };
        break;

    default:
        throw std::runtime_error("You specify a wrong Alignemnt type!");
    }

    m_text.setOrigin(newOrigin);
}

void Label::AddText(const std::string& text)
{
    m_text.setString(text);
}

void Label::AddText(const int& number) 
{
    AddText(std::to_string(number));
}

sf::Vector2f Label::GetSize()
{
    sf::Vector2f size = { m_text.getLocalBounds().width, m_text.getLocalBounds().height };
    return size;
}

void Label::SetFont(const std::string& fontName)
{
    m_text.setFont(*m_resManager.GetResource<sf::Font>(fontName));
}

void Label::SetPosition(const sf::Vector2f& pos) 
{
    m_position = pos;

    m_text.setPosition({m_position.x, m_position.y});
}