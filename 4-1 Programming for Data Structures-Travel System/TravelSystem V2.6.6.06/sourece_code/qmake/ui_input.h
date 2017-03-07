/********************************************************************************
** Form generated from reading UI file 'input.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUT_H
#define UI_INPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_input
{
public:
    QFrame *frame_2;
    QLabel *label;
    QSpinBox *spinBox;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QComboBox *comboBox_mid_1;
    QLabel *label_4;
    QComboBox *comboBox_mid_2;
    QLabel *label_8;
    QComboBox *comboBox_mid_3;
    QLabel *label_7;
    QComboBox *comboBox_mid_4;
    QLabel *label_6;
    QComboBox *comboBox_mid_5;
    QDialogButtonBox *buttonBox;
    QFrame *frame_4;
    QLabel *label_2;
    QSpinBox *spinBox_settst;
    QGroupBox *groupBox_3;
    QComboBox *comboBox_des;
    QGroupBox *groupBox_4;
    QSpinBox *spinBox_lmt;
    QGroupBox *groupBox;
    QRadioButton *radioButton_yes;
    QRadioButton *radioButton_no;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_cost;
    QRadioButton *radioButton_time;
    QRadioButton *radioButton_both;

    void setupUi(QDialog *input)
    {
        if (input->objectName().isEmpty())
            input->setObjectName(QStringLiteral("input"));
        input->setEnabled(true);
        input->resize(451, 437);
        frame_2 = new QFrame(input);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(230, 60, 181, 61));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(12, 12, 80, 16));
        spinBox = new QSpinBox(frame_2);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setEnabled(false);
        spinBox->setGeometry(QRect(12, 34, 141, 20));
        spinBox->setMinimumSize(QSize(141, 20));
        frame_3 = new QFrame(input);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(230, 130, 181, 271));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        comboBox_mid_1 = new QComboBox(frame_3);
        comboBox_mid_1->setObjectName(QStringLiteral("comboBox_mid_1"));
        comboBox_mid_1->setEnabled(false);

        verticalLayout_2->addWidget(comboBox_mid_1);

        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        comboBox_mid_2 = new QComboBox(frame_3);
        comboBox_mid_2->setObjectName(QStringLiteral("comboBox_mid_2"));
        comboBox_mid_2->setEnabled(false);

        verticalLayout_2->addWidget(comboBox_mid_2);

        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_2->addWidget(label_8);

        comboBox_mid_3 = new QComboBox(frame_3);
        comboBox_mid_3->setObjectName(QStringLiteral("comboBox_mid_3"));
        comboBox_mid_3->setEnabled(false);

        verticalLayout_2->addWidget(comboBox_mid_3);

        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_2->addWidget(label_7);

        comboBox_mid_4 = new QComboBox(frame_3);
        comboBox_mid_4->setObjectName(QStringLiteral("comboBox_mid_4"));
        comboBox_mid_4->setEnabled(false);

        verticalLayout_2->addWidget(comboBox_mid_4);

        label_6 = new QLabel(frame_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_2->addWidget(label_6);

        comboBox_mid_5 = new QComboBox(frame_3);
        comboBox_mid_5->setObjectName(QStringLiteral("comboBox_mid_5"));
        comboBox_mid_5->setEnabled(false);

        verticalLayout_2->addWidget(comboBox_mid_5);

        buttonBox = new QDialogButtonBox(input);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(270, 410, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        frame_4 = new QFrame(input);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(30, 10, 181, 40));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(12, 12, 80, 16));
        spinBox_settst = new QSpinBox(frame_4);
        spinBox_settst->setObjectName(QStringLiteral("spinBox_settst"));
        spinBox_settst->setGeometry(QRect(100, 10, 81, 21));
        spinBox_settst->setMaximum(4);
        groupBox_3 = new QGroupBox(input);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(30, 60, 181, 76));
        comboBox_des = new QComboBox(groupBox_3);
        comboBox_des->setObjectName(QStringLiteral("comboBox_des"));
        comboBox_des->setGeometry(QRect(12, 27, 131, 21));
        groupBox_4 = new QGroupBox(input);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(30, 340, 181, 61));
        spinBox_lmt = new QSpinBox(groupBox_4);
        spinBox_lmt->setObjectName(QStringLiteral("spinBox_lmt"));
        spinBox_lmt->setEnabled(false);
        spinBox_lmt->setGeometry(QRect(0, 30, 161, 20));
        groupBox = new QGroupBox(input);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 140, 181, 81));
        radioButton_yes = new QRadioButton(groupBox);
        radioButton_yes->setObjectName(QStringLiteral("radioButton_yes"));
        radioButton_yes->setGeometry(QRect(12, 27, 51, 19));
        radioButton_no = new QRadioButton(groupBox);
        radioButton_no->setObjectName(QStringLiteral("radioButton_no"));
        radioButton_no->setGeometry(QRect(12, 53, 43, 19));
        radioButton_no->setChecked(true);
        groupBox_2 = new QGroupBox(input);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 220, 181, 121));
        radioButton_cost = new QRadioButton(groupBox_2);
        radioButton_cost->setObjectName(QStringLiteral("radioButton_cost"));
        radioButton_cost->setGeometry(QRect(12, 27, 91, 19));
        radioButton_cost->setChecked(true);
        radioButton_time = new QRadioButton(groupBox_2);
        radioButton_time->setObjectName(QStringLiteral("radioButton_time"));
        radioButton_time->setGeometry(QRect(12, 53, 91, 19));
        radioButton_both = new QRadioButton(groupBox_2);
        radioButton_both->setObjectName(QStringLiteral("radioButton_both"));
        radioButton_both->setGeometry(QRect(12, 79, 123, 19));

        retranslateUi(input);
        QObject::connect(radioButton_yes, SIGNAL(toggled(bool)), comboBox_mid_1, SLOT(setEnabled(bool)));
        QObject::connect(radioButton_yes, SIGNAL(toggled(bool)), spinBox, SLOT(setEnabled(bool)));
        QObject::connect(radioButton_both, SIGNAL(toggled(bool)), spinBox_lmt, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(input);
    } // setupUi

    void retranslateUi(QDialog *input)
    {
        input->setWindowTitle(QApplication::translate("input", "Dialog", 0));
        label->setText(QApplication::translate("input", "Mid_Number", 0));
        label_3->setText(QApplication::translate("input", "NO.1", 0));
        label_4->setText(QApplication::translate("input", "NO.2", 0));
        label_8->setText(QApplication::translate("input", "NO.3", 0));
        label_7->setText(QApplication::translate("input", "NO.4", 0));
        label_6->setText(QApplication::translate("input", "NO.5", 0));
        label_2->setText(QApplication::translate("input", "Tourist ID", 0));
        groupBox_3->setTitle(QApplication::translate("input", "Destination", 0));
        groupBox_4->setTitle(QApplication::translate("input", "lmt", 0));
        groupBox->setTitle(QApplication::translate("input", "Mid_City", 0));
        radioButton_yes->setText(QApplication::translate("input", "YES", 0));
        radioButton_no->setText(QApplication::translate("input", "NO", 0));
        groupBox_2->setTitle(QApplication::translate("input", "Strategy", 0));
        radioButton_cost->setText(QApplication::translate("input", "minicost", 0));
        radioButton_time->setText(QApplication::translate("input", "minitime", 0));
        radioButton_both->setText(QApplication::translate("input", "minicost_lmt", 0));
    } // retranslateUi

};

namespace Ui {
    class input: public Ui_input {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUT_H
