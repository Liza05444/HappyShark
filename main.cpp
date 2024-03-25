#include <SFML/Graphics.hpp>
#include "Game/Game.h"

int main() {
    /*std::cout << "Game: \n";
    Game g(5);
    std::cout << "g = " << g.get_a() << std::endl;*/

    sf::RenderWindow window(sf::VideoMode(800, 600), "Happy Shark");
    sf::Texture f;
    f.loadFromFile("Images/Ocean_for_Game.jpg");
    sf::Sprite fon(f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::White);
        window.draw(fon);
        window.display();
    }

    return 0;
}