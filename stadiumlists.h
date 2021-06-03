#ifndef STADIUMLISTS_H
#define STADIUMLISTS_H

#include <QDialog>
#include "global.h"
namespace Ui {
class stadiumlists;
}

class stadiumlists : public QDialog
{
    Q_OBJECT

public:
    explicit stadiumlists(QWidget *parent = nullptr);
    ~stadiumlists();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::stadiumlists *ui;
};

#endif // STADIUMLISTS_H
