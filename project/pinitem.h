#ifndef PINITEM_H
#define PINITEM_H

#include <QGraphicsEllipseItem>
#include <QGraphicsSimpleTextItem>
#include <QPen>
#include <QDebug>

class PinItem : public QGraphicsEllipseItem
{
   // Q_OBJECT

public:
     PinItem(const QString& name, double x, double y, QGraphicsItem* parent = nullptr);

private:

};

#endif // PINITEM_H
