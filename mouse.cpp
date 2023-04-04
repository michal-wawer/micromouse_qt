#include <QGraphicsView>
#include <stdlib.h>
#include "directions.h"
#include "mouse.h"

Mouse::Mouse(QGraphicsItem* parent) : QObject(), QGraphicsItem(parent)
{
   //setFlag(QGraphicsItem::ItemIsFocusable);
    this->x = 0;
    this->y = 0;
    this->direction = Direction::RIGHT;
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
    QPropertyAnimation* animation = new QPropertyAnimation(this, "pos");
    animation->setDuration(1000);
    animation->setStartValue(QPointF(this->x * 30, this->y * 30));

    switch(this->direction) {
        case Direction::UPPER:
            this->y--;
            break;
        case Direction::RIGHT:
            this->x++;
            break;
        case Direction::BOTTOM:
            this->y++;
            break;
        case Direction::LEFT:
            this->x--;
            break;
    }

    animation->setEndValue(QPointF(this->x * 30, this->y * 30));

    return animation;
}

QPropertyAnimation* Mouse::turnRight() {
    QPropertyAnimation *animation = new QPropertyAnimation(this, "rotation");
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(90.0);

    this->direction = rotateRightMap.at(this->direction);

    return animation;
}

QPropertyAnimation* Mouse::turnLeft() {
    QPropertyAnimation *animation = new QPropertyAnimation(this, "rotation");
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(-90.0);

    this->direction = rotateLeftMap.at(this->direction);

    return animation;
}
