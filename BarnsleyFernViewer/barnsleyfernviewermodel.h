#ifndef BARNSLEYFERNVIEWERMODEL_H
#define BARNSLEYFERNVIEWERMODEL_H

#include "transformationmanager.h"
#include "point.h"
#include <QObject>
#include <QPointF>
#include <QImage>

class BarnsleyFernViewerModel : public QObject
{
    Q_OBJECT

    TransformationManager transformationManager;
    int currentIteration;
    int iterationMax;
    Point currentPoint;
    Point startPoint;
    QImage fernImage;
    int fernImageWidth;
    int fernImageHeight;
    double xMax;
    double yMax;
    QColor fernColor;
public:
    explicit BarnsleyFernViewerModel(QObject *parent = nullptr);
    QImage* getFernImagePointer();

public slots:
    void setIterationMax(int iterations);
    void setStartPointX(double x);
    void setStartPointY(double y);
    void drawFern();
    // void drawFern(int steps);
    void resetFern();
    void setImageWidth(int width);
    void setImageHeight(int height);
    void setFernColor(QColor color);

signals:
    void fernUpdated();
};

#endif // BARNSLEYFERNVIEWERMODEL_H
