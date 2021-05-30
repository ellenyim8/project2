#ifndef PURCHASE_REPORT_H
#define PURCHASE_REPORT_H

#include <QDialog>

#include "purchasecontainer.h"
#include "purchase.h"
#include "souvenircontainer.h"

namespace Ui {
class purchase_report;
}

class purchase_report : public QDialog
{
    Q_OBJECT

public:
    explicit purchase_report(QWidget *parent = nullptr);
    //purchase_report(QWidget *parent, PurchaseContainer *all_purchases,
    //                SouvenirContainer *all_souvenirs);
    ~purchase_report();

private slots:
    void on_submit_clicked();
    void on_exit_clicked();

private:
    void singleSouvenirReport(std::string s);
    void allSouvenirsReport();

    Ui::purchase_report *ui;
    PurchaseContainer *all_purchases;
    SouvenirContainer *all_souvenirs;
};

#endif // PURCHASE_REPORT_H
