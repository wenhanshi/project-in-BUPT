/********************************************************************************
** Form generated from reading UI file 'search.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Search
{
public:
    QGroupBox *groupBox;
    QSpinBox *id;
    QGroupBox *groupBox_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *sn_city;
    QLabel *label_2;
    QLineEdit *sn_next;
    QLabel *label_3;
    QLineEdit *sn_dur;
    QLabel *label_4;
    QLineEdit *sn_ismove;
    QLabel *label_12;
    QLineEdit *sn_transportation;
    QGroupBox *groupBox_4;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QLineEdit *strgy_strgy;
    QLabel *label_8;
    QTextBrowser *strgy_midcity;
    QLabel *label_9;
    QLineEdit *strgy_dest;
    QGroupBox *groupBox_5;
    QFrame *frame_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_10;
    QLineEdit *res_cost_money;
    QLabel *label_5;
    QLineEdit *res_cost_time;
    QPushButton *closeButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_11;
    QTextBrowser *res_plan;

    void setupUi(QDialog *Search)
    {
        if (Search->objectName().isEmpty())
            Search->setObjectName(QStringLiteral("Search"));
        Search->resize(733, 483);
        groupBox = new QGroupBox(Search);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 10, 201, 51));
        id = new QSpinBox(groupBox);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(30, 20, 141, 22));
        groupBox_2 = new QGroupBox(Search);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(250, 10, 201, 301));
        frame = new QFrame(groupBox_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 10, 161, 281));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        sn_city = new QLineEdit(frame);
        sn_city->setObjectName(QStringLiteral("sn_city"));

        verticalLayout->addWidget(sn_city);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        sn_next = new QLineEdit(frame);
        sn_next->setObjectName(QStringLiteral("sn_next"));

        verticalLayout->addWidget(sn_next);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        sn_dur = new QLineEdit(frame);
        sn_dur->setObjectName(QStringLiteral("sn_dur"));

        verticalLayout->addWidget(sn_dur);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        sn_ismove = new QLineEdit(frame);
        sn_ismove->setObjectName(QStringLiteral("sn_ismove"));

        verticalLayout->addWidget(sn_ismove);

        label_12 = new QLabel(frame);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout->addWidget(label_12);

        sn_transportation = new QLineEdit(frame);
        sn_transportation->setObjectName(QStringLiteral("sn_transportation"));

        verticalLayout->addWidget(sn_transportation);

        groupBox_4 = new QGroupBox(Search);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(30, 70, 201, 371));
        frame_3 = new QFrame(groupBox_4);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(20, 30, 161, 311));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_3->addWidget(label_7);

        strgy_strgy = new QLineEdit(frame_3);
        strgy_strgy->setObjectName(QStringLiteral("strgy_strgy"));

        verticalLayout_3->addWidget(strgy_strgy);

        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_3->addWidget(label_8);

        strgy_midcity = new QTextBrowser(frame_3);
        strgy_midcity->setObjectName(QStringLiteral("strgy_midcity"));

        verticalLayout_3->addWidget(strgy_midcity);

        label_9 = new QLabel(frame_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_3->addWidget(label_9);

        strgy_dest = new QLineEdit(frame_3);
        strgy_dest->setObjectName(QStringLiteral("strgy_dest"));

        verticalLayout_3->addWidget(strgy_dest);

        groupBox_5 = new QGroupBox(Search);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(250, 310, 201, 131));
        frame_4 = new QFrame(groupBox_5);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(30, 20, 141, 101));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame_4);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 111, 95));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_2->addWidget(label_10);

        res_cost_money = new QLineEdit(layoutWidget);
        res_cost_money->setObjectName(QStringLiteral("res_cost_money"));

        verticalLayout_2->addWidget(res_cost_money);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        res_cost_time = new QLineEdit(layoutWidget);
        res_cost_time->setObjectName(QStringLiteral("res_cost_time"));

        verticalLayout_2->addWidget(res_cost_time);

        closeButton = new QPushButton(Search);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(590, 400, 91, 31));
        layoutWidget1 = new QWidget(Search);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(470, 20, 211, 361));
        verticalLayout_5 = new QVBoxLayout(layoutWidget1);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_5->addWidget(label_11);

        res_plan = new QTextBrowser(layoutWidget1);
        res_plan->setObjectName(QStringLiteral("res_plan"));

        verticalLayout_5->addWidget(res_plan);

        layoutWidget->raise();
        groupBox->raise();
        groupBox_2->raise();
        groupBox_4->raise();
        groupBox_5->raise();
        closeButton->raise();

        retranslateUi(Search);

        QMetaObject::connectSlotsByName(Search);
    } // setupUi

    void retranslateUi(QDialog *Search)
    {
        Search->setWindowTitle(QApplication::translate("Search", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("Search", "ID", 0));
        groupBox_2->setTitle(QApplication::translate("Search", "STATE_N", 0));
        label->setText(QApplication::translate("Search", "Departure city", 0));
        label_2->setText(QApplication::translate("Search", "Next Stop", 0));
        label_3->setText(QApplication::translate("Search", "Duration", 0));
        label_4->setText(QApplication::translate("Search", "Is Move", 0));
        label_12->setText(QApplication::translate("Search", "Transportation", 0));
        groupBox_4->setTitle(QApplication::translate("Search", "STRATEGY", 0));
        label_7->setText(QApplication::translate("Search", "Strategy", 0));
        label_8->setText(QApplication::translate("Search", "Midcity", 0));
        label_9->setText(QApplication::translate("Search", "Destination", 0));
        groupBox_5->setTitle(QApplication::translate("Search", "RESULT", 0));
        label_10->setText(QApplication::translate("Search", "Money Cost", 0));
        label_5->setText(QApplication::translate("Search", "Time Cost", 0));
        closeButton->setText(QApplication::translate("Search", "Close", 0));
        label_11->setText(QApplication::translate("Search", "Travel Plan", 0));
    } // retranslateUi

};

namespace Ui {
    class Search: public Ui_Search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
