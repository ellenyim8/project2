#include "admin.h"
#include "ui_admin.h"

/****************************************************
 * Admin()
 *  CTOR; sets up ui
 * -------------------------------------------------
 *  Preconditions: none
 * -------------------------------------------------
 *  Postconditions: admin window is set up
****************************************************/
Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    ui->title->hide();
    ui->modify_souvenirs->hide();
    ui->stadium_button->hide();

}

/****************************************************
 * ~Admin()
 *  destructor; receives no parameters and returns
 *  nothing
 * -------------------------------------------------
 *  Preconditions: none
 * -------------------------------------------------
 *  Postconditions: ui stops running
****************************************************/
Admin::~Admin()
{
    delete ui;
}

/**********************************************************
 * void on_login_clicked()
 *
 *  admin enters right username ("cs8") and password
 *  ("baseball") in order to access and modify stadiums/
 *  teams/souvenirs.
 * --------------------------------------------------------
 *  Pre-conditions: username and password is inputted
 *  into lineEdits
 * -------------------------------------------------------
 *  Post-condition: adminDialog page is shown
**********************************************************/
void Admin::on_login_clicked()
{
    QString user, password;

    user = ui->usernameInput->text();
    password = ui->passwordInput->text();

    if (user == "cs8" && password == "baseball")
    {
        ui->title->show();
        ui->modify_souvenirs->show();
        ui->stadium_button->show();
        ui->usernameLabel->hide();
        ui->usernameInput->hide();
        ui->passwordLabel->hide();
        ui->passwordInput->hide();
        ui->login->hide();
    }
    else
    {
        QMessageBox msg;
        msg.setText("incorrect username/password.");
        msg.exec();
        return;
    }
}

void Admin::on_modify_souvenirs_clicked()
{
    this->hide();

    ms = new ModifySouvenirs(nullptr, &svc);
    ms->setModal(true);
    ms->show();
}

void Admin::on_stadium_button_clicked()
{
    this->hide();

    modifyStadium = new ModifyStadium(nullptr);
    modifyStadium->setModal(true);
    modifyStadium->show();
}
