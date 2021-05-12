#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include "global.h"
#include "heap.h"
#include <QFile>
using namespace std;
Heap<Stadiums,StadiumsNameMin> MLS;
Heap<Stadiums,StringMin> MLS2;
Heap<Stadiums,StringMin> ALS;
Heap<Stadiums,StringMin> NLS;
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
           ALS.insert(Stadiums(line.toStdString(),line2.toStdString(),line3.toStdString(),line4.toStdString(),line5.toStdString(),line6.toStdString(),line7.toStdString()));
           MLS.insert(Stadiums(line.toStdString(),line2.toStdString(),line3.toStdString(),line4.toStdString(),line5.toStdString(),line6.toStdString(),line7.toStdString()));
           MLS2.insert(Stadiums(line.toStdString(),line2.toStdString(),line3.toStdString(),line4.toStdString(),line5.toStdString(),line6.toStdString(),line7.toStdString()));
        }
        input.close();
    }

    QFile input2(":/resource/image/National League Teams.txt");
    if(input2.open(QIODevice::ReadOnly))
    {
        QTextStream in(&input2);
        while (!in.atEnd())
        {
           QString line = in.readLine();
           QString line2 = in.readLine();
           QString line3 = in.readLine();
           QString line4 = in.readLine();
           QString line5 = in.readLine();
           QString line6 = in.readLine();
           QString line7 = in.readLine();
           NLS.insert(Stadiums(line.toStdString(),line2.toStdString(),line3.toStdString(),line4.toStdString(),line5.toStdString(),line6.toStdString(),line7.toStdString()));
           MLS.insert(Stadiums(line.toStdString(),line2.toStdString(),line3.toStdString(),line4.toStdString(),line5.toStdString(),line6.toStdString(),line7.toStdString()));
           MLS2.insert(Stadiums(line.toStdString(),line2.toStdString(),line3.toStdString(),line4.toStdString(),line5.toStdString(),line6.toStdString(),line7.toStdString()));
        }
        input2.close();
    }

    MainWindow w;
    w.show();
    return a.exec();
}
