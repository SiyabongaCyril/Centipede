#ifndef UPDATE_H
#define UPDATE_H

#include "Centipede.h"
#include "Bullet.h"
#include "Splashscreen.h"
#include "Scores.h"
#include "Mushroom.h"
#include "Player.h"
#include "Window.h"

bool isColliding (const sf::Sprite& entity_1, const sf::Sprite& entity_2);

class Update
{
public:
    Update();

    void moveCentipede(Centipede& centipedeObj, Scores& scoreObj, Window& gameWindow );
    void updatePlayerMoves(Window& gameWindow, Mushroom& mushroomObj, Player& playerObj);
    void updateBullets(Window&gameWindow, Bullet& bulletObj, Player& playerObj);

    void updateCentipedeLife(Centipede& centipedeObj, Window& gameWindow);

    void CentipedePlayer(Centipede& centipedeObj,Window& gameWindow, Player& playerObj);
    void CentipedeAndBullet(Bullet& bulletObj, Centipede& centipedeObj, Scores& scoreObj);
    void CentipedeMushroom(Mushroom& mushroomObj,Centipede& centipedeObj, Window& gameWindow);
};

#endif // UPDATE_H
