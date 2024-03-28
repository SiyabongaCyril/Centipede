#ifndef DRAW_H
#define DRAW_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Centipede.h"
#include "Bullet.h"
#include "Splashscreen.h"
#include "Scores.h"
#include "Mushroom.h"
#include "Player.h"
#include "Window.h"

class Draw
{
public:
    Draw();
    void drawCentipede(Window& window,Centipede& centipedeObject);

    void drawBullets(Window& window,Bullet& bulletObject);
    void drawPlayer(Window& window,Player& playerObject);

    void drawMushrooms(Window& window,Mushroom& mushroomObject);
    void drawVerticalBar(Window& window,Scores& ScoresObject);
    void drawScores(Window& window,Scores& ScoresObject);

    void drawGameIntro(Window& window,Splashscreen& splashObject);
    void drawGamePaused(Window& window,Splashscreen& splashObj);
    void drawGameOver(Window& window,Splashscreen& splashObject,Scores& ScoresObj);

};

#endif // DRAW_H
