#ifndef MAP_H
#define MAP_H

#include <QDialog>
namespace Ui {
class Map;
}

class Map : public QDialog
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = nullptr);
    ~Map();

private:
    Ui::Map *ui;

protected:
    void paintEvent(QPaintEvent *e);

};

#endif // MAP_H
