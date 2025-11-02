#pragma once

#include <SFML/Graphics.hpp>
#include "Managers/CursorManager.hpp"
#include "Managers/ResourceManager.hpp"
#include "UI/Widgets/Buttons/ButtonSprite.hpp"
#include "Game/Window.hpp"

class MainMenu {
public:
    MainMenu(Window& window, ResourceManager& resManager, CursorManager& curManager);
    void HandleEvents(const sf::Event& event, Window& window);
    void Update(sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window);

private:
    void ToggleDisplayMenu() { m_displayMenu = !m_displayMenu; }
    void GenerateButtons();
    void PlaceButtons(std::vector<ButtonSprite*>& buttons, float startPosY, float spacingBetweenY, const sf::Vector2f& scale, int textSize);

	ResourceManager& m_resManager;
	CursorManager& m_curManager;

    sf::Sprite m_menuSprite;

    const int m_buttonCount = 3;
    ButtonSprite m_btnStartGame;
    ButtonSprite m_btnSettings;
    ButtonSprite m_btnExit;

    sf::Vector2f m_scale;

    bool m_displayMenu;
};
