#pragma once
#include <SFML/Graphics.hpp>
#include "../Regime.h"

class Shark {
private:
    sf::Sprite sprite;
    sf::FloatRect rect;
    float frame;
    float dx;
    float dy;
    bool onGround;

public:
    Shark(const sf::Sprite& sprite, const sf::FloatRect& rect, float frame, float dx, float dy, bool onGroundState);
    sf::Sprite GetSprite();
    sf::FloatRect GetRect();
    float GetDy();
    float GetDx();
    bool GetOnGround();
    Shark& SetDx(float dx1);
    Shark& SetDy(float dy1);
    void Update(float time);
};

class SharkBuilder {
private:
    sf::Sprite sprite;
    sf::FloatRect rect;
    float frame;
    float dx;
    float dy;
    bool onGround;
public:
    SharkBuilder(const sf::Texture& image);
    SharkBuilder& SetDx(float dx1);
    SharkBuilder& SetDy(float dy1);
    SharkBuilder& SetFrame(float frame1);
    SharkBuilder& SetOnGround(bool onGroundState);
    Shark Build();
};
