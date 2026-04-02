#include "placementscene.h"
#include "ui_placementscene.h"

#include <QGraphicsSceneMouseEvent>

PlacementScene::PlacementScene(QObject  *parent) :
    QGraphicsScene(parent){}

void PlacementScene::addFootprint(const QVector<PinInfo>& pins){
    auto* fp = new FootprintItem(pins);
    addItem(fp);

    connect(fp, &FootprintItem::hoverChanged,
            this, &PlacementScene::footprintHover);
    fp->setZValue(1000);
}

void PlacementScene::mousePressEvent(QGraphicsSceneMouseEvent* e){
    drawing = true;
    lastPoint = e->scenePos();

    QGraphicsScene::mousePressEvent(e);
}

void PlacementScene::mouseMoveEvent(QGraphicsSceneMouseEvent* e){
    if(drawing){
        QPointF p = e->scenePos();
        emit drawLine(lastPoint, p);
        lastPoint = p;
    }

    QGraphicsScene::mouseMoveEvent(e);
}

void PlacementScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* e){
    if(drawing){
        drawing = false;
        emit strokeFinished();
    }

    QGraphicsScene::mouseReleaseEvent(e);
}
