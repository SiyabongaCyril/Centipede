#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "Resources.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class Mushroom
{
public:
    Mushroom();

    const vector<sf::Sprite>& getMushrooms() const;
    vector <int>& getMushroomsShot();
    void createMushrooms(int windowWidth, int windowHeight);
    int checkShotMushrooms();

private:

    Resources mushroom;
    vector<sf::Sprite> mushrooms_;
    vector <int> mushroomsShot;
    string mushroomFile;
    float mushroomX;
    float mushroomY;
    int noMushrooms;
    int mushroomDurability;

    void generateRandomPosition(int windowWidth, int windowHeight);

};

#endif // MUSHROOM_H
