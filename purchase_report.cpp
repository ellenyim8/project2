#include "purchase_report.h"
#include "ui_purchase_report.h"
#include <algorithm>

purchase_report::purchase_report(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::purchase_report)
{
    ui->setupUi(this);
}

purchase_report::~purchase_report()
{
    delete ui;
}

void purchase_report::on_exit_clicked()
{
    ui->~purchase_report();
    purchase_report::close();
}

void purchase_report::on_submit_clicked()
{
    ui->report->clear();

    if (ui->checkBox_2->isChecked())    // if allSouvenir is checked
    {
        allSouvenirsReport();
    }
    else
    {
        std::string souvenirName = ui->name->text().toStdString();
        if (!all_souvenirs->contains(souvenirName))
        {
            QMessageBox::warning(this, "Warning", "Souvenir not found. ");
            return;
        }
        singleSouvenirReport(souvenirName);
    }
}

void purchase_report::singleSouvenirReport(std::string s)
{
    ui->report->clear();
    PurchaseContainer output;

    for (size_t i=0; i<all_purchases->size(); i++)
    {
        if (s == (*all_purchases)[i].getSouvenirName())
            output.push_back((*all_purchases)[i]);
    }

    if (output.size() == 0)
    {
        QMessageBox::warning(this, "Warning", "No purchases made for that souvenir. ");
        return;
    }

    int quantity = 0;
    double price = output.getTotal();
    for (size_t i=0; i<output.size(); i++)
    {
        quantity += output[i].getQuantity();
    }

    QString report;
    report += "----------Report----------\n\n";
    report += "Souvenir name: ";
    report += s.c_str();
    report += "\n";

    report += "Souvenir Quantity bought: ";
    report += to_string(quantity).c_str();
    report += "\n";
    report += "Total spent for Souvenir: $";
    report += to_string(price).c_str();
    report += "\n\n";
    report += "----------End of report---------\n";

    ui->report->setText(report);
}

void purchase_report::allSouvenirsReport()
{
    ui->report->clear();
    PurchaseContainer purchases;
    for (size_t i=0; i<all_purchases->size(); i++)
    {
        int index = purchases.find((*all_purchases)[i].getSouvenirName());
        if (index == -1)
            purchases.push_back((*all_purchases)[i]);
        else
        {
            int s1 = purchases[index].getQuantity();
            int s2 = (*all_purchases)[i].getQuantity();
            purchases[index].setQuantity(s1 + s2);
        }
    }

    if (purchases.size() == 0)
    {
        QMessageBox::warning(this, "Warning", "No purchases made for that souvenir.");
        return;
    }

    //std::sort(all_souvenirs->begin(), all_souvenirs->end());

    QString outs = "------------Report------------\n\n";
    int bought = 0;
    for (size_t i=0; i<all_souvenirs->get_souvenirs_count(); i++)
    {
        int index = purchases.find((*all_souvenirs)[i].get_item());
        index != -1 ? bought = purchases[index].getQuantity() : bought = 0;

        outs += "Souvenir: ";
        outs += QString::fromStdString((*all_souvenirs)[i].get_item());
        outs += "\n";
        outs += "Souvenir quantity bought: ";
        outs += QString::fromStdString(to_string(bought));
        outs += "\n";
    }

    outs += "Total number of souvenirs: ";
    outs += QString::fromStdString(to_string((*all_souvenirs).get_souvenirs_count()));
    outs += "\n\n";
    outs += "----------End of report-------------\n";

    ui->report->setText(outs);
}
