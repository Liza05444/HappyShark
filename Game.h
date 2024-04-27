#pragma once
#include <SFML/Graphics.hpp>
#include "Shark/Shark.h"
#include "Tap/Tap.h"
#include "Pipe/Pipe.h"

void game() {
    sf::RenderWindow window(sf::VideoMode(288, 512), "Happy Shark");
    sf::Texture pictureBackground;
    pictureBackground.loadFromFile("Images/Back.jpg");
    sf::Sprite background(pictureBackground);

    sf::Texture pictureShark;
    pictureShark.loadFromFile("Images/HappyShark.jpg");
    Shark shark(pictureShark);

    sf::Texture pictureTap;
    pictureTap.loadFromFile("Images/Tap.jpg");
    Tap tap(pictureTap);

    sf::Texture picturePipe;
    picturePipe.loadFromFile("Images/Pipe.jpg");
    Pipe pipe(picturePipe);

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

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.key.code == sf::Mouse::Left) {
                if (startGame) {
                    startGame = false;
                    playGame = true;
                }
                if (playGame) {
                    shark.SetDy(-0.2);
                }
            }
        }
        if (playGame) {
            if (shark.GetRect().left > 10) {
                shark.SetDx(-0.2);
            }
            else {
                shark.SetDx(0);
            }
            pipe.SetDx(-0.05);
        }
        shark.Update(time);
        if (startGame) {
            tap.Update();
        }
        pipe.Update();
        window.clear(sf::Color::White);
        window.draw(background);
        window.draw(shark.GetSprite());
        if (tap.GetShadow() && startGame) {
            window.draw(tap.GetSprite());
        }
        for (int i = 0; i < 2; ++i) {
            window.draw(pipe.GetSprite(i));
        }
        window.display();
    }
}