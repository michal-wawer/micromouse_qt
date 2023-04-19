#include <QGraphicsView>
#include <stdlib.h>
#include "directions.h"
#include "mouse.h"
#include <string>

using namespace std;

const int MAX_MOVES_COUNT = 5000;

Mouse::Mouse(Maze* maze, QGraphicsItem* parent) : QObject(), QGraphicsItem(parent)
{
    this->maze = maze;
    this->x = 0; // column
    this->y = 0; // row
    this->direction = Direction::RIGHT;
    this->currentRotation = 0;
    this->movesCount = 0;
    this->leftSensor = new LeftSensor(this->maze->getCell(0, 0), this->direction);
    this->rightSensor = new RightSensor(this->maze->getCell(0, 0), this->direction);
    this->frontSensor = new FrontSensor(this->maze->getCell(0, 0), this->direction);
    this->drive = new Drive();
}

QRectF Mouse::boundingRect() const {
    return QRectF(0, 0, 30, 30);
}

void Mouse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPixmap pixmap(":/resources/robot.png");
    painter->drawPixmap(5, 5, 20, 20, pixmap);
    this->setTransformOriginPoint(this->boundingRect().center());
}

QPropertyAnimation* Mouse::moveForward() {
    cout << "x:" << this->x << " y:" << this->y << " rotation:" << to_string(this->currentRotation) << endl;

    QPropertyAnimation* animation = new QPropertyAnimation(this, "pos");
    animation->setDuration(this->speed);
    animation->setStartValue(QPointF(this->x * 30, this->y * 30));

    this->drive->moveForward(this->x, this->y, this->direction);

    animation->setEndValue(QPointF(this->x * 30, this->y * 30));

    this->leftSensor->updatePositionAfterMove(this->maze->getCell(this->x, this->y), this->direction);
    this->rightSensor->updatePositionAfterMove(this->maze->getCell(this->x, this->y), this->direction);
    this->frontSensor->updatePositionAfterMove(this->maze->getCell(this->x, this->y), this->direction);
    this->movesCount++;

    return animation;
}

QPropertyAnimation* Mouse::turnRight() {
    QPropertyAnimation *animation = new QPropertyAnimation(this, "rotation");
    animation->setDuration(this->speed);
    animation->setStartValue(this->currentRotation);

    this->drive->turnRight(this->currentRotation, this->direction);

    animation->setEndValue(this->currentRotation);
    return animation;
}

QPropertyAnimation* Mouse::turnLeft() {
    QPropertyAnimation *animation = new QPropertyAnimation(this, "rotation");
    animation->setDuration(this->speed);
    animation->setStartValue(this->currentRotation);

    this->drive->turnLeft(this->currentRotation, this->direction);

    animation->setEndValue(this->currentRotation);
    return animation;
}

QPropertyAnimation* Mouse::turnBack()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "rotation");
    animation->setDuration(this->speed * 2);
    animation->setStartValue(this->currentRotation);

    this->drive->turnBack(this->currentRotation, this->direction);

    animation->setEndValue(this->currentRotation);
    return animation;
}

bool Mouse::isWallOnFront()
{
    return this->frontSensor->checkWall();
}

bool Mouse::isWallOnLeft()
{
    return this->leftSensor->checkWall();
}

bool Mouse::isWallOnRight()
{
    return this->rightSensor->checkWall();
}

bool Mouse::isFinished()
{
    return this->maze->isInCenter(this->x, this->y);
}

void Mouse::setSpeed(int speed)
{
    this->speed = speed;
}

bool Mouse::checkForInfLoop() {
    if (this->movesCount > MAX_MOVES_COUNT) {
        return true;
    }

    return false;
}
