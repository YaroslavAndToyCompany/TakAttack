#include "Managers/CursorManager.hpp"
#include "Managers/ResourceManager.hpp"

sf::Cursor CursorManager::s_arrow;
sf::Cursor CursorManager::s_hand;

void CursorManager::LoadCursors()
{
    s_arrow.loadFromSystem(sf::Cursor::Arrow);
    s_hand.loadFromSystem(sf::Cursor::Hand);
}

void CursorManager::SetArrow(sf::RenderWindow& window)
{
    window.setMouseCursor(s_arrow);
}

void CursorManager::SetHand(sf::RenderWindow& window)
{
    window.setMouseCursor(s_hand);
}