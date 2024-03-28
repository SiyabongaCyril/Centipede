#include "Segments.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>

int Segments::noSegments =0;

Segments::Segments()
{
    segmentDistance_.x = 0;
    segmentDistance_.y =0;
    inrement = 1.5;
    up = false;
}

Segments::Segments(const Segments &obj)
{
    noSegments=obj.noSegments;
    row_=obj.row_;
    segment=obj.segment;
    segmentBlock_=obj.segmentBlock_;
    segmentDistance_=obj.segmentDistance_;
    size_=obj.size_;
    segmentDistance_.x = obj.segmentDistance_.x;
    segmentDistance_.y = obj.segmentDistance_.y;
    inrement = obj.inrement;
    up = obj.up;
}

void Segments::increaseNoSegments()
{
    noSegments++;
}
int Segments::getNumberOfSegements()
{
    return noSegments;
}

/// Create a general segment
void Segments::creategeneralSegment(std::string segmentType, float x, float y)
{
    increaseNoSegments();
    segment.createSprite(segmentType,x,y);
    row_ = segment.getEntitySize();
    size_ =segment.getSprite().getTexture()->getSize();
    segmentBlock_ = segment.getSprite();
}

void Segments::moveHorizontal()
{
    segmentDistance_.x =  segmentBlock_.getPosition().x;
    segmentDistance_.x  += inrement;
}

void Segments::moveDown()
{
    segmentDistance_.y =  segmentBlock_.getPosition().y;
    segmentDistance_.y  += abs(row_);
    inrement=  - inrement;
}

void Segments::moveUp()
{
    segmentDistance_.y =  segmentBlock_.getPosition().y;
    segmentDistance_.y  -= abs(row_);
    inrement=  - inrement;
}

void Segments::moveUpFirst()
{
    segmentDistance_.y =  segmentBlock_.getPosition().y;
    segmentDistance_.y  -= abs(row_);
}

/// Collisions
void Segments:: moveSegment(int xBound, int yBound)
{
    /// To move horizonatlly
    if( (segmentBlock_.getPosition().x >=0 && segmentBlock_.getPosition().x + segmentBlock_.getGlobalBounds().width <= xBound))
    {
        moveHorizontal();
    }
    /// To move down
    if( segmentBlock_.getPosition().x <0 )
    {
        segmentBlock_.setPosition(0, segmentBlock_.getPosition().y);
        if(up == false)
        moveDown();
        else
            moveUp();

        moveHorizontal();
    }

    else if (segmentBlock_.getPosition().x +  segmentBlock_.getGlobalBounds().width> xBound)
    {
        segmentBlock_.setPosition(xBound - segmentBlock_.getGlobalBounds().width,
                                  segmentBlock_.getPosition().y);
        if(up == false)
        moveDown();
        else
        moveUp();
        moveHorizontal();
    }
    /// Player Bound
    if(segmentBlock_.getPosition().y +  segmentBlock_.getGlobalBounds().height> yBound)
    {
        up = true;
        moveUpFirst();
    }

    if( up == true)
    {
        if( segmentDistance_.y <  0.75*yBound )
            up = false;
    }
    segmentBlock_.setPosition(segmentDistance_);
}

/// Return a segment
float Segments::getSizeOfSegment() const
{
    return row_;;
}

sf::Sprite& Segments::getSegment()
{
    return segmentBlock_;
}
