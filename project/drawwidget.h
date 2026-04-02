#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>
#include <QPixmap>
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
    void clearAll();
    void undoLast();
    void setDrawingEnabled(bool enabled);

public slots:
    void addLine(QPointF a, QPointF b);
    void finishStroke();

protected:
    void paintEvent(QPaintEvent*) override;
    void resizeEvent(QResizeEvent* e) override;

private:
    QPixmap _canvas;
    QPixmap _drawingLayer;

    QVector<Stroke> _strokesHistory;
    Stroke _currentStroke;

    bool m_drawingEnabled = true;
};

#endif // DRAWWIDGET_H
