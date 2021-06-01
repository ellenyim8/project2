#include "mainwindow.h"
#include "ui_mainwindow.h"

/****************************************************
 * MainWindow(QWidget *parent)
 *  CTOR; sets up ui
 * -------------------------------------------------
 *  Preconditions: none
 * -------------------------------------------------
 *  Postconditions: mainwindow is set up
****************************************************/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->title->show();
    ui->admin->show();
}

/****************************************************
 * ~MainWindow()
 *  destructor; receives no parameters and returns
 *  nothing
 * -------------------------------------------------
 *  Preconditions: none
 * -------------------------------------------------
 *  Postconditions: ui stops running
****************************************************/
MainWindow::~MainWindow()
{
    delete ui;
    delete administrator;
}

/**********************************************************
 * void on_admin_clicked()
 *
 *  Show the admin window.
 * --------------------------------------------------------
 *  Pre-conditions: None.
 * -------------------------------------------------------
 *  Post-condition: admin window is shown.
**********************************************************/
void MainWindow::on_admin_clicked()
{
    this->hide();
    administrator = new Admin(nullptr);
    administrator->setModal(true);
    administrator->show();
}

/**********************************************************
 * void on_Map_clicked()
 *
 *  Show the map window.
 * --------------------------------------------------------
 *  Pre-conditions: None.
 * -------------------------------------------------------
 *  Post-condition: Map window is shown.
**********************************************************/
// show map button
void MainWindow::on_Map_clicked()
{
    Map m;
    this->hide();
    m.setModal(true);
    m.exec();
    if (m.close())
        this->show();
}

/**********************************************************
 * void on_pushButton_clicked()
 *
 *  Show the teams list window after push the button.
 * --------------------------------------------------------
 *  Pre-conditions: None.
 * -------------------------------------------------------
 *  Post-condition: teams list window is shown.
**********************************************************/
// teams list button
void MainWindow::on_pushButton_clicked()
{
    stadiumlists l;
    this->hide();
    l.setModal(true);
    l.exec();
    if (l.close())
        this->show();
}

/**********************************************************
 * void on_pushButton_2_clicked()
 *
 *  Show the tirps to other stadiums window after push the
 *  button.
 * --------------------------------------------------------
 *  Pre-conditions: None.
 * -------------------------------------------------------
 *  Post-condition: New window is shown.
**********************************************************/
// trips to other stadiums button
void MainWindow::on_pushButton_2_clicked()
{
    trips t;
    this->hide();
    t.setModal(true);
    t.exec();
    if (t.close())
        this->show();
}

/**********************************************************
 * void on_pushButton_3_clicked()
 *
 *  Show the plan a dream vacation window after push the
 *  button.
 * --------------------------------------------------------
 *  Pre-conditions: None.
 * -------------------------------------------------------
 *  Post-condition: New window is shown.
**********************************************************/
// plan a dream vacation
void MainWindow::on_pushButton_3_clicked()
{
    dreamvacation d;
    this->hide();
    d.setModal(true);
    d.exec();
    if (d.close())
        this->show();
}

/**********************************************************
 * void on_pushButton_4_clicked()
 *
 *  Show check distances between stadiums window after push
 *   the button.
 * --------------------------------------------------------
 *  Pre-conditions: None.
 * -------------------------------------------------------
 *  Post-condition: New window is shown.
**********************************************************/
// check distances b/w stadiums
void MainWindow::on_pushButton_4_clicked()
{
    checkdistance c;
    this->hide();
    c.setModal(true);
    c.exec();
    if (c.close())
        this->show();
}

/**********************************************************
 * void on_pushButton_5_clicked()
 *
 *  Show souvenir purchases report window after push the
 *  button.
 * --------------------------------------------------------
 *  Pre-conditions: None.
 * -------------------------------------------------------
 *  Post-condition: New window is shown.
**********************************************************/
// souvenir purchases report
void MainWindow::on_pushButton_5_clicked()
{
    purchase_report p;
    this->hide();
    p.setModal(true);
    p.exec();
    if (p.close())
        this->show();
}

/**********************************************************
 * void on_pushButton_6_clicked()
 *
 *  Show randomly access any baseball stadium window after
 *  push the button.
 * --------------------------------------------------------
 *  Pre-conditions: None.
 * -------------------------------------------------------
 *  Post-condition: New window is shown.
**********************************************************/
// randomly access any baseball stadium
void MainWindow::on_pushButton_6_clicked()
{
    randomstadium c;
    this->hide();
    c.setModal(true);
    c.exec();
    if (c.close())
        this->show();
}
