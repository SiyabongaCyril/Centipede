#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include <vector>

using std::vector;

enum class Direction {LEFT,RIGHT,UP,DOWN};

class Player
{
public:
    Player();

    void movePlayer(Direction dir, const vector<sf::Sprite>& mushrooms);
    void createPlayer();

    const sf::Sprite& getPlayer() const;
    const Direction&  getDirection() const;

    void setverticalBarXPos( float position);
    void setWindowSize( sf::Vector2u Size);
    void setPath(Direction dir);

private:

    Resources playerR;

    sf::Sprite player;
    sf::Texture playerTexture;
    sf::Vector2u size_;
    sf::Vector2u windowSize;

    float verticalBarXPos;
    float movementSpeed;

    Direction path;

};

#endif // PLAYER_H
