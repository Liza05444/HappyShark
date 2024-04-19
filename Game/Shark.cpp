#include "Shark.h"

Shark::Shark(const sf::Texture& image) {
    sprite.setTexture(image);
    sprite.setTextureRect(sf::IntRect(0, 0, 38, 25));
    rect.left = 125;
    rect.top = 100;
    frame = 0;
}

sf::Sprite Shark::GetSprite() {
    return sprite;
}

void Shark::Update(float time) {
    frame += 0.005 * time;
    if (frame > 3) {
        frame -= 3;
    }
    sprite.setTextureRect(sf::IntRect(38 * int(frame), 0, 38, 25));
    sprite.setPosition(rect.left, rect.top);
}