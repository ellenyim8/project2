#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    cout << "hello group!";
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
