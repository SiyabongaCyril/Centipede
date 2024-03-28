#ifndef Scores_H
#define Scores_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include <string>

using std::string;

class Scores
{
public:
    Scores();

    void setWindowSize(sf::Vector2u Size);

    void setScore(int score_);
    const sf::Text& getScore() const;
    const sf::Text& getScoreText() const;

    void setHighScore(int highScore_);
    const sf::Text& getHighScore() const;
    const sf::Text& getHighScoreText() const;


    void setNumberOfLives(int numberOfLives_);
    const sf::Text& getNumberOfLives() const;
    const sf::Text& getNumberOfLivesText() const;

    const sf::RectangleShape& getVerticalBar() const;

    void loseLife();
    void finalScore(float x, float y);

private:

    int intScore;
    int intNumberOfLives;
    int intHighScore;
    int scoreTextSize;
    std::string scoresFont;

    sf::RectangleShape verticalBar;
    sf::Font font;
    sf::Text scoreText;
    sf::Text highScoreText;
    sf::Text score;
    sf::Text highScore;
    sf::Text numberOfLivesText;
    sf::Text numberOfLives;
    sf::Vector2u windowSize_;

    Resources scoreTexts;
    Resources scoreValues;

    void createVerticalBar(float, float,float);
    void createScoreTexts();
    void createScoreInitialValues();
};

#endif // Scores_H
