#include "State.h"

MenuState::MenuState() {
    aboutGame.loadFromFile("Images/Score.png");
    rabbit.loadFromFile("Images/Score.png");
    shark.loadFromFile("Images/Score.png");
    Pooh.loadFromFile("Images/Score.png");
    exitGame.loadFromFile("Images/Score.png");
    menuBackground.loadFromFile("Images/Back.jpg");

    menuGame.setTexture(aboutGame);
    menuRabbit.setTexture(rabbit);
    menuShark.setTexture(shark);
    menuPooh.setTexture(Pooh);
    menuExit.setTexture(exitGame);
    menuBack.setTexture(menuBackground);

    menuGame.setPosition(50, 30);
    menuRabbit.setPosition(50, 90);
    menuShark.setPosition(50, 150);
    menuPooh.setPosition(50, 210);
    menuExit.setPosition(50, 270);
}

void MenuState::handleInput(sf::Texture pictureBye, sf::Texture pictureBackGame, sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            if (sf::IntRect(50, 30, 300, 50).contains(sf::Mouse::getPosition(window))) {
                sf::Sprite backGame(pictureBackGame);
                window.draw(backGame);
                window.draw(menuGame);
                window.display();
                while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter));
                window.close();
            }
            else if (sf::IntRect(50, 90, 300, 50).contains(sf::Mouse::getPosition(window))) {
                sf::Texture picture;
                picture.loadFromFile("Images/Ocean_for_Game.jpg");
                State* newState = new GameState();
                newState->handleInput(rabbit, picture, window);
                delete newState;
            }
            else if (sf::IntRect(50, 150, 300, 50).contains(sf::Mouse::getPosition(window))) {
                sf::Texture picture;
                picture.loadFromFile("Images/Ocean_for_Game.jpg");
                State* newState = new GameState();
                newState->handleInput(shark, picture, window);
                delete newState;
            }
            else if (sf::IntRect(50, 210, 300, 50).contains(sf::Mouse::getPosition(window))) {
                sf::Texture picture;
                picture.loadFromFile("Images/Back.jpg");
                State* newState = new GameState();
                newState->handleInput(Pooh, picture, window);
                delete newState;
            }
            else if (sf::IntRect(50, 270, 300, 50).contains(sf::Mouse::getPosition(window))) {
                sf::Sprite bye(pictureBye);
                window.draw(bye);
                window.display();
                window.close();
            }
        }
    }
}

void MenuState::render(sf::RenderWindow& window) {
    window.draw(menuBack);
    window.draw(menuGame);
    window.draw(menuRabbit);
    window.draw(menuShark);
    window.draw(menuPooh);
    window.draw(menuExit);
    window.display();
}

GameState::GameState() {
    pictureTap.loadFromFile("Images/Tap.jpg");
    picturePipe.loadFromFile("Images/Pipe.jpg");
    pictureScore.loadFromFile("Images/Score.png");
    pictureGameOver.loadFromFile("Images/GameOver.png");

    gameover.setTexture(pictureGameOver);
    gameover.setPosition(30, 200);
}

void GameState::handleInput(sf::Texture playerTexture, sf::Texture pictureBackground, sf::RenderWindow& windowTemp) {
    windowTemp.close();
    sf::RenderWindow window(sf::VideoMode(288, 512), "HappyShark");

    background.setTexture(pictureBackground);
    Shark player(playerTexture);
    Tap tap(pictureTap);
    Pipe pipe(picturePipe);
    Score score(pictureScore);

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
                    player.SetDy(-0.2);
                }
            }
        }

        if (playGame) {
            if (player.GetRect().left > 10) {
                player.SetDx(-0.2);
            }
            else {
                player.SetDx(0);
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
                if (player.GetSprite().getGlobalBounds().intersects(pipe.GetSprite(i).getGlobalBounds()) || player.GetOnGround()) {
                    playGame = false;
                    gameOver = true;
                }
            }
        }

        player.Update(time);
        if (startGame) {
            tap.Update();
        }
        pipe.Update();
        score.Update();

        window.clear(sf::Color::White);
        window.draw(background);
        window.draw(player.GetSprite());
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
        render(window);
    }
}

void GameState::render(sf::RenderWindow& window) {
    window.display();
}