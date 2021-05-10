#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include "modifysouvenirs.h"
#include "binaryTree.h"
#include "stadium.h"

struct StadiumComparator
{
    bool operator() (Stadium one, Stadium two) {
        int compare = one.get_team().compare(two.get_team());
        if (compare < 0)
            return true;
        else
            return false;
    }
};

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
    void on_addNewTeam_clicked();
    void on_addNewStadium_clicked();
    void on_displayStadiums_clicked();
    void on_souvenirsPageButton_clicked();

private:
    Ui::Admin *ui;
    BinaryTree<Stadium, StadiumComparator>* stadium_list;
    vector<Stadium> list;

    ModifySouvenirs* ms;
    SouvenirContainer sc;

};

#endif // ADMIN_H
