#include "drawwidget.h"
#include <algorithm>

QPoint DrawWidget::clampToWidget(const QPoint& p, const QSize& s){
    int x = std::min(std::max(p.x(), 0), s.width() - 1);
    int y = std::min(std::max(p.y(), 0), s.height() - 1);
    return QPoint(x, y);
}

DrawWidget::DrawWidget(QWidget* parent) : QWidget(parent)
{
setMinimumSize(800, 600);
_canvas = QPixmap(size());
_canvas.fill(Qt::white);
}

void DrawWidget::resizeEvent(QResizeEvent *){
    if (_canvas.isNull()){         // фон
        _canvas = QPixmap(size());
        _canvas.fill(Qt::white);
    } else {
        QPixmap newCanvas(size());
        newCanvas.fill(Qt::white);

        QPainter p(&newCanvas);
        p.drawPixmap(0, 0, _canvas);

        _canvas = std::move(newCanvas);
    }

    //if (_drawingLayer.isNull()){         // слой рисунка
        _drawingLayer = QPixmap(size());
        _drawingLayer.fill(Qt::transparent);
   // } else {
       // QPixmap newDrawingLayer(size());
       // newDrawingLayer.fill(Qt::white);

       // QPainter p(&newDrawingLayer);
       // p.drawPixmap(0, 0, _drawingLayer);

       // _canvas = std::move(newDrawingLayer);
   // }

    _lastPoint = QPoint();
    _drawing = false;
    update();
}

void DrawWidget::paintEvent(QPaintEvent *){
    QPainter p(this);
    p.drawPixmap(0, 0, _canvas);
    p.drawPixmap(0, 0, _drawingLayer);
}

void DrawWidget::mousePressEvent(QMouseEvent *e){
    if (e->button() == Qt::LeftButton){
        _lastPoint = DrawWidget::clampToWidget(e->pos(), size());
        _drawing = true;

        _currentStroke.segs.clear();
    }
}

void DrawWidget::mouseMoveEvent(QMouseEvent *e){
    if (!_drawing || !(e->buttons() & Qt::LeftButton)) {return;}

    QPoint cur = DrawWidget::clampToWidget(e->pos(), size());

    QPainter p(&_drawingLayer);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    p.drawLine(_lastPoint, cur);

    _currentStroke.segs.push_back({_lastPoint, cur});
    _lastPoint = cur;

    update();
}

void DrawWidget::mouseReleaseEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        _drawing = false;

        if (!_currentStroke.segs.isEmpty()){
            _strokesHistory.push_back(_currentStroke);
        }
    }
}

void DrawWidget::clearAll(){

    if(_drawingLayer.isNull()) {return;}
    _drawingLayer.fill(Qt::transparent);
    _lastPoint = QPoint();
    _drawing = false;

    update();
}

void DrawWidget::undoLast(){
    if(_strokesHistory.isEmpty()) {return;};

    _strokesHistory.pop_back();

    _drawingLayer.fill(Qt::transparent);

    QPainter p(&_drawingLayer);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    for (const auto& stroke : _strokesHistory){
        for(const auto& seg : stroke.segs){
            p.drawLine(seg.a, seg.b);
        }
     }

    _lastPoint = QPoint();
    _drawing = false;

    update();
}
