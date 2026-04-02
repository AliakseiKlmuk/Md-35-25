#include "drawwidget.h"
#include <QPainter>
#include <QResizeEvent>

DrawWidget::DrawWidget(QWidget* parent) : QWidget(parent)
{
setMinimumSize(800, 600);

QImage img(size(), QImage::Format_ARGB32);
img.fill(Qt::transparent);
_canvas = QPixmap::fromImage(img);

QImage img2(size(), QImage::Format_ARGB32);
img2.fill(Qt::transparent);
_drawingLayer = QPixmap::fromImage(img2);
}

void DrawWidget::resizeEvent(QResizeEvent *e){
    QSize s = e->size();

    QImage img(s, QImage::Format_ARGB32);
    img.fill(Qt::transparent);
    QPixmap newCanvas = QPixmap::fromImage(img);

    if(!_canvas.isNull()){
        QPainter p(&newCanvas);
        p.drawPixmap(0, 0, _canvas);
    }

    _canvas = newCanvas;

    QImage img2(s, QImage::Format_ARGB32);
    img2.fill(Qt::transparent);
    _drawingLayer = QPixmap::fromImage(img2);

    update();
}

void DrawWidget::paintEvent(QPaintEvent*){
    QPainter p(this);
    p.drawPixmap(0, 0, _canvas);
    p.drawPixmap(0, 0, _drawingLayer);
}

void DrawWidget::addLine(QPointF a, QPointF b){
    if(!m_drawingEnabled) {return;};

    QPainter p(&_drawingLayer);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    p.drawLine(a, b);

    _currentStroke.segs.push_back({a.toPoint(), b.toPoint()});
    update();
}

void DrawWidget::finishStroke(){
    if(!_currentStroke.segs.isEmpty()){ _strokesHistory.push_back(_currentStroke);}

    _currentStroke.segs.clear();
}

void DrawWidget::clearAll(){
    _drawingLayer.fill(Qt::transparent);
    _canvas.fill(Qt::transparent);
    _strokesHistory.clear();
    _currentStroke.segs.clear();
    update();
}

void DrawWidget::undoLast(){
    if(_strokesHistory.isEmpty()) {return;};

    _strokesHistory.pop_back();

    _drawingLayer.fill(Qt::transparent);

    QPainter p(&_drawingLayer);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.setPen(QPen(Qt::black, 2));

    for (const auto& stroke : _strokesHistory){
        for(const auto& seg : stroke.segs){
            p.drawLine(seg.a, seg.b);
        }
     }

    update();
}

void DrawWidget::setDrawingEnabled(bool enabled){
    m_drawingEnabled = enabled;
}

