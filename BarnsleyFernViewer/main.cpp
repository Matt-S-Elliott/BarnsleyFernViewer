#include "mainwindow.h"
#include "barnsleyfernviewermodel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BarnsleyFernViewerModel model;
    MainWindow w(model);
    w.show();
    return a.exec();
}
