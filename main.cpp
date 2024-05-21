#include "State/State.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(288, 512), "HappyShark");
    sf::Texture pictureBye, pictureAboutGame;
    pictureBye.loadFromFile("../../../../Images/Picture_Bye.jpg");
    pictureAboutGame.loadFromFile("../../../../Images/Picture_About_Game.jpg");
    State* currentState = new MenuState();
    while (window.isOpen()) {
        currentState->handleInput(pictureBye, pictureAboutGame, window);
        currentState->render(window);
    }
    delete currentState;
    return 0;
}