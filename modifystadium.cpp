#include "modifystadium.h"
#include "ui_modifystadium.h"

ModifyStadium::ModifyStadium(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyStadium)
{
    ui->setupUi(this);

}

ModifyStadium::~ModifyStadium()
{
    delete ui;
}


void ModifyStadium::on_stadiumConfirmedButton_accepted()
{
    Stadium newStadium;
    string name = ui->nameLineEdit->text().toStdString();
    if (name.size()==0)
    {
        QMessageBox msg;
        msg.setText("name is empty.");
        msg.exec();
        return;
    }
    else newStadium.set_stadium_name(name);
    string team = ui->teamLineEdit->text().toStdString();
    if (team.size()==0)
    {
        QMessageBox msg;
        msg.setText("team is empty.");
        msg.exec();
        return;
    }
    else newStadium.set_team(team);
    string street = ui->streetLineEdit->text().toStdString();
    if (street.size()==0)
    {
        QMessageBox msg;
        msg.setText("street is empty.");
        msg.exec();
        return;
    }
    else newStadium.set_street(street);
    string city = ui->cityLineEdit->text().toStdString();
    if (city.size()==0)
    {
        QMessageBox msg;
        msg.setText("city is empty.");
        msg.exec();
        return;
    }
    else newStadium.set_city(city);
    string phoneNo = ui->phoneLineEdit->text().toStdString();
    if (phoneNo.size()==0)
    {
        QMessageBox msg;
        msg.setText("city is empty.");
        msg.exec();
        return;
    }
    else newStadium.set_phone_num(phoneNo);
    date opened;
    if (ui->openingdayLineEdit->text().toStdString().size()!=0)
    {
        opened.setDay(ui->openingdayLineEdit->text().toInt());
        opened.setMonth(ui->monthBox->value());
        opened.setYear(ui->yearBox->value());
        newStadium.set_open(opened);
    }
    else
    {
        QMessageBox msg;
        msg.setText("date is empty.");
        msg.exec();
        return;
    }
    if (ui->capcityLineEdit->text().toStdString().size()!=0)
    {
        int capacity = ui->capcityLineEdit->text().toInt();
        newStadium.set_capacity(capacity);
    }
    else
    {
        QMessageBox msg;
        msg.setText("capcity is empty.");
        msg.exec();
        return;
    }
    bool national;
    if (ui->leagueComboBox->currentIndex()==0)
        national = true;
    else national = false;
    newStadium.set_national(national);
    //need function to convert longitude and latitude to map coordinates
    int xcoord = ui->longitudeLineEdit->text().toDouble();
    int ycoord = ui->latitudeLineEdit->text().toDouble();
    positions.push_back(make_pair(name,QPoint(xcoord,ycoord)));
}
