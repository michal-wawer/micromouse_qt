#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mouse.h"
#include <QGraphicsItemAnimation>
#include <QGraphicsRectItem>
#include <QTimeLine>
#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mazeBlock = new Maze();
    ui->mazeView->setScene(mazeBlock);
    Mouse *mouse = new Mouse();
    mazeBlock->addItem(mouse); // tym tez mozna ogarnac dodanie scian

//    QGraphicsRectItem *item = new QGraphicsRectItem(QRectF(0, 0, 30, 30));
    //item->setPos(0, 0);
//    mazeBlock->addItem(item);


    mouse->moveRight();
}

MainWindow::~MainWindow()
{
    delete ui;
}

