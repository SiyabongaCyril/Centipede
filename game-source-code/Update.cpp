#include "Update.h"

Update::Update()
{
    //ctor
}

void Update::moveCentipede(Centipede& centipedeObj, Scores& scoreObj, Window& gameWindow )
{
    for( auto i = 0u; i < centipedeObj.getCentipedeTrains().size(); i++)
    {
        if( !centipedeObj.checkIndices(i) )
        {
            centipedeObj.moveCentipede(scoreObj.getVerticalBar().getPosition().x,gameWindow.getWindowSize().y);
        }
    }
}

void Update::updatePlayerMoves(Window& gameWindow, Mushroom& mushroomObj, Player& playerObj)
{
    if(gameWindow.getPath())
    {
        playerObj.movePlayer( gameWindow.getMovement(), mushroomObj.getMushrooms() ) ;
    }
}

void Update:: updateBullets(Window&gameWindow, Bullet& bulletObj, Player& playerObj)
{
    if(gameWindow.getShoot())
    {
        bulletObj.loadBullet( playerObj.getPlayer().getPosition().x, playerObj.getPlayer().getPosition().y);
        gameWindow.turnOffShoot();
    }
}


void Update:: updateCentipedeLife(Centipede& centipedeObj, Window& gameWindow)
{
    if(centipedeObj.isCentipedeDead())
    {
        gameWindow.setGameOver();
    }
}

void Update:: CentipedePlayer(Centipede& centipedeObj,Window& gameWindow, Player& playerObj)
{
    for( auto s=0u; s < centipedeObj.getCentipedeTrains().size(); s++)
    {
        if( !centipedeObj.checkIndices(s) )
        {
            for( auto j=0u; j<centipedeObj.getCentipedeTrains()[s].size(); j++)
            {
                if( isColliding(playerObj.getPlayer(), centipedeObj.getCentipedeTrains()[s][j].getSegment() ) )
                {
                    gameWindow.setGameOver();
                    break;
                }
            }
        }
    }
}

void Update::CentipedeAndBullet(Bullet& bulletObj, Centipede& centipedeObj, Scores& scoreObj)
{
    for( auto i=0u; i<bulletObj.getBullets().size(); i++)
    {
        for( auto s=0u; s < centipedeObj.getCentipedeTrains().size(); s++)
        {
            if( !centipedeObj.checkIndices(s) )
            {
                for( auto j=0u; j<centipedeObj.getCentipedeTrains()[s].size(); j++)
                {
                    if( isColliding(bulletObj.getBullets()[ i ], centipedeObj.getCentipedeTrains()[s][j].getSegment() ) )
                    {
                        centipedeObj.eliminate( s, j );
                        bulletObj.deleteBullet(i);

                        if( centipedeObj.getCentipedeTrains()[s].size()-1 == j)
                        {
                            scoreObj.setScore(100);
                        }
                        else
                        {
                            scoreObj.setScore(10);
                        }

                        break;
                    }
                }
            }

        }
    }
}

void Update::CentipedeMushroom(Mushroom& mushroomObj,Centipede& centipedeObj, Window& gameWindow)
{
    for(auto i=1u; i<mushroomObj.getMushrooms().size(); i++)
    {
        for( auto s=0u; s < centipedeObj.getCentipedeTrains().size(); s++)
        {
            if( !centipedeObj.checkIndices(s) )
            {
                for( auto j=0u; j<centipedeObj.getCentipedeTrains()[s].size(); j++)
                {
                    if( isColliding(mushroomObj.getMushrooms()[i], centipedeObj.getCentipedeTrains()[s][j].getSegment() ) )
                    {
                        auto x1 = mushroomObj.getMushrooms()[i].getPosition().x;

                        auto c = centipedeObj.getCentipedeTrains()[s][j].getSegment().getPosition().x;

                        if(c<x1)
                        {
                            centipedeObj.moveTrain(x1, gameWindow.getWindowSize().y, s, j);
                        }
                        if (c>x1)
                        {
                            centipedeObj.moveTrain(x1, gameWindow.getWindowSize().y, s, j);
                        }
                    }
                }
            }

        }
    }
}

bool isColliding (const sf::Sprite& entity_1, const sf::Sprite& entity_2)
{
    sf::FloatRect playerBoundingBox_1 =  entity_1.getGlobalBounds();
    sf::FloatRect playerBoundingBox_2 =  entity_2.getGlobalBounds();

    if (playerBoundingBox_1.intersects(playerBoundingBox_2))
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}
