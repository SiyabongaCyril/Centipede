#ifndef GAME_H
#define GAME_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Centipede.h"
#include "Bullet.h"
#include "Splashscreen.h"
#include "Scores.h"
#include "Mushroom.h"
#include "Player.h"
#include "Draw.h"
#include "Update.h"


class Game
{
public:
    Game();

    void run();

private:

    void update();
    void render();

    Window gameWindow;
    Player playerObj;
    Centipede centipedeObj;
    Bullet bulletObj;
    Splashscreen splashObj;
    Mushroom mushroomObj;
    Scores scoreObj;
    Draw display;
    Update updateObj;

};

#endif // GAME_H
