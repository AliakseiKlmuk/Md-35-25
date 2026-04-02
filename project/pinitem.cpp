#include "pinitem.h"

PinItem::PinItem(const QString& name, double x, double y, QGraphicsItem* parent)
    : QGraphicsEllipseItem(parent)
{
   const double r = 4.0;

   setRect(x - r, y - r, r*2, r*2);
   setBrush(Qt::yellow);
   setPen(QPen(Qt::black, 1));

   setAcceptedMouseButtons(Qt::NoButton);
   setFlag(QGraphicsItem::ItemIsMovable, false);
   setFlag(QGraphicsItem::ItemIsSelectable, false);

   auto* label = new QGraphicsSimpleTextItem(name, this);
   label->setPos(x + 6, y - 6);
}


