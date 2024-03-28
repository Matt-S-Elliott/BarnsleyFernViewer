#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "barnsleyfernviewermodel.h"
#include <QPainter>

MainWindow::MainWindow(BarnsleyFernViewerModel& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    fernImagePointer = model.getFernImagePointer();
    transformsPointer = model.getTransformsPointer();
    ui->setupUi(this);

    connect(ui->drawFernButton,
            &QPushButton::clicked,
            &model,
            &BarnsleyFernViewerModel::drawFern);

    connect(&model,
            &BarnsleyFernViewerModel::fernUpdated,
            this,
            [this]{this->repaint();});

    connect(&model,
            &BarnsleyFernViewerModel::transformsUpdated,
            this,
            &MainWindow::updateTransformsList);
}

void MainWindow::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QRect rect = ui->drawPanel->frameGeometry();
    painter.drawImage(rect, *fernImagePointer);
}

void MainWindow::updateTransformsList() {
    for (Transform tr : *transformsPointer) {

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
