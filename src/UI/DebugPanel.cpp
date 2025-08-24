#include "UI/DebugPanel.hpp" 
#include "Managers/ResourceManager.hpp"

sf::Text DebugPanel::m_text;
sf::RectangleShape DebugPanel::m_panel;

void DebugPanel::Init(View& view)
{
    sf::Font* font = ResourceManager::GetResource<sf::Font>("BoldPixels");
    m_text.setFont(*font);

    sf::Vector2f viewCenter = view.GetSfmlView().getCenter();
    m_text.setPosition(viewCenter); // TEMP

    m_panel.setPosition(viewCenter);
    m_panel.setFillColor(sf::Color::White);
    m_panel.setSize({80, 25});
}

void DebugPanel::SetString(const std::string& text)
{
    m_text.setString(text);
    m_text.setCharacterSize(18);
    m_text.setFillColor(sf::Color::Black);
}

void DebugPanel::Draw(sf::RenderWindow& window)
{
    // window.draw(m_panel); TODO: Panel that appears and stretchis when there is a text
    window.draw(m_text);
}
