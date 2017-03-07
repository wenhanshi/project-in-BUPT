#include "input.h"
#include "struct&typ.h"
#include "Graph.h"
#include "ui_input.h"
#include <QString>
#include <QMessageBox>
#include <QButtonGroup>
#include <QSpinBox>
#include <QComboBox>
#include<iostream>
#include<cstring>
#include<queue>
#include<cstdlib>

using namespace std;
void printSTML(STML &r_stml);

extern int Time;
//extern n_state;
extern int num_city;
extern int num_route;
extern Graph tg;
extern TST arr_tst[MAX_TST];

input::input(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::input)
{
    ui->setupUi(this);
    ui->spinBox->setRange(1,5);
    ui->spinBox_lmt->setRange(1,99);
    for(int i = 0; i < num_city; i++)
    {
        QString  temp;
        temp = QString::fromStdString(tg._arrCity[i]);
        ui->comboBox_des->addItem(temp);
        ui->comboBox_mid_1->addItem(temp);
        ui->comboBox_mid_2->addItem(temp);
        ui->comboBox_mid_3->addItem(temp);
        ui->comboBox_mid_4->addItem(temp);
        ui->comboBox_mid_5->addItem(temp);
    }
    ui->comboBox_mid_1->setCurrentText("BEIJING");
    ui->comboBox_mid_2->setCurrentText("TIANJIN");
    ui->comboBox_mid_3->setCurrentText("SHANGHAI");
    ui->comboBox_mid_4->setCurrentText("GUANGZHOU");
    ui->comboBox_mid_5->setCurrentText("HAIKOU");
    connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(openCB()));
    Qt::WindowFlags flags = 0;
    setWindowFlags(windowFlags() &~ Qt::WindowCloseButtonHint);
}
void input:: openCB(void)//decide how many cbs need to be opened
{
    int numcb = ui->spinBox->value();
    switch(numcb)
    {
    case 1:
        ui->comboBox_mid_1->setEnabled(true);
        ui->comboBox_mid_2->setEnabled(false);
        ui->comboBox_mid_3->setEnabled(false);
        ui->comboBox_mid_4->setEnabled(false);
        ui->comboBox_mid_5->setEnabled(false);
        break;
    case 2:
        ui->comboBox_mid_1->setEnabled(true);
        ui->comboBox_mid_2->setEnabled(true);
        ui->comboBox_mid_3->setEnabled(false);
        ui->comboBox_mid_4->setEnabled(false);
        ui->comboBox_mid_5->setEnabled(false);
        break;
    case 3:
        ui->comboBox_mid_1->setEnabled(true);
        ui->comboBox_mid_2->setEnabled(true);
        ui->comboBox_mid_3->setEnabled(true);
        ui->comboBox_mid_4->setEnabled(false);
        ui->comboBox_mid_5->setEnabled(false);
        break;
    case 4:
        ui->comboBox_mid_1->setEnabled(true);
        ui->comboBox_mid_2->setEnabled(true);
        ui->comboBox_mid_3->setEnabled(true);
        ui->comboBox_mid_4->setEnabled(true);
        ui->comboBox_mid_5->setEnabled(false);
        break;
    case 5:
        ui->comboBox_mid_1->setEnabled(true);
        ui->comboBox_mid_2->setEnabled(true);
        ui->comboBox_mid_3->setEnabled(true);
        ui->comboBox_mid_4->setEnabled(true);
        ui->comboBox_mid_5->setEnabled(true);
        break;
    }
}

input::~input()
{
    delete ui;
}

void input::on_buttonBox_accepted()
{
    signal_disable = false;
    this->close();
}

void input::on_buttonBox_rejected()
{
    signal_disable = true;
    this->close();
}

int input::compCity(Graph& tg, QString city)   //城市匹配数组
{
    string strcity = "";
    strcity = city.toStdString();
    for(int i = 0; i < num_city; i++)
    {
        if(strcity == tg._arrCity[i])
        {
            return i;
        }
    }
    return -1;
}

