#ifndef RESOURCES_H
#define RESOURCES_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>

using std::string;

class FileCannotBeLoaded{};
class FontCannotBeLoaded{};

class Resources
{
public:
    Resources();

    void createSprite(std::string fileName, float x, float y);
    void createMessage(std::string message,std::string fontFile, int fontSize, float x, float y);

    const sf::Sprite& getSprite() const;
    const sf::Text& getMessage() const;
    float getEntitySize() const;

private:
    /// Sprites
    sf::Sprite sp_;
    sf::Texture txt_;
    float sizeOfEntity_;
    bool loadTexture(std::string textureFile);

    /// Fonts and Messages
    sf::Font font;
    sf::Text text_;
    sf::FloatRect Font_size;
    bool loadTextFont(std::string fontFile);
};

#endif // RESOURCES_H
