#include "mygraphicview.h"
#include "mainwindow.h"


MyGraphicView::MyGraphicView(QWidget *parent) : QGraphicsView(parent)
{
     setMouseTracking(true);
}


int get_intensivity(double x, double y){
    Complex c(x, y);
    Complex z(0, 0);
    for (uchar gray = 255; gray; gray--)
    {
        if (z.Norm() > 2)
            return gray;
         z = z * z + c;
    }
    return 0;
}



QColor get_color(int gray){
    return QColor(4 * gray % 256, 6 * gray % 256, 8 * gray % 256);
}


void MyGraphicView::CalcFractal(double x1, double y1, double x2, double y2){
    scene->clear();
    double w = x2 - x1;
    double h = y2 - y1;

    h = (x2 - x1) * (height() - 10) / (width() - 10);
    /*if ((y2 - y1) / (x2 - x1) < (height() - 10) / (width() - 10)){
        w = (y2 - y1) * (width() - 10) / (height() - 10);
    }else{
        h = (x2 - x1) * (height() - 10) / (width() - 10);
    }*/
    if (!v.size()){
        v.push_back({x1, y1, w, h});
    }else{
        x1 *= v.back()[2] / (width() - 10);
        x1 += v.back()[0];
        x2 *= v.back()[2] / (width() - 10);
        x2 += v.back()[0];
        y1 *= v.back()[3] / (height() - 10);
        y1 += v.back()[1];
        y2 *= v.back()[3] / (height() - 10);
        y2 += v.back()[1];
    }
    w = x2 - x1;
    h = w * (height() - 10) / (width() - 10);

    //image = new QImage(width(), height(), QImage::Format_RGB32);
    qDebug() << w << h << x1 << y1;
    for (int i = 0; i < width() - 10; ++i){
        for (int j = 0; j < height() - 10; ++j){
            int gray = get_intensivity(x1 + i * w / (width() - 10), y1 + j * h / (height() - 10));
            QColor color = get_color(gray);
            image->setPixelColor(i, j, color);
        }
    }
    v.push_back({x1, y1, w, h});
    //scene->clear();
    scene->addPixmap(QPixmap::fromImage(*image));
    scene->setSceneRect(0, 0, width() - 10, height() - 10);

}

void MyGraphicView::DrawLast(double x1, double y1, double w, double h){
    scene->clear();
    for (int i = 0; i < width() - 10; ++i){
        for (int j = 0; j < height() - 10; ++j){
            int gray = get_intensivity(x1 + i * w / (width() - 10), y1 + j * h / (height() - 10));
            QColor color = get_color(gray);
            image->setPixelColor(i, j, color);
        }
    }
    scene->addPixmap(QPixmap::fromImage(*image));
    scene->setSceneRect(0, 0, width() - 10, height() - 10);
}


void MyGraphicView::mousePressEvent(QMouseEvent *e)
{
    //qDebug() << e->pos().x() << e->pos().y();
    resize_rect = scene->addRect(e->pos().x(), e->pos().y(), 1, 1,  QPen(Qt::gray, Qt::DashLine));
    x = e->pos().x();
    y = e->pos().y();
}

void MyGraphicView::mouseMoveEvent(QMouseEvent *e)
{
    if (resize_rect != nullptr){
        //qDebug() << e->x();
        resize_rect->setRect(x, y,
                             -x + e->pos().x(),
                             -y + e->pos().y());

    }
}


void MyGraphicView::mouseReleaseEvent(QMouseEvent *e)
{
    if (resize_rect != nullptr){
        CalcFractal(x, y, e->pos().x(), e->pos().y());
    }
    resize_rect = nullptr;
}

void MyGraphicView::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Minus){
        if (v.size() >= 2){
            v.pop_back();
            qDebug() << "YES";
            DrawLast(v.back()[0], v.back()[1], v.back()[2], v.back()[3]);
        }
    }
}



