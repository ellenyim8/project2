#ifndef MODIFYSOUVENIRS_H
#define MODIFYSOUVENIRS_H

#include <QDialog>
#include <algorithm>
#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include "souvenircontainer.h"

namespace Ui {
class ModifySouvenirs;
}

class ModifySouvenirs : public QDialog
{
    Q_OBJECT

public:
    explicit ModifySouvenirs(QWidget *parent = nullptr);
    ModifySouvenirs(QWidget*parent, SouvenirContainer* s);
    ~ModifySouvenirs();

private slots:
    void on_addButtonSubmit_clicked();
    void on_deleteButtonSubmit_clicked();
    void on_viewCurrentList_clicked();
    void on_viewButton_clicked();
    void on_exit_clicked();

private:
    void empty();
    void generate_souvenir_list();

    Ui::ModifySouvenirs *ui;
    SouvenirContainer* sc;

};


/*****************************************************
 * ModifySouvenir class
 *  This ui designer class modifies the souvenirs
 *  if admin requests a change in souvenirs
 *
 * void empty()
 * void generate_list()
 *
 * Constructors and destructor
 *  ModifySouvenir(QDialog*parent=nullptr)
 *  ModifySouvenir(QDialog* parent, SouvenirContainer*sc)
 *  ~ModifySouvenir()
 *
 * void empty()
 * void generate_souvenir_list()
 *
 * slots
 * void on_addButtonSubmit_clicked()
 * void on_deleteButtonSubmit_clicked()
 * void on_viewCurrentList_clicked();
 * void on_viewButton_clicked();
 * void on_exit_clicked()
 *
******************************************************/

#endif // MODIFYSOUVENIRS_H
