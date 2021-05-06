#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label->show();
    ui->modifySouvenirs->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ms;
}

void MainWindow::on_modifySouvenirs_clicked()
{
    ms = new ModifySouvenirs(nullptr, &sc);
    ms->show();
}

