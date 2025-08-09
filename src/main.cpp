#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>
#include <iostream>
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    sf::Texture texture;
    if (!texture.loadFromFile("../res/assets/awesomeface.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    std::cout << "TAK ATTACK";
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();

        window.draw(sprite);

        window.display();
    }

    return EXIT_SUCCESS;
}