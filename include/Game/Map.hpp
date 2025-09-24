#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "UI/View.hpp"
#include "Game/GridCell.hpp"
#include "Game/Window.hpp"
#include "Managers/ResourceManager.hpp"


class Map {
public:
    Map(ResourceManager& resManager, const std::string& mapName);

    void SetMap(ResourceManager& resManager, const std::string& mapName);
    
    void Draw(sf::RenderWindow& window);
    
    sf::Sprite GetSprite() const { return m_map; }
    sf::Vector2f GetGlobalCenter() const { return m_globalCenter; }
    sf::Vector2f GetSize() const { return m_size; }

    GridCell* GetCellPosition(const sf::Vector2f& pos);
    void DrawGrid(sf::RenderWindow& window);
    void MarkCellAsCastle(int gridX, int gridY);

private:
    void SetUpMap(ResourceManager& resManager, const std::string& mapName);
    void CalculateGlobalMapCenter();
    void SetUpGrid();

    sf::Sprite m_map;
    sf::Vector2f m_size;
    sf::Vector2f m_globalCenter;

    std::vector<GridCell> m_grid;
    int m_gridWidth = 20;
    int m_gridHeight = 15;
    float m_cellWitdh = 32.0f;
    float m_cellHeight = 32.0f;
};