#pragma once

#include <SFML/Graphics.hpp>
#include "Managers/CursorManager.hpp"
#include "Managers/ResourceManager.hpp"
#include "UI/Widgets/Button.hpp"
#include "Game/Window.hpp"

class MainMenu {
public:
    MainMenu(Window& window, ResourceManager& resManager, CursorManager& curManager);
    void HandleEvents(const sf::Event& event, sf::RenderWindow& window);
    void Update(sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window);

    bool IsCursorSetted() { return m_isCursorSetted; }

private:
    void ToggleDisplayMenu() { m_displayMenu = !m_displayMenu; }
    void PlaceButtons(std::vector<Button*>& buttons, float startPosY, float spacingBetweenY, const sf::Vector2f& scale, int textSize);

	ResourceManager& m_resManager;
	CursorManager& m_curManager;

    sf::Sprite m_menuSprite;

    Button m_btnStartGame;
    Button m_btnSettings;
    Button m_btnExit;

    sf::Vector2f m_scale;

    bool m_displayMenu;
    bool m_isCursorSetted;
};