void init_state(int target,Graph &travel_graph)
{
    int diff;
    if(arr_tst[target].state_n.ismove == false)
    {
       if(arr_tst[target]._stml.size_arr == 0)
       {
           arr_tst[target].state_n.state_dur = MAX_WEIGHT;
           arr_tst[target].state_n.dest =  arr_tst[target].state_n.city;
           arr_tst[target].state_n.ismove = false;
       }
       else
       {
           diff =( (travel_graph._arrEdge[arr_tst[target]._stml.arr_opEdge[0]].derive_time - arr_tst[target].state_now.time_now)+72 )%24;
           arr_tst[target].state_n.city = arr_tst[target].state_now.city_now;
           if(diff == 0)//next he will move right now
           {
               arr_tst[target].state_n.ismove = true;
               arr_tst[target].state_n.dest = travel_graph._arrEdge[arr_tst[target]._stml.arr_opEdge[0]].dest_city; // debug on 5.28
               arr_tst[target].state_n.state_dur = travel_graph._arrEdge[arr_tst[target]._stml.arr_opEdge[0]].dur;
               //cout<<"debug here !!!!"<<endl;
           }
           else//he still need wait
           {
               arr_tst[target].state_n.ismove = false;
               arr_tst[target].state_n.state_dur = diff ;
           }
           arr_tst[target].timepass = 0;
       }
    }
    else
    {
        cout<<"open move flag!!!!!"<<endl;
        arr_tst[target].moveflag = 1;
    }
    arr_tst[target].e_now = 0;
}

int input::getID()
{
    if(signal_disable == false)
    {
        return ui->spinBox_settst->value();
    }
    else
        return -1;
}

