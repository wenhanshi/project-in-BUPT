/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextBrowser *postView_textBrowser;
    QGroupBox *groupBox;
    QPushButton *makePost_pushButton;
    QPushButton *viewPost_pushButton;
    QGroupBox *groupBox_2;
    QPushButton *makeBM_pushButton;
    QGroupBox *groupBox_3;
    QComboBox *comboBox;
    QRadioButton *index_radioButton;
    QRadioButton *board_radioButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *key_lineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *go_pushButton;
    QGroupBox *groupBox_4;
    QPushButton *logout_pushButton;
    QPushButton *info_pushButton;
    QLabel *name_label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(676, 760);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        postView_textBrowser = new QTextBrowser(centralWidget);
        postView_textBrowser->setObjectName(QStringLiteral("postView_textBrowser"));
        postView_textBrowser->setGeometry(QRect(260, 20, 371, 641));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 440, 171, 121));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        makePost_pushButton = new QPushButton(groupBox);
        makePost_pushButton->setObjectName(QStringLiteral("makePost_pushButton"));
        makePost_pushButton->setGeometry(QRect(20, 80, 131, 31));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        makePost_pushButton->setFont(font1);
        viewPost_pushButton = new QPushButton(groupBox);
        viewPost_pushButton->setObjectName(QStringLiteral("viewPost_pushButton"));
        viewPost_pushButton->setGeometry(QRect(20, 30, 130, 31));
        viewPost_pushButton->setFont(font1);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(50, 570, 171, 91));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        groupBox_2->setFont(font2);
        makeBM_pushButton = new QPushButton(groupBox_2);
        makeBM_pushButton->setObjectName(QStringLiteral("makeBM_pushButton"));
        makeBM_pushButton->setGeometry(QRect(20, 30, 131, 41));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setWeight(75);
        makeBM_pushButton->setFont(font3);
        makeBM_pushButton->setAutoRepeat(false);
        makeBM_pushButton->setAutoExclusive(false);
        makeBM_pushButton->setAutoDefault(false);
        makeBM_pushButton->setFlat(false);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(50, 210, 171, 221));
        groupBox_3->setFont(font1);
        comboBox = new QComboBox(groupBox_3);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(20, 70, 131, 41));
        comboBox->setFont(font1);
        index_radioButton = new QRadioButton(groupBox_3);
        index_radioButton->setObjectName(QStringLiteral("index_radioButton"));
        index_radioButton->setGeometry(QRect(20, 130, 151, 21));
        QFont font4;
        font4.setPointSize(9);
        index_radioButton->setFont(font4);
        board_radioButton = new QRadioButton(groupBox_3);
        board_radioButton->setObjectName(QStringLiteral("board_radioButton"));
        board_radioButton->setGeometry(QRect(20, 40, 115, 19));
        board_radioButton->setFont(font4);
        board_radioButton->setChecked(true);
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 170, 151, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        key_lineEdit = new QLineEdit(layoutWidget);
        key_lineEdit->setObjectName(QStringLiteral("key_lineEdit"));
        key_lineEdit->setEnabled(false);
        key_lineEdit->setFont(font4);

        horizontalLayout->addWidget(key_lineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        horizontalLayout_2->addLayout(horizontalLayout);

        go_pushButton = new QPushButton(layoutWidget);
        go_pushButton->setObjectName(QStringLiteral("go_pushButton"));
        go_pushButton->setEnabled(false);
        go_pushButton->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_2->addWidget(go_pushButton);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(50, 30, 171, 161));
        groupBox_4->setFont(font1);
        logout_pushButton = new QPushButton(groupBox_4);
        logout_pushButton->setObjectName(QStringLiteral("logout_pushButton"));
        logout_pushButton->setGeometry(QRect(20, 70, 131, 31));
        QFont font5;
        font5.setPointSize(11);
        font5.setBold(true);
        font5.setWeight(75);
        font5.setStrikeOut(false);
        logout_pushButton->setFont(font5);
        logout_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(255, 84, 32);"));
        info_pushButton = new QPushButton(groupBox_4);
        info_pushButton->setObjectName(QStringLiteral("info_pushButton"));
        info_pushButton->setGeometry(QRect(20, 110, 131, 31));
        info_pushButton->setFont(font1);
        name_label = new QLabel(groupBox_4);
        name_label->setObjectName(QStringLiteral("name_label"));
        name_label->setGeometry(QRect(20, 30, 131, 31));
        QFont font6;
        font6.setPointSize(11);
        font6.setItalic(true);
        name_label->setFont(font6);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 676, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(comboBox, SIGNAL(currentTextChanged(QString)), postView_textBrowser, SLOT(setText(QString)));
        QObject::connect(board_radioButton, SIGNAL(toggled(bool)), comboBox, SLOT(setEnabled(bool)));
        QObject::connect(index_radioButton, SIGNAL(toggled(bool)), key_lineEdit, SLOT(setEnabled(bool)));
        QObject::connect(index_radioButton, SIGNAL(toggled(bool)), go_pushButton, SLOT(setEnabled(bool)));

        makeBM_pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Post", 0));
        makePost_pushButton->setText(QApplication::translate("MainWindow", "New Post", 0));
        viewPost_pushButton->setText(QApplication::translate("MainWindow", "Search Post", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Admin", 0));
        makeBM_pushButton->setText(QApplication::translate("MainWindow", "Admin Options", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Board Select", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Game", 0)
         << QApplication::translate("MainWindow", "Movie", 0)
         << QApplication::translate("MainWindow", "Coding", 0)
         << QApplication::translate("MainWindow", "All", 0)
        );
        index_radioButton->setText(QApplication::translate("MainWindow", "Index Mode", 0));
        board_radioButton->setText(QApplication::translate("MainWindow", "Board Mode", 0));
        key_lineEdit->setText(QString());
        go_pushButton->setText(QApplication::translate("MainWindow", "Go!", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "User", 0));
        logout_pushButton->setText(QApplication::translate("MainWindow", "Log Out", 0));
        info_pushButton->setText(QApplication::translate("MainWindow", "My Info", 0));
        name_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
