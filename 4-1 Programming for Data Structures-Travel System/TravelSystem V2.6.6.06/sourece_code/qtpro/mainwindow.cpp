#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Graph.h"
#include "input.h"
#include "newlabel.h"
#include "firstinput.h"
#include "search.h"
#include <QtCore>
#include <QPainter>
#include <QFile>
#include <QMessageBox>

#define TIMER 50

extern int Time;
extern int count_time;
extern int num_city;
extern int num_route;
extern Graph tg;
//extern bool close_enable;

extern void _simulation(Graph &);
extern QPointF pointf[15];
int flag = 0;
TST arr_tst[MAX_TST];
QPointF pointf[15] = {QPointF(734, 287), QPointF(750, 315), QPointF(842, 460), QPointF(815, 490),
                    QPointF(700, 402), QPointF(524, 490), QPointF(695, 535), QPointF(704, 624),
                    QPointF(493, 360), QPointF(300, 488), QPointF(870, 150), QPointF(645, 700),
                    QPointF(286, 199), QPointF(616, 425), QPointF(495, 600)};
QString sFilePath = "outfile.txt";
QString gFilePath = "graphInfo.txt";
QFile file(sFilePath);
QFile g_file(gFilePath);

void init_tst(void)
{
    __MUTI_TST_LOOP__
    {
        arr_tst[i].ID = i;
        arr_tst[i].e_now = 0;
        arr_tst[i].res.result_money = MAX_WEIGHT;
        arr_tst[i].res.result_time = MAX_WEIGHT;
        arr_tst[i].timepass = 0;
        arr_tst[i]._stml.size_arr = 0;
        arr_tst[i].moveflag = 0;
    }
}
void writeFile_graphInfo(void)
{
    QTextStream out(&g_file);
    out<<"ARR_EDGE:"<<endl;
    for(int e = 0 ; e <= num_route - 1 ; e++)
    {
        out<<e<<": "<<QString::fromStdString(tg._arrEdge[e].number)<<" from:"
           <<tg._arrEdge[e].derive_city<<" to:"<<tg._arrEdge[e].dest_city<<" time:"
          <<tg._arrEdge[e].derive_time<<" dur:"<<tg._arrEdge[e].dur<<" cost:"<<tg._arrEdge[e].cost<<endl;
    }
    out<<endl;
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1250, 750);
    ui->label_background->setFixedSize(1250, 750);
    connect(ui->inputButton,SIGNAL(clicked(bool)),this,SLOT(set_time_enable_input()));
    connect(ui->searchButton,SIGNAL(clicked(bool)),this,SLOT(set_time_enable_search()));
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text))
        QMessageBox::critical(NULL, "warning", "can't open the file!");
    if (!g_file.open(QIODevice::WriteOnly|QIODevice::Text))
        QMessageBox::critical(NULL, "warning", "can't open the g_file!");
    //else QTextStream out(&file);
    startTimer(10);
    writeFile_graphInfo();
}


MainWindow::~MainWindow()
{
    delete ui;
    file.close();
}
//paintEvent
void MainWindow::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    ui->label_background->setStyleSheet("background-image:url(:/new/prefix1/map.jpg)");
    ui->label_background->setFixedSize(1250, 750);
    ui->label_point->setStyleSheet("background-image:url(:/new/prefix1/dp0.png)");
    ui->label_point->setFixedSize(30, 45);
    ui->label_point_2->setStyleSheet("background-image:url(:/new/prefix1/dp1.png)");
    ui->label_point_2->setFixedSize(30, 45);
    ui->label_point_3->setStyleSheet("background-image:url(:/new/prefix1/dp2.png)");
    ui->label_point_3->setFixedSize(30, 45);
    ui->label_point_4->setStyleSheet("background-image:url(:/new/prefix1/dp3.png)");
    ui->label_point_4->setFixedSize(30, 45);
    ui->label_point_5->setStyleSheet("background-image:url(:/new/prefix1/dp4.png)");
    ui->label_point_5->setFixedSize(30, 45);
    //ui->le_ismove->setText(QString::number(arr_tst[0].state_n.ismove));
    //ui->le_city->setText(QString::fromStdString(tg._arrCity[arr_tst[0].state_n.city]));
    //ui->le_state_willdur->setText(QString::number(arr_tst[0].state_n.state_dur));
    //ui->le_dest_for_staten->setText(QString::fromStdString(tg._arrCity[arr_tst[0].state_n.dest]));
    ui->lineEdit_2->setText(QString::number(Time) + ":00");
    //show(pic,x,y);
    //show(backg,X,Y);
}

newLabel::newLabel(QWidget *parent) :
    QLabel(parent)
{}

