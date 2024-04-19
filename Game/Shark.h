#pragma once
#include <SFML/Graphics.hpp>

class Shark {
private:
    sf::FloatRect rect;
    sf::Sprite sprite;
    float frame;
public:
    Shark(const sf::Texture& image);
    sf::Sprite GetSprite();
    void Update(float time);
};