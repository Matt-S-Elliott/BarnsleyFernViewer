#ifndef TRANSFORMATIONMANAGER_H
#define TRANSFORMATIONMANAGER_H

#include "transform.h"
#include <vector>
#include <QRandomGenerator>

class TransformationManager
{
private:
    std::vector<Transform> transformations;
    double currentTotalProbability;
    Transform* selectTransform();
    QRandomGenerator rand;
    qint32 currentSeed;

public:
    TransformationManager();

    TransformationManager(qint32 seed);

    void addTransformation();

    // Adds a tr with all values set to 0
    void addTransformation(Transform tr);

    // If tr brings the currentTotalProbability above one, it will not be updated.
    // index must be between 0 - 5 inclusive.
    // Returns true if tr was updated, false if not.
    bool updateTransform(Transform tr, int index);

    // Modifies the pt provided by a random transform in the
    // TransformationManager based off the probabilities of the transforms.
    void transformPoint(Point& pt);

    // Manually set seed for the rng
    void setSeed(qint32 seed);

    // Resets the rng
    void resetRand();
};

#endif // TRANSFORMATIONMANAGER_H
