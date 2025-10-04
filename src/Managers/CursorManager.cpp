#include <iostream>
#include "Managers/CursorManager.hpp"

CursorManager::CursorManager()
{
    m_arrow.loadFromSystem(sf::Cursor::Type::Arrow);
    m_hand.loadFromSystem(sf::Cursor::Type::Hand);

    m_sizeVertical.loadFromSystem(sf::Cursor::Type::SizeVertical);
    m_sizeHorizontal.loadFromSystem(sf::Cursor::Type::SizeHorizontal);
}

void CursorManager::Set(CursorType type) 
{
    m_curType = type;
    m_isCursorSpecified = true;
}

void CursorManager::Draw(sf::RenderWindow& window) 
{
    if (m_isCursorSpecified) 
    {
        AssignCurToWindow(window);
        m_isCursorSpecified = false;
    }
    else
        window.setMouseCursor(m_arrow);
}

void CursorManager::AssignCurToWindow(sf::RenderWindow& window) 
{
    switch (m_curType)
    {
    case CursorType::Hand:
        window.setMouseCursor(m_hand);
        break;
    
    case CursorType::SizeVertical:
        window.setMouseCursor(m_sizeVertical);
        break;

    case CursorType::SizeHorizontal:
        window.setMouseCursor(m_sizeHorizontal);
        break;

    case CursorType::Arrow:
        window.setMouseCursor(m_sizeVertical);
        break;

    default:
        std::cerr << "Error. You specifie unsupported cursor!" << std::endl;
        break;
    }
}
