#include "Player.h"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h"

Player::Player():size_{sf::Vector2u(0,0)}, windowSize{sf::Vector2f(1600,900)}, movementSpeed{4.0f}
{
    verticalBarXPos = windowSize.y;
    player.setPosition(windowSize.x/2,windowSize.y*0.98);
}

void Player::createPlayer()
{
    playerR.createSprite("resources/ship.png",verticalBarXPos/2,windowSize.y*0.98);
    size_ = playerR.getSprite().getTexture()->getSize();
    player = playerR.getSprite();

    player.setOrigin(size_.x/2,size_.y/2);
    player.setScale(0.15f, 0.3f);
    player.setColor(sf::Color::White);
}

void Player::movePlayer(Direction dir, const vector<sf::Sprite>& mushrooms)
{
    sf::Vector2f tempPosition = player.getPosition();

    if(dir == Direction::LEFT)
    {
        if( player.getPosition().x >= ((size_.y*player.getScale().y)/2) )
            player.setPosition(player.getPosition().x -movementSpeed, player.getPosition().y);
    }

    if(dir == Direction::RIGHT)
    {
        if( player.getPosition().x <= (verticalBarXPos - ((size_.y*player.getScale().y)/2)) )
            player.setPosition(player.getPosition().x +movementSpeed, player.getPosition().y);
    }

    if(dir == Direction::UP)
    {
        if( player.getPosition().y >= windowSize.y*0.75)
            player.setPosition(player.getPosition().x, player.getPosition().y-movementSpeed);
    }

    if(dir == Direction::DOWN)
    {
        if( player.getPosition().y <= (windowSize.y -  ((size_.y*player.getScale().y)/2)))
            player.setPosition(player.getPosition().x, player.getPosition().y +movementSpeed );
    }

    for( auto i=0u; i<mushrooms.size(); i++)
    {
        if( isColliding(mushrooms[i], player) )
        {
            player.setPosition( tempPosition );
        }
    }
}

const sf::Sprite& Player::getPlayer() const
{
    return player;
}

void Player::setWindowSize(sf::Vector2u Size)
{
    windowSize = Size;
}

void Player::setverticalBarXPos( float position)
{
    verticalBarXPos = position;
}

const Direction& Player::getDirection() const
{
    return path;
}

void Player::setPath(Direction dir)
{
    path = dir;
}

