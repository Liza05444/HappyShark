#include "Shark.h"

Shark::Shark(const sf::Texture& image) {
    sprite.setTexture(image);
    sprite.setTextureRect(sf::IntRect(0, 0, 38, 20));
    rect.left = 125;
    rect.top = 100;
    frame = 0;
    dx = dy = 0;
}

sf::Sprite Shark::GetSprite() {
    return sprite;
}

sf::FloatRect Shark::GetRect() {
    return rect;
}

float Shark::GetDy() {
    return dy;
}

float Shark::GetDx() {
    return dx;
}

bool Shark::GetOnGround() {
    return onGround;
}

void Shark::SetDy(float dy1) {
    dy = dy1;
}

void Shark::SetDx(float dx1) {
    dx = dx1;
}

void Shark::Update(float time) {
    rect.left += dx * time;
    if (!onGround && (playGame || gameOver)) {
        dy += 0.001 * time;
    }
    rect.top += dy * time;
    onGround = false;
    if (rect.top > 480) {
        rect.top = 480;
        dy = 0;
        onGround = true;
    }
    if (!gameOver) {
        frame += 0.005 * time;
        if (frame > 3) {
            frame -= 3;
        }
        sprite.setPosition(rect.left, rect.top);
    }
}