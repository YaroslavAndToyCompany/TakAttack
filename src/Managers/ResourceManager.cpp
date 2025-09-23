#include "Managers/ResourceManager.hpp"

ResourceManager::ResourceManager() {
// TEMP ifdef
#if defined(SFML_SYSTEM_WINDOWS)
    UploadResource<sf::Texture>("Map1", "D:/projects/takattack/TakAttack/res/Maps/Map1.png");
    UploadResource<sf::Texture>("MenuButton", "D:/projects/takattack/TakAttack/res/UI/Button.png");
    UploadResource<sf::Texture>("MenuFrame", "D:/projects/takattack/TakAttack/res/UI/MenuFrame.png");
    UploadResource<sf::Texture>("Castle", "D:/projects/takattack/TakAttack/res/Sprites/Castle.png");
    UploadResource<sf::Texture>("Artillery", "D:/projects/takattack/TakAttack/res/Sprites/artillery.png");
    UploadResource<sf::Font>("BoldPixels", "D:/projects/takattack/TakAttack/res/UI/Fonts/BoldPixels.ttf");
#elif defined(SFML_SYSTEM_LINUX)
    UploadResource<sf::Texture>("Map1", "res/Maps/Map1.png");
    UploadResource<sf::Texture>("MenuButton", "res/UI/Button.png");
    UploadResource<sf::Texture>("MenuFrame", "res/UI/MenuFrame.png");
    UploadResource<sf::Texture>("Castle", "res/Sprites/Castle.png");
    UploadResource<sf::Texture>("Artillery", "res/Sprites/artillery.png");
    UploadResource<sf::Font>("BoldPixels", "res/UI/Fonts/BoldPixels.ttf");
#endif
}