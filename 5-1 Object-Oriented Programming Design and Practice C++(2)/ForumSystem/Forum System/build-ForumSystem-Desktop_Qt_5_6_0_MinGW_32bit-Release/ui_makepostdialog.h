/********************************************************************************
** Form generated from reading UI file 'makepostdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAKEPOSTDIALOG_H
#define UI_MAKEPOSTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MakePostDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *title_lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QTextEdit *content_textEdit;

    void setupUi(QDialog *MakePostDialog)
    {
        if (MakePostDialog->objectName().isEmpty())
            MakePostDialog->setObjectName(QStringLiteral("MakePostDialog"));
        MakePostDialog->resize(437, 532);
        buttonBox = new QDialogButtonBox(MakePostDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(50, 470, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(MakePostDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 30, 351, 421));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QFont font1;
        font1.setPointSize(11);
        comboBox->setFont(font1);

        horizontalLayout->addWidget(comboBox);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        title_lineEdit = new QLineEdit(widget);
        title_lineEdit->setObjectName(QStringLiteral("title_lineEdit"));

        horizontalLayout_2->addWidget(title_lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout);

        content_textEdit = new QTextEdit(widget);
        content_textEdit->setObjectName(QStringLiteral("content_textEdit"));

        horizontalLayout_3->addWidget(content_textEdit);


        verticalLayout_5->addLayout(horizontalLayout_3);


        retranslateUi(MakePostDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MakePostDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MakePostDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MakePostDialog);
    } // setupUi

    void retranslateUi(QDialog *MakePostDialog)
    {
        MakePostDialog->setWindowTitle(QApplication::translate("MakePostDialog", "Dialog", 0));
        label->setText(QApplication::translate("MakePostDialog", "Board", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MakePostDialog", "Game", 0)
         << QApplication::translate("MakePostDialog", "Movie", 0)
         << QApplication::translate("MakePostDialog", "Coding", 0)
        );
        label_2->setText(QApplication::translate("MakePostDialog", "Title", 0));
        label_3->setText(QApplication::translate("MakePostDialog", "Content", 0));
    } // retranslateUi

};

namespace Ui {
    class MakePostDialog: public Ui_MakePostDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAKEPOSTDIALOG_H
