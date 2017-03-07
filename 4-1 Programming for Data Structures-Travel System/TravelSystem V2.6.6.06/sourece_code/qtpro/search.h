#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>
#include <QString>
#include "Graph.h"
#include "struct&typ.h"

namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = 0);
    QString compCity(Graph& tg , int city);   //match the city number with the city name
    QString getTransportation(Graph& tg, int number);  //show which transport the tourist are taking
    ~Search();

private slots:
    void on_closeButton_clicked();
    void showInfo(void);

private:
    Ui::Search *ui;
};

#endif // SEARCH_H
