#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Cursor.hpp>

class CursorManager {
public:
    static void LoadCursors();
    static void SetArrow(sf::RenderWindow& window);
    static void SetHand(sf::RenderWindow& window);
    static void SetSizeTop(sf::RenderWindow& window);
    static void SetSizeBottom(sf::RenderWindow& window);
    static void SetSizeLeft(sf::RenderWindow& window);
    static void SetSizeRight(sf::RenderWindow& window);

private:
    CursorManager() { };

    static sf::Cursor s_arrow;
    static sf::Cursor s_hand;
    static sf::Cursor s_sizeTop;
    static sf::Cursor s_sizeBottom;
    static sf::Cursor s_sizeLeft;
    static sf::Cursor s_sizeRight;
};