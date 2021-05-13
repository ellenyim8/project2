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
    ui->listWidget->addItem(QString::fromStdString("Trips to all the major league stadiums"));
    ui->listWidget->addItem(QString::fromStdString("Starting at Dodger Stadium:"));
    ui->listWidget->addItem(QString::fromStdString(""));


    pair<string,int>* pos = MLSP.get_positions();
    vector<vector<string>> list = MLSP.get_lists();
    string output;
    for(int i =0;i < MLSP.get_size();i++){
        output = "Dodger Stadium -> " + pos[i].first;
        ui->listWidget->addItem(QString::fromStdString(output));
        output = "Number of stadiums visited: " + to_string(list.at(i).size());
        ui->listWidget->addItem(QString::fromStdString(output));
        output = "Stadiums visited in order: ";
        int k;
        for(k = list.at(i).size()-1;k > 0;k--){
            output.append(list[i].at(k) + ", ");
        }
        output.append(list[i].at(k));
        ui->listWidget->addItem(QString::fromStdString(output));
        output = "Total distance travelled: " + to_string(pos[i].second);
        ui->listWidget->addItem(QString::fromStdString(output));
        ui->listWidget->addItem(QString::fromStdString(""));
    }
}


// trips to all the American league stadiums
void trips::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
    ui->listWidget->addItem(QString::fromStdString("Trips to all the American league stadiums"));
    ui->listWidget->addItem(QString::fromStdString("Starting at Dodger Stadium:"));
    ui->listWidget->addItem(QString::fromStdString(""));
    pair<string,int>* pos = MLSP.get_positions();
    vector<vector<string>> list = MLSP.get_lists();
    string output;
    for(int i =0;i < MLSP.get_size();i++){
        if(ALS.contains(pos[i].first)){
            output = "Dodger Stadium -> " + pos[i].first;
            ui->listWidget->addItem(QString::fromStdString(output));
            output = "Number of stadiums visited: " + to_string(list.at(i).size());
            ui->listWidget->addItem(QString::fromStdString(output));
            output = "Stadiums visited in order: ";
            int k;
            for(k = list.at(i).size()-1;k > 0;k--){
                output.append(list[i].at(k) + ", ");
            }
            output.append(list[i].at(k));
            ui->listWidget->addItem(QString::fromStdString(output));
            output = "Total distance travelled: " + to_string(pos[i].second);
            ui->listWidget->addItem(QString::fromStdString(output));
            ui->listWidget->addItem(QString::fromStdString(""));
        }
    }
}

// trips to all the National league stadiums
void trips::on_pushButton_3_clicked()
{
    ui->listWidget->clear();
    ui->listWidget->addItem(QString::fromStdString("Trips to all the National league stadiums"));
    ui->listWidget->addItem(QString::fromStdString("Starting at Dodger Stadium:"));
    ui->listWidget->addItem(QString::fromStdString(""));
    pair<string,int>* pos = MLSP.get_positions();
    vector<vector<string>> list = MLSP.get_lists();
    string output;
    for(int i =0;i < MLSP.get_size();i++){
        if(NLS.contains(pos[i].first)){
            output = "Dodger Stadium -> " + pos[i].first;
            ui->listWidget->addItem(QString::fromStdString(output));
            output = "Number of stadiums visited: " + to_string(list.at(i).size());
            ui->listWidget->addItem(QString::fromStdString(output));
            output = "Stadiums visited in order: ";
            int k;
            for(k = list.at(i).size()-1;k > 0;k--){
                output.append(list[i].at(k) + ", ");
            }
            output.append(list[i].at(k));
            ui->listWidget->addItem(QString::fromStdString(output));
            output = "Total distance travelled: " + to_string(pos[i].second);
            ui->listWidget->addItem(QString::fromStdString(output));
            ui->listWidget->addItem(QString::fromStdString(""));
        }
    }
}
