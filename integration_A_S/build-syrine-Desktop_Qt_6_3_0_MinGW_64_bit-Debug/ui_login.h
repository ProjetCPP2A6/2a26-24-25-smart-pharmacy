/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *widget;
    QLabel *label;
    QWidget *widget_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *line_id;
    QLabel *label_5;
    QLineEdit *line_password;
    QPushButton *forgotPasswordButton;
    QPushButton *pushButton_3;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(912, 587);
        login->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background: #ffffff;\n"
"}\n"
"QWidget{\n"
"	background: #ffffff;\n"
"}\n"
"#line_id\n"
" {\n"
"	   background-color: #2596be;\n"
"}\n"
"#line_password\n"
" {\n"
"	   background-color: #2596be;\n"
"}\n"
"#forgotPasswordButton{\n"
"	background-color: transparent;\n"
"	border-radius: 10px;\n"
"	border: 2px solid  transparent;\n"
"    color: #FF0000;\n"
"}\n"
""));
        widget = new QWidget(login);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, -1, 551, 581));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-10, 0, 561, 571));
        label->setPixmap(QPixmap(QString::fromUtf8(":/res/loggin")));
        widget_2 = new QWidget(login);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(560, 0, 351, 581));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 50, 211, 41));
        QFont font;
        font.setPointSize(25);
        font.setBold(true);
        label_2->setFont(font);
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 90, 41, 61));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/res/icone15")));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 130, 141, 61));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        label_4->setFont(font1);
        line_id = new QLineEdit(widget_2);
        line_id->setObjectName(QString::fromUtf8("line_id"));
        line_id->setGeometry(QRect(40, 190, 261, 31));
        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 230, 161, 61));
        label_5->setFont(font1);
        line_password = new QLineEdit(widget_2);
        line_password->setObjectName(QString::fromUtf8("line_password"));
        line_password->setGeometry(QRect(40, 290, 261, 31));
        line_password->setEchoMode(QLineEdit::Password);
        forgotPasswordButton = new QPushButton(widget_2);
        forgotPasswordButton->setObjectName(QString::fromUtf8("forgotPasswordButton"));
        forgotPasswordButton->setGeometry(QRect(30, 350, 171, 29));
        QFont font2;
        font2.setBold(true);
        forgotPasswordButton->setFont(font2);
        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(90, 420, 191, 31));
        pushButton_3->setFont(font2);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("login", "Connexion", nullptr));
        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("login", " Identifiant :", nullptr));
        label_5->setText(QCoreApplication::translate("login", "Mot de passe :", nullptr));
        forgotPasswordButton->setText(QCoreApplication::translate("login", "Mot de passe oubli\303\251 ?", nullptr));
        pushButton_3->setText(QCoreApplication::translate("login", "Se connecter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
