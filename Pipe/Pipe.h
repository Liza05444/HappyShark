#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include "../Regime.h"

class Pipe {
private:
    sf::Sprite sprite[2];
    int y;
    float dx;
    sf::FloatRect rect;
public:
    Pipe(const sf::Texture& image);
    sf::Sprite GetSprite(int i1);
    sf::FloatRect GetRect();
    void SetDx(float dx1);
    void Update();
    void Coordinates();
};