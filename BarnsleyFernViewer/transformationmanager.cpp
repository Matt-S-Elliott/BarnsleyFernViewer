#include "transformationmanager.h"
#include <vector>

TransformationManager::TransformationManager() {
    currentSeed = 1;
    currentTotalProbability = 0;
    rand = QRandomGenerator::securelySeeded();
}

std::vector<Transform>* TransformationManager::getTransformsPointer() {
    return &transformations;
}


void TransformationManager::addTransformation() {
    transformations.push_back(Transform(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
}

void TransformationManager::addTransformation(Transform tr) {
    if (currentTotalProbability + tr.getProbability() <= 100) {
        currentTotalProbability += tr.getProbability();
        transformations.push_back(tr);
    }
}

bool TransformationManager::updateTransform(Transform tr, int index) {
    double newProbability = currentTotalProbability + tr.getProbability() - transformations[index].getProbability();
    if (newProbability <= 1) {
        transformations[index] = tr;
        return true;
    }
    return false;
}

void TransformationManager::transformPoint(Point& pt) {
    pt *= *selectTransform();
}

void TransformationManager::setSeed(qint32 seed) {
    currentSeed = seed;
    rand = QRandomGenerator(seed);
    currentSeedMode = TransformationManager::SeedMode::Deterministic;
}

void TransformationManager::useSecureSeed() {
    rand = QRandomGenerator::securelySeeded();
    currentSeedMode = TransformationManager::SeedMode::Secure;
}

void TransformationManager::resetRand() {
    if (currentSeedMode == TransformationManager::SeedMode::Deterministic)
        rand = QRandomGenerator(currentSeed);
    else
        rand = QRandomGenerator::securelySeeded();
}

Transform* TransformationManager::selectTransform() {
    double randomValue = rand.generateDouble();
    double probSum = 0;

    for (int i = 0; i < (int)transformations.size(); i++) {
        // Multiply by reciprocal of currentTotalProbability to account for probability totals less than 1.0
        probSum += (transformations[i].getProbability() * (1.0 / currentTotalProbability));
        if (randomValue <= probSum)
            return &transformations[i];
    }
    return nullptr;
}
