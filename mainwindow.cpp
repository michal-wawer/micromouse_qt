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
    ui->algoComboBox->addItems({"lewa-strona", "prawa-strona", "random"});
    ui->algoComboBox->setCurrentIndex(0);

    mazeBlock = new Maze();
    ui->mazeView->setScene(mazeBlock);

    Mouse *mouse = new Mouse();
    mazeBlock->addItem(mouse); // adding walls can be done with something like this

    mouse->moveRight();
}

MainWindow::~MainWindow()
{
    delete ui;
}

