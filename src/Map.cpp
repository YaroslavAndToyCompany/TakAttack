#include "Map.h"

Map::Map()
{
    SetUpMap("../res/Maps/Map1.png");
}

Map::Map(const std::string& mapPath)
{
    SetUpMap(mapPath);
}

void Map::SetMap(const std::string& mapPath)
{
    SetUpMap(mapPath);
}

void Map::SetUpMap(const std::string& mapPath)
{
    m_mapTex.loadFromFile(mapPath);
    m_map.setTexture(m_mapTex);
}