void newLabel::paintEvent(QPaintEvent *event)
{
    int pos1, pos2, temp;

    QLabel::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    __MUTI_TST_LOOP__
    {
        switch(i)
        {
        case 0:
            painter.setPen(QPen(QColor(254, 67, 101), 3));
            break;
        case 1:
            painter.setPen(QPen(QColor(100, 255, 0), 3));
            break;
        case 2:
            painter.setPen(QPen(QColor(0, 0, 200), 3));
            break;
        case 3:
            painter.setPen(QPen(QColor(200, 200, 0), 3));
            break;
        case 4:
            painter.setPen(QPen(QColor(255, 0, 255), 3));
            break;
        }
        if(arr_tst[i]._stml.size_arr != 0)
        {
            if(arr_tst[i].moveflag == false)
            {
                QPointF temp_p = QPointF(arr_tst[i].sp.x,arr_tst[i].sp.y);
                painter.drawLine(pointf[ tg._arrEdge[arr_tst[i]._stml.arr_opEdge[arr_tst[i].e_now]].dest_city ] , temp_p);
                for(int e = arr_tst[i].e_now + 1; e <= arr_tst[i]._stml.size_arr-1; e++)
                {
                   temp = arr_tst[i]._stml.arr_opEdge[e];
                   pos1 = tg._arrEdge[temp].derive_city;
                   pos2 = tg._arrEdge[temp].dest_city;
                   painter.drawLine(pointf[pos1], pointf[pos2]);
                }
            }
            else
            {
                for(int e = 0; e <= arr_tst[i]._stml.size_arr-1; e++)
                {
                   temp = arr_tst[i]._stml.arr_opEdge[e];
                   pos1 = tg._arrEdge[temp].derive_city;
                   pos2 = tg._arrEdge[temp].dest_city;
                   painter.drawLine(pointf[pos1], pointf[pos2]);
                }
            }
         }
    }
}

void MainWindow::timerEvent(QTimerEvent*)
{
    if(time_enable == true)
    {
        //speed,locate
        if(count_time == TIMER)
        {
            Time = ( Time + 1 ) % 24;
            _simulation(tg);//timepass ++
            count_time = 0;
            writeFile();
        }
        count_time++;
        __MUTI_TST_LOOP__
        {
            if(arr_tst[i].state_n.ismove == 0)
            {
                getPosition(i);
            }
            getSpeed(i);
            arr_tst[i].sp.x = arr_tst[i].sp.x + arr_tst[i].sp.dx;
            arr_tst[i].sp.y = arr_tst[i].sp.y + arr_tst[i].sp.dy;
            movePic();
            this->update();
        }
        //cout<<"speed : x/y :"<<arr_tst[0].sp.dx<<"/"<<arr_tst[0].sp.dy<<endl;
    }
    else
    {
        if(flag == 0)//init start
        {
            firstInput *startdialog = new firstInput;
            connect(startdialog, SIGNAL(sendCity(QString)), this, SLOT(receiveCity(QString)));
            connect(startdialog, SIGNAL(sendTime(int)), this, SLOT(receiveTime(int)));
            connect(startdialog, SIGNAL(sendCloseMessage(bool)), this, SLOT(closeEnable(bool)));
            startdialog->exec();
            time_enable = true;
            delete startdialog;
            init_tst();
            movePic();
            this->update();
            flag = 1;
        }
        else if(flag == 2)
        {
            Search *searchdialog = new Search;
            searchdialog->setModal(true);
            searchdialog->exec();
            time_enable = true;
            delete searchdialog;
            flag = 1;
        }
        else
        {
            input *dialog = new input;
            dialog->setModal(true);
            dialog->exec();
            time_enable = true;
            dialog->getValue(tg);
            int id = dialog->getID();
            if(id != -1)
            {
                writeFile(id);
            }
            delete dialog;
            //writeFile();
        }

    }
}

void MainWindow::getPosition(int target)
{
    arr_tst[target].sp.x = pointf[arr_tst[target].state_n.city].x();
    arr_tst[target].sp.y = pointf[arr_tst[target].state_n.city].y();
}

void MainWindow::getSpeed(int target)
{
    qreal temp1 = 0, temp2 = 0;
    temp1 = pointf[arr_tst[target].state_n.dest].x();
    temp2 = pointf[arr_tst[target].state_n.dest].y();
    arr_tst[target].sp.dx = (temp1 - pointf[arr_tst[target].state_n.city].x()) / (arr_tst[target].state_n.state_dur * TIMER);
    arr_tst[target].sp.dy = (temp2 - pointf[arr_tst[target].state_n.city].y()) / (arr_tst[target].state_n.state_dur * TIMER);
}

void MainWindow::movePic()
{
    ui->label_point->setGeometry(arr_tst[0].sp.x, arr_tst[0].sp.y, 30, 30);
    ui->label_point_2->setGeometry(arr_tst[1].sp.x, arr_tst[1].sp.y, 30, 30);
    ui->label_point_3->setGeometry(arr_tst[2].sp.x, arr_tst[2].sp.y, 30, 30);
    ui->label_point_4->setGeometry(arr_tst[3].sp.x, arr_tst[3].sp.y, 30, 30);
    ui->label_point_5->setGeometry(arr_tst[4].sp.x, arr_tst[4].sp.y, 30, 30);
}

