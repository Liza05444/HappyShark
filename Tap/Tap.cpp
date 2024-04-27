#include "Tap.h"

Tap::Tap(const sf::Texture& image) {
	sprite.setTexture(image);
	sprite.setPosition(125, 200);
	shadow = true;
	time = 2000;
}

bool Tap::GetShadow() {
	return shadow;
}

sf::Sprite Tap::GetSprite() {
	return sprite;
}

void Tap::Update() {
	time--;
	if (time < 1000) {
		shadow = false;
		if (time == 0) {
			shadow = true;
			time = 2000;
		}
	}
}