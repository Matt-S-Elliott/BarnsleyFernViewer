#include "transformationmanager.h"

TransformationManager::TransformationManager() {}

void TransformationManager::addTransformation() {
    transformations.push_back(Transform(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
}

std::vector<Transform>* TransformationManager::getTransformations() {
    return &transformations;
}
