#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "barnsleyfernviewermodel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
private:
    Q_OBJECT

    QImage* fernImagePointer;
    std::vector<Transform>* transformsPointer;
    Ui::MainWindow *ui;

public:

    MainWindow(BarnsleyFernViewerModel& model, QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);

    ~MainWindow();

public slots:
        void updateTransformsList();

};
#endif // MAINWINDOW_H
