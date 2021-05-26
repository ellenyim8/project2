#include "trips.h"
#include "ui_trips.h"

trips::trips(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::trips)
{
    ui->setupUi(this);
}

trips::~trips()
{
    delete ui;
}

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
    vector<string> vvvv = s.get_route();
    for(unsigned long long i = 0;i < vvvv.size();i++){
        ui->listWidget->addItem(QString::fromStdString(vvvv[i]));
    }
    ui->listWidget->addItem(QString::fromStdString(""));
    ui->listWidget->addItem(QString::fromStdString("The total distance travelled: " + to_string(s.get_distance())));
}


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
    vector<string> vvvv = s.get_route();
    for(unsigned long long i = 0;i < vvvv.size();i++){
        ui->listWidget->addItem(QString::fromStdString(vvvv[i]));
    }
    ui->listWidget->addItem(QString::fromStdString(""));
    ui->listWidget->addItem(QString::fromStdString("The total distance travelled: " + to_string(s.get_distance())));


}

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
    vector<string> vvvv = s.get_route();
    for(unsigned long long i = 0;i < vvvv.size();i++){
        ui->listWidget->addItem(QString::fromStdString(vvvv[i]));
    }
    ui->listWidget->addItem(QString::fromStdString(""));
    ui->listWidget->addItem(QString::fromStdString("The total distance travelled: " + to_string(s.get_distance())));

}
