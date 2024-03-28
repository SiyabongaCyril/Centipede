#include "Mushroom.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Game.h"

using std::vector;

Mushroom::Mushroom()
{
    mushroomX = 0.f;
    mushroomY = 0.f;
    noMushrooms = 80;
    mushroomDurability = 4;
    mushroomsShot.resize( noMushrooms);
    mushroomFile = "resources/mushroom.png";
    srand(time(0));
}

void Mushroom::createMushrooms(int windowWidth, int windowHeight)
{
    for(auto i=0; i<noMushrooms; i++)
    {
        mushroomX = (rand()%windowWidth);
        mushroomY = (rand()%windowHeight)*mushroom.getEntitySize();

        mushroom.createSprite(mushroomFile,mushroomX,mushroomY);

        for(auto i=0u; i<mushrooms_.size(); i++)
        {
            bool overShadow = isColliding(mushroom.getSprite(), mushrooms_[i] );

             while ((mushroomX+mushroom.getSprite().getGlobalBounds().width >= windowWidth) ||  overShadow)
            {
                mushroomX = (rand()%windowWidth);
                mushroom.createSprite(mushroomFile,mushroomX,mushroomY);
                overShadow = isColliding(mushroom.getSprite(), mushrooms_[i] );
            }

            while ((mushroomY+mushroom.getSprite().getGlobalBounds().height > windowHeight) || overShadow)
            {
                mushroomY = (rand()%windowHeight)*mushroom.getEntitySize();
                mushroom.createSprite(mushroomFile,mushroomX,mushroomY);
                overShadow = isColliding(mushroom.getSprite(), mushrooms_[i] );
            }
        }
        generateRandomPosition(windowWidth, windowHeight);

        mushrooms_.push_back(mushroom.getSprite());
    }
}

const vector<sf::Sprite>& Mushroom::getMushrooms() const
{
    return mushrooms_;
}

vector <int>& Mushroom::getMushroomsShot()
{
    return mushroomsShot;
}

int Mushroom::checkShotMushrooms()
{
    auto counter = 0;

    for( auto j=0u; j<mushroomsShot.size(); j++)
    {
        if( mushroomsShot[j] >= mushroomDurability)
        {
            counter+=1;
            mushrooms_.erase(begin(mushrooms_) + j);
            mushroomsShot.erase(begin(mushroomsShot) + j);
        }
    }
    return counter;
}

void Mushroom::generateRandomPosition(int windowWidth, int windowHeight)
{
    for(auto i=0u; i<mushrooms_.size(); i++)
    {
        bool overShadow = isColliding(mushroom.getSprite(), mushrooms_[i] );

        while ((mushroomY+mushroom.getSprite().getGlobalBounds().height >= windowHeight) || overShadow || mushroomY <= mushroom.getEntitySize()*(1/2))
        {
            mushroomY = (rand()%windowHeight)*mushroom.getEntitySize();
            mushroom.createSprite(mushroomFile,mushroomX,mushroomY);
            overShadow = isColliding(mushroom.getSprite(), mushrooms_[i] );
        }

        while ((mushroomX+mushroom.getSprite().getGlobalBounds().width >= windowWidth) ||  overShadow)
        {
            mushroomX = (rand()%windowWidth);
            mushroom.createSprite(mushroomFile,mushroomX,mushroomY);
            overShadow = isColliding(mushroom.getSprite(), mushrooms_[i] );
        }
    }
}
