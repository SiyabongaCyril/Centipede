#ifndef SEGMENTS_H
#define SEGMENTS_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "Resources.h"

class Segments
{
public:
    Segments();
    Segments( const Segments &obj);  // copy constructor

    /// Sprite Creation
    void creategeneralSegment(std::string segmentType, float x, float y);
    static void increaseNoSegments();
    static int getNumberOfSegements();

    /// Movements
    void moveHorizontal();
    void moveDown();
    void moveUp();
    void moveUpFirst();
    void moveSegment(int windowWidth, int windowHeight);

    /// Get Sprite
    sf::Sprite& getSegment();
    float getSizeOfSegment() const;

private:

    /// Sprite properties
    Resources segment;
    sf::Sprite segmentBlock_;
    float row_;
    sf::Vector2u size_;
    static int noSegments;

    /// Movement variables
    sf::Vector2f segmentDistance_;
    int inrement;
    bool up;
};

#endif // SEGMENTS_H
