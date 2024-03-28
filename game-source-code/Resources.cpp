#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include <string>

using std::string;

Resources::Resources()
{
    //ctor
}
/// Sprites
bool Resources::loadTexture(std::string fileName)
{
    if(txt_.loadFromFile(fileName))
    {
        return true;
    }
    else
    {
        throw FileCannotBeLoaded{};
    }
}

void Resources::createSprite(std::string fileName, float x, float y)
{
    if(loadTexture(fileName))
    {
        sp_.setTexture(txt_);
         sf::Vector2u sizeOfTexture_ = txt_.getSize();
        sizeOfEntity_ = 13;
        sp_.setScale(sizeOfEntity_/sizeOfTexture_.x,sizeOfEntity_/sizeOfTexture_.y);
        sp_.setPosition(x,y);
    }
}

const sf::Sprite& Resources :: getSprite() const
{
    return sp_;
}

float Resources:: getEntitySize() const
{
    return sizeOfEntity_;
}

/// Fonts
bool Resources::loadTextFont(std::string fontFile)
{
    if(font.loadFromFile(fontFile))
    {
        return true;
    }
    else
    {
        throw FontCannotBeLoaded{};
    }
}

void Resources::createMessage(std::string message,std::string fontFile, int fontSize, float x, float y)
{
    if(loadTextFont(fontFile))
    {
        text_.setFont(font);
        text_.setCharacterSize(fontSize);
        text_.setPosition(sf::Vector2f(x,y));

        text_.setOrigin(sf::Vector2f(Font_size.width/2, Font_size.height/2));
        text_.setFillColor(sf::Color::Cyan);
        text_.setString(message);
    }
}

const sf::Text& Resources:: getMessage() const
{
    return text_;
}
