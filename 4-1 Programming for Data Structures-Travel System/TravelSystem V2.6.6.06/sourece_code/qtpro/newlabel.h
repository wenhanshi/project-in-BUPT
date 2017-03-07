#ifndef NEWLABEL_H
#define NEWLABEL_H

#include <QMainWindow>
#include <QLabel>
#include <QPainter>
#include <QPixmap>

class newLabel: public QLabel
{
    Q_OBJECT
public:
    newLabel(QWidget * parent = 0);
protected:
    void paintEvent(QPaintEvent*);
//private:
  //  Ui::MainWindow *ui;

};


#endif // NEWLABEL_H
