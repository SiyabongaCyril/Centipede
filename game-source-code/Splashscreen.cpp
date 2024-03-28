#include "Splashscreen.h"

Splashscreen::Splashscreen()
{
     screenFontFile = "resources/BAUHS93.TTF";
     setIntroMessage();
     setIntruction();
     setEndMessage();
}

/// MESSAGES
void Splashscreen::setIntroMessage()
{
    auto introText = "Welcome to Centipede++";
    screen.createMessage(introText,screenFontFile,50,150,150);
    introMessage = screen.getMessage();
}

const sf::Text& Splashscreen:: getIntroMessage() const
{
    return introMessage;
}

void Splashscreen::setIntruction()
{
    auto instruct = "enter: Start Game\n Press arrow keys to move the player \nspacebar: Shoot\n p: Pause Game\n o: Continue\n q : Quit";
    screen.createMessage(instruct,screenFontFile,30,150,300);
    instructions = screen.getMessage();
}

const sf::Text& Splashscreen:: getIntruction() const
{
    return instructions;
}

void Splashscreen::setEndMessage()
{
    auto outroText = "GAME OVER";
    screen.createMessage(outroText,screenFontFile, 50,275,200);
    endMessage = screen.getMessage();
}

const sf::Text& Splashscreen:: getEndMessage() const
{
    return endMessage;
}

void Splashscreen::setPauseMessage()
{
    auto pauseText = "PAUSED";
    screen.createMessage(pauseText,screenFontFile, 50,250,250);
    pauseMessage = screen.getMessage();
    pauseMessage.setColor(sf::Color(0, 255, 255, 1));
 }

const sf::Text& Splashscreen::getPauseMessage() const
{
   return pauseMessage;
}

void Splashscreen::setMessages()
{
    setIntroMessage();
    setIntruction();
    setEndMessage();
    setPauseMessage();
}
