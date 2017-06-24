/********************************************************************************
** Form generated from reading UI file 'postviewdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSTVIEWDIALOG_H
#define UI_POSTVIEWDIALOG_H

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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PostViewDialog
{
public:
    QPushButton *send_pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTextBrowser *Post_textBrowser;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QTextBrowser *Comment_textBrowser;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QTextEdit *commentInput_textEdit;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *postID_lineEdit;
    QPushButton *pushButton;
    QPushButton *delPost_pushButton;
    QPushButton *stick_pushButton;
    QLabel *delInfo_label;
    QLabel *empty_label;

    void setupUi(QDialog *PostViewDialog)
    {
        if (PostViewDialog->objectName().isEmpty())
            PostViewDialog->setObjectName(QStringLiteral("PostViewDialog"));
        PostViewDialog->resize(949, 615);
        send_pushButton = new QPushButton(PostViewDialog);
        send_pushButton->setObjectName(QStringLiteral("send_pushButton"));
        send_pushButton->setGeometry(QRect(520, 500, 351, 71));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        send_pushButton->setFont(font);
        layoutWidget = new QWidget(PostViewDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 90, 421, 481));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        Post_textBrowser = new QTextBrowser(layoutWidget);
        Post_textBrowser->setObjectName(QStringLiteral("Post_textBrowser"));

        verticalLayout->addWidget(Post_textBrowser);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        verticalLayout_2->addWidget(label_3);

        Comment_textBrowser = new QTextBrowser(layoutWidget);
        Comment_textBrowser->setObjectName(QStringLiteral("Comment_textBrowser"));

        verticalLayout_2->addWidget(Comment_textBrowser);


        verticalLayout_3->addLayout(verticalLayout_2);

        layoutWidget1 = new QWidget(PostViewDialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(520, 90, 351, 361));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        verticalLayout_4->addWidget(label_4);

        commentInput_textEdit = new QTextEdit(layoutWidget1);
        commentInput_textEdit->setObjectName(QStringLiteral("commentInput_textEdit"));

        verticalLayout_4->addWidget(commentInput_textEdit);

        layoutWidget2 = new QWidget(PostViewDialog);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(72, 32, 821, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        postID_lineEdit = new QLineEdit(layoutWidget2);
        postID_lineEdit->setObjectName(QStringLiteral("postID_lineEdit"));

        horizontalLayout->addWidget(postID_lineEdit);

        pushButton = new QPushButton(layoutWidget2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        delPost_pushButton = new QPushButton(layoutWidget2);
        delPost_pushButton->setObjectName(QStringLiteral("delPost_pushButton"));
        delPost_pushButton->setEnabled(true);

        horizontalLayout->addWidget(delPost_pushButton);

        stick_pushButton = new QPushButton(layoutWidget2);
        stick_pushButton->setObjectName(QStringLiteral("stick_pushButton"));

        horizontalLayout->addWidget(stick_pushButton);

        delInfo_label = new QLabel(layoutWidget2);
        delInfo_label->setObjectName(QStringLiteral("delInfo_label"));
        delInfo_label->setMinimumSize(QSize(300, 0));

        horizontalLayout->addWidget(delInfo_label);

        empty_label = new QLabel(PostViewDialog);
        empty_label->setObjectName(QStringLiteral("empty_label"));
        empty_label->setGeometry(QRect(520, 460, 351, 31));

        retranslateUi(PostViewDialog);

        QMetaObject::connectSlotsByName(PostViewDialog);
    } // setupUi

    void retranslateUi(QDialog *PostViewDialog)
    {
        PostViewDialog->setWindowTitle(QApplication::translate("PostViewDialog", "Dialog", 0));
        send_pushButton->setText(QApplication::translate("PostViewDialog", "Send Comment", 0));
        label_2->setText(QApplication::translate("PostViewDialog", "Post", 0));
        label_3->setText(QApplication::translate("PostViewDialog", "Comments", 0));
        label_4->setText(QApplication::translate("PostViewDialog", "Make Comment", 0));
        label->setText(QApplication::translate("PostViewDialog", "PostID", 0));
        pushButton->setText(QApplication::translate("PostViewDialog", "Search", 0));
        delPost_pushButton->setText(QApplication::translate("PostViewDialog", "Delete Post", 0));
        stick_pushButton->setText(QApplication::translate("PostViewDialog", "Stick Post", 0));
        delInfo_label->setText(QString());
        empty_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PostViewDialog: public Ui_PostViewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSTVIEWDIALOG_H
