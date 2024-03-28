#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"

using std::string;

enum class GameState {Play,Pause,End,Default};

class Window
{
public:
    Window();
    Window(const sf::Vector2u& window_size, const string& window_title);

    void update();
    void clearWindow();
    void draw(const sf::Drawable& object);
    void display();

    sf::Vector2u getWindowSize() const;
    Direction getMovement() const;
    bool getShoot() const;
    bool getPath() const;
    GameState isPlaying() const;
    bool isClosed() const;

    void setGameOver();
    void setToDefault();
    void turnOffShoot();

private:

    GameState state;
    sf::Vector2u windowSize;
    string windowTitle;
    sf::RenderWindow window;

    void setup();
    bool closed = false;
    bool shoot = false;
    bool path = false;
    Player playerObj;
    bool isOver = false;
};

#endif // WINDOW_H
