#include "stadiumlists.h"
#include "ui_stadiumlists.h"

stadiumlists::stadiumlists(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stadiumlists)
{
    ui->setupUi(this);
}

stadiumlists::~stadiumlists()
{
    delete ui;
}

void stadiumlists::on_pushButton_clicked()
{
    Heap<Stadiums,StringMin> h2 = h;
    int j = h.size();
    string s1;
    string s2;
    ui->listWidget->addItem(QString::fromStdString("American League stadiums"));
    ui->listWidget->addItem(QString::fromStdString(" "));

    for(int i = 0;i < j;i++){
        s1 = "Stadium name: ";
        s2 = "Team name: ";
        s1.append(h2.peek().Stadium_Name);
        s2.append(h2.peek().Team_Name);
        ui->listWidget->addItem(QString::fromStdString(s1));
        ui->listWidget->addItem(QString::fromStdString(s2));
        ui->listWidget->addItem(QString::fromStdString(""));
        h2.remove();
    }
}
