#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include "global.h"
#include "heap.h"
#include "Dijkstra.h"
#include <QFile>
#include <QTextStream>

using namespace std;
Heap<Stadiums,StadiumsNameMin> MLS; // major league stadiums sorted by stadium names
Heap<Stadiums,StringMin> MLS2;      // major league stadiums sorted by team names
Heap<Stadiums,StringMin> ALS;       // American league stadiums
Heap<Stadiums,StringMin> NLS;       // National league stadiums
vector<pair<int,vector<string>>> MLSP;           // major league stadiums paths



int main(int argc, char *argv[])
{
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
           QString line8 = in.readLine();
           QString line9 = in.readLine();
           ALS.insert(Stadiums(line.toStdString(),line2.toStdString(),
                               line3.toStdString(),line4.toStdString(),
                               line5.toStdString(),line6.toStdString(),
                               line7.toStdString(),line8.toStdString(),
                               line9.toStdString()));
           MLS.insert(Stadiums(line.toStdString(),line2.toStdString(),
                               line3.toStdString(),line4.toStdString(),
                               line5.toStdString(),line6.toStdString(),
                               line7.toStdString(),line8.toStdString(),
                               line9.toStdString()));
           MLS2.insert(Stadiums(line.toStdString(),line2.toStdString(),
                                line3.toStdString(),line4.toStdString(),
                                line5.toStdString(),line6.toStdString(),
                                line7.toStdString(),line8.toStdString(),
                                line9.toStdString()));
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
           QString line8 = in.readLine();
           QString line9 = in.readLine();
           NLS.insert(Stadiums(line.toStdString(),line2.toStdString(),
                               line3.toStdString(),line4.toStdString(),
                               line5.toStdString(),line6.toStdString(),
                               line7.toStdString(),line8.toStdString(),
                               line9.toStdString()));
           MLS.insert(Stadiums(line.toStdString(),line2.toStdString(),
                               line3.toStdString(),line4.toStdString(),
                               line5.toStdString(),line6.toStdString(),
                               line7.toStdString(),line8.toStdString(),
                               line9.toStdString()));
           MLS2.insert(Stadiums(line.toStdString(),line2.toStdString(),
                                line3.toStdString(),line4.toStdString(),
                                line5.toStdString(),line6.toStdString(),
                                line7.toStdString(),line8.toStdString(),
                                line9.toStdString()));
        }
        input2.close();
    }
    MainWindow w;
    w.show();
    return a.exec();
}

