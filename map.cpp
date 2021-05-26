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

void Map::set_list(const vector<string>& v)
{
    list = v;
}

void Map::paintEvent(QPaintEvent *e)
{
    QPixmap pix(":/resource/image/map2.png");
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label_2->setText("<font color='red'>Red: American League</font>");
    ui->label_3->setText("<font color='blue'>Blue: National League</font>");

    QPainter painter(&pix);
    QPen paintpen(Qt::blue);
    QPen paintpen1(Qt::red);
    paintpen.setWidth(6);
    paintpen1.setWidth(6);

    QPen linepen(Qt::black);
    linepen.setWidth(2);



    for(size_t i = 0;i < positions.size();i++){        
        if(ALS.contains(positions[i].first)){
            painter.setPen(paintpen1);
        }
        else{
            painter.setPen(paintpen);
        }
        painter.drawPoint(positions[i].second);
        painter.drawText(positions[i].second,QString::fromStdString(positions[i].first));
    }


    painter.setPen(linepen);
    if(!list.empty()){
        for(unsigned long long i = 0;i < list.size()-1;i++){
            pair<string,QPoint> p1 = find_pos(list[i]);
            pair<string,QPoint> p2 = find_pos(list[i+1]);
            painter.drawLine(p1.second,p2.second);
        }
    }


    ui->label->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}
