#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Resources.h"

class Splashscreen
{
public:
    Splashscreen();

    /// MESSAGES
    void setMessages();

    const sf::Text& getIntroMessage() const;
    const sf::Text& getIntruction() const;
    const sf::Text& getEndMessage() const;
    const sf::Text& getPauseMessage() const;

private:
    Resources screen;
    std::string screenFontFile;

    void setIntroMessage();
    sf::Text introMessage;

    void setIntruction();
    sf::Text instructions;

    void setPauseMessage();
    sf::Text pauseMessage;

    void setEndMessage();
    sf::Text endMessage;

};

#endif // SPLASHSCREEN_H
