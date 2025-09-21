#include "UI/MainMenu.hpp"
#include "Managers/ResourceManager.hpp"
#include "Managers/CursorManager.hpp"
#include "Utils/Utils.hpp"

MainMenu::MainMenu(Window& window)
    : m_btnStartGame("MenuButton"), m_btnSettings("MenuButton"), m_btnExit("MenuButton")
{
    m_scale = sf::Vector2f(4, 4);

    m_menuSprite.setTexture(*ResourceManager::GetResource<sf::Texture>("MenuFrame"));
    m_menuSprite.setScale(m_scale);

    // TODO: add to the utils function that sets sprite's orgin to the center of the sprite
    sf::FloatRect menuRect = m_menuSprite.getLocalBounds();
    sf::Vector2f menuCenter(menuRect.width / 2.0f, menuRect.height / 2.0f);
    m_menuSprite.setOrigin(menuCenter);

    m_menuSprite.setPosition(sf::Vector2f(window.GetWindowSize().x / 2.0f, window.GetWindowSize().y / 2.0f));

    m_btnStartGame.SetText("Start the Game");
    m_btnSettings.SetText("Settings");
    m_btnExit.SetText("Exit");

    std::vector<Button*> buttons = { &m_btnStartGame, &m_btnSettings, &m_btnExit };
    float startPositionY = m_menuSprite.getPosition().y - 7.0f * m_scale.x;
    float spacingBetweenY = 22;
    int textSize = 8 * m_scale.x;

    PlaceButtons(buttons, startPositionY, spacingBetweenY, m_scale, textSize);

    m_displayMenu = true;
}

void MainMenu::HandleEvents(const sf::Event& event, sf::RenderWindow& window)
{

    if (!m_displayMenu)
        return;

    sf::FloatRect btnRectStartGame = m_btnStartGame.GetSprite().getGlobalBounds();
    sf::FloatRect btnRectSettings = m_btnSettings.GetSprite().getGlobalBounds();
    sf::FloatRect btnRectExit = m_btnExit.GetSprite().getGlobalBounds();

    switch (event.type)
    {
    case sf::Event::MouseButtonPressed:
    {
        break;
    }
    case sf::Event::MouseButtonReleased:
    {
        sf::Vector2f mousePos = utils::ConvertMousePixelsToCoords(
                                event.mouseButton.x, event.mouseButton.y, window);

        if (event.mouseButton.button == sf::Mouse::Left && btnRectStartGame.contains(mousePos))
        {
            ToggleDisplayMenu();
            CursorManager::SetArrow(window);
            m_isCursorSetted = false;
        }
        break;
    }
    default:
        break;
    }
}

void MainMenu::Update(sf::RenderWindow& window)
{
    if (!m_displayMenu)
        return;

    m_isCursorSetted = false;

    sf::FloatRect btnRectStartGame = m_btnStartGame.GetSprite().getGlobalBounds();
    sf::FloatRect btnRectSettings = m_btnSettings.GetSprite().getGlobalBounds();
    sf::FloatRect btnRectExit = m_btnExit.GetSprite().getGlobalBounds();

    sf::Vector2f mousePos = utils::ConvertMousePixelsToCoords(
                                sf::Mouse::getPosition(window), window);

        if (btnRectStartGame.contains(mousePos) 
            || btnRectSettings.contains(mousePos) 
            || btnRectExit.contains(mousePos))
        {
            CursorManager::SetHand(window);
            m_isCursorSetted = true;
        }
}

void MainMenu::Draw(sf::RenderWindow& window)
{
    if (!m_displayMenu)
        return;

    window.draw(m_menuSprite);
    m_btnStartGame.Draw(window);
    m_btnSettings.Draw(window);
    m_btnExit.Draw(window);
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

