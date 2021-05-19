#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include "global.h"
#include "heap.h"
#include "Dijkstra.h"
#include <QFile>
using namespace std;
Heap<Stadiums,StadiumsNameMin> MLS; // major league stadiums sorted by stadium names
Heap<Stadiums,StringMin> MLS2;      // major league stadiums sorted by team names
Heap<Stadiums,StringMin> ALS;       // American league stadiums
Heap<Stadiums,StringMin> NLS;       // National league stadiums
Dijkstra<string> MLSP;              // major league stadiums paths
vector<pair<string,QPoint>> positions;  // store all the stadiums and their positions
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

    // create the paths
    dp p1(make_pair(make_pair("AT&T Park","SafeCo Field"),680));
    dp p2(make_pair(make_pair("AT&T Park","O.co Coliseum"),0));
    dp p3(make_pair(make_pair("Dodger Stadium","AT&T Park"),340));
    dp p4(make_pair(make_pair("AT&T Park","Chase Field"),650));
    dp p5(make_pair(make_pair("SafeCo Field","Rogers Center"),2070));
    dp p6(make_pair(make_pair("SafeCo Field","Target Field"),1390));
    dp p7(make_pair(make_pair("Dodger Stadium","Target Field"),1500));
    dp p8(make_pair(make_pair("Dodger Stadium","Petco Park"),110));
    dp p9(make_pair(make_pair("Dodger Stadium","Angel Stadium"),0));
    dp p10(make_pair(make_pair("Petco Park","Coors Field"),830));
    dp p11(make_pair(make_pair("Petco Park","Chase Field"),300));
    dp p12(make_pair(make_pair("Chase Field","Coors Field"),580));
    dp p13(make_pair(make_pair("Chase Field","Rangers Ballpark"),870));
    dp p14(make_pair(make_pair("Chase Field","Minute Maid Park"),1115));
    dp p15(make_pair(make_pair("Coors Field","Kauffman Stadium"),560));
    dp p16(make_pair(make_pair("Coors Field","Rangers Ballpark"),650));
    dp p17(make_pair(make_pair("Target Field","Miller Park"),300));
    dp p18(make_pair(make_pair("Target Field","Busch Stadium"),465));
    dp p19(make_pair(make_pair("Kauffman Stadium","US Cellular Field"),415));
    dp p20(make_pair(make_pair("Kauffman Stadium","Busch Stadium"),235));
    dp p21(make_pair(make_pair("Rangers Ballpark","Kauffman Stadium"),460));
    dp p22(make_pair(make_pair("Rangers Ballpark","Turner Field"),740));
    dp p23(make_pair(make_pair("Rangers Ballpark","Minute Maid Park"),230));
    dp p24(make_pair(make_pair("Minute Maid Park","Busch Stadium"),680));
    dp p25(make_pair(make_pair("Minute Maid Park","Tropicana Field"),790));
    dp p26(make_pair(make_pair("Minute Maid Park","Marlins Park"),965));
    dp p27(make_pair(make_pair("Busch Stadium","Great American Ballpark"),310));
    dp p28(make_pair(make_pair("Miller Park","Wrigley Field"),80));
    dp p29(make_pair(make_pair("Miller Park","Rogers Center"),430));
    dp p30(make_pair(make_pair("Wrigley Field","US Cellular Field"),0));
    dp p31(make_pair(make_pair("Wrigley Field","Comerica Park"),240));
    dp p32(make_pair(make_pair("Wrigley Field","Great American Ballpark"),250));
    dp p33(make_pair(make_pair("Comerica Park","Rogers Center"),210));
    dp p34(make_pair(make_pair("Comerica Park","Progressive Field"),90));
    dp p35(make_pair(make_pair("Great American Ballpark","Progressive Field"),225));
    dp p36(make_pair(make_pair("Great American Ballpark","PNC Park"),260));
    dp p37(make_pair(make_pair("Great American Ballpark","Turner Field"),375));
    dp p38(make_pair(make_pair("Great American Ballpark","Tropicana Field"),790));
    dp p39(make_pair(make_pair("Turner Field","Nationals Park"),560));
    dp p40(make_pair(make_pair("Turner Field","Marlins Park"),600));
    dp p41(make_pair(make_pair("Progressive Field","PNC Park"),115));
    dp p42(make_pair(make_pair("Rogers Center","Fenway Park"),430));
    dp p43(make_pair(make_pair("Rogers Center","PNC Park"),225));
    dp p44(make_pair(make_pair("PNC Park","Yankee Stadium"),315));
    dp p45(make_pair(make_pair("PNC Park","Nationals Park"),195));
    dp p46(make_pair(make_pair("Tropicana Field","Marlins Park"),210));
    dp p47(make_pair(make_pair("Nationals Park","Camden Yards"),0));
    dp p48(make_pair(make_pair("Nationals Park","Citizens Bank Park"),90));
    dp p49(make_pair(make_pair("Nationals Park","Marlins Park"),930));
    dp p50(make_pair(make_pair("Marlins Park","Fenway Park"),1255));
    dp p51(make_pair(make_pair("Citizens Bank Park","Yankee Stadium"),80));
    dp p52(make_pair(make_pair("Yankee Stadium","Citi Field"),0));
    dp p53(make_pair(make_pair("Citi Field","Fenway Park"),195));

    // insert all major stadiums paths
    MLSP.set_start_position("Dodger Stadium");
    MLSP.insert_path(p7);
    MLSP.insert_path(p8);
    MLSP.insert_path(p9);
    MLSP.insert_path(p3);
    MLSP.insert_path(p1);
    MLSP.insert_path(p2);
    MLSP.insert_path(p4);
    MLSP.insert_path(p5);
    MLSP.insert_path(p6);
    MLSP.insert_path(p10);
    MLSP.insert_path(p11);
    MLSP.insert_path(p12);
    MLSP.insert_path(p13);
    MLSP.insert_path(p14);
    MLSP.insert_path(p15);
    MLSP.insert_path(p16);
    MLSP.insert_path(p17);
    MLSP.insert_path(p18);
    MLSP.insert_path(p19);
    MLSP.insert_path(p20);
    MLSP.insert_path(p21);
    MLSP.insert_path(p22);
    MLSP.insert_path(p23);
    MLSP.insert_path(p24);
    MLSP.insert_path(p25);
    MLSP.insert_path(p26);
    MLSP.insert_path(p27);
    MLSP.insert_path(p28);
    MLSP.insert_path(p29);
    MLSP.insert_path(p30);
    MLSP.insert_path(p31);
    MLSP.insert_path(p32);
    MLSP.insert_path(p33);
    MLSP.insert_path(p34);
    MLSP.insert_path(p35);
    MLSP.insert_path(p36);
    MLSP.insert_path(p37);
    MLSP.insert_path(p38);
    MLSP.insert_path(p39);
    MLSP.insert_path(p40);
    MLSP.insert_path(p41);
    MLSP.insert_path(p42);
    MLSP.insert_path(p43);
    MLSP.insert_path(p44);
    MLSP.insert_path(p45);
    MLSP.insert_path(p46);
    MLSP.insert_path(p47);
    MLSP.insert_path(p48);
    MLSP.insert_path(p49);
    MLSP.insert_path(p50);
    MLSP.insert_path(p51);
    MLSP.insert_path(p52);
    MLSP.insert_path(p53);

    MLSP.shortest_path();

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
