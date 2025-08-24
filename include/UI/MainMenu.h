#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Window.h"

class MainMenu {
public:
    MainMenu(Window& window);
    void Update(sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window);

private:
    void ToggleDisplayMenu() { m_displayMenu = !m_displayMenu; }

    sf::Vector2f CalculateNextButtonPlacement(const Button& previousButton);

    sf::Text m_menuText;
    sf::Sprite m_menuSprite;

    Button m_btnStartGame;
    Button m_btnSettings;
    Button m_btnExit;

    bool m_displayMenu;
};