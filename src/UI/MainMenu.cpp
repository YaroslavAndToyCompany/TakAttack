#include "UI/MainMenu.h"

#include "ResourceManager.h"

MainMenu::MainMenu()
    : m_btnStartGame("MenuButton")
{
    m_btnStartGame.SetText("Start the Game");
    m_btnStartGame.SetTextColor(sf::Color::Black);
}

void MainMenu::Draw(sf::RenderWindow& window)
{
    m_btnStartGame.Draw(window);
}
