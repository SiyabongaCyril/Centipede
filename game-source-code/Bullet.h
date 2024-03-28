#ifndef BULLET_H
#define BULLET_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Resources.h"

using std::vector;

class Bullet
{
    public:
    Bullet();

    void loadBullet(float x, float y);
    void moveBullets(const vector<sf::Sprite>& mushrooms, vector<int>& mushroomsShot);
    void deleteBullet(int index);

    const vector<sf::Sprite>& getBullets() const;

    private:

    Resources bulletR;
    float movementSpeed;

    vector<sf::Sprite> bullets;
    sf::Sprite bullet;
};

#endif // BULLET_H
