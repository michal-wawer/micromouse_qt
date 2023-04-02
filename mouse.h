#ifndef MOUSE_H
#define MOUSE_H

#include <QGraphicsItem>


class Mouse : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos ) // moze trzeba dodac funkcje setPos NOTIFY posChanged
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation ) // NOTIFY rotationChanged

public:
    Mouse(QGraphicsItem* parent = nullptr);
    void moveForward();
    void turnLeft();
    void turnRight();
    void wait(int ms);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

private:
    int x;
    int y;
    char direction;
};

#endif // MOUSE_H
