#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"

class MainMenu {
public:
    MainMenu();
    void Draw(sf::RenderWindow& window);

private:
    sf::Text m_menuText;
    Button m_btnStartGame;
    Button m_btnSettings;
    Button m_btnExit;
};