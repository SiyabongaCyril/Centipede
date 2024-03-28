#include "Game.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

Game::Game(): gameWindow{sf::Vector2u (800,600),  "Centipede++"}
{
    centipedeObj.setCentipedeSize(13);
}

void Game::run()
{
    scoreObj.setWindowSize(gameWindow.getWindowSize());

    playerObj.setWindowSize( gameWindow.getWindowSize() );
    playerObj.setverticalBarXPos(scoreObj.getVerticalBar().getPosition().x);
    playerObj.createPlayer();

    mushroomObj.createMushrooms((scoreObj.getVerticalBar().getPosition().x),gameWindow.getWindowSize().y);

    if( gameWindow.isPlaying() == GameState::Default )
    {
        splashObj.setMessages();
    }

    while(!gameWindow.isClosed() )
    {
        while( gameWindow.isPlaying() == GameState::Pause)
        {
            display.drawGamePaused(gameWindow,splashObj);

            gameWindow.display();

            if(gameWindow.isClosed())
            {
                break;
            }
            else
            {
                //View Window events
                gameWindow.update();
            }
        }

        //Update Objects
        update();

        //Render Objects
        if((gameWindow.isPlaying() == GameState::Play))
        {
            render();
        }
        //Render Splashscreens
        else if( gameWindow.isPlaying() == GameState::Default)
        {
            display.drawGameIntro(gameWindow,splashObj);
        }
        else if( gameWindow.isPlaying() == GameState::End )
        {
            display.drawGameOver(gameWindow,splashObj,scoreObj);
        }
    }
}

void Game::update()
{
    gameWindow.update();

    if( (gameWindow.isPlaying() == GameState::Play))
    {

        /// Moving the Centipede
        updateObj.moveCentipede(centipedeObj,scoreObj,gameWindow);

        /// Moving the Player
        updateObj.updatePlayerMoves(gameWindow,mushroomObj,playerObj);

        /// Shoot Bullet
        updateObj.updateBullets(gameWindow, bulletObj, playerObj);

        /// Move Bullet
        bulletObj.moveBullets(mushroomObj.getMushrooms(), mushroomObj.getMushroomsShot());

        ///Eliminate mushrooms that were shot 3 times
        scoreObj.setScore( mushroomObj.checkShotMushrooms() );

        /// Centipede and Bullet Collision
        updateObj.CentipedeAndBullet(bulletObj,centipedeObj,scoreObj);

        /// Centipede & Mushroom Collision
        updateObj.CentipedeMushroom(mushroomObj,centipedeObj,gameWindow);

        /// Centipede & Player Collision
        updateObj.CentipedePlayer(centipedeObj,gameWindow,playerObj);

        /// Track Life-span of the Centipede
        updateObj.updateCentipedeLife(centipedeObj,gameWindow);
    }

}

void Game::render()
{
    ///Clear Window
    gameWindow.clearWindow();

    ///Draw Vertical bar
    display.drawVerticalBar(gameWindow,scoreObj);

    ///Draw Player
    display.drawPlayer(gameWindow,playerObj);

    ///Draw Bullets
    display.drawBullets(gameWindow,bulletObj);

    /// Draw the centipede
    display.drawCentipede(gameWindow,centipedeObj);

    /// Draw Mushrooms
    display.drawMushrooms(gameWindow,mushroomObj);

    /// Draw Scores
    display.drawScores(gameWindow,scoreObj);

    ///Display
    gameWindow.display();
}

