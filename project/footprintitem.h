#ifndef FOOTPRINTITEM_H
#define FOOTPRINTITEM_H

//#include <QAbstractItemModel>

#include <QGraphicsRectItem>
#include <QGraphicsObject>

#include "pinitem.h"
#include "PinInfo.h"

class FootprintItem : public QGraphicsObject
{
    Q_OBJECT
public:
     explicit FootprintItem(const QVector<PinInfo>& pins, QGraphicsItem* parent = nullptr);

     QRectF boundingRect() const override;
     void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

     void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
     void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;

     void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
     void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;

    QPainterPath shape() const override;

public slots:
     void onFootprintMoved(const QPointF& newPos);

signals:
     void moved(const QPointF& newPos);
     void hoverChanged(bool inside);

protected:
     void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
     QVariant itemChange(GraphicsItemChange change, const QVariant& value) override;

private:
     QGraphicsRectItem* m_rect = nullptr;
     QRectF m_bounds;
     bool m_dragging  = false;
};

#endif // FOOTPRINTITEM_H
