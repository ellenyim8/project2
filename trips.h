#ifndef TRIPS_H
#define TRIPS_H

#include <QDialog>
//#include "Dijkstra.h"
#include "global.h"

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

private:
    Ui::trips *ui;
};

#endif // TRIPS_H
