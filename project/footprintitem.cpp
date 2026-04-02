#include "footprintitem.h"

#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QPainter>

FootprintItem::FootprintItem(const QVector<PinInfo>& pins, QGraphicsItem* parent)
    : QGraphicsObject(parent)
{
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setAcceptedMouseButtons(Qt::LeftButton);
    setFlag(QGraphicsItem::ItemContainsChildrenInShape, true);

    for (const auto& p : pins){
        auto* pin = new PinItem(p.name, p.x, p.y, this);
        pin->setAcceptedMouseButtons(Qt::NoButton);
    }

    m_bounds = childrenBoundingRect().adjusted(-10, -10, 10, 10);
    m_rect = new QGraphicsRectItem(m_bounds, this);

    m_rect->setPen(QPen(Qt::blue, 1));
    m_rect->setAcceptedMouseButtons(Qt::NoButton);

    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
    setFlag(ItemSendsScenePositionChanges);
}

QRectF FootprintItem::boundingRect() const {
    return m_bounds;
}

void FootprintItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event){

    m_dragging  = false;
    emit hoverChanged(false);
    QGraphicsObject::mouseReleaseEvent(event);
}

QVariant FootprintItem::itemChange(GraphicsItemChange change, const QVariant& value){
    return QGraphicsObject::itemChange(change, value);
}

void FootprintItem::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) {
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(boundingRect());
}

void FootprintItem::onFootprintMoved(const QPointF& newPos){

    qDebug() << "Footprint moved to:" << newPos;
}

void FootprintItem::mousePressEvent(QGraphicsSceneMouseEvent* event){
    qDebug() << "PRESS on footprintItem";
    m_dragging = true;
    emit hoverChanged(true);
    QGraphicsObject::mousePressEvent(event);
}

void FootprintItem::mouseMoveEvent(QGraphicsSceneMouseEvent* event){
    qDebug() << "MOVE on footprintItem";
    QGraphicsObject::mouseMoveEvent(event);
}

void FootprintItem::hoverEnterEvent(QGraphicsSceneHoverEvent* event){
    qDebug() << "ENTER footprint";
    if(!m_dragging){
       emit hoverChanged(true);
    }
    QGraphicsObject::hoverEnterEvent(event);
}

void FootprintItem::hoverLeaveEvent(QGraphicsSceneHoverEvent* event){
    qDebug() << "LEAVE footprint";
    if(!m_dragging){
       emit hoverChanged(false);
    }

    QGraphicsObject::hoverLeaveEvent(event);
}

QPainterPath FootprintItem::shape() const{
    QPainterPath p;
    p.addRect(m_bounds);
    return p;
}
