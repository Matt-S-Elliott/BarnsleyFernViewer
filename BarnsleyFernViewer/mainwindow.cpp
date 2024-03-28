#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "barnsleyfernviewermodel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    BarnsleyFernViewerModel model;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
