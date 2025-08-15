#include "UI/DebugPanel.h" 
#include "ResourceManager.h"

sf::Text DebugPanel::m_text;

void DebugPanel::Init()
{
    sf::Font* font = ResourceManager::GetResource<sf::Font>("BoldPixels");
    m_text.setFont(*font);
}

void DebugPanel::SetString(const std::string& text)
{
    m_text.setString(text);
    m_text.setCharacterSize(18);
    m_text.setFillColor(sf::Color::Black);
}

void DebugPanel::Draw(sf::RenderWindow& window)
{
    window.draw(m_text);
}
