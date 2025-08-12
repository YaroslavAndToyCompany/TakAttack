#include "Map.h"
#include "ResourceManager.h"

Map::Map(const std::string& mapName)
{
    SetUpMap(mapName);
}

void Map::SetMap(const std::string& mapName)
{
    SetUpMap(mapName);
}

void Map::SetUpMap(const std::string& mapName)
{
    sf::Texture* texture = ResourceManager::GetResource<sf::Texture>(mapName);
    
    m_map.setTexture(*texture);
}

void Map::Draw(sf::RenderWindow& window) {
    window.draw(m_map);
}
