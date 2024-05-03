#pragma once
#include <SFML/Graphics.hpp>
#include "../Shark/Shark.h"
#include "../Tap/Tap.h"
#include "../Pipe/Pipe.h"
#include "../Score/Score.h"

class State {
public:
    virtual void handleInput(sf::Texture Texture1, sf::Texture Texture2, sf::RenderWindow& window) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};

class GameState : public State {
private:
    sf::Texture pictureTap, picturePipe, pictureScore, pictureGameOver;
    sf::Sprite gameover, background;
public:
    GameState();
    void handleInput(sf::Texture playerTexture, sf::Texture pictureBackground, sf::RenderWindow& windowTemp) override;
    void render(sf::RenderWindow& window) override;
    ~GameState() {}
};

class MenuState : public State {
private:
    sf::Texture aboutGame, rabbit, shark, Pooh, exitGame, menuBackground;
    sf::Sprite menuGame, menuRabbit, menuShark, menuPooh, menuExit, menuBack;
public:
    MenuState();
    void handleInput(sf::Texture pictureBye, sf::Texture pictureBackGame, sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;
    ~MenuState() {}
};