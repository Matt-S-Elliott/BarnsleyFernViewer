#ifndef BARNSLEYFERNVIEWERMODEL_H
#define BARNSLEYFERNVIEWERMODEL_H

#include "transformationmanager.h"
#include <QObject>
#include <QPointF>
#include <QImage>

class BarnsleyFernViewerModel : public QObject
{
    Q_OBJECT

    TransformationManager transformationManager;
    int currentIteration;
    int iterationMax;
    QPointF currentPoint;
    QPointF startPoint;
    QImage fernImage;
public:
    explicit BarnsleyFernViewerModel(QObject *parent = nullptr);

public slots:
    void setIterationMax(int iterations);
    void setStartPoint(QPointF point);
    void drawFern();
    void drawFern(int steps);
    void resetFern();
signals:
};

#endif // BARNSLEYFERNVIEWERMODEL_H
