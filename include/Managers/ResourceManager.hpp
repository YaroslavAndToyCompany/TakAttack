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
// TEMP ifdef
#if defined(SFML_SYSTEM_WINDOWS)
    ResourceManager::UploadResource<sf::Texture>("Map1", "D:/projects/takattack/TakAttack/res/Maps/Map1.png");
    ResourceManager::UploadResource<sf::Texture>("MenuButton", "D:/projects/takattack/TakAttack/res/UI/Button.png");
    ResourceManager::UploadResource<sf::Texture>("MenuFrame", "D:/projects/takattack/TakAttack/res/UI/MenuFrame.png");
    ResourceManager::UploadResource<sf::Font>("BoldPixels", "D:/projects/takattack/TakAttack/res/UI/Fonts/BoldPixels.ttf");
#elif defined(SFML_SYSTEM_LINUX)
    ResourceManager::UploadResource<sf::Texture>("Map1", "res/Maps/Map1.png");
    ResourceManager::UploadResource<sf::Texture>("MenuButton", "res/UI/Button.png");
    ResourceManager::UploadResource<sf::Texture>("MenuFrame", "res/UI/MenuFrame.png");
    ResourceManager::UploadResource<sf::Font>("BoldPixels", "res/UI/Fonts/BoldPixels.ttf");
#endif
}

template <typename T>
void ResourceManager::UploadResource(const std::string& resourceName, const std::string& resourcePath)
{
    auto itr = s_resources<T>.find(resourceName);
    if (itr != s_resources<T>.end()) {
        throw std::runtime_error("Failed to upload resource because the resource with a name " + resourceName + " is already exist!");
    }

    T* resource = new T();
    if (!resource->loadFromFile(resourcePath)) {
        delete resource;
        throw std::runtime_error("Failed to load resource from: " + resourcePath);
    }

    s_resources<T>.insert( {resourceName, resource} );
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