#include "mouse.h"
#include<QtGui>
#include<QGraphicsView>
#include <stdlib.h>


Mouse::Mouse(QGraphicsItem* parent) : QObject(), QGraphicsItem(parent)
{
   //setFlag(QGraphicsItem::ItemIsFocusable);
}

QRectF Mouse::boundingRect() const {
    return QRectF(0, 0, 30, 30);
}

void Mouse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::yellow);
    painter->drawRoundedRect(0, 0, 30, 30, 5, 5);
}

void Mouse::moveRight() {
    QPropertyAnimation *animation = new QPropertyAnimation(this, "pos");
    animation->setDuration(1000); // Czas trwania animacji w milisekundach
    animation->setStartValue(QPointF(0, 0)); // Początkowa pozycja elementu //  mouse->pos()
    animation->setEndValue(QPointF(30, 0)); // Końcowa pozycja elementu
    animation->start();

//    moveBy(30, 0);
}

void Mouse::moveLeft() {
    moveBy(-30, 0);
}

void Mouse::moveUp() {
    moveBy(0, -30);
}

void Mouse::moveDown() {
    moveBy(0, 30);
}

void Mouse::wait( int ms ) {
   QElapsedTimer timer;
   timer.start();

   while ( timer.elapsed() < ms )
       QCoreApplication::processEvents();
}
