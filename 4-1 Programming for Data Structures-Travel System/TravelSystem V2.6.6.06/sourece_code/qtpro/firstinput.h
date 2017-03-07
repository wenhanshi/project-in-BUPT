#ifndef FIRSTINPUT_H
#define FIRSTINPUT_H

#include <QDialog>

namespace Ui {
class firstInput;
}

class firstInput : public QDialog
{
    Q_OBJECT

public:
    explicit firstInput(QWidget *parent = 0);
    ~firstInput();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::firstInput *ui;
signals:
    void sendCity(QString);       //send departure city to mainwindow
    void sendTime(int);           //send start time to mainwindow
    void sendCloseMessage(bool);  //jude whether to terminate the application or not
};

#endif // FIRSTINPUT_H
