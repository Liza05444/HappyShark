#pragma once
#include <SFML/Graphics.hpp>

class Score {
private:
    sf::Sprite scoreSprite[3];
    int number[3], score;
    bool view[3], add;
public:
    Score(const sf::Texture& image);
    bool GetAdd();
    int GetScore();
    sf::Sprite GetScoreSprite(int i1);
    bool GetView(int i1);
    void SetAdd(bool add1);
    void SetScore(int score1);
    void Update();
};
