#include "Game/Map.hpp"
#include "Managers/ResourceManager.hpp"

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
    m_map.setTexture(*ResourceManager::GetResource<sf::Texture>(mapName));

    m_size = sf::Vector2f(m_map.getLocalBounds().width, m_map.getLocalBounds().height);
    m_map.setOrigin(m_size * 0.5f);
    
    CalculateGlobalMapCenter();
}

void Map::CalculateGlobalMapCenter()
{
    sf::FloatRect bounds = m_map.getGlobalBounds();
    sf::Vector2f center = sf::Vector2f(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);

    m_globalCenter = center;
}

void Map::Draw(sf::RenderWindow& window) {
    window.draw(m_map);
}
