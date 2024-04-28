#include "Score.h"

Score::Score(const sf::Texture& image) {
	for (int i = 0; i < 3; ++i) {
		scoreSprite[i].setTexture(image);
		scoreSprite[i].setPosition(100 + 44 * i, 25);
		scoreSprite[i].setTextureRect(sf::IntRect(0, 0, 44, 45));
		number[i] = 0;
		score = 0;
	}
	add = true;
}

bool Score::GetAdd() {
	return add;
}

int Score::GetScore() {
	return score;
}

sf::Sprite Score::GetScoreSprite(int i1) {
	return scoreSprite[i1];
}

bool Score::GetView(int i1) {
	return view[i1];
}

void Score::SetAdd(bool add1) {
	add = add1;
}

void Score::SetScore(int score1) {
	score = score1;
}

void Score::Update() {
	if (score < 10) {
		number[0] = score;
		view[0] = true;
		view[1] = false;
		view[2] = false;
	}
	else if (score >= 10 && score < 100) {
		number[0] = score / 10;
		number[1] = score % 10;
		view[0] = true;
		view[1] = true;
		view[2] = false;
	}
	else if (score >= 100 && score < 1000) {
		number[0] = score / 100;
		number[1] = (score / 10) % 10;
		number[2] = (score % 100) % 10;
		view[0] = true;
		view[1] = true;
		view[2] = true;
	}
	for (int i = 0; i < 3; ++i) {
		scoreSprite[i].setTextureRect(sf::IntRect(44 * number[i], 0, 44, 45));
	}
}