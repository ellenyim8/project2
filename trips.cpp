#include "trips.h"
#include "ui_trips.h"
/****************************************************
 * trips()
 *  CTOR; sets up ui
 * -------------------------------------------------
 *  Preconditions: none
 * -------------------------------------------------
 *  Postconditions: trips window is set up
****************************************************/
trips::trips(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::trips)
{
    ui->setupUi(this);
}

/****************************************************
 * ~trips()
 *  destructor; receives no parameters and returns
 *  nothing
 * -------------------------------------------------
 *  Preconditions: none
 * -------------------------------------------------
 *  Postconditions: ui stops running
****************************************************/
trips::~trips()
{
    delete ui;
}

/**********************************************************
 * void on_pushButton_clicked()
 *
 *  Push the button will show the trip to all the major
 *  league stadiums
 * --------------------------------------------------------
 *  Pre-conditions: None
 * -------------------------------------------------------
 *  Post-condition: Current window is close, main window
 *  shows.
**********************************************************/
// trips to all the major league stadiums
void trips::on_pushButton_clicked()
{
    ui->listWidget->clear();
    ui->listWidget->addItem(QString::fromStdString("Trip to all the major league stadiums"));
    ui->listWidget->addItem(QString::fromStdString("Starting from Dodger Stadium"));
    ui->listWidget->addItem(QString::fromStdString(""));

    shortestTrip s;
    string name = "Dodger Stadium";
    s.insert_city(name);
    while(s.get_noc() != 30){
        graph g;
        vector<pair<int,vector<string>>> vv;
        g.Dijstra(name,vv);
        for(unsigned long long i = 0;i < vv.size();i++){
            for(unsigned long long j = i + 1;j < vv.size();j++){
                if(vv[i].first > vv[j].first){
                    pair<int,vector<string>> p = vv[i];
                    vv[i] = vv[j];
                    vv[j] = p;
                }
            }
        }
        int num = 0;
        while(s.check(vv[num].second.back())){
            num++;
        }
        s.insert(vv[num]);
        name = vv[num].second.back();
        s.insert_city(name);
    }

    graph g1;
    vector<pair<int,vector<string>>> v3;
    g1.Dijstra(s.get_cities().back(),v3);
    int num1 = 0;
    while(v3[num1].second.back() != "Dodger Stadium")
        num1++;
    s.insert(v3[num1]);
    s.set_trip();
    string output = "Number of stadiums visited: " + to_string(s.get_route().size());
    ui->listWidget->addItem(QString::fromStdString(output));
    ui->listWidget->addItem(QString::fromStdString(""));
    ui->listWidget->addItem(QString::fromStdString("The order the stadiums are visited:"));
    v1 = s.get_route();
    for(unsigned long long i = 0;i < v1.size();i++){
        ui->listWidget->addItem(QString::fromStdString(v1[i]));
    }
    ui->listWidget->addItem(QString::fromStdString(""));
    ui->listWidget->addItem(QString::fromStdString("The total distance travelled: " + to_string(s.get_distance())));

}

/**********************************************************
 * void on_pushButton_2_clicked()
 *
 *  Push the button will show the trip to all the American
 *  league stadiums
 * --------------------------------------------------------
 *  Pre-conditions: None
 * -------------------------------------------------------
 *  Post-condition: Current window is close, main window
 *  shows.
**********************************************************/
// trips to all the American league stadiums
void trips::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
    ui->listWidget->addItem(QString::fromStdString("Trip to all the American league stadiums"));
    ui->listWidget->addItem(QString::fromStdString("Starting from Angel Stadium"));
    ui->listWidget->addItem(QString::fromStdString(""));

    shortestTrip s;
    string name = "Angel Stadium";
    s.insert_city(name);
    while(s.get_noc() != ALS.size()){
        graph g;
        vector<pair<int,vector<string>>> vv;
        g.Dijstra(name,vv);
        for(unsigned long long i = 0;i < vv.size();i++){
            for(unsigned long long j = i + 1;j < vv.size();j++){
                if(vv[i].first > vv[j].first){
                    pair<int,vector<string>> p = vv[i];
                    vv[i] = vv[j];
                    vv[j] = p;
                }
            }
        }
        int num = 0;
        while(s.check(vv[num].second.back()) || !ALS.contains(vv[num].second.back())){
            num++;
        }
        s.insert(vv[num]);
        name = vv[num].second.back();
        s.insert_city(name);
    }

    graph g1;
    vector<pair<int,vector<string>>> v3;
    g1.Dijstra(s.get_cities().back(),v3);
    int num1 = 0;
    while(v3[num1].second.back() != "Angel Stadium")
        num1++;
    s.insert(v3[num1]);
    s.set_trip();
    string output = "Number of stadiums visited: " + to_string(s.get_route().size());
    ui->listWidget->addItem(QString::fromStdString(output));
    ui->listWidget->addItem(QString::fromStdString(""));
    ui->listWidget->addItem(QString::fromStdString("The order the stadiums are visited:"));
    v2 = s.get_route();
    for(unsigned long long i = 0;i < v2.size();i++){
        ui->listWidget->addItem(QString::fromStdString(v2[i]));
    }
    ui->listWidget->addItem(QString::fromStdString(""));
    ui->listWidget->addItem(QString::fromStdString("The total distance travelled: " + to_string(s.get_distance())));


}

