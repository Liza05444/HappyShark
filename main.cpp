#include "State/State.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(288, 512), "HappyShark");
    sf::Texture pictureBye, pictureBackGame;
    pictureBye.loadFromFile("Images/Ocean_for_Game.jpg");
    pictureBackGame.loadFromFile("Images/Ocean_for_Game.jpg");
    State* currentState = new MenuState();
    while (window.isOpen()) {
        currentState->handleInput(pictureBye, pictureBackGame, window);
        currentState->render(window);
    }
    delete currentState;
    return 0;
}