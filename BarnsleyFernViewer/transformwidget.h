#ifndef TRANSFORMWIDGET_H
#define TRANSFORMWIDGET_H

#include "transform.h"
#include <QObject>
#include <QWidget>
#include <QFrame>

class TransformWidget : public QFrame
{
    Q_OBJECT
public:
    explicit TransformWidget(Transform tr, QWidget *parent = nullptr);

signals:
};

#endif // TRANSFORMWIDGET_H
