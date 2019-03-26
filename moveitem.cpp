#include "moveitem.h"


MoveItem::MoveItem(QObject *parent) :QGraphicsObject ()
{

}

MoveItem::~MoveItem()
{

}

QRectF MoveItem::boundingRect() const
{
    return QRectF (-12,-15,24,30);//область где лежит треугольник
}

void MoveItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
      QPolygon polygon;
      polygon << QPoint(0,-15) << QPoint(12,15) << QPoint(-12,15);
      painter->setBrush(Qt::black);
      painter->drawPolygon(polygon);

      Q_UNUSED(option);
      Q_UNUSED(widget);
}

void MoveItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
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

void MoveItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);

}

void MoveItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

