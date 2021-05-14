#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include "modifysouvenirs.h"

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    void on_login_clicked();
    void on_modify_souvenirs_clicked();

private:
    Ui::Admin *ui;
    ModifySouvenirs* ms;
    SouvenirContainer svc;
};

#endif // ADMIN_H
