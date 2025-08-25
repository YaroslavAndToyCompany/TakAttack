#pragma once

#include <SFML/Graphics.hpp>
#include "UI/Button.hpp"
#include "Game/Window.hpp"

class MainMenu {
public:
    MainMenu(Window& window);
    void Update(sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window);

private:
    void ToggleDisplayMenu() { m_displayMenu = !m_displayMenu; }
    void PlaceButtons(std::vector<Button*>& buttons, float startPosY, float spacingBetweenY, const sf::Vector2f& scale, int textSize);

    sf::Sprite m_menuSprite;

    Button m_btnStartGame;
    Button m_btnSettings;
    Button m_btnExit;

    sf::Vector2f m_scale;

    bool m_displayMenu;
};