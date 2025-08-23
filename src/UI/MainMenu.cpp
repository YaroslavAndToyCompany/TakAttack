#include "UI/MainMenu.h"
#include "ResourceManager.h"
#include "Managers/CursorManager.h"

MainMenu::MainMenu(Window& window)
    : m_btnStartGame("MenuButton"), m_btnSettings("MenuButton"), m_btnExit("MenuButton")
{
    m_menuSprite.setTexture(*ResourceManager::GetResource<sf::Texture>("MenuFrame"));
    m_menuSprite.setScale(2, 2);

    sf::FloatRect menuRect = m_menuSprite.getLocalBounds();
    sf::Vector2f menuCenter(menuRect.width / 2.0f, menuRect.height / 2.0f);
    m_menuSprite.setOrigin(menuCenter);

    m_menuSprite.setPosition(sf::Vector2f(window.GetWindowSize().x / 2.0f, window.GetWindowSize().y / 2.0f));

    m_btnStartGame.SetText("Start the Game");
    m_btnSettings.SetText("Settings");
    m_btnExit.SetText("Exit");

    std::vector<Button*> buttons = { &m_btnStartGame, &m_btnSettings, &m_btnExit };
    float startPositionY = m_menuSprite.getPosition().y - 15;
    float spacingBetweenY = 22;
    int textSize = 15;

    PlaceButtons(buttons, startPositionY, spacingBetweenY, sf::Vector2f(2, 2), textSize);

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

void MainMenu::PlaceButtons(std::vector<Button*>& buttons, float startPosY, float spacingBetweenY, const sf::Vector2f& scale, int textSize) {
    spacingBetweenY *= scale.y;

    for (int i = 0; i < buttons.size(); i++) {
        if (i == 0) {
            buttons[i]->SetPosition(sf::Vector2f(m_menuSprite.getPosition().x, startPosY));
        }
        else {
            sf::Vector2f previousBtnSize = buttons[i - 1]->GetSprite().getPosition();
            buttons[i]->SetPosition(sf::Vector2f(previousBtnSize.x, previousBtnSize.y + spacingBetweenY));
        }

        buttons[i]->SetScale(scale);
        buttons[i]->SetTextSize(textSize);
    }
}

