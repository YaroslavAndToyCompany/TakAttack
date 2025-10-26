#include "UI/MainMenu.hpp"
#include "Managers/ResourceManager.hpp"
#include "Managers/CursorManager.hpp"
#include "Utils/Utils.hpp"
#include "Utils/Widgets.hpp"

MainMenu::MainMenu(Window& window, ResourceManager& resManager, CursorManager& curManager)
	: m_resManager(resManager), m_curManager(curManager),
    m_btnStartGame(m_resManager, "MenuButton"), m_btnSettings(m_resManager, "MenuButton"), m_btnExit(m_resManager, "MenuButton")
{
    m_scale = sf::Vector2f(4, 4);

    m_menuSprite.setTexture(*m_resManager.GetResource<sf::Texture>("MenuFrame"));
    m_menuSprite.setScale(m_scale);

    sf::Vector2f menuCenter = CalcRectOriginCenter(m_menuSprite.getLocalBounds());
    m_menuSprite.setOrigin(menuCenter);

    m_menuSprite.setPosition(sf::Vector2f(window.GetWindowSize().x / 2.0f, window.GetWindowSize().y / 2.0f));
    
    GenerateButtons();

    m_displayMenu = true;
}

void MainMenu::HandleEvents(const sf::Event& event, Window& window)
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
                                event.mouseButton.x, event.mouseButton.y, *window.GetRenderWindowPtr());

        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if (btnRectStartGame.contains(mousePos))
                ToggleDisplayMenu();
            else if (btnRectSettings.contains(mousePos)) {}
                // Open Settings
            else if (btnRectExit.contains(mousePos))
                window.ToggleDone();

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

    m_btnStartGame.ChangeCursor(window, m_curManager);
    m_btnSettings.ChangeCursor(window, m_curManager);
    m_btnExit.ChangeCursor(window, m_curManager);
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

void MainMenu::GenerateButtons() 
{
    m_btnStartGame.SetText("Start the Game");
    m_btnSettings.SetText("Settings");
    m_btnExit.SetText("Exit");

    std::vector<Button*> buttons = { &m_btnStartGame, &m_btnSettings, &m_btnExit };
    float startPositionY = m_menuSprite.getPosition().y - 7.0f * m_scale.x;
    float spacingBetweenY = 22;
    int textSize = 8 * m_scale.x;

    PlaceButtons(buttons, startPositionY, spacingBetweenY, m_scale, textSize);
}

void MainMenu::PlaceButtons(std::vector<Button*>& buttons, float startPosY, float spacingBetweenY, const sf::Vector2f& scale, int textSize) 
{
    spacingBetweenY *= scale.y;

    for (int i = 0; i < buttons.size(); i++) 
    {
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

