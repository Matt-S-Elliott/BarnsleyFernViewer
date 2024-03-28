#ifndef POINT_H
#define POINT_H

#include <QObject>

class Transform;

class Point : public QObject
{
private:
    Q_OBJECT

    double x,y;

public:
    explicit Point(QObject *parent = nullptr);
    // default constructor initializes to (0, 0)
    Point();
    // This constructor takes initial values
    Point(double initX, double initY, QObject *parent = nullptr);
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
