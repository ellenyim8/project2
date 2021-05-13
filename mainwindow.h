#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "modifysouvenirs.h"
#include "admin.h"
#include "map.h"
#include "global.h"
#include "stadiumlists.h"
#include "trips.h"

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
    void on_user_clicked();

    void on_Map_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    Admin* administrator;

};


#endif // MAINWINDOW_H
