#include "point.h"
#include <iostream>

Point::Point(QObject *parent)
    : QObject{parent}
{}


Point::Point(double initx, double inity, QObject *parent) : x(initx), y(inity), QObject(parent) {

}

double Point::getX() {
    return x;
}

double Point::getY() {
    return y;
}

// Operators
Point Point::operator*(double scaleFactor) {
    Point res(x*scaleFactor, y*scaleFactor);
    return res;
}

// This doesn't start with Point:: so it is not class code.
std::ostream& operator<<(std::ostream& output, Point pt) {
    output << pt.x << ", " << pt.y;
    return output;
}
