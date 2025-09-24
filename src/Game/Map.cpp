#include "Game/Map.hpp"

Map::Map(ResourceManager& resManager, const std::string& mapName)
{
    SetUpMap(resManager, mapName);

}

void Map::SetMap(ResourceManager& resManager, const std::string& mapName)
{
    SetUpMap(resManager, mapName);
}

GridCell* Map::GetCellPosition(const sf::Vector2f& pos)
{
    for(auto& cell : m_grid) 
    {
        if (cell.bounds.contains(pos)) {
            return &cell;
    }
    }
    return nullptr;
}

void Map::DrawGrid(sf::RenderWindow& window)
{
    for (auto& cell : m_grid)
    {
        sf::RectangleShape m_rect;
        m_rect.setSize(sf::Vector2f(m_cellWitdh, m_cellHeight));
        m_rect.setPosition(cell.bounds.left, cell.bounds.top);
        m_rect.setFillColor(sf::Color::Transparent);
        m_rect.setOutlineThickness(1.f);

        if (cell.type == CellType::Castle)
            m_rect.setOutlineColor(sf::Color::Red);
        else
            m_rect.setOutlineColor(sf::Color::Red);

        window.draw(m_rect);
    }
}

void Map::MarkCellAsCastle(int gridX, int gridY)
{
    int index = gridY * m_gridWidth + gridX;
    
    if (index >= 0 && index < m_grid.size()) {
        m_grid[index].type = CellType::Castle;
    }
    else {
        std::cout << "Error: index out of range!" << std::endl;
    }
}

void Map::SetUpMap(ResourceManager& resManager, const std::string& mapName)
{
    m_map.setTexture(*resManager.GetResource<sf::Texture>(mapName));

    m_size = sf::Vector2f(m_map.getLocalBounds().width, m_map.getLocalBounds().height);
    m_map.setOrigin(m_size * 0.5f);
    
    CalculateGlobalMapCenter();

    SetUpGrid();

    for (int y = 8; y <= 9; ++y) {
        for (int x = 17; x <= 19; ++x) {
            MarkCellAsCastle(x, y);
        }
    }

}

void Map::CalculateGlobalMapCenter()
{
    sf::FloatRect bounds = m_map.getGlobalBounds();
    sf::Vector2f center = sf::Vector2f(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);

    m_globalCenter = center;
}

void Map::SetUpGrid()
{
    std::cout << "Grid width: " << m_gridWidth << ", Grid height: " << m_gridHeight << "\n";
    std::cout << "Cell width: " << m_cellWitdh << ", Cell height: " << m_cellHeight << "\n";

    m_grid.clear();

    for(int y = 0; y < m_gridHeight; ++y)
    {
    for(int x = 0; x < m_gridWidth; ++x) 
    {
        GridCell cell;
        cell.gridX = x;
        cell.gridY = y;
        sf::Vector2f mapCenter = m_map.getPosition();
        float posX = mapCenter.x - m_size.x / 2.f + x * m_cellWitdh;
        float posY = mapCenter.y - m_size.y / 2.f + y * m_cellHeight;
        if (x < 3 && y < 3) {
            std::cout << "Cell (" << x << ", " << y << ") bounds: ["
                << posX << ", " << posY << ", "
                << m_cellWitdh << ", " << m_cellHeight << "]\n";
        }
        cell.bounds = sf::FloatRect(posX, posY, m_cellWitdh, m_cellHeight);
        cell.type = CellType::Empty;

        m_grid.push_back(cell);
    }
    }
    
}

void Map::Draw(sf::RenderWindow& window) {
    window.draw(m_map);
    DrawGrid(window);
}
