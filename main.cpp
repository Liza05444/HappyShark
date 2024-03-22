#include <SFML/Graphics.hpp>
#include "Game/Game.h"
using namespace sf;

int main() {
    std::cout << "Game: \n";
    Game g(5);
    std::cout << "g = " << g.get_a() << std::endl;

    RenderWindow window(VideoMode(400, 400), L"Game", Style::Default);
    window.setVerticalSyncEnabled(true);

    CircleShape shape(100.f, 3);
    shape.setPosition(100, 100);
    shape.setFillColor(Color::Magenta);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear(Color::Blue);
        window.draw(shape);
        window.display();
    }
    return 0;
}