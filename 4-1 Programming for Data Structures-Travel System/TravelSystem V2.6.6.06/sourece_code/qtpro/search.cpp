#include "search.h"
#include "ui_search.h"
#include "struct&typ.h"
#include <QString>

extern TST arr_tst[MAX_TST];
extern int num_city;
extern int num_route;
extern Graph tg;
extern int Time;

Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
    ui->id->setRange(0, 4);
    connect(ui->id,SIGNAL(valueChanged(int)),this,SLOT(showInfo()));
}

Search::~Search()
{
    delete ui;
}

void Search::on_closeButton_clicked()
{
    this->close();
}


void Search::showInfo()
{
    int id = 0;
    id = ui->id->value();
    //ui->sn_dest->setText(compCity(tg, arr_tst[id].dest));
    ui->sn_city->setText(compCity(tg, arr_tst[id].state_n.city));
    ui->sn_next->setText(compCity(tg, arr_tst[id].state_n.dest));
    ui->sn_ismove->setText(QString::number(arr_tst[id].state_n.ismove, 10));
    ui->sn_dur->setText(QString::number(arr_tst[id].state_n.state_dur, 10));;

    //ui->snow_city->setText(compCity(tg, arr_tst[id].state_now.city_now));
    //ui->snow_time->setText(QString::number(arr_tst[id].state_now.time_now, 10));
    //ui->snow_edge->setText(QString::number(arr_tst[id]._stml.arr_opEdge[arr_tst[id].e_now]));

    ui->strgy_dest->setText(compCity(tg, arr_tst[id].dest));
    switch(arr_tst[id].strgy)
    {
    case 0:
        ui->strgy_strgy->setText("minicost");
        break;
    case 1:
        ui->strgy_strgy->setText("minitime");
        break;
    case 2:
        ui->strgy_strgy->setText("minicost_lmt: " + QString::number(arr_tst[id].lmt, 10));
        break; // 5.28 night debug
    }
    if(arr_tst[id].midflag == 0)
        ui->strgy_midcity->setText("EMPTY");
    else
    {
        QString city = QString::number(arr_tst[id].size_mid, 10) + ":\n";
        for(int i = 0; i < arr_tst[id].size_mid; i++)
        {
            city = city + compCity(tg, arr_tst[id].mid[i]) + " ";
        }
        ui->strgy_midcity->setText(city);
    }
    if(arr_tst[id].res.result_money == MAX_WEIGHT)
        ui->res_cost_money->setText("MAX_WEIGHT");
    else
        ui->res_cost_money->setText(QString::number(arr_tst[id].res.result_money, 10));
    if(arr_tst[id].res.result_time == MAX_WEIGHT)
        ui->res_cost_time->setText("MAX_WEIGHT");
    else
        ui->res_cost_time->setText(QString::number(arr_tst[id].res.result_time, 10));
    QString edge = QString::number(arr_tst[id]._stml.size_arr, 10) + ":\n";
    for(int i = 0; i < arr_tst[id]._stml.size_arr; i++)
    {
        edge = edge + "[ " + QString::number(arr_tst[id]._stml.arr_opEdge[i], 10) +
                      ", " + QString::fromStdString(tg._arrEdge[arr_tst[id]._stml.arr_opEdge[i]].number) + " ] -> ";
    }
    ui->res_plan->setText(edge + "#");
    ui->sn_transportation->setText( getTransportation(tg, arr_tst[id]._stml.arr_opEdge[arr_tst[id].e_now]));
}

QString Search::compCity(Graph &tg, int city)
{
    QString strcity = "";
    strcity = QString::fromStdString(tg._arrCity[city]);
    return strcity;
}

QString Search::getTransportation(Graph &tg, int number)
{
    QChar transportation;
    QString vehicle;
    transportation = tg._arrEdge[number].number[0];
    if(transportation == 'T' && ui->sn_ismove->text() == "1") return vehicle = "Train";
    else if(transportation == 'A' && ui->sn_ismove->text() == "1") return vehicle = "Airplane";
    else if(transportation == 'B' && ui->sn_ismove->text() == "1") return vehicle = "Bus";
    else return vehicle = "NONE";
}
