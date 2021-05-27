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

    // testing...
    Souvenir s1("Baseball bat", 35.35);
    Souvenir s2("Baseball cap", 25.99);
    Souvenir s3("Team pennant", 12.99);
    Souvenir s4("Autographed baseball", 19.99);
    s->add_souvenir(s1);
    s->add_souvenir(s2);
    s->add_souvenir(s3);
    s->add_souvenir(s4);

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

void ModifySouvenirs::saveAtSouvenirFile()
{
    //.. save changes to file
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
    string tempString;
    if (this->sc->get_souvenirs_count() == 0)
        empty();

    else
    {
        for (int i=0; i<this->sc->get_souvenirs_count(); i++) {
            list += sc->get_souvenir(i).get_item().c_str();
            list += "\n";
            //create temporary string
            tempString = to_string(sc->get_souvenir(i).get_price()).c_str();
            //cut string up to decimal point and two places after
            tempString = tempString.substr(0, tempString.find(".")+3);
            list += tempString.c_str();
            //list += to_string(sc->get_souvenir(i).get_price()).c_str();
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

    name = ui->input_souvenir->text();
    price = ui->input_price->text();

    string souvenir = name.toStdString();
    double price_souvenir = price.toDouble();

    if ((price.toStdString().size() == 0) || (name.toStdString().size() == 0))
    {
        QMessageBox msg;
        msg.setText("something is empty.");
        msg.exec();
        return;
    }

    for (int i=0; i<(int)price.toStdString().size(); ++i)
    {
        if (!isdigit(price.toStdString()[i]))
        {
            QMessageBox msg;
            msg.setText("Price should be a number.");
            msg.exec();
            return;
        }
    }

    Souvenir s(souvenir, price_souvenir);
    sc->add_souvenir(s);

    ui->report->setPlainText(QString::fromStdString("Added! Total Souvenirs: "));
    ui->report->setPlainText(QString::fromStdString("Added! Total Souvenirs: ") + QString::number(sc->get_souvenirs_count()));

    saveAtSouvenirFile();

    ui->input_souvenir->clear();
    ui->input_price->clear();
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
    bool exists = false;
    name = ui->input_souvenir->text();

    for (int i=0; i<sc->get_souvenirs_count(); i++)
    {
        if (sc->get_souvenir(i).get_item() == name.toStdString())
        {
            sc->remove_souvenir(name.toStdString());
            exists = true;
        }
    }

    if (!exists)
    {
        QMessageBox msg;
        msg.setText("Souvenir doesn't exists.");
        msg.exec();
        return;
    }

    int count = sc->get_souvenirs_count();
    QString msg = "Deleted! Total souvenirs: ";
    ui->report->setPlainText(msg + QString::number(count));

    saveAtSouvenirFile();

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
 * void on_viewButton_clicked()
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
    string item = s.get_item();
    double p = s.get_price();
    QString display_item = QString::fromStdString(item);
    QString display_price = QString::number(p);

    ui->report->setPlainText(msg + "\n" + souvenir + display_item
                             + "\n" + price + display_price + "\n");

}

void ModifySouvenirs::on_change_clicked()
{
    QString name;
    QString price;
    double price_amt;
    bool exists = false;

    name = ui->input_souvenir->text();
    price = ui->input_price->text();

    if ((price.toStdString().size() == 0) || (name.toStdString().size() == 0))
    {
        QMessageBox msg;
        msg.setText("an input is blank. ");
        msg.exec();
        return;
    }

    for (int i=0; i<(int)price.toStdString().size(); ++i)
    {
        if (!isdigit(price.toStdString()[i]))
        {
            QMessageBox msg;
            msg.setText("Price should be a number.");
            msg.exec();
            return;
        }
    }

    price_amt = stod(price.toStdString());
    for (int i=0; i<sc->get_souvenirs_count(); i++)
    {
        if (sc->get_souvenir(i).get_item() == name.toStdString())
        {
            sc->get_souvenir(i).set_price(price_amt);
            exists = true;
        }
    }

    if (!exists)
    {
        QMessageBox msg;
        msg.setText("Souvenir doesn't exist. ");
        msg.exec();
        return;
    }

    saveAtSouvenirFile();

}

