#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "mouse.h"
#include "righthandrule.h"
#include <QGraphicsItemAnimation>
#include <QGraphicsRectItem>
#include <QTimeLine>
#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->algoComboBox->addItems({"Left", "Right", "FloodFill"});
    ui->algoComboBox->setCurrentIndex(0);

    mazeBlock = new Maze();
    ui->mazeView->setScene(mazeBlock);

    Mouse *mouse = new Mouse();
    mazeBlock->addItem(mouse);

    RightHandRule *algo = new RightHandRule();
    algo->run(mouse);
}

MainWindow::~MainWindow()
{
    delete ui;
}

