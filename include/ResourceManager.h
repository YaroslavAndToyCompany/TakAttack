#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

class ResourceManager {
public:
    static inline void Init();

    template <typename T>
    static T* GetResource(const std::string& resourceName);
    
    static inline void ReleaseResources();
    
private:
    ResourceManager() { }

    template <typename T>
    static void ClearResource();
    
    template <typename T>
    static void UploadResource(const std::string& resourceName, const std::string& resourcePath);
    
    template <typename T>
    static std::map<std::string, T*> s_resources;
};

template <typename T>
std::map<std::string, T*> ResourceManager::s_resources;

void ResourceManager::Init() {
    ResourceManager::UploadResource<sf::Texture>("Map1", "res/Maps/Map1.png");
    ResourceManager::UploadResource<sf::Texture>("MenuButton", "res/UI/Button.png");
    ResourceManager::UploadResource<sf::Font>("BoldPixels", "res/UI/Fonts/BoldPixels.ttf");
}

template <typename T>
void ResourceManager::UploadResource(const std::string& resourceName, const std::string& resourcePath)
{
    T* resource = new T();
    if (!resource->loadFromFile(resourcePath)) {
        delete resource;
        throw std::runtime_error("Failed to load resource from: " + resourcePath);
    }

    std::pair<std::string, T*> resourcePackage(resourceName, resource);
    s_resources<T>.insert(resourcePackage);
}

template <typename T>
T* ResourceManager::GetResource(const std::string& resourceName)
{
    auto itr = s_resources<T>.find(resourceName);
    if (itr == s_resources<T>.end()) {
        std::cerr << "Cannot retrieve " << resourceName << " resource" << std::endl; 
        return nullptr;
    }

    return itr->second;
}

template <typename T>
void ResourceManager::ClearResource() {
    auto& map = s_resources<T>;

    for (auto const& [key, value] : map) {
        delete value;
    }

    map.clear();
}

void ResourceManager::ReleaseResources()
{
    ClearResource<sf::Texture>();
    ClearResource<sf::Font>();
}