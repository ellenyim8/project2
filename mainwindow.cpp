#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->title->show();
    ui->user->show();
    ui->admin->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete administrator;
}

void MainWindow::on_admin_clicked()
{
    administrator = new Admin(nullptr);
    administrator->show();
}

void MainWindow::on_user_clicked()
{
    // if click on user button
}

void MainWindow::on_Map_clicked()
{
    Map m;
    this->hide();
    m.setModal(true);
    m.exec();
    if (m.close())
        this->show();
}


void MainWindow::on_pushButton_clicked()
{
    stadiumlists l;
    this->hide();
    l.setModal(true);
    l.exec();
    if (l.close())
        this->show();
}
