#ifndef MOUSE_H
#define MOUSE_H

#include <QGraphicsItem>

class Mouse : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)

public:
    Mouse(QGraphicsItem* parent = nullptr);
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    void wait(int ms);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // MOUSE_H
