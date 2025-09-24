#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <iostream>
#include <memory>

class ResourceManager {
public:
    ResourceManager();

    template <typename T>
    T* GetResource(const std::string& resourceName);
    
private:
    template <typename T>
    void UploadResource(const std::string& resourceName, const std::string& resourcePath);
    
    std::unordered_map<std::string, std::unique_ptr<sf::Texture>> m_textures;
    std::unordered_map<std::string, std::unique_ptr<sf::Font>> m_fonts;
};

template <typename T>
void ResourceManager::UploadResource(const std::string& resourceName, const std::string& resourcePath)
{
    auto uploadLogic = [](auto& map, const std::string& resourceName,
                          const std::string& resourcePath, const std::string& resourceTypeName)
    {
        using ResourceType = typename std::remove_reference_t<decltype(map)>::mapped_type::element_type;

        if (map.count(resourceName) > 0)
            throw std::runtime_error("Failed to upload " + resourceTypeName + " because a resource named '" + resourceName + "' already exists!");

        auto resource = std::make_unique<ResourceType>();
        if (!resource->loadFromFile(resourcePath))
            throw std::runtime_error("Failed to load " + resourceTypeName + " from path: " + resourcePath);

        map.emplace(resourceName, std::move(resource));
    };

    if constexpr (std::is_same_v<T, sf::Texture>)
    {
        uploadLogic(m_textures, resourceName, resourcePath, "Texture");
    }
    else if constexpr (std::is_same_v<T, sf::Font>)
    {
        uploadLogic(m_fonts, resourceName, resourcePath, "Font");
    }
}

template <typename T>
T* ResourceManager::GetResource(const std::string& resourceName)
{
    auto getLogic = [](auto& map, const std::string& resourceName)
    {
        using ResourcePtrType = decltype(map.begin()->second.get());

        auto itr = map.find(resourceName);

        if (itr != map.end())
            return itr->second.get();

        throw std::runtime_error("Cannot retrieve resource '" + resourceName + "' - not found");
    };

    if constexpr (std::is_same_v<T, sf::Texture>)
        return getLogic(m_textures, resourceName);
    else if constexpr (std::is_same_v<T, sf::Font>)
        return getLogic(m_fonts, resourceName);
    else
        throw std::runtime_error("You specified unsupported type in ResourceManager::GetResource()");
}