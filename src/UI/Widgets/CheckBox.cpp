#include <UI/Widgets/CheckBox.hpp>
#include "Utils/Widgets.hpp"
#include "Utils/Utils.hpp"

CheckBox::CheckBox(ResourceManager& resManager, bool state, const std::string& text)
    : m_label(resManager)
{
    m_alignment = Alignment::Center;
    m_isChecked = state;
    
    m_outerBox.setSize({ CHECKBOX_SIZE, CHECKBOX_SIZE });
    m_innerBox.setSize({ CHECKBOX_SIZE / 2.0f, CHECKBOX_SIZE / 2.0f });

    m_outerBox.setFillColor(sf::Color::Black);
    m_innerBox.setFillColor(sf::Color::White);
       
    m_label.AddText(text);
    AlignTo(m_alignment);
}

void CheckBox::AlignTo(Alignment alignment)
{
    sf::Vector2f texPos;
    sf::Vector2f halfSize = GetSize() * 0.5f;

    switch (alignment)
    {
    case Alignment::TopLeft:
        texPos = { (m_position.x + halfSize.x + 30), (m_position.y + halfSize.y) };
        break;

    case Alignment::Center:
        m_outerBox.setOrigin(CalcRectOriginCenter(m_outerBox.getLocalBounds()));
        m_innerBox.setOrigin(CalcRectOriginCenter(m_innerBox.getLocalBounds()));
        texPos = { m_position.x + 30, m_position.y }; 
        break;
    
    default:
        throw std::runtime_error("You specify a wrong alignment type!");
    }

    m_label.AlignTo(Alignment::Left);
    m_label.SetPosition(texPos);
    m_alignment = alignment;
}

void CheckBox::SetPosition(const sf::Vector2f& pos) 
{
    m_position = pos;

    m_outerBox.setPosition(m_position);
    m_innerBox.setPosition(m_position);
    m_label.SetPosition({m_position.x + 30, m_position.y});

    AlignTo(m_alignment);
}

void CheckBox::HandleEvents(const sf::Event& event, sf::RenderWindow& window) 
{
    sf::Vector2f mousePos;
    switch (event.type)
    {
    case sf::Event::MouseButtonReleased:
        mousePos = utils::ConvertMousePixelsToCoords(event.mouseButton.x, event.mouseButton.y, window);

        if (event.mouseButton.button == sf::Mouse::Left 
            && m_outerBox.getGlobalBounds().contains(mousePos))
        {
            ToggleChecked();
        }

        break;
    default:
        break;
    }
}

void CheckBox::Update(sf::RenderWindow& window) {}

void CheckBox::Draw(sf::RenderWindow& window)
{
    window.draw(m_outerBox);
    if (m_isChecked) window.draw(m_innerBox);
    m_label.Draw(window);
}
