#pragma once
#include <SFML/Graphics.hpp>
#include "Shark/Shark.h"
#include "Tap/Tap.h"
#include "Pipe/Pipe.h"
#include "Score/Score.h"

void game() {
    sf::RenderWindow window(sf::VideoMode(288, 512), "Happy Shark");
    sf::Texture pictureBackground;
    pictureBackground.loadFromFile("Images/Back.jpg");
    sf::Sprite background(pictureBackground);

    sf::Texture pictureShark;
    pictureShark.loadFromFile("Images/Shark.jpg");
    Shark shark(pictureShark);

    sf::Texture pictureTap;
    pictureTap.loadFromFile("Images/Tap.jpg");
    Tap tap(pictureTap);

    sf::Texture picturePipe;
    picturePipe.loadFromFile("Images/Pipe.jpg");
    Pipe pipe(picturePipe);

    sf::Texture pictureScore;
    pictureScore.loadFromFile("Images/Score.png");
    Score score(pictureScore);

    sf::Texture pictureGameOver;
    pictureGameOver.loadFromFile("Images/GameOver.png");
    sf::Sprite gameover(pictureGameOver);
    gameover.setPosition(30, 200);

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

            if (pipe.GetRect().left < 0 && score.GetAdd()) {
                score.SetScore(score.GetScore() + 1);
                score.SetAdd(false);
            }
            else if (pipe.GetRect().left > 200) {
                score.SetAdd(true);
            }

            for (int i = 0; i < 2; ++i) {
                if (shark.GetSprite().getGlobalBounds().intersects(pipe.GetSprite(i).getGlobalBounds()) || shark.GetOnGround()) {
                    playGame = false;
                    gameOver = true;
                }
            }
        }
        shark.Update(time);
        if (startGame) {
            tap.Update();
        }
        pipe.Update();
        score.Update();
        window.clear(sf::Color::White);
        window.draw(background);
        window.draw(shark.GetSprite());
        if (tap.GetShadow() && startGame) {
            window.draw(tap.GetSprite());
        }
        for (int i = 0; i < 2; ++i) {
            window.draw(pipe.GetSprite(i));
        }
        for (int i = 0; i < 3; ++i) {
            if (score.GetView(i)) {
                window.draw(score.GetScoreSprite(i));
            }
        }
        if (gameOver) {
            window.draw(gameover);
        }
        window.display();
    }
}