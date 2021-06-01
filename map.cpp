#include "map.h"
#include "ui_map.h"

/****************************************************
 * Map()
 *  CTOR; sets up ui
 * -------------------------------------------------
 *  Preconditions: none
 * -------------------------------------------------
 *  Postconditions: Map window is set up
****************************************************/
Map::Map(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);
}

/****************************************************
 * ~Map()
 *  destructor; receives no parameters and returns
 *  nothing
 * -------------------------------------------------
 *  Preconditions: none
 * -------------------------------------------------
 *  Postconditions: ui stops running
****************************************************/
Map::~Map()
{
    delete ui;
}

/**********************************************************
 * void set_list(const vector<string>& v)
 *
 *  Set the list variable to the given input.
 * --------------------------------------------------------
 *  Pre-conditions: None.
 * -------------------------------------------------------
 *  Post-condition: The class variable list has been set.
**********************************************************/
void Map::set_list(const vector<string>& v)
{
    list = v;
}

/**********************************************************
 * void paintEvent(QPaintEvent *e)
 *
 *  print the map on the window
 * --------------------------------------------------------
 *  Pre-conditions: None.
 * -------------------------------------------------------
 *  Post-condition: The map is shown on the window.
**********************************************************/
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


    Heap<Stadiums,StringMin> h2 = ALS;
    for(int i = 0;i < ALS.size();i++){
        painter.setPen(paintpen1);
        painter.drawPoint(h2.peek().position);
        painter.drawText(h2.peek().position,QString::fromStdString(h2.peek().Stadium_Name));
        h2.remove();
    }

    Heap<Stadiums,StringMin> h3 = NLS;
    for(int i = 0;i < NLS.size();i++){
        painter.setPen(paintpen);
        painter.drawPoint(h3.peek().position);
        painter.drawText(h3.peek().position,QString::fromStdString(h3.peek().Stadium_Name));
        h3.remove();
    }

    painter.setPen(linepen);
    if(!list.empty()){
        for(unsigned long long i = 0;i < list.size()-1;i++){
            QPoint p1 = MLS.find_element(list[i]).position;
            QPoint p2 = MLS.find_element(list[i+1]).position;
            painter.drawLine(p1,p2);
        }
    }

    ui->label->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}
