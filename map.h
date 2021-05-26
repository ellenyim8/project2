#ifndef MAP_H
#define MAP_H

#include <QDialog>
#include <QPainter>
#include "global.h"
namespace Ui {
class Map;
}

class Map : public QDialog
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = nullptr);
    ~Map();
    void set_list(const vector<string>& v);

private:
    Ui::Map *ui;

protected:
    void paintEvent(QPaintEvent *e);
    vector<string> list;
};

#endif // MAP_H
