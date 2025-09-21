#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Cursor.hpp>

class CursorManager {
public:
    static void LoadCursors();
    static void SetArrow(sf::RenderWindow& window);
    static void SetHand(sf::RenderWindow& window);
    static void SetSizeVertical(sf::RenderWindow& window);
    static void SetSizeHorizontal(sf::RenderWindow& window);

private:
    CursorManager() { };

    static sf::Cursor s_arrow;
    static sf::Cursor s_hand;
    static sf::Cursor s_sizeVertical;
    static sf::Cursor s_sizeHorizontal;
};