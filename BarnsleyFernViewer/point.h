#ifndef POINT_H
#define POINT_H

#include <QObject>

class Transform;

class Point
{
private:
    double x,y;

public:
    // default constructor initializes to (0, 0)
    Point();
    // This constructor takes initial values
    Point(double initX, double initY);
    // The deconstructor does nothing because we didn't allocate any new memory
    ~Point();
    // Getter for the x value
    double getX();
    // Getter for the y value
    double getY();
    // Operators
    Point operator*(double scaleFactor);
    // Friend insertion operator to make printing easy
    friend std::ostream& operator<<(std::ostream& output, Point pt);
    // Friend *= operator to make transforming points easy
    friend Point& operator*=(Point& point, Transform transform);

signals:
};

#endif // POINT_H
