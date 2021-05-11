#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include "global.h"
#include "heap.h"
#include <QFile>
using namespace std;
Heap<Stadiums,StringMin> h;
int main(int argc, char *argv[])
{
    cout << "hello group!";
    QApplication a(argc, argv);
    string Stadium_Name;
    string Team_Name;
    string address;
    string City_State_Zip;
    string Box_Office_Num;
    string Date_Opened;
    string Seating_Capacity;
    QFile input(":/resource/image/American League Teams.txt");
    if(input.open(QIODevice::ReadOnly))
    {
        QTextStream in(&input);
        while (!in.atEnd())
        {
           QString line = in.readLine();
           QString line2 = in.readLine();
           QString line3 = in.readLine();
           QString line4 = in.readLine();
           QString line5 = in.readLine();
           QString line6 = in.readLine();
           QString line7 = in.readLine();
           h.insert(Stadiums(line.toStdString(),line2.toStdString(),line3.toStdString(),line4.toStdString(),line5.toStdString(),line6.toStdString(),line7.toStdString()));
        }
        input.close();
    }

    MainWindow w;
    w.show();
    return a.exec();
}