void MainWindow::receiveCity(QString data)
{
    int temp;
    //ui->lineEdit->setText(data);
    temp = compCity(tg, data);
    __MUTI_TST_LOOP__
    {
        arr_tst[i].state_n.city = temp;
        arr_tst[i].state_n.dest = temp;
        arr_tst[i].state_n.ismove = 0;
        arr_tst[i].state_n.state_dur = MAX_WEIGHT;
        arr_tst[i].sp.x = pointf[temp].x();
        arr_tst[i].sp.y = pointf[temp].y();
    }
}

int MainWindow::compCity(Graph& tg, QString city)   //城市匹配数组
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

void MainWindow::receiveTime(int data)
{
    QString text;
    Time = data;
    text = QString::number(data, 10) + ":00";
    ui->lineEdit_2->setText(text);
}

void MainWindow::set_time_enable_input()
{
    time_enable = false;
}

void MainWindow::set_time_enable_search()
{
    time_enable = false;
    flag = 2;
}

void MainWindow::writeFile()
{
    QTextStream out(&file);
    out << "---------TIME:"<< Time << ":00" <<"---------"<<endl;
    for(int id = 0; id < MAX_TST; id++)
    {
        out << "ID: " << id << ":" << endl;
        out << "Destination:" << getCity(tg, arr_tst[id].dest) << endl;
        out << "State_n: " << "city: " << getCity(tg, arr_tst[id].state_n.city) << " "
                          << "dest: " << getCity(tg, arr_tst[id].state_n.dest) << " "
                          << "ismove: " << QString::number(arr_tst[id].state_n.ismove, 10) << " "
                          << "dur: " << QString::number(arr_tst[id].state_n.state_dur, 10) << endl;
        out << "State_now(for debug): " << "citynow: " << getCity(tg, arr_tst[id].state_now.city_now) << " "
                             << "timenow: " << QString::number(arr_tst[id].state_now.time_now, 10) << endl;
        out << "Strategy: ";
        switch(arr_tst[id].strgy)
        {
        case 0:
            out << "minicost " << endl;
            break;
        case 1:
            out << "minitime" << endl;
        case 2:
            out << "minicost_lmt: " << QString::number(arr_tst[id].lmt, 10) << " " << endl;
        }
        out << "midcity: ";
        if(arr_tst[id].midflag == 0) out << "empty "<<endl;
        else
        {
            QString city = QString::number(arr_tst[id].size_mid, 10) + ":\n";
            for(int i = 0; i < arr_tst[id].size_mid; i++)
            {
                city = city + getCity(tg, arr_tst[id].mid[i]) + " ";
            }
            out << city << endl;
        }
        if(arr_tst[id].res.result_time == MAX_WEIGHT)
        {
            out << "TimeResult: MAX_WEIGHT" << endl;
        }
        else
        {
            out << "TimeResult: " << QString::number(arr_tst[id].res.result_time, 10) << endl;
        }
        if(arr_tst[id].res.result_time == MAX_WEIGHT)
        {
            out << "MoneyResult: MAX_WEIGHT" << endl;
        }
        else
        {
           out << "MoneyResult: " << QString::number(arr_tst[id].res.result_money, 10) << endl;
        }
        out << "Total edges: ";
        QString edge = QString::number(arr_tst[id]._stml.size_arr, 10) + "\n";
        for(int i = 0; i < arr_tst[id]._stml.size_arr - 1; i++)
        {
            edge = edge + QString::number(arr_tst[id]._stml.arr_opEdge[i], 10) + "->";
        }
        out << edge << "#" << endl << endl;
    }
}

QString MainWindow::getCity(Graph& tg , int city)
{
    return search.compCity(tg , city);
}

void MainWindow::closeEnable(bool close_enable)
{
    if (close_enable == true)
    {
       this->close();
    }
}

/*bool MainWindow::quitApp(QApplication* a)
{
    if(close_enable == false)
        a->quit();
}
*/
void MainWindow::receiveID(int data)
{
    writeFile(data);
}
void MainWindow::writeFile(int id)
{
    QTextStream out(&file);
    //for(int id = 0; id < MAX_TST; id++)
    //{
    out << "--------- INPUT INSTRUCTION ---------"<<endl;
    out << "INPUT MESSAGE:" << endl;
    out << "INPUT TIME IS: " << Time << ":00" << endl;
        out << "ID: " << id << ":" << endl;
        out << "Destination:" << getCity(tg, arr_tst[id].dest) << endl;
        out << "Strategy: ";
        switch(arr_tst[id].strgy)
        {
        case 0:
            out << "minicost " << endl;
            break;
        case 1:
            out << "minitime" << endl;
        case 2:
            out << "minicost_lmt: " << QString::number(arr_tst[id].lmt, 10) << " "<<endl;
        }
        out << "midcity: ";
        if(arr_tst[id].midflag == 0) out << "empty "<<endl;
        else
        {
            QString city = QString::number(arr_tst[id].size_mid, 10) + ":\n";
            for(int i = 0; i < arr_tst[id].size_mid; i++)
            {
                city = city + getCity(tg, arr_tst[id].mid[i]) + " ";
            }
            out << city << endl;
        }
   // }
}
