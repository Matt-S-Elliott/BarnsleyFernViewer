#include "barnsleyfernviewermodel.h"
#include "transformationmanager.h"
#include "transform.h"
#include "point.h"

BarnsleyFernViewerModel::BarnsleyFernViewerModel(QObject *parent)
    : QObject{parent},
    currentIteration(0),
    iterationMax(1000000),
    fernImageWidth(1000),
    fernImageHeight(1000),
    xMax(2.75),
    yMax(10.5),
    fernColor(Qt::green)
{
    transformationManager.addTransformation(Transform (0.0, 0.0, 0.0, 0.0, .16, 0.0, 0.01));
    transformationManager.addTransformation(Transform (.85, .04, 0.0, -.04, .85, 1.6, 0.85));
    transformationManager.addTransformation(Transform (.20, -.26, 0.0, .23, .22, 1.6, 0.07));
    transformationManager.addTransformation(Transform (-.15, .28, 0.0, .26, .24, .44, 0.07));
    fernImage = QImage(1000, 1000, QImage::Format_RGBA8888);
    fernImage.fill(Qt::white);

    emit transformsUpdated();
}

QImage* BarnsleyFernViewerModel::getFernImagePointer() {
    return &fernImage;
}

std::vector<Transform>* BarnsleyFernViewerModel::getTransformsPointer() {
    return transformationManager.getTransformsPointer();
}

void BarnsleyFernViewerModel::setIterationMax(int iterations) {
   iterationMax = iterations;
}

void BarnsleyFernViewerModel::setStartPointX(double x) {
    startPoint.x = x;
}

void BarnsleyFernViewerModel::setStartPointY(double y) {
    startPoint.y = y;
}

void BarnsleyFernViewerModel::setImageWidth(int width) {
    fernImageWidth = width;
    resetFern();
}

void BarnsleyFernViewerModel::setImageHeight(int height) {
    fernImageHeight = height;
    resetFern();
}

void BarnsleyFernViewerModel::setFernColor(QColor color) {
    fernColor = color;
}

void BarnsleyFernViewerModel::drawFern() {
    for (;currentIteration < iterationMax; currentIteration++) {
        int pixelX = fernImageWidth / 2 + (int)(fernImageWidth * currentPoint.x) / xMax / 2;
        int pixelY = fernImageHeight - 1 - (int)(fernImageHeight * currentPoint.y) / yMax;
        fernImage.setPixelColor(pixelX, pixelY, fernColor);
        transformationManager.transformPoint(currentPoint);
    }
    emit fernUpdated();
}

// void BarnsleyFernViewerModel::drawFern(int steps) {
//     for (int i = 0; i < steps && currentIteration < iterationMax;) {
//         int pixelX = fernImageWidth / 2 + (int)(fernImageWidth * currentPoint.x) / xMax / 2;
//         int pixelY = (int)(fernImageHeight * currentPoint.y) / yMax;
//         fernImage.setPixelColor(pixelX, pixelY, fernColor);
//         transformationManager.transformPoint(currentPoint);
//         currentIteration++;
//         i++;
//     }
//     emit fernUpdated();
// }

void BarnsleyFernViewerModel::resetFern() {
    currentIteration = 0;
    currentPoint = startPoint;
    fernImage = QImage(fernImageWidth, fernImageHeight, QImage::Format_RGBA8888);
    fernImage.fill(Qt::white);
}
