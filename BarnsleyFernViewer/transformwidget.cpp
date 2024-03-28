#include "transformwidget.h"
#include "transform.h"
#include <QGridLayout>


TransformWidget::TransformWidget(Transform tr, QWidget *parent)
    : QFrame{parent}
{
    setFrameStyle(QFrame::Box | QFrame::Raised);

    QGridLayout layout(this);
}
