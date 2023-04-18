#include <QGraphicsView>
#include <stdlib.h>
#include "directions.h"
#include "mouse.h"
#include <string>

using namespace std;

Mouse::Mouse(Maze* maze, QGraphicsItem* parent) : QObject(), QGraphicsItem(parent)
{
   //setFlag(QGraphicsItem::ItemIsFocusable);
    this->maze = maze;
    // TODO: walidacja zeby nie przeszlo poza pole
    this->x = 0; // column
    this->y = 0; // row
    this->direction = Direction::RIGHT;
    this->currentRotation = 0;
    this->currentCell = &this->maze->getCell(0, 0);
    this->prevVisitedCell = nullptr;
}

QRectF Mouse::boundingRect() const {
    return QRectF(0, 0, 30, 30);
}

void Mouse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPixmap pixmap("C:\\Users\\mwawe\\Documents\\micromouse_qt_project\\robot.png");
    painter->drawPixmap(5, 5, 20, 20, pixmap);
    this->setTransformOriginPoint(this->boundingRect().center());
}

QPropertyAnimation* Mouse::moveForward() {
    cout << "Przed moveForward = x:" << this->x << " y:" << this->y << " rotation:" << to_string(this->currentRotation) << endl;
    QPropertyAnimation* animation = new QPropertyAnimation(this, "pos");

    this->prevVisitedCell = &this->maze->getCell(this->x, this->y);//this->currentCell;

    animation->setDuration(this->speed);
    animation->setStartValue(QPointF(this->x * 30, this->y * 30));

    switch(this->direction) {
        case Direction::UPPER:
            this->y--; // -1 row
            break;
        case Direction::RIGHT:
            this->x++; // +1 column
            break;
        case Direction::BOTTOM:
            this->y++; // +1 row
            break;
        case Direction::LEFT:
            this->x--; // -1 column
            break;
    }

    animation->setEndValue(QPointF(this->x * 30, this->y * 30));

    this->currentCell = &this->maze->getCell(this->x, this->y);// this->maze->getCell(this->y, this->x);
    cout << "Po moveForward = x:" << this->x << " y:" << this->y << " rotation:" << to_string(this->currentRotation) << endl;
    return animation;
}

QPropertyAnimation* Mouse::turnRight() {
    QPropertyAnimation *animation = new QPropertyAnimation(this, "rotation");
    animation->setDuration(this->speed);
    animation->setStartValue(this->currentRotation);
    this->currentRotation += 90.0;
    animation->setEndValue(this->currentRotation);

    this->direction = rotateRightMap.at(this->direction);

    return animation;
}

QPropertyAnimation* Mouse::turnLeft() {
    QPropertyAnimation *animation = new QPropertyAnimation(this, "rotation");
    animation->setDuration(this->speed);
    animation->setStartValue(this->currentRotation);
    this->currentRotation -= 90.0;
    animation->setEndValue(this->currentRotation);

    this->direction = rotateLeftMap.at(this->direction);

    return animation;
}

QPropertyAnimation* Mouse::turnBack()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "rotation");
    animation->setDuration(this->speed * 2);
    animation->setStartValue(this->currentRotation);
    this->currentRotation -= 180.0;
    animation->setEndValue(this->currentRotation);

    this->direction = rotateBackMap.at(this->direction);

    return animation;
}

bool Mouse::isWallOnFront()
{
    switch(this->direction) {
        case Direction::UPPER:
            return this->currentCell->getUpperWall();
            break;
        case Direction::RIGHT:
            return this->currentCell->getRightWall();
            break;
        case Direction::BOTTOM:
            return this->currentCell->getBottomWall();
            break;
        case Direction::LEFT:;
            return this->currentCell->getLeftWall();
            break;
    }

    return true;
}

bool Mouse::isWallOnLeft()
{
    switch(this->direction) {
        case Direction::UPPER:
            return this->currentCell->getLeftWall();
            break;
        case Direction::RIGHT:
            return this->currentCell->getUpperWall();
            break;
        case Direction::BOTTOM:
            return this->currentCell->getRightWall();
            break;
        case Direction::LEFT:
            return this->currentCell->getBottomWall();
            break;
    }

    return true;
}

bool Mouse::isWallOnRight()
{
    switch(this->direction) {
        case Direction::UPPER:
            return this->currentCell->getRightWall();
            break;
        case Direction::RIGHT:
            return this->currentCell->getBottomWall();
            break;
        case Direction::BOTTOM:
            return this->currentCell->getLeftWall();
            break;
        case Direction::LEFT:
            return this->currentCell->getUpperWall();
            break;
    }

    return true;
}

vector<Direction> Mouse::possibleDirections()
{
    vector<Direction> result;

    if (this->currentCell->getUpperWall()) {
        result.push_back(Direction::UPPER);
    }

    if (this->currentCell->getBottomWall()) {
        result.push_back(Direction::BOTTOM);
    }

    if (this->currentCell->getRightWall()) {
        result.push_back(Direction::RIGHT);
    }

    if (this->currentCell->getLeftWall()) {
        result.push_back(Direction::LEFT);
    }
    return result;
}

 bool Mouse::isFinished()
 {
     return this->maze->isInCenter(this->x, this->y);
 }

 void Mouse::setSpeed(int speed)
 {
     this->speed = speed;
 }

 //*******************************************
 // only for floodfill testing
 //*******************************************
 bool Mouse::getFrontWall(int x, int y) {
    Cell cell = this->maze->getCell(x, y);
//    cout << "[" << this->x << "," << this->y << "]" << cell.toString() << endl;
    return cell.getUpperWall();
 }

 bool Mouse::getLeftWall(int x, int y) {
     Cell cell = this->maze->getCell(x, y);
//     cout << "[" << this->x << "," << this->y << "]" << cell.toString() << endl;
     return cell.getLeftWall();
 }

 bool Mouse::getRightWall(int x, int y) {
     Cell cell = this->maze->getCell(x, y);
//     cout << "[" << this->x << "," << this->y << "]" << cell.toString() << endl;
     return cell.getRightWall();
 }

 bool Mouse::getBottomWall(int x, int y) {
     Cell cell = this->maze->getCell(x, y);
//     cout << "[" << this->x << "," << this->y << "]" << cell.toString() << endl;
     return cell.getBottomWall();
}


 void Mouse::setCellAsVisited() {
//     cout << "Ustawiam jako aktywne " << this->currentCell->getX() << "," << this->currentCell->getY() << endl;
    this->currentCell->setVisited(true);
 }

 bool Mouse::isCurrentCellVisited() {
    return this->currentCell->getVisited();
 }

 void Mouse::setFloodfillValueForCurrentCell(int value) {
    return this->currentCell->setFloodfillValue(value);
 }

 int Mouse::getFloodfillValueForCurrentCell() {
     return this->currentCell->getFloodfillValue();
 }

 Cell Mouse::getCell(int x, int y) {
     return this->maze->getCell(x, y);
 }

 Direction Mouse::getCurrentDirection() {
     return this->direction;
 }

 int Mouse::getX() {
    return this->x;
 }

 int Mouse::getY() {
    return this->y;
 }

 Cell* Mouse::getPrevVisitedCell() {
    return this->prevVisitedCell;
 }

 void Mouse::positionComparsion() {
     cout << "getX/Y = [" << this->x << "," << this->y << "] | currentCell = [" << this->currentCell->getX() << "," << this->currentCell->getY() << "]" << endl;
 }
