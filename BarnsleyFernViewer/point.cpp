#include "point.h"
#include <iostream>

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(double initx, double inity) : x(initx), y(inity){}

// Operators
Point Point::operator*(double scaleFactor) {
    Point res(x*scaleFactor, y*scaleFactor);
    return res;
}

Point::~Point(){}

// This doesn't start with Point:: so it is not class code.
std::ostream& operator<<(std::ostream& output, Point pt) {
    output << pt.x << ", " << pt.y;
    return output;
}
