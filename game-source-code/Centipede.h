#ifndef CENTIPEDE_H
#define CENTIPEDE_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Segments.h"
#include "Resources.h"

using std::vector;
using std::string;

class Centipede
{
public:

    Centipede();

    void setCentipedeSize(int);
    void createSegmentCollection(int);
    void eliminate(int index, int segment);
    void decreaseSegmentCount();
    void moveCentipede(int, int);
    void moveTrain(int windowWidth, int windowHeight, unsigned int trainIndex, unsigned int segmentIndex);

    vector<vector<Segments>>& getCentipedeTrains();
    int getCentipedeTrainSize(int index) const;
    const vector<int> getIndices() const;
    bool isCentipedeDead() const;
    bool checkIndices(int index) const;

private:

    const string headSegment_;
    const string bodySegment_;
    Segments segn_;
    Segments headSegn_;

    vector<vector<Segments>> centipedeTrains;
    vector <Segments> temporaryTrain;
    vector<int> indices;

    int sizeOfCentipede;
    bool isCentipedeNoMore;
    int segmentCount;
    int getSegmentCount() const;
};

#endif // CENTIPEDE_H
