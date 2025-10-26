#include "Managers/ResourceManager.hpp"

ResourceManager::ResourceManager() {


    UploadResource<sf::Texture>("Map1", "res/Maps/Map1.png");
    UploadResource<sf::Texture>("MenuButton", "res/UI/Button.png");
    UploadResource<sf::Texture>("MenuFrame", "res/UI/MenuFrame.png");
    UploadResource<sf::Texture>("Castle", "res/Sprites/Castle.png");
    UploadResource<sf::Texture>("Artillery", "res/Sprites/artillery.png");
    UploadResource<sf::Font>("BoldPixels", "res/UI/Fonts/BoldPixels.ttf");

} 