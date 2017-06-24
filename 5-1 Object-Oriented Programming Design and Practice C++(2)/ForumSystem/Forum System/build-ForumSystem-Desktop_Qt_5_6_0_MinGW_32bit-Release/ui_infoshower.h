/********************************************************************************
** Form generated from reading UI file 'infoshower.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOSHOWER_H
#define UI_INFOSHOWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_InfoShower
{
public:
    QLabel *label;
    QTextBrowser *info_textBrowser;

    void setupUi(QDialog *InfoShower)
    {
        if (InfoShower->objectName().isEmpty())
            InfoShower->setObjectName(QStringLiteral("InfoShower"));
        InfoShower->resize(331, 364);
        label = new QLabel(InfoShower);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 211, 31));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        info_textBrowser = new QTextBrowser(InfoShower);
        info_textBrowser->setObjectName(QStringLiteral("info_textBrowser"));
        info_textBrowser->setGeometry(QRect(30, 70, 261, 261));

        retranslateUi(InfoShower);

        QMetaObject::connectSlotsByName(InfoShower);
    } // setupUi

    void retranslateUi(QDialog *InfoShower)
    {
        InfoShower->setWindowTitle(QApplication::translate("InfoShower", "Dialog", 0));
        label->setText(QApplication::translate("InfoShower", "User Information", 0));
    } // retranslateUi

};

namespace Ui {
    class InfoShower: public Ui_InfoShower {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOSHOWER_H
