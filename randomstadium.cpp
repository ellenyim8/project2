#include "randomstadium.h"
#include "ui_randomstadium.h"

randomstadium::randomstadium(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::randomstadium)
{
    ui->setupUi(this);
}

randomstadium::~randomstadium()
{
    delete ui;
}

void randomstadium::on_pushButton_clicked()
{
    ui->listWidget->clear();
    srand(time(NULL));
    int num = MLS.size();
    int num2 = rand()%num + 1;
    Stadiums s = MLS.get_element(num2);
    ui->listWidget->addItem(QString::fromStdString("Stadium name: " + s.Stadium_Name));
    ui->listWidget->addItem(QString::fromStdString("Team name: " + s.Team_Name));
    ui->listWidget->addItem(QString::fromStdString(s.address));
    ui->listWidget->addItem(QString::fromStdString(s.City_State_Zip));
    ui->listWidget->addItem(QString::fromStdString(s.Box_Office_Num));
    ui->listWidget->addItem(QString::fromStdString(s.Date_Opened));
    ui->listWidget->addItem(QString::fromStdString(s.Seating_Capacity));
    ui->listWidget->addItem(QString::fromStdString("Surface: " + s.surface));
}
