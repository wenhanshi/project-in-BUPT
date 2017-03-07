/********************************************************************************
** Form generated from reading UI file 'firstinput.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRSTINPUT_H
#define UI_FIRSTINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_firstInput
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_2;
    QSpinBox *start_time;
    QGroupBox *groupBox;
    QComboBox *start_city;
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *firstInput)
    {
        if (firstInput->objectName().isEmpty())
            firstInput->setObjectName(QStringLiteral("firstInput"));
        firstInput->resize(379, 173);
        horizontalLayoutWidget = new QWidget(firstInput);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 30, 351, 121));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(horizontalLayoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        start_time = new QSpinBox(groupBox_2);
        start_time->setObjectName(QStringLiteral("start_time"));
        start_time->setGeometry(QRect(20, 30, 91, 22));

        horizontalLayout_2->addWidget(groupBox_2);

        groupBox = new QGroupBox(horizontalLayoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        start_city = new QComboBox(groupBox);
        start_city->setObjectName(QStringLiteral("start_city"));
        start_city->setGeometry(QRect(30, 30, 111, 22));
        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setEnabled(true);
        buttonBox->setGeometry(QRect(10, 80, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(groupBox);

        label = new QLabel(firstInput);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 231, 16));

        retranslateUi(firstInput);

        QMetaObject::connectSlotsByName(firstInput);
    } // setupUi

    void retranslateUi(QDialog *firstInput)
    {
        firstInput->setWindowTitle(QApplication::translate("firstInput", "Dialog", 0));
        groupBox_2->setTitle(QApplication::translate("firstInput", "Start Time", 0));
        groupBox->setTitle(QApplication::translate("firstInput", "Start City", 0));
        label->setText(QApplication::translate("firstInput", "Please write down the city and time", 0));
    } // retranslateUi

};

namespace Ui {
    class firstInput: public Ui_firstInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRSTINPUT_H
