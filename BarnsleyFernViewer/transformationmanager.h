#ifndef TRANSFORMATIONMANAGER_H
#define TRANSFORMATIONMANAGER_H

#include "transform.h"
#include <vector>

class TransformationManager
{
private:
    std::vector<Transform> transformations;
public:
    TransformationManager();
    void addTransformation();
    std::vector<Transform>* getTransformations();

};

#endif // TRANSFORMATIONMANAGER_H
