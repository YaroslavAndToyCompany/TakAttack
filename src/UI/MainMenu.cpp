#include "UI/MainMenu.h"

#include "ResourceManager.h"

MainMenu::MainMenu()
{
    sf::Font* boldPixelsFont = ResourceManager::GetResource<sf::Font>("BoldPixels");

    m_menuText.setFont(*boldPixelsFont);
    m_menuText.setString("Start Game");
    m_menuText.setCharacterSize(24);
    m_menuText.setFillColor(sf::Color::Black);

    m_menuText.setPosition(10, 10);
}

void MainMenu::Draw(sf::RenderWindow& window)
{
    window.draw(m_menuText);
}
