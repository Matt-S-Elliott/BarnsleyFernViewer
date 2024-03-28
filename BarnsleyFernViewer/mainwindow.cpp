#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "barnsleyfernviewermodel.h"
#include <QPainter>

MainWindow::MainWindow(BarnsleyFernViewerModel& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    fernImagePointer = model.getFernImagePointer();
    ui->setupUi(this);

    connect(ui->drawFernButton,
            &QPushButton::clicked,
            &model,
            &BarnsleyFernViewerModel::drawFern);

    connect(&model,
            &BarnsleyFernViewerModel::fernUpdated,
            this,
            [this]{this->repaint();});
}

void MainWindow::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QRect rect = ui->drawPanel->frameGeometry();
    painter.drawImage(rect, *fernImagePointer);
}

MainWindow::~MainWindow()
{
    delete ui;
}
