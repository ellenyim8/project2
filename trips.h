#ifndef TRIPS_H
#define TRIPS_H

#include <QDialog>
#include "Dijkstra.h"
#include "designtrip.h"
#include "global.h"
#include "map.h"

namespace Ui {
class trips;
}

class trips : public QDialog
{
    Q_OBJECT

public:
    explicit trips(QWidget *parent = nullptr);
    ~trips();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::trips *ui;
    vector<string> v1;
    vector<string> v2;
    vector<string> v4;
};

#endif // TRIPS_H
