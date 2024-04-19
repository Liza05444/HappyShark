#include <SFML/Graphics.hpp>
#include "Game/Shark.h"
#include "Game/Tap.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(288, 512), "Happy Shark");
    sf::Texture pictureBackground;
    pictureBackground.loadFromFile("Images/Background.jpg");
    sf::Sprite background(pictureBackground);

    sf::Texture pictureShark;
    pictureShark.loadFromFile("Images/Shark.jpg");
    Shark shark(pictureShark);

    sf::Texture pictureTap;
    pictureTap.loadFromFile("Images/Tap.jpg");
    Tap tap(pictureTap);

    sf::Clock clock;
    float time;
    while (window.isOpen()) {
        time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        shark.Update(time);
        tap.Update();
        window.clear(sf::Color::White);
        window.draw(background);
        window.draw(shark.GetSprite());
        if (tap.GetShadow()) {
            window.draw(tap.GetSprite());
        }
        window.display();
    }

    return 0;
}