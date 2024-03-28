#include "Bullet.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.h"

using std::vector;

Bullet::Bullet()
{
    bulletR.createSprite("resources/bullet.png",300.0f, 559.0f);
    sf::Vector2u size_ = bulletR.getSprite().getTexture()->getSize();
    bullet = bulletR.getSprite();
    bullet.setScale(size_.x/2740.740741f,size_.y/460.f);
    bullet.setColor(sf::Color::Red);
    bullet.setOrigin(size_.x/2,size_.y/2);

    movementSpeed = -8.0f;
}

void Bullet::loadBullet(float x, float y)
{
    bullet.setPosition(x, y);
    bullets.push_back(bullet);
}

void Bullet::moveBullets(const vector<sf::Sprite>& mushrooms, vector<int>& mushroomsShot )
{
    for( auto i=0u; i<bullets.size(); i++)
    {
        bullets[i].move( 0.0f, movementSpeed);

        if( bullets[i].getPosition().y <= 0.0f)
        {
            deleteBullet(i);
        }

        for( auto j=0u; j<mushrooms.size(); j++)
        {
            if( isColliding(mushrooms[j], bullets[i]) )
            {
                deleteBullet(i);
                mushroomsShot[j] = mushroomsShot[j]+1;
            }
        }
    }
}

const vector<sf::Sprite>& Bullet::getBullets() const
{
    return bullets;
}

void Bullet::deleteBullet(int index)
{
    bullets.erase(begin(bullets) + index);
}


