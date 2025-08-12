#pragma once

#include <SFML/Graphics.hpp>

class MainMenu {
public:
    MainMenu();
    void Draw(sf::RenderWindow& window);

private:
    sf::Text m_menuText;
};