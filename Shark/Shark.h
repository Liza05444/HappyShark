#pragma once
#include <SFML/Graphics.hpp>
#include "../Regime.h"

class Shark {
private:
    sf::FloatRect rect;
    sf::Sprite sprite;
    float frame;
    float dx;
    float dy;
    bool onGround;
public:
    Shark(const sf::Texture& image);
    sf::Sprite GetSprite();
    sf::FloatRect GetRect();
    float GetDy();
    float GetDx();
    bool GetOnGround();
    void SetDy(float dy1);
    void SetDx(float dx1);
    void Update(float time);
};