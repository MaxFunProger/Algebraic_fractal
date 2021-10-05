#include "mainwindow.h"
#include "ui_mainwindow.h"


int w = 0;
int h = 0;
int gv;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
    ui->gV->scene = new QGraphicsScene();
    QGraphicsScene* scene = ui->gV->scene;
    ui->gV->setScene(scene);
    w = ui->gV->width() - 10;
    h = ui->gV->height() - 10;
    image = new QImage(w, h, QImage::Format_RGB32);
    ui->gV->image = image;
    ui->gV->CalcFractal(-(width() - 10) / 2. * scale, -(height() - 10) / 3. * scale, (ui->gV->width() - 10-(width() - 10) / 2.) * scale, (ui->gV->height() -10 -(height() - 10) / 3.) * scale);
    //CalcFractal();
    //scene->addPixmap(QPixmap::fromImage(*image));
    //scene->setSceneRect(0, 0, w, h);
}






MainWindow::~MainWindow()
{
    delete ui;
}

