#include "Draw.h"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

Draw::Draw()
{

}

void Draw::drawBullets(Window& window,Bullet& bulletObj)
{
    for( auto i=0u; i<bulletObj.getBullets().size(); i++)
    {
        window.draw(bulletObj.getBullets()[i]);
    }
}

void Draw::drawCentipede(Window& window,Centipede& centipedeObj)
{
    for(auto i = 0u; i<centipedeObj.getCentipedeTrains().size(); i++)
    {
        if( !centipedeObj.checkIndices(i) )
        {
            for(auto j = 0u; j<centipedeObj.getCentipedeTrains()[i].size(); j++)
            {
                window.draw(centipedeObj.getCentipedeTrains()[i][j].getSegment());
            }
        }
    }
}

void Draw::drawMushrooms(Window& window,Mushroom& mushroomObj)
{
    for ( auto i=1u; i<mushroomObj.getMushrooms().size(); i++)
    {
        window.draw(mushroomObj.getMushrooms()[i]);
    }
}

void Draw::drawPlayer(Window& window,Player& playerObj)
{
    window.draw( playerObj.getPlayer());
}

void Draw::drawVerticalBar(Window& window,Scores& ScoresObj)
{
    window.draw(ScoresObj.getVerticalBar());
}

void Draw::drawScores(Window& window,Scores& ScoresObj)
{
    window.draw(ScoresObj.getScoreText());
    window.draw(ScoresObj.getScore());
    window.draw(ScoresObj.getHighScoreText());
    window.draw(ScoresObj.getHighScore());
    window.draw(ScoresObj.getNumberOfLivesText());
    window.draw(ScoresObj.getNumberOfLives());
}

void Draw::drawGameIntro(Window& window,Splashscreen& splashObj)
{
    window.clearWindow();
    window.draw(splashObj.getIntroMessage());
    window.draw(splashObj.getIntruction());
    window.display();
}

void Draw:: drawGamePaused(Window& window,Splashscreen& splashObj)
{
     window.draw(splashObj.getPauseMessage() );
}
void  Draw::drawGameOver(Window& window,Splashscreen& splashObj, Scores& ScoresObj)
{
    ScoresObj.finalScore(275,300);
    window.clearWindow();
    window.draw(splashObj.getEndMessage());
    window.draw(ScoresObj.getScoreText());
    window.draw(ScoresObj.getScore());
    window.display();
}
