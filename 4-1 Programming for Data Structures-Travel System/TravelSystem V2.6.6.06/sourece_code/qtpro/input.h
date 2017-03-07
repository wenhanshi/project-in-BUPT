#ifndef INPUT_H
#define INPUT_H


#include <QDialog>
#include <QButtonGroup>
#include "Graph.h"
#include "struct&typ.h"

namespace Ui {
class input;
}

class input : public QDialog
{
    Q_OBJECT

public:
    explicit input(QWidget *parent = 0);
    void getValue(Graph& tg);   //get information from input dialog
    int compCity(Graph& tg , QString city);  //match the city name with the city number
    int getID();
    ~input();
    bool signal_disable = false;  //if we press cancel then we'd not send the update message
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void openCB(void);       //decided how many combobox to open

private:
    Ui::input *ui;
signals:
    //void sendData(QString);
    //void sendData1(QString);
};

#endif // INPUT_H
