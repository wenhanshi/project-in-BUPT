/********************************************************************************
** Form generated from reading UI file 'rgstdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RGSTDIALOG_H
#define UI_RGSTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RgstDialog
{
public:
    QLabel *label_3;
    QLabel *error_label;
    QPushButton *enroll_pushButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *nameInput_lineEdit;
    QLineEdit *passwordInput_lineEdit;

    void setupUi(QDialog *RgstDialog)
    {
        if (RgstDialog->objectName().isEmpty())
            RgstDialog->setObjectName(QStringLiteral("RgstDialog"));
        RgstDialog->resize(413, 230);
        label_3 = new QLabel(RgstDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 30, 71, 20));
        QFont font;
        font.setPointSize(11);
        label_3->setFont(font);
        error_label = new QLabel(RgstDialog);
        error_label->setObjectName(QStringLiteral("error_label"));
        error_label->setGeometry(QRect(40, 130, 331, 31));
        enroll_pushButton = new QPushButton(RgstDialog);
        enroll_pushButton->setObjectName(QStringLiteral("enroll_pushButton"));
        enroll_pushButton->setGeometry(QRect(280, 170, 93, 28));
        QFont font1;
        font1.setPointSize(9);
        enroll_pushButton->setFont(font1);
        widget = new QWidget(RgstDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 60, 337, 55));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        nameInput_lineEdit = new QLineEdit(widget);
        nameInput_lineEdit->setObjectName(QStringLiteral("nameInput_lineEdit"));

        verticalLayout->addWidget(nameInput_lineEdit);

        passwordInput_lineEdit = new QLineEdit(widget);
        passwordInput_lineEdit->setObjectName(QStringLiteral("passwordInput_lineEdit"));

        verticalLayout->addWidget(passwordInput_lineEdit);


        horizontalLayout_3->addLayout(verticalLayout);


        retranslateUi(RgstDialog);

        QMetaObject::connectSlotsByName(RgstDialog);
    } // setupUi

    void retranslateUi(QDialog *RgstDialog)
    {
        RgstDialog->setWindowTitle(QApplication::translate("RgstDialog", "Dialog", 0));
        label_3->setText(QApplication::translate("RgstDialog", "New User", 0));
        error_label->setText(QString());
        enroll_pushButton->setText(QApplication::translate("RgstDialog", "Enroll", 0));
        label->setText(QApplication::translate("RgstDialog", "Your Name", 0));
        label_2->setText(QApplication::translate("RgstDialog", "Your password", 0));
    } // retranslateUi

};

namespace Ui {
    class RgstDialog: public Ui_RgstDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RGSTDIALOG_H
