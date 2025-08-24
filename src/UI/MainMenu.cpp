#include "UI/MainMenu.h"
#include "ResourceManager.h"
#include "Managers/CursorManager.h"

MainMenu::MainMenu(Window& window)
    : m_btnStartGame("MenuButton"), m_btnSettings("MenuButton"), m_btnExit("MenuButton")
{
    sf::Texture* mainMenuTex = ResourceManager::GetResource<sf::Texture>("MenuFrame");
    m_menuSprite.setTexture(*mainMenuTex);
    m_menuSprite.setScale(2, 2);

    sf::FloatRect menuRect = m_menuSprite.getLocalBounds();
    sf::Vector2f menuCenter(menuRect.width / 2.0f, menuRect.height / 2.0f);
    m_menuSprite.setOrigin(menuCenter);

    m_menuSprite.setPosition(sf::Vector2f(window.GetWindowSize().x / 2.0f, window.GetWindowSize().y / 2.0f));

    m_btnStartGame.SetText("Start the Game");
    m_btnStartGame.SetPosition(sf::Vector2f(m_menuSprite.getPosition().x, m_menuSprite.getPosition().y - 15));
    m_btnStartGame.SetScale(sf::Vector2f(2, 2));
    m_btnStartGame.SetTextSize(15);

    m_btnSettings.SetText("Settings");
    m_btnSettings.SetPosition(CalculateNextButtonPlacement(m_btnStartGame));
    m_btnSettings.SetScale(sf::Vector2f(2, 2));
    m_btnSettings.SetTextSize(15);

    m_btnExit.SetText("Exit");
    m_btnExit.SetPosition(CalculateNextButtonPlacement(m_btnSettings));
    m_btnExit.SetScale(sf::Vector2f(2, 2));
    m_btnExit.SetTextSize(15);

    m_displayMenu = true;
}


void MainMenu::Update(sf::RenderWindow & window)
{
    if (m_displayMenu) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosInCoords = window.mapPixelToCoords(mousePos);

        sf::FloatRect btnRectStartGame = m_btnStartGame.GetSprite().getGlobalBounds();
        sf::FloatRect btnRectSettings = m_btnSettings.GetSprite().getGlobalBounds();
        sf::FloatRect btnRectExit = m_btnExit.GetSprite().getGlobalBounds();
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && btnRectStartGame.contains(mousePosInCoords)) {
            ToggleDisplayMenu();
            CursorManager::SetArrow(window);
            return;  
        }

        if (btnRectStartGame.contains(mousePosInCoords) || btnRectSettings.contains(mousePosInCoords) || btnRectExit.contains(mousePosInCoords)) {
            CursorManager::SetHand(window);
        }
        else {
            CursorManager::SetArrow(window);
        }
    }
}

void MainMenu::Draw(sf::RenderWindow& window)
{
    if (m_displayMenu) {
        window.draw(m_menuSprite);
        m_btnStartGame.Draw(window);
        m_btnSettings.Draw(window);
        m_btnExit.Draw(window);
    }
}

sf::Vector2f MainMenu::CalculateNextButtonPlacement(const Button& previousButton)
{
    return sf::Vector2f(previousButton.GetSprite().getPosition().x, 
                        previousButton.GetSprite().getPosition().y + 22 
                        * previousButton.GetSprite().getScale().y);
}

