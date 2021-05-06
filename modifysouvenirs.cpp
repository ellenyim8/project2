#include "modifysouvenirs.h"
#include "ui_modifysouvenirs.h"

/****************************************************
 * ModifySouvenirs(QWidget*)
 *
 * default constructor; receives a parameter from
 * QWidget
 * -------------------------------------------------
 *  Pre-conditions: none
 * -------------------------------------------------
 *  Post-conditions: sets up ui
****************************************************/
ModifySouvenirs::ModifySouvenirs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifySouvenirs)
{
    ui->setupUi(this);
}

/****************************************************
 * ModifySouvenirs(QWidget*, SouvenirContainer*)
 *
 * constructor; receives parameters from QWidget and
 * SouvenirContainer
 * -------------------------------------------------
 *  Pre-conditions: none
 * -------------------------------------------------
 *  Post-conditions: sets up ui; hides labels/inputs
****************************************************/
ModifySouvenirs::ModifySouvenirs(QWidget* parent, SouvenirContainer* s)
    : QDialog(parent),
      ui(new Ui::ModifySouvenirs)
{
    ui->setupUi(this);
    ui->exit->show();

    ui->itemLabel->show();
    ui->input_souvenir->show();
    ui->priceLabel->show();
    ui->input_price->show();
    ui->input_quantity->show();
    ui->quantityLabel->show();
    ui->report->show();
    ui->addButtonSubmit->show();
    ui->deleteButtonSubmit->show();

    // testing... [will delete later]
    Souvenir s1("T-shirt", 9.00, 20);
    Souvenir s2("Cap", 11.00, 15);
    s->add_souvenir(s1);
    s->add_souvenir(s2);

    this->sc = s;
}

/****************************************************
 * ModifySouvenirs()
 *
 * destructor; receives no arguments
 * -------------------------------------------------
 *  Pre-conditions: constructor called
 * -------------------------------------------------
 *  Post-conditions: deletes ui
****************************************************/
ModifySouvenirs::~ModifySouvenirs()
{
    delete ui;
}

/****************************************************
 * void on_exit_clicked()
 *  Receives no parameters.
 *  Returns nothing.
 * -------------------------------------------------
 *  Pre-conditions: destructor called
 * -------------------------------------------------
 *  Post-conditions: closes this window
****************************************************/
void ModifySouvenirs::on_exit_clicked()
{
    ui->~ModifySouvenirs();
    ModifySouvenirs::close();
}

/****************************************************
 * void empty()
 *  Receives no parameters
 *  Returns nothing
 * -------------------------------------------------
 *  Pre-conditions: souvenir list count == 0
 * -------------------------------------------------
 *  Post-conditions: displays to text that souvenir
 *      list is empty.
****************************************************/
void ModifySouvenirs::empty()
{
    ui->report->setText("Souvenir List = 0");
}

/****************************************************
 * ModifySouvenirs()
 *  Receives no parameters
 *  Returns nothing
 * -------------------------------------------------
 *  Pre-conditions: none
 * -------------------------------------------------
 *  Post-conditions: displays souvenir information:
 *      souvenir name, price, and quantity
****************************************************/
void ModifySouvenirs::generate_souvenir_list()
{
    QString list = "-----------------------------------\n";
    if (this->sc->get_souvenirs_count() == 0)
        empty();

    else
    {
        for (int i=0; i<this->sc->get_souvenirs_count(); i++) {
            list += sc->get_souvenir(i).get_item().c_str();
            list += "\n";
            list += to_string(sc->get_souvenir(i).get_price()).c_str();
            list += "\t";
            list += to_string(sc->get_souvenir(i).get_quantity()).c_str();
            list += "\n\n";
        }
    }
    list += "----------End of report----------";
    ui->report->setPlainText(list);

}

/****************************************************
 * void on_addButtonSubmit_clicked()
 *  Receives no parameters.
 *  Returns nothing.
 * -------------------------------------------------
 *  Pre-conditions: textedits: name, price, and
 *      quantity input
 * -------------------------------------------------
 *  Post-conditions: adds souvenir to list
****************************************************/
void ModifySouvenirs::on_addButtonSubmit_clicked()
{
    QString name;
    QString price;
    QString quantity;

    name = ui->input_souvenir->text();
    price = ui->input_price->text();
    quantity = ui->input_quantity->text();

    string souvenir = name.toStdString();
    double price_souvenir = price.toDouble();
    int s_quan = quantity.toInt();

    Souvenir s(souvenir, price_souvenir, s_quan);
    sc->add_souvenir(s);

    ui->report->setPlainText(QString::fromStdString("Added! Total Souvenirs: "));
    ui->report->setPlainText(QString::fromStdString("Added! Total Souvenirs: ") + QString::number(sc->get_souvenirs_count()));

    ui->input_souvenir->clear();
    ui->input_price->clear();
    ui->input_quantity->clear();
}

/****************************************************
 * void on_deleteButtonSubmit()
 *  Receives no parameters.
 *  Returns nothing.
 * -------------------------------------------------
 *  Pre-conditions: (textedit) name input
 * -------------------------------------------------
 *  Post-conditions: removes souvenir from list
****************************************************/
void ModifySouvenirs::on_deleteButtonSubmit_clicked()
{
    QString name;

    name = ui->input_souvenir->text();

    string souvenir = name.toStdString();

    sc->remove_souvenir(souvenir);
    int count = sc->get_souvenirs_count();
    QString msg = "Deleted! Total souvenirs: ";

    ui->report->setPlainText(msg + QString::number(count));

    ui->input_souvenir->clear();
}

/****************************************************
 * void on_viewCurrentList_clicked()
 *  Receives no parameters.
 *  Returns nothing.
 * -------------------------------------------------
 *  Pre-conditions: none
 * -------------------------------------------------
 *  Post-conditions: displays current list of
 *      souvenirs to text
****************************************************/
void ModifySouvenirs::on_viewCurrentList_clicked()
{
    generate_souvenir_list();
}

/****************************************************
 * void on_addButtonSubmit_clicked()
 *  Receives no parameters.
 *  Returns nothing.
 * -------------------------------------------------
 *  Pre-conditions: (textedit) name
 * -------------------------------------------------
 *  Post-conditions: displays specified souvenir
 *      information to text
****************************************************/
void ModifySouvenirs::on_viewButton_clicked()
{
    QString name;

    name = ui->input_souvenir->text();
    string view_souvenir = name.toStdString();
    ui->input_souvenir->clear();

    if (!sc->contains(name.toStdString())) {
        QMessageBox::warning(this, "Warning", "souvenir not listed.");
        return;
    }

    Souvenir s = sc->get_souvenir(view_souvenir);
    QString msg = "Souvenir information: ";
    QString souvenir = "Souvenir: ";
    QString price = "Price selling at: ";
    QString quan = "Quantity: ";
    string item = s.get_item();
    double p = s.get_price();
    int q = s.get_quantity();
    QString display_item = QString::fromStdString(item);
    QString display_price = QString::number(p);
    QString display_quantity = QString::number(q);

    ui->report->setPlainText(msg + "\n" + souvenir + display_item
                             + "\n" + price + display_price + "\t"
                             + quan + display_quantity + "\n");

}

