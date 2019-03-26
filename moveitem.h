#ifndef MOVEITEM_H
#define MOVEITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QPointF>




class MoveItem :  public QGraphicsObject
{
    Q_OBJECT
public:
    explicit MoveItem(QObject *parent = 0);
    ~MoveItem();

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
