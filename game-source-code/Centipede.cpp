#include "Centipede.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

using std::vector;

Centipede::Centipede(): headSegment_{"resources/segmenthead.png"},bodySegment_{"resources/segmentblock.png"}
{
    isCentipedeNoMore = false;
}

void Centipede:: setCentipedeSize(int n)
{
    if(n<10)
    {
        sizeOfCentipede =10;
    }
    else if(n>=15)
    {
        sizeOfCentipede =15;
    }
    else
    {
        sizeOfCentipede =n;
    }
    createSegmentCollection(sizeOfCentipede);
    segmentCount =segn_.getNumberOfSegements();
}

void Centipede:: createSegmentCollection(int n)
{
    // the body
    for(auto i =0; i<n-1; i++)
    {
        segn_.creategeneralSegment(bodySegment_, i*(segn_.getSizeOfSegment()), 0.f);
         temporaryTrain.insert( temporaryTrain.begin()+i,segn_);
    }
    // the head
    headSegn_.creategeneralSegment(headSegment_,(n-1)*(segn_.getSizeOfSegment()), 0.f);
    temporaryTrain.insert( temporaryTrain.begin()+n-1,headSegn_);

    centipedeTrains.push_back( temporaryTrain);

    temporaryTrain.clear();
}

void Centipede::moveCentipede(int windowWidth, int windowHeight)
{
    for(auto i = 0u; i<centipedeTrains.size(); i++)
    {
        for(auto j = 0u; j<centipedeTrains[i].size(); j++)
        {
            centipedeTrains[i][j].moveSegment(windowWidth,windowHeight);
        }
    }
}

void Centipede::moveTrain(int windowWidth, int windowHeight, unsigned int trainIndex, unsigned int segmentIndex)
{
        centipedeTrains[trainIndex][segmentIndex].moveSegment(windowWidth,windowHeight);
}

void Centipede::eliminate(int index, int segment)
{
    decreaseSegmentCount();
    if(getSegmentCount()==0)
    {
        isCentipedeNoMore= true;
    }

    auto Size = getCentipedeTrainSize(index);

    indices.push_back(index);


    if( getCentipedeTrainSize(index) == 1 )
    {
        return;
    }
    else
    {
        for( auto i=0; i < segment-1 ; i++ )
        {
            temporaryTrain.push_back( centipedeTrains[index][i]);
        }

        if(segment>0)
        {
            centipedeTrains[index][segment-1].getSegment().setTexture( *(headSegn_.getSegment().getTexture()) );
            temporaryTrain.push_back(centipedeTrains[index][segment-1]);
            centipedeTrains.push_back(temporaryTrain);
        }

        if(!temporaryTrain.empty())
        {
            temporaryTrain.clear();
        }

        auto counter = 0;

        for( auto i= segment+1; i < Size ; i++ )
        {
            temporaryTrain.push_back( centipedeTrains[index][i] );
            counter+=1;
        }

        if( counter > 0)
        {
            centipedeTrains.push_back(temporaryTrain);
        }

        if(!temporaryTrain.empty())
        {
            temporaryTrain.clear();
        }
    }
}

void Centipede::decreaseSegmentCount()
{
    segmentCount = segmentCount -1;
}

int Centipede:: getSegmentCount() const
{
    return segmentCount;
}

bool Centipede::isCentipedeDead() const
{
    return isCentipedeNoMore;
}

vector<vector<Segments>>& Centipede::getCentipedeTrains()
{
    return centipedeTrains;
}

int Centipede::getCentipedeTrainSize(int index) const
{
    return centipedeTrains[index].size();
}

const vector<int> Centipede::getIndices() const
{
    return indices;
}

bool Centipede::checkIndices(int index) const
{
    for( auto t = 0u; t < indices.size(); t++)
    {
            if(indices[t] ==  index)
            {
                return true;
            }
    }

    return false;
}
