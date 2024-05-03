#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Score {
private:
    std::vector<sf::Sprite> scoreSprite;
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
