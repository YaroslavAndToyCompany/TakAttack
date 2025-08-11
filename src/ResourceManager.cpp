#include "ResourceManager.h"

#include <iostream>


std::map<std::string, sf::Texture*> ResourceManger::s_resources;

void ResourceManger::Init()
{
    ResourceManger::UploadTexture("Map1", "res/Maps/Map1.png");
}

void ResourceManger::UploadTexture(const std::string& textureName, const std::string& texturePath)
{
    sf::Texture* texture = new sf::Texture();
    if (!texture->loadFromFile(texturePath)) {
        std::cerr << "Failed to load texture: " << texturePath << std::endl;
        delete texture;
        return;
    }

    std::pair<std::string, sf::Texture*> texturePackage(textureName, texture);
    s_resources.insert(texturePackage);
}

sf::Texture* ResourceManger::GetTexture(const std::string& textureName)
{
    auto itr = s_resources.find(textureName);
    if (itr == s_resources.end()) {
        std::cerr << "Cannot retrieve " << textureName << " texture" << std::endl; 
        return nullptr;
    }

    return itr->second;
}

void ResourceManger::ReleaseResources()
{
    for (auto& texture : s_resources) {
        delete texture.second;
    }
    s_resources.clear();
}
