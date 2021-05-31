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

// American League Stadiums sorted by team name
void stadiumlists::on_pushButton_clicked()
{
    ui->listWidget->clear();
    Heap<Stadiums,StringMin> h2 = ALS;
    int j = ALS.size();
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

// National League Stadiums sorted by team name
void stadiumlists::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
    Heap<Stadiums,StringMin> h2 = NLS;
    int j = NLS.size();
    string s1;
    string s2;
    ui->listWidget->addItem(QString::fromStdString("National League stadiums"));
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

// Major League Stadiums sorted by team name
void stadiumlists::on_pushButton_3_clicked()
{
    ui->listWidget->clear();
    Heap<Stadiums,StringMin> h2 = MLS2;
    int j = MLS2.size();
    string s1;
    string s2;
    ui->listWidget->addItem(QString::fromStdString("Major League stadiums"));
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

// Major League Stadiums sorted by Stadium name
void stadiumlists::on_pushButton_4_clicked()
{
    ui->listWidget->clear();
    Heap<Stadiums,StadiumsNameMin> h2 = MLS;
    int j = MLS.size();
    string s1;
    string s2;
    ui->listWidget->addItem(QString::fromStdString("Major League stadiums"));
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

// Stadiums that have grass surface sorted by team name
void stadiumlists::on_pushButton_5_clicked()
{
    ui->listWidget->clear();
    Heap<Stadiums,StringMin> h2 = MLS2;
    Heap<Stadiums,StringMin> h3;
    for(int i = 0;i < MLS2.size();i++){
        if(h2.peek().surface == "Grass")
            h3.insert(h2.peek());
        h2.remove();
    }
    ui->listWidget->addItem(QString::fromStdString("Stadiums that have grass surface:"));
    ui->listWidget->addItem(QString::fromStdString(""));
    int j = h3.size();
    string s1,s2;
    for(int i = 0;i < j;i++){
        s1 = "Stadium name: ";
        s2 = "Team name: ";
        s1.append(h3.peek().Stadium_Name);
        s2.append(h3.peek().Team_Name);
        ui->listWidget->addItem(QString::fromStdString(s1));
        ui->listWidget->addItem(QString::fromStdString(s2));
        ui->listWidget->addItem(QString::fromStdString(""));
        h3.remove();
    }
}

// Stadiums in chronological order
void stadiumlists::on_pushButton_6_clicked()
{
    ui->listWidget->clear();
    Heap<Stadiums,StringMin> h2 = MLS2;
    Heap<Stadiums,DateMin> h3;
    for(int i = 0;i < MLS2.size();i++){
        h3.insert(h2.peek());
        h2.remove();
    }
    ui->listWidget->addItem(QString::fromStdString("Stadiums in chronological order:"));
    ui->listWidget->addItem(QString::fromStdString(""));
    int j = h3.size();
    string s1,s2,s3;
    for(int i = 0;i < j;i++){
        s1 = "Stadium name: ";
        s2 = "Team name: ";
        s1.append(h3.peek().Stadium_Name);
        s2.append(h3.peek().Team_Name);
        s3 = h3.peek().Date_Opened;
        ui->listWidget->addItem(QString::fromStdString(s1));
        ui->listWidget->addItem(QString::fromStdString(s2));
        ui->listWidget->addItem(QString::fromStdString(s3));
        ui->listWidget->addItem(QString::fromStdString(""));
        h3.remove();
    }
}
