#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <QObject>

class Transform : public QObject
{
    Q_OBJECT
public:
    explicit Transform(QObject *parent = nullptr);

signals:
};

#endif // TRANSFORM_H
