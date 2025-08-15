#include "UI/MainMenu.h"

#include "ResourceManager.h"

MainMenu::MainMenu()
    : m_btnStartGame("MenuButton"), m_btnSettings("MenuButton"), m_btnExit("MenuButton")
{
    m_btnStartGame.SetText("Start the Game");
    m_btnStartGame.SetPosition(sf::Vector2f(400, 300));
    m_btnStartGame.SetScale(sf::Vector2f(3, 3));
    m_btnStartGame.SetTextSize(24);

    m_btnSettings.SetText("Settings");
    m_btnSettings.SetPosition(sf::Vector2f(400, 350));
    m_btnSettings.SetScale(sf::Vector2f(3, 3));
    m_btnSettings.SetTextSize(24);

    m_btnExit.SetText("Exit");
    m_btnExit.SetPosition(sf::Vector2f(400, 400));
    m_btnExit.SetScale(sf::Vector2f(3, 3));
    m_btnExit.SetTextSize(24);
}

void MainMenu::Draw(sf::RenderWindow& window)
{
    m_btnStartGame.Draw(window);
    m_btnSettings.Draw(window);
    m_btnExit.Draw(window);
}
