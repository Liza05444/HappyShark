#include "Pipe.h"

Pipe::Pipe(const sf::Texture& image) {
	for (int i = 0; i < 2; ++i) {
		sprite[i].setTexture(image);
	}
	sprite[1].setTextureRect(sf::IntRect(0, 415, 45, -415));
	dx = 0;
	Coordinates();
}

void Pipe::SetDx(float dx1) {
	dx = dx1;
}

sf::Sprite Pipe::GetSprite(int i1) {
	return sprite[i1];
}

void Pipe::Update() {
	if (playGame) {
		rect.left += dx;
	}
	if (rect.left < -50) {
		Coordinates();
	}
	for (int i = 0; i < 2; ++i) {
		sprite[i].setPosition(rect.left, rect.top - 500 * i);
	}
}

void Pipe::Coordinates() {
	srand(time(0));
	y = rand() % 6;
	rect.left = 288;
	rect.top = 100 + 50 * y;
}