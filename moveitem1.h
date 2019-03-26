#ifndef MOVEITEM1_H
#define MOVEITEM1_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QPointF>




class MoveItem1 :  public QGraphicsObject
{
    Q_OBJECT
public:
    explicit MoveItem1(QObject *parent = 0);
    ~MoveItem1();

 signals:
    void n();

    //void signalTargetCoordinate(QPointF point);

public:
    QRectF boundingRect() const;//отрисовка
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);//отрисовка

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);


public slots:
};

#endif // MOVEITEM_H
