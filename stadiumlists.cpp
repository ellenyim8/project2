#include "stadiumlists.h"
#include "ui_stadiumlists.h"

/****************************************************
 * stadiumlists()
 *  CTOR; sets up ui
 * -------------------------------------------------
 *  Preconditions: none
 * -------------------------------------------------
 *  Postconditions: stadiumlists window is set up
****************************************************/
stadiumlists::stadiumlists(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stadiumlists)
{
    ui->setupUi(this);
}

/****************************************************
 * ~stadiumlists()
 *  destructor; receives no parameters and returns
 *  nothing
 * -------------------------------------------------
 *  Preconditions: none
 * -------------------------------------------------
 *  Postconditions: ui stops running
****************************************************/
stadiumlists::~stadiumlists()
{
    delete ui;
}

/**********************************************************
 * void on_pushButton_clicked()
 *
 *  Show all american league stadiums sorted by team name.
 * --------------------------------------------------------
 *  Pre-conditions: None.
 * -------------------------------------------------------
 *  Post-condition: Current window closed, main window shows.
**********************************************************/
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

/**********************************************************
 * void on_pushButton_2_clicked()
 *
 *  Show all national league stadiums sorted by team name.
 * --------------------------------------------------------
 *  Pre-conditions: None.
 * -------------------------------------------------------
 *  Post-condition: Current window closed, main window shows.
**********************************************************/
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

/**********************************************************
 * void on_pushButton_3_clicked()
 *
 *  Show all major league stadiums sorted by team name.
 * --------------------------------------------------------
 *  Pre-conditions: None.
 * -------------------------------------------------------
 *  Post-condition: Current window closed, main window shows.
**********************************************************/
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

/**********************************************************
 * void on_pushButton_4_clicked()
 *
 *  Show all major league stadiums sorted by stadium name.
 * --------------------------------------------------------
 *  Pre-conditions: None.
 * -------------------------------------------------------
 *  Post-condition: Current window closed, main window shows.
**********************************************************/
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

/**********************************************************
 * void on_pushButton_5_clicked()
 *
 *  Show all Stadiums that have grass surface sorted by team name.
 * --------------------------------------------------------
 *  Pre-conditions: None.
 * -------------------------------------------------------
 *  Post-condition: Current window closed, main window shows.
**********************************************************/
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

/**********************************************************
 * void on_pushButton_6_clicked()
 *
 *  Show all Stadiums in chronological order.
 * --------------------------------------------------------
 *  Pre-conditions: None.
 * -------------------------------------------------------
 *  Post-condition: Current window closed, main window shows.
**********************************************************/
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
