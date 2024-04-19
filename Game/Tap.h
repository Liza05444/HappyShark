#pragma once
#include <SFML/Graphics.hpp>

class Tap {
private:
	sf::Sprite sprite;
	bool shadow;
	int time;
public:
	Tap(const sf::Texture& image);
	bool GetShadow();
	sf::Sprite GetSprite();
	void Update();
};
