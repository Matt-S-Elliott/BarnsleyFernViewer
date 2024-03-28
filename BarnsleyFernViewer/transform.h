#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <QObject>
class Point;

class Transform
{
private:
    // The parameters of the transform.
    double a, b, c, d, e, f;
public:
    // Constructs a transform from the 6 provided doubles.
    Transform(double a, double b, double c, double d, double e, double f);

    // Takes an array that can contain at least 6 doubles.
    // Puts the transform values a, b, c, d, e, and f into the first 6 values of the array in order.
    void getParameters(double* arr);

    // Allows operations like "Point pt = transform * otherPoint"
    Point operator*(Point point);

    // Friend *= operator to make transforming points easy
    friend Point& operator*=(Point& point, Transform transform);
    // Friend insertion operator to make printing easy
    friend std::ostream& operator<<(std::ostream& output, Transform tr);
signals:
};

#endif // TRANSFORM_H
