/********************************************************************************
** Form generated from reading UI file 'statistique.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTIQUE_H
#define UI_STATISTIQUE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_statistique
{
public:
    QWidget *leftmenu;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_13;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_14;
    QFrame *frame_15;
    QLabel *logo_2;
    QLabel *label_22;
    QPushButton *pushButton_27;
    QPushButton *pushButton_28;
    QPushButton *pushButton_29;
    QPushButton *pushButton_30;
    QPushButton *pushButton_31;
    QPushButton *pushButton_32;
    QPushButton *pushButton_20;
    QWidget *mainbody;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_12;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *pushButton_7;
    QLabel *label_13;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_14;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_14;
    QLineEdit *lineEdit_11;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *pushButton_8;
    QPushButton *pushButton_19;
    QPushButton *pushButton_stat;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_30;
    QStackedWidget *stackedWidgetStat;
    QWidget *page_3;
    QWidget *page_4;
    QPushButton *retour_2;

    void setupUi(QDialog *statistique)
    {
        if (statistique->objectName().isEmpty())
            statistique->setObjectName(QString::fromUtf8("statistique"));
        statistique->resize(920, 601);
        statistique->setStyleSheet(QString::fromUtf8("* {\n"
"    color: #000;\n"
"    border: none;\n"
"}\n"
"\n"
"#centralwidget {\n"
"    background-color: #eff99fe;\n"
"}\n"
"\n"
"#leftmenu {\n"
"    background-color: #2596be;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    background: transparent;\n"
"}\n"
"\n"
"QFrame {\n"
"    border-radius: 10px;\n"
"    border: 2px solid #2596be;\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #2596be;\n"
"}\n"
"\n"
"#employe_2 {\n"
"    background-color: #cecece;\n"
"}\n"
"\n"
"#lineEdit_2 {\n"
"    background: transparent;\n"
"}\n"
"\n"
"#label_22, #label_4, #label_17, #label_6, #label_7, #label_8, #label_9, #label_10 ,#label_18,#label_19,#label_15,#label_16,#label_20,#label_21,#label_14{\n"
"    color: #000;\n"
"    border: #000;\n"
"}\n"
"\n"
"#lineEdit_3, #code,#nom, #adresse, #contact, #quantite, #produit {\n"
"    background: #ffffff;\n"
"}\n"
"\n"
"#pushButton_7, #pushButton_8, #ajouter, #modifier,#qrcode {\n"
"    border-radius: 10px;\n"
"    border: 3px solid #2596be;\n"
"}\n"
"\n"
"\n"
"#label_11, #label_12, #label_23,#label_13 {\n"
""
                        "    border: #000;\n"
"}\n"
"\n"
"#frame_4, #frame_8 {\n"
"    border-radius: 10px;\n"
"    border: 1px solid #2596be;\n"
"}\n"
"\n"
"#LineEdit_10 {\n"
"    background: #CECECE;\n"
"}\n"
"\n"
"#widget_3 {\n"
"    background-color: #fefeff;\n"
"}\n"
"\n"
"#mainbody {\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"#tableView_f {\n"
"    background-color: #2596be;\n"
"}\n"
"\n"
"#lineEdit_supp {\n"
"    border-radius: 6px;\n"
"    border: 1px solid #4cd814;\n"
"    background: #fffff;\n"
"}\n"
"\n"
"#del_button{\n"
"    border-radius: 10px;\n"
"    border: 2px solid #090909;\n"
"    background: #fffff;\n"
"}\n"
"\n"
"#pushButton_13 {\n"
"    border-radius: 20px;\n"
"    border: 2px solid #4cd814;\n"
"    background: #fffff;\n"
"}\n"
"\n"
"#pushButton_14 {\n"
"    border-radius: 20px;\n"
"    border: 2px solid #2596be;\n"
"    background: #fffff;\n"
"}\n"
"\n"
"#retour {\n"
"    border-radius: 20px;\n"
"    border: 2px solid #2596be;\n"
"    background: #fffff;\n"
"}\n"
"#chatBot_2 {\n"
"    border-radius: 20px;"
                        "\n"
"    border: 2px solid #2596be;\n"
"    background: #fffff;\n"
"}\n"
"\n"
"#label_24, #label_25, #label_26 {\n"
"    color: #000;\n"
"    border: #000;\n"
"}\n"
"\n"
"#logo {\n"
"    border-radius: 6px;\n"
"    border: 3px solid #4cd814;\n"
"    background: #fffff;\n"
"}\n"
"\n"
"#sous {\n"
"    background-color: #cecece;\n"
"}\n"
"\n"
"#label_27, #label_28, #label_29, #label_30, #label_31, #label_32 {\n"
"    border-radius: 1px;\n"
"    border: 1px solid #ffffff;\n"
"    color: #000;\n"
"}\n"
"\n"
"#pushButton_17 {\n"
"    background-color: #fefeff;\n"
"    padding: 5px;\n"
"    text-align: left;\n"
"    border-top-left-radius: 20px;\n"
"}\n"
"\n"
"#pushButton_22 {\n"
"    color: #4cd814;\n"
"}\n"
"#pushButton_20 {\n"
"    background-color: #fefeff;\n"
"    padding: 5px;\n"
"    text-align: left;\n"
"    border-top-left-radius: 20px;\n"
"}\n"
"#pushButton_stat {\n"
"    border-radius: 20px;\n"
"    border: 2px solid #2596be;\n"
"    background: #ffffff;\n"
"}\n"
"#logo_2 {\n"
"    border-radius: 6px;\n"
""
                        "    border: 3px solid #4cd814;\n"
"    background: #fffff;\n"
"}\n"
"#pushButton_32{\n"
"\n"
"    color: #4cd814;\n"
"\n"
"}\n"
"#pushButton_27{\n"
"    background-color: #2596be;\n"
"}\n"
"#pushButton_28{\n"
"    background-color: #2596be;\n"
"}\n"
"#pushButton_29{\n"
"    background-color: #2596be;\n"
"}\n"
"#pushButton_20{\n"
"    \n"
"	background-color: #fefeff;\n"
"    padding: 5px;\n"
"    text-align: left;\n"
"    border-top-left-radius: 20px;\n"
"}\n"
"#pushButton_30{\n"
"    background-color: #2596be;\n"
"}\n"
"#pushButton_31{\n"
"    background-color: #2596be;\n"
"}\n"
"#pushButton_32{\n"
"    background-color: #2596be;\n"
"} \n"
"#label_3 {\n"
"    color: #000;\n"
"    border: #000;\n"
"}\n"
"#label_22\n"
"{\n"
"	 background-color: #2596be;\n"
"}"));
        leftmenu = new QWidget(statistique);
        leftmenu->setObjectName(QString::fromUtf8("leftmenu"));
        leftmenu->setGeometry(QRect(0, 0, 200, 601));
        leftmenu->setMinimumSize(QSize(100, 0));
        leftmenu->setMaximumSize(QSize(200, 16777215));
        verticalLayout_3 = new QVBoxLayout(leftmenu);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frame_13 = new QFrame(leftmenu);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        frame_13->setFrameShape(QFrame::NoFrame);
        verticalLayout_4 = new QVBoxLayout(frame_13);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        frame_14 = new QFrame(frame_13);
        frame_14->setObjectName(QString::fromUtf8("frame_14"));
        frame_14->setFrameShape(QFrame::NoFrame);
        frame_15 = new QFrame(frame_14);
        frame_15->setObjectName(QString::fromUtf8("frame_15"));
        frame_15->setGeometry(QRect(0, 0, 160, 61));
        frame_15->setFrameShape(QFrame::NoFrame);
        logo_2 = new QLabel(frame_15);
        logo_2->setObjectName(QString::fromUtf8("logo_2"));
        logo_2->setGeometry(QRect(0, 10, 51, 41));
        logo_2->setPixmap(QPixmap(QString::fromUtf8(":/res/image22")));
        label_22 = new QLabel(frame_15);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(60, 0, 101, 61));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        label_22->setFont(font);
        pushButton_27 = new QPushButton(frame_14);
        pushButton_27->setObjectName(QString::fromUtf8("pushButton_27"));
        pushButton_27->setGeometry(QRect(40, 70, 75, 24));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(true);
        pushButton_27->setFont(font1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/icone23"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_27->setIcon(icon);
        pushButton_28 = new QPushButton(frame_14);
        pushButton_28->setObjectName(QString::fromUtf8("pushButton_28"));
        pushButton_28->setGeometry(QRect(0, 120, 161, 31));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setUnderline(false);
        pushButton_28->setFont(font2);
        pushButton_28->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 150, 190);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/icone27"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_28->setIcon(icon1);
        pushButton_29 = new QPushButton(frame_14);
        pushButton_29->setObjectName(QString::fromUtf8("pushButton_29"));
        pushButton_29->setGeometry(QRect(20, 170, 111, 24));
        pushButton_29->setFont(font2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/icone26"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_29->setIcon(icon2);
        pushButton_30 = new QPushButton(frame_14);
        pushButton_30->setObjectName(QString::fromUtf8("pushButton_30"));
        pushButton_30->setGeometry(QRect(30, 270, 101, 24));
        pushButton_30->setFont(font1);
        pushButton_30->setIcon(icon);
        pushButton_31 = new QPushButton(frame_14);
        pushButton_31->setObjectName(QString::fromUtf8("pushButton_31"));
        pushButton_31->setGeometry(QRect(30, 330, 101, 24));
        pushButton_31->setFont(font1);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/icone24"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_31->setIcon(icon3);
        pushButton_32 = new QPushButton(frame_14);
        pushButton_32->setObjectName(QString::fromUtf8("pushButton_32"));
        pushButton_32->setGeometry(QRect(10, 470, 141, 41));
        pushButton_32->setFont(font1);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/res/icone30"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_32->setIcon(icon4);
        pushButton_20 = new QPushButton(frame_14);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));
        pushButton_20->setGeometry(QRect(0, 220, 161, 31));
        pushButton_20->setFont(font1);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/res/icone25"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_20->setIcon(icon5);

        verticalLayout_4->addWidget(frame_14);


        verticalLayout_3->addWidget(frame_13);

        mainbody = new QWidget(statistique);
        mainbody->setObjectName(QString::fromUtf8("mainbody"));
        mainbody->setGeometry(QRect(200, 0, 1421, 711));
        QFont font3;
        font3.setBold(false);
        mainbody->setFont(font3);
        widget_4 = new QWidget(mainbody);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(0, 0, 671, 50));
        widget_4->setMinimumSize(QSize(400, 0));
        widget_4->setMaximumSize(QSize(800, 135));
        horizontalLayout_12 = new QHBoxLayout(widget_4);
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        widget_10 = new QWidget(widget_4);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout_13 = new QHBoxLayout(widget_10);
        horizontalLayout_13->setSpacing(7);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(10, 10, 10, 10);
        pushButton_7 = new QPushButton(widget_10);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/res/icone1.jog.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon6);
        pushButton_7->setIconSize(QSize(50, 50));

        horizontalLayout_13->addWidget(pushButton_7);

        label_13 = new QLabel(widget_10);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(10, 0));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/res/icone7")));
        label_13->setScaledContents(false);
        label_13->setWordWrap(false);

        horizontalLayout_13->addWidget(label_13);


        horizontalLayout_12->addWidget(widget_10);

        widget_11 = new QWidget(widget_4);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        widget_11->setMaximumSize(QSize(553, 16777215));
        horizontalLayout_14 = new QHBoxLayout(widget_11);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(9, 9, -1, -1);
        frame_5 = new QFrame(widget_11);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setMinimumSize(QSize(250, 0));
        frame_5->setStyleSheet(QString::fromUtf8(""));
        frame_5->setFrameShape(QFrame::NoFrame);
        horizontalLayout_15 = new QHBoxLayout(frame_5);
        horizontalLayout_15->setSpacing(0);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(frame_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMaximumSize(QSize(30, 30));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/res/icone2.jpg.png")));
        label_14->setScaledContents(true);

        horizontalLayout_15->addWidget(label_14);

        lineEdit_11 = new QLineEdit(frame_5);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));

        horizontalLayout_15->addWidget(lineEdit_11);


        horizontalLayout_14->addWidget(frame_5);


        horizontalLayout_12->addWidget(widget_11);

        widget_12 = new QWidget(widget_4);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        widget_12->setMinimumSize(QSize(200, 0));
        horizontalLayout_16 = new QHBoxLayout(widget_12);
        horizontalLayout_16->setSpacing(9);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(50, 9, 9, 9);
        pushButton_8 = new QPushButton(widget_12);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(32, 32));
        pushButton_8->setMaximumSize(QSize(32, 32));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/res/icone4.jpg.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon7);
        pushButton_8->setIconSize(QSize(32, 32));

        horizontalLayout_16->addWidget(pushButton_8);

        pushButton_19 = new QPushButton(widget_12);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/res/icone20"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_19->setIcon(icon8);

        horizontalLayout_16->addWidget(pushButton_19);


        horizontalLayout_12->addWidget(widget_12);

        pushButton_stat = new QPushButton(mainbody);
        pushButton_stat->setObjectName(QString::fromUtf8("pushButton_stat"));
        pushButton_stat->setGeometry(QRect(10, 60, 71, 41));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/res/icone11"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_stat->setIcon(icon9);
        pushButton_stat->setIconSize(QSize(32, 32));
        label_27 = new QLabel(mainbody);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(600, 60, 51, 91));
        label_27->setPixmap(QPixmap(QString::fromUtf8(":/res/icone16")));
        label_28 = new QLabel(mainbody);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(540, 70, 49, 71));
        label_28->setPixmap(QPixmap(QString::fromUtf8(":/res/icone18")));
        label_30 = new QLabel(mainbody);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(10, 110, 101, 21));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        label_30->setFont(font4);
        stackedWidgetStat = new QStackedWidget(mainbody);
        stackedWidgetStat->setObjectName(QString::fromUtf8("stackedWidgetStat"));
        stackedWidgetStat->setGeometry(QRect(20, 150, 661, 411));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        stackedWidgetStat->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        retour_2 = new QPushButton(page_4);
        retour_2->setObjectName(QString::fromUtf8("retour_2"));
        retour_2->setGeometry(QRect(290, 340, 75, 24));
        retour_2->setFont(font4);
        stackedWidgetStat->addWidget(page_4);

        retranslateUi(statistique);

        stackedWidgetStat->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(statistique);
    } // setupUi

    void retranslateUi(QDialog *statistique)
    {
        statistique->setWindowTitle(QCoreApplication::translate("statistique", "Dialog", nullptr));
        logo_2->setText(QString());
        label_22->setText(QCoreApplication::translate("statistique", "MedicaPRO", nullptr));
        pushButton_27->setText(QCoreApplication::translate("statistique", "Menu", nullptr));
        pushButton_28->setText(QCoreApplication::translate("statistique", "Employ\303\251", nullptr));
        pushButton_29->setText(QCoreApplication::translate("statistique", "M\303\251dicaments", nullptr));
        pushButton_30->setText(QCoreApplication::translate("statistique", "Ordonnances", nullptr));
        pushButton_31->setText(QCoreApplication::translate("statistique", "Financi\303\250res", nullptr));
        pushButton_32->setText(QCoreApplication::translate("statistique", "Se d\303\251connecter", nullptr));
        pushButton_20->setText(QCoreApplication::translate("statistique", "Fournisseurs", nullptr));
        pushButton_7->setText(QString());
        label_13->setText(QString());
        label_14->setText(QString());
        lineEdit_11->setText(QString());
        lineEdit_11->setPlaceholderText(QCoreApplication::translate("statistique", "Recherche", nullptr));
        pushButton_8->setText(QString());
        pushButton_19->setText(QString());
        pushButton_stat->setText(QString());
        label_27->setText(QString());
        label_28->setText(QString());
        label_30->setText(QCoreApplication::translate("statistique", "Statistiques", nullptr));
        retour_2->setText(QCoreApplication::translate("statistique", "Retour", nullptr));
    } // retranslateUi

};

namespace Ui {
    class statistique: public Ui_statistique {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTIQUE_H
