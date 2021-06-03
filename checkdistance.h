#ifndef CHECKDISTANCE_H
#define CHECKDISTANCE_H

#include <QDialog>
#include "global.h"
#include <sstream>
#include "Dijkstra.h"
#include "designtrip.h"
#include "map.h"
namespace Ui {
class checkdistance;
}

class checkdistance : public QDialog
{
    Q_OBJECT

public:
    explicit checkdistance(QWidget *parent = nullptr);
    ~checkdistance();

private slots:
    void on_pushButton_clicked();

private:
    Ui::checkdistance *ui;
    vector<string> vec;
};

#endif // CHECKDISTANCE_H
