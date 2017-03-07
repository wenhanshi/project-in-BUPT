#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTimer>
#include <QLabel>
#include <QPainter>
#include <QPixmap>
#include <QPoint>
#include "struct&typ.h"
#include "Graph.h"
#include "search.h"
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool time_enable = false;
    //bool close_enable = false;
    void movePic();
    void getSpeed(int target);
    void getPosition(int target);
    int compCity(Graph& tg , QString city);
    void writeFile(void);
    void writeFile(int id);
    //bool quitApp(QApplication*);
    Search search;
    QString getCity(Graph& tg , int city);
    //qreal x;
    //qreal y;
    //qreal dx;
    //qreal dy;
protected:
    void paintEvent(QPaintEvent*);
    void timerEvent(QTimerEvent*);
public slots:
    void set_time_enable_input(void);   //open the input window
    void set_time_enable_search(void);  //open the search window
private slots:
    //void receiveData(QString data);
    //void receiveData1(QString data);
    void receiveCity(QString data);  //update current city from input
    void receiveTime(int data);  //update current time
    void closeEnable(bool close_enable);  //judge to close the mainwindow or not
    void receiveID(int data);
    //void on_inputButton_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
