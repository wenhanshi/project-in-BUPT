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
    QLabel *delInfo_label;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTextBrowser *Post_textBrowser;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QTextBrowser *Comment_textBrowser;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QTextEdit *commentInput_textEdit;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *postID_lineEdit;
    QPushButton *pushButton;
    QPushButton *delPost_pushButton;

    void setupUi(QDialog *PostViewDialog)
    {
        if (PostViewDialog->objectName().isEmpty())
            PostViewDialog->setObjectName(QStringLiteral("PostViewDialog"));
        PostViewDialog->resize(895, 616);
        send_pushButton = new QPushButton(PostViewDialog);
        send_pushButton->setObjectName(QStringLiteral("send_pushButton"));
        send_pushButton->setGeometry(QRect(520, 500, 291, 71));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        send_pushButton->setFont(font);
        delInfo_label = new QLabel(PostViewDialog);
        delInfo_label->setObjectName(QStringLiteral("delInfo_label"));
        delInfo_label->setGeometry(QRect(510, 30, 301, 31));
        widget = new QWidget(PostViewDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(70, 90, 421, 481));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        Post_textBrowser = new QTextBrowser(widget);
        Post_textBrowser->setObjectName(QStringLiteral("Post_textBrowser"));

        verticalLayout->addWidget(Post_textBrowser);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        verticalLayout_2->addWidget(label_3);

        Comment_textBrowser = new QTextBrowser(widget);
        Comment_textBrowser->setObjectName(QStringLiteral("Comment_textBrowser"));

        verticalLayout_2->addWidget(Comment_textBrowser);


        verticalLayout_3->addLayout(verticalLayout_2);

        widget1 = new QWidget(PostViewDialog);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(520, 90, 291, 391));
        verticalLayout_4 = new QVBoxLayout(widget1);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        verticalLayout_4->addWidget(label_4);

        commentInput_textEdit = new QTextEdit(widget1);
        commentInput_textEdit->setObjectName(QStringLiteral("commentInput_textEdit"));

        verticalLayout_4->addWidget(commentInput_textEdit);

        widget2 = new QWidget(PostViewDialog);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(70, 30, 421, 41));
        horizontalLayout_2 = new QHBoxLayout(widget2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget2);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        horizontalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        postID_lineEdit = new QLineEdit(widget2);
        postID_lineEdit->setObjectName(QStringLiteral("postID_lineEdit"));

        horizontalLayout->addWidget(postID_lineEdit);

        pushButton = new QPushButton(widget2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        delPost_pushButton = new QPushButton(widget2);
        delPost_pushButton->setObjectName(QStringLiteral("delPost_pushButton"));
        delPost_pushButton->setEnabled(true);

        horizontalLayout->addWidget(delPost_pushButton);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(PostViewDialog);

        QMetaObject::connectSlotsByName(PostViewDialog);
    } // setupUi

    void retranslateUi(QDialog *PostViewDialog)
    {
        PostViewDialog->setWindowTitle(QApplication::translate("PostViewDialog", "Dialog", 0));
        send_pushButton->setText(QApplication::translate("PostViewDialog", "Send Comment", 0));
        delInfo_label->setText(QString());
        label_2->setText(QApplication::translate("PostViewDialog", "Post", 0));
        label_3->setText(QApplication::translate("PostViewDialog", "Comments", 0));
        label_4->setText(QApplication::translate("PostViewDialog", "Make Comment", 0));
        label->setText(QApplication::translate("PostViewDialog", "PostID", 0));
        pushButton->setText(QApplication::translate("PostViewDialog", "Search", 0));
        delPost_pushButton->setText(QApplication::translate("PostViewDialog", "Delete Post", 0));
    } // retranslateUi

};

namespace Ui {
    class PostViewDialog: public Ui_PostViewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSTVIEWDIALOG_H
