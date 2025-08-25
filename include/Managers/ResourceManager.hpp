#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <iostream>
#include <memory>

class ResourceManager {
public:
    ResourceManager() = delete;

    static inline void Init();

    template <typename T>
    static T* GetResource(const std::string& resourceName);
    
private:
    template <typename T>
    static void UploadResource(const std::string& resourceName, const std::string& resourcePath);
    
    template <typename T>
    static std::unordered_map<std::string, std::unique_ptr<T>> s_resources;
};

template <typename T>
std::unordered_map<std::string, std::unique_ptr<T>> ResourceManager::s_resources;

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

    std::unique_ptr<T> resource = std::make_unique<T>();
    if (!resource.get()->loadFromFile(resourcePath)) {
        throw std::runtime_error("Failed to load resource from: " + resourcePath);
    }

    s_resources<T>.insert( {resourceName, std::move(resource)} );
}

template <typename T>
T* ResourceManager::GetResource(const std::string& resourceName)
{
    auto itr = s_resources<T>.find(resourceName);
    if (itr == s_resources<T>.end()) {
        std::cerr << "Cannot retrieve " << resourceName << " resource" << std::endl; 
        return nullptr;
    }

    return itr->second.get();
}