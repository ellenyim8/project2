#include "admin.h"
#include "ui_admin.h"
#include "ui_modifysouvenirs.h"

Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_addNewTeam_clicked()
{
    // make a modifystadium ui/designer
}

void Admin::on_addNewStadium_clicked()
{
    // ...
}

void Admin::on_displayStadiums_clicked()
{
    // displaying stadium list ..
}

void Admin::on_souvenirsPageButton_clicked()
{
    ms = new ModifySouvenirs(nullptr, &sc);
    ms->show();
}
