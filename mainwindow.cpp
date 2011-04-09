#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ball.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(600, 600);
    scene = new QGraphicsScene();
    ui->graphicsView->setRenderHints(QPainter::Antialiasing);
    ui->graphicsView->setScene(scene);

    scene->addItem(new Ball(0, 0, 256, Qt::darkCyan));
}

MainWindow::~MainWindow()
{
    delete ui;
}
