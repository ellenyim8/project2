#include "dreamvacation.h"
#include "ui_dreamvacation.h"

dreamvacation::dreamvacation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dreamvacation)
{
    ui->setupUi(this);
    ui->listWidget->addItem(QString::fromStdString("All Major Stadiums: "));
    ui->listWidget->addItem(QString::fromStdString(""));

    Heap<Stadiums,StringMin> h = MLS2;
    string name;
    for(int i = 0;i < MLS2.size();i++){
        name = to_string(i+1) + ": "+ h.peek().Stadium_Name;
        vec.push_back(h.peek().Stadium_Name);
        ui->listWidget->addItem(QString::fromStdString(name));
        h.remove();
    }
}

dreamvacation::~dreamvacation()
{
    delete ui;
}

void dreamvacation::on_pushButton_clicked()
{
    ui->listWidget_2->clear();
    QString q = ui->lineEdit->text();
    string input = q.toStdString();
    vector<int> v;
    int num;
    stringstream ss(input);
    while(ss >> num){
       v.push_back(num);
    }
    int checknum = 0;
    for(size_t i =0;i < v.size();i++){
        if(v.at(i) > MLS2.size())
            checknum = 1;
    }
    if(checknum == 1)
        ui->listWidget_2->addItem(QString::fromStdString("Can not enter a number larger than "
        + to_string(MLS2.size())));
    else{

        shortestTrip s;
        vector<string> v2;
        for(size_t j = 0;j < v.size();j++){
            for(int i =0;i <= vec.size();i++){
                if(i == v.at(j))
                    v2.push_back(vec.at(i-1));
            }
        }

        int count = 0;
        string name = v2.at(count);
        ui->listWidget_2->addItem(QString::fromStdString("Starting from " + name));
        ui->listWidget_2->addItem(QString::fromStdString(""));
        s.insert_city(v2.at(count));
        while(s.get_noc() != v2.size()){
            count++;
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
            while(vv[num].second.back() != v2.at(count)){
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
        while(v3[num1].second.back() != v2.at(0))
            num1++;
        s.insert(v3[num1]);
        s.set_trip();
        string output = "Number of stadiums visited: " + to_string(s.get_route().size());
        ui->listWidget_2->addItem(QString::fromStdString(output));
        ui->listWidget_2->addItem(QString::fromStdString(""));
        ui->listWidget_2->addItem(QString::fromStdString("The order the stadiums are visited:"));
        v1 = s.get_route();
        for(unsigned long long i = 0;i < v1.size();i++){
            ui->listWidget_2->addItem(QString::fromStdString(v1[i]));
        }
        ui->listWidget_2->addItem(QString::fromStdString(""));
        ui->listWidget_2->addItem(QString::fromStdString("The total distance travelled: " + to_string(s.get_distance())));
    }
}

void dreamvacation::on_pushButton_2_clicked()
{
    Map m;
    m.set_list(v1);
    m.setModal(true);
    m.exec();
}
