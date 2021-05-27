#include "checkdistance.h"
#include "ui_checkdistance.h"

checkdistance::checkdistance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkdistance)
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

checkdistance::~checkdistance()
{
    delete ui;
}

void checkdistance::on_pushButton_clicked()
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
        vector<string> v2;
        for(size_t j = 0;j < v.size();j++){
            for(int i =0;i < vec.size();i++){
                if(i == v.at(j)-1)
                    v2.push_back(vec.at(i));
            }
        }
        graph g;
        vector<pair<int,vector<string>>> vv;
        g.Dijstra(v2.at(0),vv);
        int num = 0;
        while(vv[num].second.back() != v2.at(1)){
            num++;
        }
        int dist = vv[num].first;
        string output = "The distance between " + v2.at(0) + " and " + v2.at(1);
        ui->listWidget_2->addItem(QString::fromStdString(output + " is: "));
        ui->listWidget_2->addItem(QString::fromStdString(to_string(dist)));
    }
}
