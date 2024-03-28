#include "transform.h"


#include "transform.h"
#include "point.h"
#include <iostream>

Transform::Transform() {
    for (int i =0; i < 6; i++)
        parameters.push_back(0);
    probability = 0;
}

Transform::Transform(double a, double b, double c, double d, double e, double f, double probability) : probability(probability) {
    parameters.push_back(a);
    parameters.push_back(b);
    parameters.push_back(c);
    parameters.push_back(d);
    parameters.push_back(e);
    parameters.push_back(f);
}

std::vector<double>* Transform::getParameters() {
    return &parameters;
}

double Transform::getProbability() {
    return probability;
}

void Transform::setProbability(double newProb) {
    if (newProb <= 0 || newProb > 1)
        return;
    probability = newProb;
}

Point Transform::operator*(Point point) {
    double newX = ((parameters[0] * point.x) + (parameters[1] * point.y) + parameters[2]);
    double newY = ((parameters[3] * point.x) + (parameters[4] * point.y) + parameters[5]);
    Point result(newX, newY);
    return result;
}

Point& operator*=(Point& point, Transform transform) {
    double newX = ((transform.parameters[0] * point.x) + (transform.parameters[1] * point.y) + transform.parameters[2]);
    double newY = ((transform.parameters[3] * point.x) + (transform.parameters[4] * point.y) + transform.parameters[5]);
    point.x = newX;
    point.y = newY;
    return point;
}

std::ostream& operator<<(std::ostream& output, Transform tr) {
    output << "[" << tr.parameters[0] << ", " << tr.parameters[1] << ", " << tr.parameters[2] << ", " << tr.parameters[3] << ", " << tr.parameters[4] << ", " << tr.parameters[5] << "]";
    return output;
}
