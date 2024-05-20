#include "State.h"

MenuState::MenuState() {
    aboutGame.loadFromFile("Images/Picture_Back_About_Game.png");
    rabbit.loadFromFile("Images/Picture_Rabbit.png");
    shark.loadFromFile("Images/Picture_Shark.png");
    Pooh.loadFromFile("Images/Picture_Pooh.png");
    exitGame.loadFromFile("Images/Picture_Exit.png");
    menuBackground.loadFromFile("Images/Picture_Menu.jpg");

    menuGame.setTexture(aboutGame);
    menuRabbit.setTexture(rabbit);
    menuShark.setTexture(shark);
    menuPooh.setTexture(Pooh);
    menuExit.setTexture(exitGame);
    menuBack.setTexture(menuBackground);

    menuGame.setPosition(100, 30);
    menuRabbit.setPosition(130, 90);
    menuShark.setPosition(130, 150);
    menuPooh.setPosition(130, 210);
    menuExit.setPosition(100, 270);
}

void MenuState::handleInput(sf::Texture pictureBye, sf::Texture pictureAboutGame, sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            if (sf::IntRect(100, 30, 300, 50).contains(sf::Mouse::getPosition(window))) {
                sf::Sprite backGame(pictureAboutGame);
                window.draw(backGame);
                window.display();
                while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
            }
            else if (sf::IntRect(130, 90, 300, 50).contains(sf::Mouse::getPosition(window))) {
                sf::Texture picture;
                picture.loadFromFile("Images/Background_Rabbit.jpg");
                State* newState = new GameState();
                newState->handleInput(rabbit, picture, window);
                delete newState;
            }
            else if (sf::IntRect(130, 150, 300, 50).contains(sf::Mouse::getPosition(window))) {
                sf::Texture picture;
                picture.loadFromFile("Images/Background_Shark.jpg");
                State* newState = new GameState();
                newState->handleInput(shark, picture, window);
                delete newState;
            }
            else if (sf::IntRect(130, 210, 300, 50).contains(sf::Mouse::getPosition(window))) {
                sf::Texture picture;
                picture.loadFromFile("Images/Background_Pooh.jpg");
                State* newState = new GameState();
                newState->handleInput(Pooh, picture, window);
                delete newState;
            }
            else if (sf::IntRect(100, 270, 300, 50).contains(sf::Mouse::getPosition(window))) {
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
    pictureTap.loadFromFile("Images/Picture_Tap.png");
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
    SharkBuilder playerBuilder(playerTexture);
    Shark player = playerBuilder.SetDx(0).SetDy(0).SetFrame(0).SetOnGround(false).Build();
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