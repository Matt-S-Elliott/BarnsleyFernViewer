#ifndef BARNSLEYFERNVIEWERMODEL_H
#define BARNSLEYFERNVIEWERMODEL_H

#include "transformationmanager.h"
#include <QObject>

class BarnsleyFernViewerModel : public QObject
{
    Q_OBJECT

    TransformationManager transformationManager;
public:
    explicit BarnsleyFernViewerModel(QObject *parent = nullptr);

signals:
};

#endif // BARNSLEYFERNVIEWERMODEL_H
