#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "controller.h"
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

    this->simulationController = Controller();
    ui->mazeView->setScene(simulationController.getMaze());

    // disable moving maze window when mouse moves
    ui->mazeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->mazeView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // set default values for controller
    this->changeAlgo(ui->algoComboBox->currentIndex());
    this->changeSpeed(ui->speedSlider->value());

    connect(ui->startButton, &QPushButton::released, this, &MainWindow::runAnimation);
    connect(ui->resetButton, &QPushButton::released, this, &MainWindow::resetMouse);
    connect(ui->algoComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeAlgo(int)));
    connect(ui->speedSlider, SIGNAL(valueChanged(int)), this, SLOT(changeSpeed(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeSpeed(int speed)
{
    this->simulationController.getMouse()->setSpeed(-speed+100); // moze zrobic ta funkcje w controllerze
}

void MainWindow::changeAlgo(int index)
{
    switch(index) {
        case 0:
            this->simulationController.setAlgorythm(ALGORYTHM_TYPE::LEFT_HAND);
            break;

        case 1:
            this->simulationController.setAlgorythm(ALGORYTHM_TYPE::RIGHT_HAND);
            break;

        case 2:
            this->simulationController.setAlgorythm(ALGORYTHM_TYPE::FLOODFILL);
            break;
    }
}

void MainWindow::runAnimation()
{
    this->simulationController.execute();
}

void MainWindow::resetMouse()
{
    this->simulationController.reset();
    this->changeSpeed(ui->speedSlider->value());
}


