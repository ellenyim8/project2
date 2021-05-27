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
vector<pair<int,vector<string>>> MLSP;                         // major league stadiums paths
vector<pair<string,QPoint>> positions;  // store all the stadiums and their positions

//void insert_paths(string start,Dijkstra<string>& d);

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

    positions.push_back(make_pair("SafeCo Field",QPoint(100,35)));
    positions.push_back(make_pair("AT&T Park",QPoint(40,230)));
    positions.push_back(make_pair("O.co Coliseum",QPoint(45,238)));
    positions.push_back(make_pair("Dodger Stadium",QPoint(80,325)));
    positions.push_back(make_pair("Angel Stadium",QPoint(85,333)));
    positions.push_back(make_pair("Petco Park",QPoint(100,355)));
    positions.push_back(make_pair("Chase Field",QPoint(190,358)));
    positions.push_back(make_pair("Coors Field",QPoint(315,235)));
    positions.push_back(make_pair("Target Field",QPoint(505,145)));
    positions.push_back(make_pair("Kauffman Stadium",QPoint(490,260)));
    positions.push_back(make_pair("Rangers Ballpark",QPoint(452,395)));
    positions.push_back(make_pair("Minute Maid Park",QPoint(480,470)));
    positions.push_back(make_pair("Busch Stadium",QPoint(553,273)));
    positions.push_back(make_pair("Miller Park",QPoint(585,167)));
    positions.push_back(make_pair("Wrigley Field",QPoint(589,195)));
    positions.push_back(make_pair("US Cellular Field",QPoint(593,205)));
    positions.push_back(make_pair("Comerica Park",QPoint(657,185)));
    positions.push_back(make_pair("Great American Ballpark",QPoint(652,253)));
    positions.push_back(make_pair("Turner Field",QPoint(670,360)));
    positions.push_back(make_pair("Progressive Field",QPoint(685,205)));
    positions.push_back(make_pair("Rogers Center",QPoint(720,140)));
    positions.push_back(make_pair("PNC Park",QPoint(725,220)));
    positions.push_back(make_pair("Tropicana Field",QPoint(720,480)));
    positions.push_back(make_pair("Marlins Park",QPoint(760,520)));
    positions.push_back(make_pair("Nationals Park",QPoint(772,240)));
    positions.push_back(make_pair("Camden Yards",QPoint(778,230)));
    positions.push_back(make_pair("Citizens Bank Park",QPoint(795,207)));
    positions.push_back(make_pair("Yankee Stadium",QPoint(810,182)));
    positions.push_back(make_pair("Citi Field",QPoint(815,192)));
    positions.push_back(make_pair("Fenway Park",QPoint(845,150)));


    MainWindow w;
    w.show();
    return a.exec();
}

