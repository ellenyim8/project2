#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->title->show();
    ui->admin->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete administrator;
}

void MainWindow::on_admin_clicked()
{
    this->hide();
    administrator = new Admin(nullptr);
    administrator->setModal(true);
    administrator->show();
}

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

void MainWindow::on_pushButton_3_clicked()
{
    dreamvacation d;
    this->hide();
    d.setModal(true);
    d.exec();
    if (d.close())
        this->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    checkdistance c;
    this->hide();
    c.setModal(true);
    c.exec();
    if (c.close())
        this->show();
}
