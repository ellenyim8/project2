#include "map.h"
#include "ui_map.h"

Map::Map(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);
}

Map::~Map()
{
    delete ui;
}

void Map::paintEvent(QPaintEvent *e)
{
    QPixmap pix(":/resource/image/map2.png");
    int w = ui->label->width();
    int h = ui->label->height();

    QPainter painter(&pix);
    QPen paintpen(Qt::black);
    paintpen.setWidth(6);

    QPen linepen(Qt::red);
    linepen.setWidth(2);

    QPoint p1;      // Safeco Field
    p1.setX(100);
    p1.setY(35);

    QPoint p2;      // AT&T Park
    p2.setX(40);
    p2.setY(230);

    QPoint p3;      // O.co Coliseum
    p3.setX(45);
    p3.setY(238);

    QPoint p4;      // Dodger Stadium
    p4.setX(80);
    p4.setY(325);

    QPoint p5;      // Angel Stadium
    p5.setX(85);
    p5.setY(333);

    QPoint p6;      // Petco Park
    p6.setX(100);
    p6.setY(355);

    QPoint p7;      // Chase Field
    p7.setX(190);
    p7.setY(358);

    QPoint p8;      // Coors Field
    p8.setX(315);
    p8.setY(235);
//    painter.setPen(linepen);
//    painter.drawLine(p1,p2);

    painter.setPen(paintpen);
    painter.drawPoint(p1);
    painter.drawPoint(p2);
    painter.drawPoint(p3);
    painter.drawPoint(p4);
    painter.drawPoint(p5);
    painter.drawPoint(p6);
    painter.drawPoint(p7);
    painter.drawPoint(p8);

    ui->label->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}
