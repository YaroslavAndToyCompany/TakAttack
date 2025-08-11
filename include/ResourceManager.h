#pragma once

#include <SFML/Graphics.hpp>
#include <map>

class ResourceManger {
public:
    static void Init();
    static void UploadTexture(const std::string& textureName, const std::string& texturePath);
    
    static sf::Texture* GetTexture(const std::string& textureName);

    static void ReleaseResources();

private:
    ResourceManger() { }

    static std::map<std::string, sf::Texture*> s_resources;
};