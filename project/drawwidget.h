#ifndef DRAWWIDGE_H
#define DRAWWIDGE_H

#include <QMainWindow>
#include <QWidget>
#include <QPixmap>
#include <QPoint>
#include <QPainter>
#include <QMouseEvent>
#include <QVector>

struct StrokeSeg{
    QPoint a;
    QPoint b;
};

struct Stroke{
    QVector<StrokeSeg> segs;
};

class DrawWidget : public QWidget
{
public:
    explicit DrawWidget(QWidget* parent = nullptr);
    QPoint clampToWidget(const QPoint& p, const QSize& s);

public:
    void clearAll();
    void undoLast();
    void addElement();
    void connectFigures();

protected:
    void paintEvent(QPaintEvent*) override;
    void resizeEvent(QResizeEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;

private:
    QPixmap _canvas;
    QPixmap _drawingLayer;
    QPoint _lastPoint;
    bool _drawing = false;

private:
    QVector<Stroke> _strokesHistory;
    Stroke _currentStroke;
};

#endif // DRAWWIDGE_H