/**********************************************************
 * void on_pushButton_3_clicked()
 *
 *  Push the button will show the trip to all the National
 *  league stadiums
 * --------------------------------------------------------
 *  Pre-conditions: None
 * -------------------------------------------------------
 *  Post-condition: Current window is close, main window
 *  shows.
**********************************************************/
// trips to all the National league stadiums
void trips::on_pushButton_3_clicked()
{
    ui->listWidget->clear();
    ui->listWidget->addItem(QString::fromStdString("Trip to all the National league stadiums"));
    ui->listWidget->addItem(QString::fromStdString("Starting from Dodger Stadium"));
    ui->listWidget->addItem(QString::fromStdString(""));

    shortestTrip s;
    string name = "Dodger Stadium";
    s.insert_city(name);
    while(s.get_noc() != NLS.size()){
        graph g;
        vector<pair<int,vector<string>>> vv;
        g.Dijstra(name,vv);
        for(unsigned long long i = 0;i < vv.size();i++){
            for(unsigned long long j = i + 1;j < vv.size();j++){
                if(vv[i].first > vv[j].first){
                    pair<int,vector<string>> p = vv[i];
                    vv[i] = vv[j];
                    vv[j] = p;
                }
            }
        }
        int num = 0;
        while(s.check(vv[num].second.back()) || !NLS.contains(vv[num].second.back())){
            num++;
        }
        s.insert(vv[num]);
        name = vv[num].second.back();
        s.insert_city(name);
    }

    graph g1;
    vector<pair<int,vector<string>>> v3;
    g1.Dijstra(s.get_cities().back(),v3);
    int num1 = 0;
    while(v3[num1].second.back() != "Dodger Stadium")
        num1++;
    s.insert(v3[num1]);
    s.set_trip();
    string output = "Number of stadiums visited: " + to_string(s.get_route().size());
    ui->listWidget->addItem(QString::fromStdString(output));
    ui->listWidget->addItem(QString::fromStdString(""));
    ui->listWidget->addItem(QString::fromStdString("The order the stadiums are visited:"));
    v4 = s.get_route();
    for(unsigned long long i = 0;i < v4.size();i++){
        ui->listWidget->addItem(QString::fromStdString(v4[i]));
    }
    ui->listWidget->addItem(QString::fromStdString(""));
    ui->listWidget->addItem(QString::fromStdString("The total distance travelled: " + to_string(s.get_distance())));

}

/**********************************************************
 * void on_pushButton_4_clicked()
 *
 *  Push the button will show the map to all the major
 *  league stadiums
 * --------------------------------------------------------
 *  Pre-conditions: None
 * -------------------------------------------------------
 *  Post-condition: Current window is close, main window
 *  shows.
**********************************************************/
// show trip to all major stadiums
void trips::on_pushButton_4_clicked()
{
    Map m;
    m.set_list(v1);
    m.setModal(true);
    m.exec();
}

/**********************************************************
 * void on_pushButton_5_clicked()
 *
 *  Push the button will show the map to all the American
 *  league stadiums
 * --------------------------------------------------------
 *  Pre-conditions: None
 * -------------------------------------------------------
 *  Post-condition: Current window is close, main window
 *  shows.
**********************************************************/
// show trip to all American stadiums
void trips::on_pushButton_5_clicked()
{
    Map m;
    m.set_list(v2);
    m.setModal(true);
    m.exec();
}

/**********************************************************
 * void on_pushButton_6_clicked()
 *
 *  Push the button will show the map to all the National
 *  league stadiums
 * --------------------------------------------------------
 *  Pre-conditions: None
 * -------------------------------------------------------
 *  Post-condition: Current window is close, main window
 *  shows.
**********************************************************/
// show trip to all national stadiums
void trips::on_pushButton_6_clicked()
{
    Map m;
    m.set_list(v4);
    m.setModal(true);
    m.exec();
}
