#include "Scores.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include <string>

using std::string;
using std::to_string;

Scores::Scores()
{
    intScore = 0;
    intHighScore = 0;
    intNumberOfLives = 3;
    createVerticalBar(630,0,90);

    scoresFont ="resources/OstrichSans-Medium.otf";
    scoreTextSize = 30;
}

void Scores::createVerticalBar(float x, float y, float theta)
{
    verticalBar.setSize(sf::Vector2f(750.0f, 1.0f));
    verticalBar.rotate(theta);
    verticalBar.setPosition(x,y);
    verticalBar.setFillColor(sf::Color::White);
}

const sf::RectangleShape& Scores::getVerticalBar() const
{
    return verticalBar;
}

void Scores:: finalScore(float x, float y)
{
    scoreText.setPosition(x,y);
    score.setPosition(x+100,y);
}

void Scores::createScoreTexts()
{
    scoreTexts.createMessage("High Score",scoresFont,scoreTextSize,
                             verticalBar.getPosition().x+10, windowSize_.y*0.01);
    highScoreText = scoreTexts.getMessage();

    scoreTexts.createMessage("Score",scoresFont,scoreTextSize,
                             verticalBar.getPosition().x+10,windowSize_.y*0.11);
    scoreText =  scoreTexts.getMessage();


    scoreTexts.createMessage("Lives",scoresFont,scoreTextSize,
                             verticalBar.getPosition().x+10,windowSize_.y*0.21);
    numberOfLivesText = scoreTexts.getMessage();
}

void Scores::createScoreInitialValues()
{
    scoreValues.createMessage(to_string(intHighScore),scoresFont,scoreTextSize,
                              verticalBar.getPosition().x+10, windowSize_.y*0.05);
    highScore = scoreValues.getMessage();

    scoreValues.createMessage(to_string(intScore),scoresFont,scoreTextSize,
                              verticalBar.getPosition().x+10,windowSize_.y*0.15);
    score = scoreValues.getMessage();

    scoreValues.createMessage(to_string(intNumberOfLives
                                        ),scoresFont,scoreTextSize,
                              verticalBar.getPosition().x+10,windowSize_.y*0.25);
    numberOfLives = scoreValues.getMessage();
}

void Scores::setWindowSize(sf::Vector2u Size)
{
    windowSize_ = Size;

    createScoreTexts();
    createScoreInitialValues();
}

void Scores::setScore(int score_)
{
    intScore+= score_;
    auto String = to_string(intScore);
    score.setString(String);
}

void  Scores::setHighScore(int highScore_)
{
    auto String = to_string(highScore_);
    highScore.setString(String);

}

void  Scores::setNumberOfLives(int numberOfLives_)
{
    auto String = to_string(numberOfLives_);
    numberOfLives.setString(String);
}

void Scores::loseLife()
{
    intNumberOfLives-=1;
    auto String = to_string(intNumberOfLives);
    numberOfLives.setString(String);
}

const sf::Text& Scores::getScore() const
{
    return score;
}

const sf::Text& Scores::getHighScore() const
{
    return highScore;
}

const sf::Text& Scores::getNumberOfLives() const
{
    return numberOfLives;
}

const sf::Text& Scores::getScoreText() const
{
    return scoreText;
}

const sf::Text& Scores::getHighScoreText() const
{
    return highScoreText;
}

const sf::Text& Scores::getNumberOfLivesText() const
{
    return numberOfLivesText;
}
