#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include "modifysouvenirs.h"
#include "modifystadium.h"
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
    void on_close_clicked();
    void on_modify_souvenirs_clicked();

    void on_stadium_button_clicked();

private:
    Ui::Admin *ui;
    ModifySouvenirs* ms;
    ModifyStadium* modifyStadium;
    SouvenirContainer svc;
};

#endif // ADMIN_H
