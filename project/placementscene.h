#ifndef PLACEMENTSCENE_H
#define PLACEMENTSCENE_H

#include <QGraphicsScene>
#include "PinInfo.h"
#include "footprintitem.h"

class PlacementScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PlacementScene(QObject  *parent = nullptr);

    void addFootprint(const QVector<PinInfo>& pins);

signals:
    void drawLine(QPointF a, QPointF b);
    void strokeFinished();
    void footprintHover(bool inside);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

private:
    QPointF lastPoint;
    bool drawing = false;
};

#endif // PLACEMENTSCENE_H
