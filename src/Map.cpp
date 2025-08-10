#include "Map.h"
#include "ResourceManager.h"

Map::Map()
{
    SetUpMap("Map1");
}

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
    sf::Texture* texture = ResourceManger::GetTexture(mapName);
    if (!texture) {
        std::cerr << "Cannot found texture: " << mapName << std::endl;
        return;
    }
    m_map.setTexture(*texture);
}
