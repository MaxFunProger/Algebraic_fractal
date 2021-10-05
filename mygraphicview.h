#ifndef MYGRAPHICVIEW_H
#define MYGRAPHICVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QDebug>

class MyGraphicView : public QGraphicsView
{
     public:
     MyGraphicView(QWidget *parent);
     void mousePressEvent(QMouseEvent *e);
     void mouseMoveEvent(QMouseEvent *e);
     void mouseReleaseEvent(QMouseEvent *e);
     void keyPressEvent(QKeyEvent *event);
     QGraphicsScene *scene;

     void CalcFractal(double, double, double, double);
     void DrawLast(double, double, double, double);
     QImage *image;
     QGraphicsRectItem *resize_rect = nullptr;
     double x, y, x2, y2;
     std::vector<std::vector<double > > v;
     double scale = 1 / 200.;


};



#endif // MYGRAPHICVIEW_H
