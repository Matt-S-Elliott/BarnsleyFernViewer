#include "barnsleyfernviewermodel.h"
#include "transformationmanager.h"
#include "transform.h"

BarnsleyFernViewerModel::BarnsleyFernViewerModel(QObject *parent)
    : QObject{parent}, currentIteration(0), iterationMax(10000),  currentPoint(QPointF()), startPoint(QPointF())
{
    transformationManager.addTransformation(Transform (0.0, 0.0, 0.0, 0.0, .16, 0.0, 0.01));
    transformationManager.addTransformation(Transform (.85, .04, 0.0, -.04, .85, 1.6, 0.85));
    transformationManager.addTransformation(Transform (.20, -.26, 0.0, .23, .22, 1.6, 0.07));
    transformationManager.addTransformation(Transform (-.15, .28, 0.0, .26, .24, .44, 0.07));
    fernImage = QImage(1000, 1000, QImage::Format_RGBA8888);
    fernImage.fill(Qt::white);
}

void BarnsleyFernViewerModel::setIterationMax(int iterations) {
   iterationMax = iterations;
}

void BarnsleyFernViewerModel::setStartPoint(QPointF point) {
    startPoint = point;
}

void BarnsleyFernViewerModel::drawFern() {
    for (;currentIteration < iterationMax; currentIteration++) {

    }
}

void BarnsleyFernViewerModel::drawFern(int steps) {

}

void BarnsleyFernViewerModel::resetFern() {
    currentIteration = 0;
    currentPoint = startPoint;
    fernImage.fill(Qt::white);
}