void input::getValue(Graph& tg)
{
    QString temp;
    if(signal_disable == false)
    {
        int target = ui->spinBox_settst->value();

        if(ui->radioButton_cost->isChecked()) arr_tst[target].strgy = 0;
        else if(ui->radioButton_time->isChecked()) arr_tst[target].strgy = 1;
        else if(ui->radioButton_both->isChecked())
        {
            arr_tst[target].strgy = 2;
            arr_tst[target].lmt = ui->spinBox_lmt->value();
            cout << "lmt:" << arr_tst[target].lmt << endl;
        }
        cout << "strgy:" << arr_tst[target].strgy << endl;
        temp = ui->comboBox_des->currentText();
        arr_tst[target].dest = this->compCity(tg, temp);
        cout << "dest:" << arr_tst[target].dest << endl;
        arr_tst[target].midflag = 0; // 5.29 debug
        if(ui->radioButton_yes->isChecked())
        {
            arr_tst[target].midflag = 1;
            cout << "midflag:" << arr_tst[target].midflag << endl;
            arr_tst[target].size_mid = ui->spinBox->value();
            cout << "size_mid:" << arr_tst[target].size_mid << endl;
            switch(arr_tst[target].size_mid)
            {
            case 1:

                temp = ui->comboBox_mid_1->currentText();
                arr_tst[target].mid[0] = this->compCity(tg, temp);
                //cout << "mid:" << arr_tst[target].mid[0] << endl;
                break;
            case 2:

                temp = ui->comboBox_mid_1->currentText();
                arr_tst[target].mid[0] = this->compCity(tg, temp);
                temp = ui->comboBox_mid_2->currentText();
                arr_tst[target].mid[1] = this->compCity(tg, temp);
                //cout << "mid:" << arr_tst[target].mid[0] << " " <<arr_tst[target].mid[1] << endl;
                break;
            case 3:

                temp = ui->comboBox_mid_1->currentText();
                arr_tst[target].mid[0] = this->compCity(tg, temp);
                temp = ui->comboBox_mid_2->currentText();
                arr_tst[target].mid[1] = this->compCity(tg, temp);
                temp = ui->comboBox_mid_3->currentText();
                arr_tst[target].mid[2] = this->compCity(tg, temp);
                //cout << "mid:" << mid[0] << " " << mid[1] << " " << mid[2] << endl;
                break;
            case 4:

                temp = ui->comboBox_mid_1->currentText();
                arr_tst[target].mid[0] = this->compCity(tg, temp);
                temp = ui->comboBox_mid_2->currentText();
                arr_tst[target].mid[1] = this->compCity(tg, temp);
                temp = ui->comboBox_mid_3->currentText();
                arr_tst[target].mid[2] = this->compCity(tg, temp);
                temp = ui->comboBox_mid_4->currentText();
                arr_tst[target].mid[3] = this->compCity(tg, temp);
                //cout << "mid:" << mid[0] << " " << mid[1] << " " << mid[2] << " " << mid[3] << endl;
                break;
            case 5:

                temp = ui->comboBox_mid_1->currentText();
                arr_tst[target].mid[0] = this->compCity(tg, temp);
                temp = ui->comboBox_mid_2->currentText();
                arr_tst[target].mid[1] = this->compCity(tg, temp);
                temp = ui->comboBox_mid_3->currentText();
                arr_tst[target].mid[2] = this->compCity(tg, temp);
                temp = ui->comboBox_mid_4->currentText();
                arr_tst[target].mid[3] = this->compCity(tg, temp);
                temp = ui->comboBox_mid_5->currentText();
                arr_tst[target].mid[4] = this->compCity(tg, temp);
               // cout << "mid:" << mid[0] << " " << mid[1] << " " << mid[2] << " " << mid[3] << " "  << mid[4] << endl;
                break;
             } // end switch
         }
    //get state_now from state_n
        if(arr_tst[target].state_n.ismove == false)
        {
            arr_tst[target].state_now.time_now = Time;
            arr_tst[target].state_now.city_now = arr_tst[target].state_n.city;
        }
        else if (arr_tst[target].moveflag == 0)
        {
            arr_tst[target].state_now.time_now = ( tg._arrEdge[arr_tst[target]._stml.arr_opEdge[arr_tst[target].e_now]].derive_time +
                                   tg._arrEdge[arr_tst[target]._stml.arr_opEdge[arr_tst[target].e_now]].dur)%24;
            arr_tst[target].state_now.city_now = tg._arrEdge[arr_tst[target]._stml.arr_opEdge[arr_tst[target].e_now]].dest_city;
        }
        else
        {
            arr_tst[target].state_now.time_now = ( Time + arr_tst[target].state_n.state_dur - arr_tst[target].timepass ) % 24;
            arr_tst[target].state_now.city_now = arr_tst[target].state_n.dest;
        }

        switch((STRATEGY)arr_tst[target].strgy) // the process of alogrim
        {
        case MINICOST :
            if(!arr_tst[target].midflag) arr_tst[target].res.result_money = tg.DIJ_MiniCost(arr_tst[target].state_now,arr_tst[target].dest,arr_tst[target]._stml);
            else         arr_tst[target].res.result_money = tg.DIJ_MiniCost(arr_tst[target].state_now,arr_tst[target].dest,arr_tst[target].mid,arr_tst[target].size_mid,arr_tst[target]._stml);
            cout<<"MINICOST STML :"<<endl;
            printSTML(arr_tst[target]._stml);
            cout<<"MINICOST = "<<arr_tst[target].res.result_money<<endl;
            if(arr_tst[target].res.result_money == 0)
                arr_tst[target].res.result_time = 0;
            else
                arr_tst[target].res.result_time = tg.getTimeUse(arr_tst[target]._stml,arr_tst[target].state_now);
            break;
        case MINITIME :
            if(!arr_tst[target].midflag) arr_tst[target].res.result_time = tg.DIJ_MiniTime(arr_tst[target].state_now,arr_tst[target].dest,arr_tst[target]._stml);
            else         arr_tst[target].res.result_time = tg.DIJ_MiniTime(arr_tst[target].state_now,arr_tst[target].dest,arr_tst[target].mid,arr_tst[target].size_mid,arr_tst[target]._stml);
            cout<<"MINITIME STML :"<<endl;
            printSTML(arr_tst[target]._stml);
            cout<<"MINITIME = "<<arr_tst[target].res.result_time<<endl;
            if(arr_tst[target].res.result_time == 0)
                arr_tst[target].res.result_money = 0;
            else
                arr_tst[target].res.result_money = tg.getMoneyUse(arr_tst[target]._stml);
            break;
        case MINICOST_LIMITIME :
            if(!arr_tst[target].midflag) arr_tst[target].res.result_money = tg.MiniCost_TimeLimt(arr_tst[target].state_now,arr_tst[target].dest,arr_tst[target].lmt,arr_tst[target]._stml);
            else         arr_tst[target].res.result_money = tg.MiniCost_TimeLimt(arr_tst[target].state_now,arr_tst[target].dest,arr_tst[target].lmt,arr_tst[target].mid,arr_tst[target].size_mid,arr_tst[target]._stml);
            cout<<"MINICOST_LIMITIME STML :"<<endl;
            printSTML(arr_tst[target]._stml);
            cout<<"MINICOST_LIMITIME = "<<arr_tst[target].res.result_money<<endl;
            if(arr_tst[target].res.result_money == 0)
                arr_tst[target].res.result_time = 0;
            else
                arr_tst[target].res.result_time = tg.getTimeUse(arr_tst[target]._stml,arr_tst[target].state_now);
            break;
        }
        init_state(target,tg);//change state_n form the result of funcs
    }
}
