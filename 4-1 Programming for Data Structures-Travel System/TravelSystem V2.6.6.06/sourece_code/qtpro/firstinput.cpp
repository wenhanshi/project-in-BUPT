#include "firstinput.h"
#include "ui_firstinput.h"
#include "Graph.h"
#include "mainwindow.h"

extern int num_city;
extern Graph tg;
bool close_enable;

firstInput::firstInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::firstInput)
{
    ui->setupUi(this);
    ui->start_time->setRange(0, 23);
    for(int i = 0; i < num_city; i++)
    {
        QString  temp;
        temp = QString::fromStdString(tg._arrCity[i]);
        ui->start_city->addItem(temp);
    }
    Qt::WindowFlags flags = 0;
    setWindowFlags(windowFlags() &~ Qt::WindowCloseButtonHint);
}

firstInput::~firstInput()
{
    delete ui;
}

void firstInput::on_buttonBox_accepted()
{
    emit sendCity(ui->start_city->currentText());
    emit sendTime(ui->start_time->value());
    this->close();
}

void firstInput::on_buttonBox_rejected()
{
    qApp->exit(0);
    //QApplication::setQuitOnLastWindowClosed(true);
    this->close();
    close_enable = true;
    emit sendCloseMessage(close_enable);
}

