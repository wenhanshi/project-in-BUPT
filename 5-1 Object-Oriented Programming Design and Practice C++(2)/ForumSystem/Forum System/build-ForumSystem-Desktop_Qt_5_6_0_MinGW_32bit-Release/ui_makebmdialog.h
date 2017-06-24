/********************************************************************************
** Form generated from reading UI file 'makebmdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAKEBMDIALOG_H
#define UI_MAKEBMDIALOG_H

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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MakebmDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *userid_lineEdit;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *board_comboBox;
    QGroupBox *groupBox;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *ele_radioButton;
    QRadioButton *del_radioButton;
    QTextBrowser *info_textBrowser;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MakebmDialog)
    {
        if (MakebmDialog->objectName().isEmpty())
            MakebmDialog->setObjectName(QStringLiteral("MakebmDialog"));
        MakebmDialog->resize(365, 548);
        widget = new QWidget(MakebmDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(25, 45, 301, 461));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        userid_lineEdit = new QLineEdit(widget);
        userid_lineEdit->setObjectName(QStringLiteral("userid_lineEdit"));

        horizontalLayout_2->addWidget(userid_lineEdit);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        board_comboBox = new QComboBox(widget);
        board_comboBox->setObjectName(QStringLiteral("board_comboBox"));

        horizontalLayout->addWidget(board_comboBox);


        verticalLayout->addLayout(horizontalLayout);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 50));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        widget1 = new QWidget(groupBox);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(20, 20, 215, 21));
        horizontalLayout_3 = new QHBoxLayout(widget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        ele_radioButton = new QRadioButton(widget1);
        ele_radioButton->setObjectName(QStringLiteral("ele_radioButton"));
        ele_radioButton->setChecked(true);

        horizontalLayout_3->addWidget(ele_radioButton);

        del_radioButton = new QRadioButton(widget1);
        del_radioButton->setObjectName(QStringLiteral("del_radioButton"));

        horizontalLayout_3->addWidget(del_radioButton);


        verticalLayout->addWidget(groupBox);

        info_textBrowser = new QTextBrowser(widget);
        info_textBrowser->setObjectName(QStringLiteral("info_textBrowser"));

        verticalLayout->addWidget(info_textBrowser);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(MakebmDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MakebmDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MakebmDialog, SLOT(reject()));
        QObject::connect(del_radioButton, SIGNAL(toggled(bool)), board_comboBox, SLOT(setDisabled(bool)));
        QObject::connect(ele_radioButton, SIGNAL(toggled(bool)), board_comboBox, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(MakebmDialog);
    } // setupUi

    void retranslateUi(QDialog *MakebmDialog)
    {
        MakebmDialog->setWindowTitle(QApplication::translate("MakebmDialog", "Dialog", 0));
        label->setText(QApplication::translate("MakebmDialog", "Input ID:", 0));
        pushButton->setText(QApplication::translate("MakebmDialog", "Search", 0));
        label_2->setText(QApplication::translate("MakebmDialog", "Board Choose", 0));
        board_comboBox->clear();
        board_comboBox->insertItems(0, QStringList()
         << QApplication::translate("MakebmDialog", "Game", 0)
         << QApplication::translate("MakebmDialog", "Movie", 0)
         << QApplication::translate("MakebmDialog", "Coding", 0)
        );
        groupBox->setTitle(QApplication::translate("MakebmDialog", "Handle", 0));
        ele_radioButton->setText(QApplication::translate("MakebmDialog", "Elevate BM", 0));
        del_radioButton->setText(QApplication::translate("MakebmDialog", "Delete BM", 0));
    } // retranslateUi

};

namespace Ui {
    class MakebmDialog: public Ui_MakebmDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAKEBMDIALOG_H
