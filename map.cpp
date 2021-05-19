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

//    painter.setPen(linepen);
//    painter.drawLine(p1,p2);

    painter.setPen(paintpen);

    for(size_t i = 0;i < positions.size();i++){
        painter.drawPoint(positions[i].second);
        painter.drawText(positions[i].second,QString::fromStdString(positions[i].first));

    }


    ui->label->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}
