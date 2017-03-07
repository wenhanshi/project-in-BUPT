#include "mainwindow.h"
#include <QApplication>
#include <QPainter>
#include <QSplashScreen>
#include <QPixmap>
#include <QElapsedTimer>
#include <QPropertyAnimation>
#include <QPushButton>
#include "input.h"
#include "firstinput.h"
#include "Graph.h"
#include "struct&typ.h"

//#define LAOSHI_FILE_SYSTEM "/test/Text.txt";
QString fn = ":/new/prefix1/TIME_TABLE.txt";
Graph tg(fn);

int Time; // the timer of system
int count_time = 0; // synchron timer
//bool close_enable = false;

int main(int argc, char *argv[])
{
    tg.printEdge();
    QApplication a(argc, argv);
    //a.addLibraryPath("./plugins");

    QPixmap pixmap(":/new/prefix1/setup interface(poster).jpg");
    QSplashScreen *splash = new QSplashScreen(pixmap);
    splash->show();
    QPropertyAnimation *animation = new QPropertyAnimation(splash, "windowOpacity");
    animation->setDuration(3000);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();

    int delaytime = 5;
    QElapsedTimer timer;
    timer.start();
    while(timer.elapsed() < (delaytime * 1000))
    {
        a.processEvents();
    }
    MainWindow w;
    w.show();
    splash->finish(&w);
    delete splash;
    //w.quitApp(&a);
    return a.exec();
}

