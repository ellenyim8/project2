#ifndef RANDOMSTADIUM_H
#define RANDOMSTADIUM_H

#include <QDialog>
#include <stdlib.h>
#include <time.h>
#include "global.h"
namespace Ui {
class randomstadium;
}

class randomstadium : public QDialog
{
    Q_OBJECT

public:
    explicit randomstadium(QWidget *parent = nullptr);
    ~randomstadium();

private slots:
    void on_pushButton_clicked();

private:
    Ui::randomstadium *ui;
};

#endif // RANDOMSTADIUM_H
