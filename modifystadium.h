#ifndef MODIFYSTADIUM_H
#define MODIFYSTADIUM_H

#include <QDialog>
#include <algorithm>
#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include <stadium.h>
#include <global.h>

namespace Ui {
class ModifyStadium;
}

class ModifyStadium : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyStadium(QWidget *parent = nullptr);
    ~ModifyStadium();

private slots:

    void on_stadiumConfirmedButton_accepted();

private:
    Ui::ModifyStadium *ui;
};
#endif // MODIFYSTADIUM_H
