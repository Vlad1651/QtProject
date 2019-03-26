#include "moveitem1.h"



MoveItem1::MoveItem1(QObject *parent) :QGraphicsObject ()
{

}

MoveItem1::~MoveItem1()
{

}

QRectF MoveItem1::boundingRect() const
{
    return QRectF (-12,-15,24,30);//область где лежит треугольник
}

void MoveItem1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
      QPolygon polygon;
      polygon << QPoint(0,-15) << QPoint(12,15) << QPoint(-12,15);
      painter->setBrush(Qt::blue);
      painter->drawPolygon(polygon);

      Q_UNUSED(option);
      Q_UNUSED(widget);
}

void MoveItem1::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    this->setPos(mapToScene(event->pos()));
    n();
//   MainWindow::ui->spinBox_75->setValue(mapToScene(event->pos()));

}

void MoveItem1::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);

}

void MoveItem1::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

