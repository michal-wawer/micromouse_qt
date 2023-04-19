#ifndef MOUSE_H
#define MOUSE_H

#include "directions.h"
#include "maze.h"
#include "leftsensor.h"
#include "frontsensor.h"
#include "rightsensor.h"
#include "drive.h"
#include <QPropertyAnimation>
#include <QGraphicsItem>

class Mouse : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos ) // NOTIFY posChanged
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation ) // NOTIFY rotationChanged

public:
    Mouse(Maze* maze, QGraphicsItem* parent = nullptr);
    QPropertyAnimation* moveForward();
    QPropertyAnimation* turnLeft();
    QPropertyAnimation* turnRight();
    QPropertyAnimation* turnBack();
    bool isWallOnFront();
    bool isWallOnLeft();
    bool isWallOnRight();
    bool isFinished();
    void setSpeed(int speed);
    bool checkForInfLoop();
    Direction getDirection();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

private:
    int x;
    int y;
    Direction direction;
    Maze* maze;
    int currentRotation;
    Cell currentCell;
    int speed;
    LeftSensor* leftSensor;
    RightSensor* rightSensor;
    FrontSensor* frontSensor;
    Drive* drive;
    int movesCount;
};

#endif // MOUSE_H
