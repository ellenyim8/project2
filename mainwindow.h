#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "admin.h"
#include "map.h"
#include "global.h"
#include "stadiumlists.h"
#include "trips.h"
#include "dreamvacation.h"
#include "checkdistance.h"
#include "purchase_report.h"
#include "randomstadium.h"

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
    void on_admin_clicked();

    void on_Map_clicked();

    void on_pushButton_clicked();       // show teams list

    void on_pushButton_2_clicked();     // trips

    void on_pushButton_3_clicked();     // plan a dream vacation

    void on_pushButton_4_clicked();     // check distances b/w stadiums

    void on_pushButton_5_clicked();     // souvenir purchases report

    void on_pushButton_6_clicked();     // randomly access any baseball stadium

private:
    Ui::MainWindow *ui;
    Admin* administrator;
};


#endif // MAINWINDOW_H
