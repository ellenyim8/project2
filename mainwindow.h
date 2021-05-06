#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "modifysouvenirs.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_modifySouvenirs_clicked();

private:
    Ui::MainWindow *ui;
    ModifySouvenirs* ms;        // admin; modify souvenirs
    SouvenirContainer sc;       // souvenir container object
};


#endif // MAINWINDOW_H
