#include "mouse.h"
#include <QtGui>
#include <QGraphicsView>
#include <stdlib.h>

Mouse::Mouse(QGraphicsItem* parent) : QObject(), QGraphicsItem(parent)
{
   //setFlag(QGraphicsItem::ItemIsFocusable);
    this->x = 0;
    this->y = 0;
}

QRectF Mouse::boundingRect() const {
    return QRectF(0, 0, 30, 30);
}

void Mouse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPixmap pixmap("C:\\Users\\mwawe\\Documents\\micromouse_qt_project\\robot.png");
//    this->setTransform(QTransform().translate(this->boundingRect().center().x(), this->boundingRect().center().y())); // poprawa rotacji (zeby robila sie w jednym miejscu)
    painter->drawPixmap(5, 5, 20, 20, pixmap);
//    painter->rotate(90);
}

void Mouse::moveForward() {
    QPropertyAnimation *animation = new QPropertyAnimation(this, "pos");
    animation->setDuration(1000); // time of animation in ms
    animation->setStartValue(QPointF(0, 0)); // start position //  mouse->pos()
    animation->setEndValue(QPointF(30, 0)); // end position
    animation->start();

//    wait(1000);

// to bedzie move forward i trzeba dodac zmienna x y i kierunek kontrolujace,
    // na podstawie kierunku tobic ruch
//    moveBy(30, 0);
}

void Mouse::turnRight() {       
   QPropertyAnimation *animation = new QPropertyAnimation(this, "rotation");
   animation->setDuration(10000); // Czas trwania animacji w milisekundach
   animation->setStartValue(0);
   animation->setEndValue(90.0);

//   this->setTransformOriginPoint(0, 0);

   animation->start();

//   wait(1000);
}

void Mouse::wait( int ms ) {
   QElapsedTimer timer;
   timer.start();

   while ( timer.elapsed() < ms )
       QCoreApplication::processEvents();
}
