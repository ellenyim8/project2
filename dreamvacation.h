#ifndef DREAMVACATION_H
#define DREAMVACATION_H

#include <QDialog>
#include "global.h"
#include <sstream>
#include "Dijkstra.h"
#include "designtrip.h"
#include "map.h"
namespace Ui {
class dreamvacation;
}

class dreamvacation : public QDialog
{
    Q_OBJECT

public:
    explicit dreamvacation(QWidget *parent = nullptr);
    ~dreamvacation();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::dreamvacation *ui;
    vector<string> vec;
    vector<string> v1;
};

#endif // DREAMVACATION_H
