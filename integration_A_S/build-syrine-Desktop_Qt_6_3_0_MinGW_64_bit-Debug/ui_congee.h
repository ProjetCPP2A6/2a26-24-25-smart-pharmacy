/********************************************************************************
** Form generated from reading UI file 'congee.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONGEE_H
#define UI_CONGEE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_congee
{
public:
    QWidget *leftmenu;
    QVBoxLayout *verticalLayout;
    QFrame *frame_9;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_11;
    QFrame *frame_10;
    QLabel *logo;
    QLabel *label_3;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QWidget *mainbody;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_7;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_3;
    QLabel *label_12;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_9;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButton_4;
    QPushButton *pushButton_15;
    QLabel *label_23;
    QLabel *label_24;
    QWidget *widget;
    QLabel *label_5;
    QLineEdit *id;
    QLabel *label_6;
    QComboBox *type;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *validerButton;
    QDateEdit *dateDebut;
    QDateEdit *dateFin;
    QTableView *tableView1;
    QLabel *label;

    void setupUi(QDialog *congee)
    {
        if (congee->objectName().isEmpty())
            congee->setObjectName(QString::fromUtf8("congee"));
        congee->resize(899, 565);
        congee->setStyleSheet(QString::fromUtf8("* {\n"
"    color: #000;\n"
"    border: none;\n"
"}\n"
"employeeUI {\n"
"    background-color: #eff99fe;\n"
"}\n"
"#leftmenu {\n"
"    background-color: #2596be;\n"
"}\n"
"#label_3 {\n"
"    background-color: #2596be;\n"
"}\n"
"#pushButton_16{\n"
"    background-color: #2596be;\n"
"}\n"
"#pushButton_17{\n"
"    background-color: #2596be;\n"
"}\n"
"#pushButton_18{\n"
"    background-color: #2596be;\n"
"}\n"
"#pushButton_19{\n"
"    background-color: #2596be;\n"
"}\n"
"#pushButton_20{\n"
"    background-color: #2596be;\n"
"}\n"
"#pushButton_21{\n"
"    background-color: #2596be;\n"
"}\n"
"#pushButton_22{\n"
"    background-color: #2596be;\n"
"}\n"
"#frame_10{\n"
"    background-color: #2596be;\n"
"}\n"
"#frame_9 {\n"
"    background-color: #2596be;\n"
"}\n"
"#frame_11 {\n"
"    background-color: #2596be;\n"
"}\n"
"QLineEdit {\n"
"    background: transparent;\n"
"}\n"
"QFrame {\n"
"    border-radius: 10px;\n"
"    border: 2px solid #2596be;\n"
"}\n"
"QLabel {\n"
"    color: #2596be;\n"
"}\n"
"#widget {\n"
"    b"
                        "ackground-color: #cecece;\n"
"}\n"
"#lineEdit_2 {\n"
"    background: transparent;\n"
"}\n"
"#label_3 {\n"
"    color: #000;\n"
"    border: #000;\n"
"}\n"
"#lineEdit_3 {\n"
"    background: #ffffff;\n"
"    background: transparent;\n"
"}\n"
"#datedebut{\n"
"    background: #ffffff;\n"
"    background: transparent;\n"
"}\n"
"#lineEdit_3 {\n"
"    background: #ffffff;\n"
"    background: transparent;\n"
"}\n"
"#label_4 {\n"
"    color: #000;\n"
"    border: #000;\n"
"}\n"
"#id {\n"
"    background: #ffffff;\n"
"}\n"
"#datedebut{\n"
"    background: #ffffff;\n"
"}\n"
"#datefin{\n"
"    background: #ffffff;\n"
"}\n"
"#label_5 {\n"
"    color: #000;\n"
"    border: #000;\n"
"}\n"
"#nom {\n"
"    background: #ffffff;\n"
"}\n"
"#label_6 {\n"
"    color: #000;\n"
"    border: #000;\n"
"}\n"
"#prenom {\n"
"    background: #ffffff;\n"
"}\n"
"#label_7 {\n"
"    color: #000;\n"
"    border: #000;\n"
"}\n"
"#post {\n"
"    background: #ffffff;\n"
"}\n"
"#label_8 {\n"
"    color: #000;\n"
"    border: #000;\n"
"}\n"
"#sexe"
                        "{\n"
"    background: #ffffff;\n"
"}\n"
"#label_9 {\n"
"    color: #000;\n"
"    border: #000;\n"
"}\n"
"#salaire {\n"
"    background: #ffffff;\n"
"}\n"
"#label_10 {\n"
"    color: #000;\n"
"    border: #000;\n"
"}\n"
"#ajouter {\n"
"    border-radius: 10px;\n"
"    border: 3px solid #2596be;\n"
"}\n"
"#pushButton_4 {\n"
"    border-radius: 10px;\n"
"    border: 3px solid #2596be;\n"
"}\n"
"#editer {\n"
"    border-radius: 10px;\n"
"    border: 3px solid #2596be;\n"
"}\n"
"#pushButton_6 {\n"
"    border-radius: 10px;\n"
"    border: 3px solid #2596be;\n"
"}\n"
"#label_11 {\n"
"    border: #000;\n"
"}\n"
"#label_12 {\n"
"    border: #000;\n"
"}\n"
"#label_23 {\n"
"    border: #000;\n"
"}\n"
"#frame_4 {\n"
"    border-radius: 10px;\n"
"    border: 1px solid #2596be;\n"
"}\n"
"#lineEdit_10 {\n"
"    background: #cecece;\n"
"}\n"
"#widget_3 {\n"
"    background-color: #fefeff;\n"
"}\n"
"#mainbody {\n"
"    background-color: #ffffff;\n"
"}\n"
"#frame_8 {\n"
"    border-radius: 10px;\n"
"    border: 1px solid #2596"
                        "be;\n"
"}\n"
"#tableView1 {\n"
"    background-color: #2596be;\n"
"}\n"
"#lineEdit_supp {\n"
"    border-radius: 6px;\n"
"    border: 1px solid #4cd814;\n"
"    background: #ffffff;\n"
"}\n"
"#supp {\n"
"    border-radius: 10px;\n"
"    border: 2px solid #090909;\n"
"    background: #fffff;\n"
"}\n"
"#ExportationButton {\n"
"    border-radius: 20px;\n"
"    border: 2px solid #4cd814;\n"
"    background: #ffffff;\n"
"}\n"
"#statistiqueButton {\n"
"    border-radius: 20px;\n"
"    border: 2px solid #2596be;\n"
"    background: #ffffff;\n"
"}\n"
"#conge {\n"
"    border-radius: 7px;\n"
"    border: 2px solid #000;\n"
"    background: #ffffff;\n"
"}\n"
"#label_24 {\n"
"    color: #000;\n"
"    border: #000;\n"
"}\n"
"#label_25 {\n"
"    color: #000;\n"
"    border: #000;\n"
"}\n"
"#label_26 {\n"
"    color: #000;\n"
"    border: #000;\n"
"}\n"
"#logo {\n"
"    border-radius: 6px;\n"
"    border: 3px solid #4cd814;\n"
"    background: #ffffff;\n"
"}\n"
"#sous {\n"
"    background-color: #cecece;\n"
"}\n"
"#label_27"
                        " {\n"
"    border-radius: 1px;\n"
"    border: 1px solid #ffffff;\n"
"    color: #000;\n"
"}\n"
"#label_28 {\n"
"    border-radius: 1px;\n"
"    border: 1px solid #ffffff;\n"
"    color: #000;\n"
"}\n"
"#label_29 {\n"
"    border-radius: 1px;\n"
"    border: 1px solid #ffffff;\n"
"    color: #000;\n"
"}\n"
"#label_30 {\n"
"    border-radius: 1px;\n"
"    border: 1px solid #ffffff;\n"
"    color: #000;\n"
"}\n"
"#label_31 {\n"
"    border-radius: 1px;\n"
"    border: 1px solid #ffffff;\n"
"    color: #000;\n"
"}\n"
"#label_32 {\n"
"    border-radius: 1px;\n"
"    border: 1px solid #ffffff;\n"
"    color: #000;\n"
"}\n"
"#pushButton_17 {\n"
"    background-color: #fefeff;\n"
"    padding: 5px;\n"
"    text-align: left;\n"
"    border-top-left-radius: 20px;\n"
"}\n"
"#pushButton_22 {\n"
"    color: #4cd814;\n"
"}\n"
"#comboBox_critere {\n"
"    border-radius: 10px;\n"
"    border: 2px solid transparent;\n"
"}\n"
"#comboBox_2 {\n"
"    border-radius: 10px;\n"
"    border: 2px solid transparent;\n"
"}\n"
"#label {\n"
""
                        " 	color: #000;\n"
"   border: #000;\n"
"   background: transparent;\n"
"}\n"
"#lineEdit_10 {\n"
"    background: transparent;\n"
"}\n"
"#validerButton{\n"
"    border-radius: 10px;\n"
"    border: 3px solid #2596be;\n"
"	background:  #cecece;\n"
"}\n"
"#label_5,#label_6,#label_7,#label_8\n"
"{\n"
"	color: #2596be;\n"
"}\n"
"#pushButton {\n"
"    border-radius: 7px;\n"
"    border: 2px;\n"
"    background: #ffffff;\n"
"}\n"
"#pushButton_4 {\n"
"    border-radius: 10px;\n"
"    border: 3px solid #2596be;\n"
"}"));
        leftmenu = new QWidget(congee);
        leftmenu->setObjectName(QString::fromUtf8("leftmenu"));
        leftmenu->setGeometry(QRect(0, 0, 200, 565));
        leftmenu->setMinimumSize(QSize(100, 0));
        leftmenu->setMaximumSize(QSize(200, 16777215));
        verticalLayout = new QVBoxLayout(leftmenu);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_9 = new QFrame(leftmenu);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setFrameShape(QFrame::NoFrame);
        verticalLayout_2 = new QVBoxLayout(frame_9);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame_11 = new QFrame(frame_9);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setFrameShape(QFrame::NoFrame);
        frame_10 = new QFrame(frame_11);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setGeometry(QRect(0, 0, 160, 61));
        frame_10->setFrameShape(QFrame::NoFrame);
        logo = new QLabel(frame_10);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(0, 10, 51, 41));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/res/image22")));
        label_3 = new QLabel(frame_10);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 15, 101, 31));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        label_3->setFont(font);
        pushButton_16 = new QPushButton(frame_11);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setGeometry(QRect(40, 70, 75, 24));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(true);
        pushButton_16->setFont(font1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/icone23"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_16->setIcon(icon);
        pushButton_17 = new QPushButton(frame_11);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        pushButton_17->setGeometry(QRect(0, 120, 161, 31));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setUnderline(false);
        pushButton_17->setFont(font2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/icone27"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_17->setIcon(icon1);
        pushButton_18 = new QPushButton(frame_11);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        pushButton_18->setGeometry(QRect(10, 170, 141, 24));
        pushButton_18->setFont(font2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/icone26"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_18->setIcon(icon2);
        pushButton_19 = new QPushButton(frame_11);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        pushButton_19->setGeometry(QRect(10, 220, 141, 24));
        pushButton_19->setFont(font1);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/icone25"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_19->setIcon(icon3);
        pushButton_20 = new QPushButton(frame_11);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));
        pushButton_20->setGeometry(QRect(10, 270, 141, 24));
        pushButton_20->setFont(font1);
        pushButton_20->setIcon(icon);
        pushButton_21 = new QPushButton(frame_11);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));
        pushButton_21->setGeometry(QRect(10, 330, 121, 24));
        pushButton_21->setFont(font1);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/res/icone24"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_21->setIcon(icon4);
        pushButton_22 = new QPushButton(frame_11);
        pushButton_22->setObjectName(QString::fromUtf8("pushButton_22"));
        pushButton_22->setGeometry(QRect(0, 470, 151, 41));
        pushButton_22->setFont(font1);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/res/icone30"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_22->setIcon(icon5);

        verticalLayout_2->addWidget(frame_11);


        verticalLayout->addWidget(frame_9);

        mainbody = new QWidget(congee);
        mainbody->setObjectName(QString::fromUtf8("mainbody"));
        mainbody->setGeometry(QRect(200, 0, 701, 565));
        QFont font3;
        font3.setBold(false);
        mainbody->setFont(font3);
        widget_3 = new QWidget(mainbody);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(0, 0, 701, 50));
        widget_3->setMinimumSize(QSize(400, 0));
        widget_3->setMaximumSize(QSize(800, 135));
        horizontalLayout_7 = new QHBoxLayout(widget_3);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        widget_7 = new QWidget(widget_3);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_8 = new QHBoxLayout(widget_7);
        horizontalLayout_8->setSpacing(7);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(10, 10, 10, 10);
        pushButton_3 = new QPushButton(widget_7);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/res/icone1.jog.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon6);
        pushButton_3->setIconSize(QSize(50, 50));

        horizontalLayout_8->addWidget(pushButton_3);

        label_12 = new QLabel(widget_7);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(10, 0));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/res/icone7")));
        label_12->setScaledContents(false);
        label_12->setWordWrap(false);

        horizontalLayout_8->addWidget(label_12);


        horizontalLayout_7->addWidget(widget_7, 0, Qt::AlignRight);

        widget_8 = new QWidget(widget_3);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setMinimumSize(QSize(200, 0));
        widget_8->setMaximumSize(QSize(553, 16777215));
        horizontalLayout_9 = new QHBoxLayout(widget_8);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(9, 9, -1, -1);
        frame_2 = new QFrame(widget_8);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(50, 0));
        frame_2->setStyleSheet(QString::fromUtf8(""));
        frame_2->setFrameShape(QFrame::NoFrame);
        horizontalLayout_10 = new QHBoxLayout(frame_2);
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(30, 30));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/res/icone2.jpg.png")));
        label_4->setScaledContents(true);

        horizontalLayout_10->addWidget(label_4);

        lineEdit_2 = new QLineEdit(frame_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_10->addWidget(lineEdit_2);


        horizontalLayout_9->addWidget(frame_2);


        horizontalLayout_7->addWidget(widget_8);

        widget_9 = new QWidget(widget_3);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setMinimumSize(QSize(200, 0));
        horizontalLayout_11 = new QHBoxLayout(widget_9);
        horizontalLayout_11->setSpacing(9);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(50, 9, 9, 9);
        pushButton_4 = new QPushButton(widget_9);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(32, 32));
        pushButton_4->setMaximumSize(QSize(32, 32));
        pushButton_4->setToolTipDuration(-2);
        pushButton_4->setLayoutDirection(Qt::LeftToRight);
        pushButton_4->setAutoFillBackground(false);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/res/icone4.jpg.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon7);
        pushButton_4->setIconSize(QSize(32, 32));

        horizontalLayout_11->addWidget(pushButton_4, 0, Qt::AlignRight);

        pushButton_15 = new QPushButton(widget_9);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/res/icone20"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_15->setIcon(icon8);

        horizontalLayout_11->addWidget(pushButton_15);


        horizontalLayout_7->addWidget(widget_9);

        label_23 = new QLabel(mainbody);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(600, 40, 51, 91));
        label_23->setPixmap(QPixmap(QString::fromUtf8(":/res/icone16")));
        label_24 = new QLabel(mainbody);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(540, 50, 49, 71));
        label_24->setPixmap(QPixmap(QString::fromUtf8(":/res/icone18")));
        widget = new QWidget(mainbody);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 110, 681, 191));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 30, 71, 21));
        QFont font4;
        font4.setPointSize(15);
        font4.setBold(true);
        label_5->setFont(font4);
        id = new QLineEdit(widget);
        id->setObjectName(QString::fromUtf8("id"));
        id->setGeometry(QRect(10, 60, 121, 22));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(200, 20, 71, 31));
        label_6->setFont(font4);
        type = new QComboBox(widget);
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->setObjectName(QString::fromUtf8("type"));
        type->setGeometry(QRect(180, 60, 121, 21));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(true);
        type->setFont(font5);
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(350, 20, 161, 31));
        label_7->setFont(font4);
        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(520, 20, 151, 31));
        label_8->setFont(font4);
        validerButton = new QPushButton(widget);
        validerButton->setObjectName(QString::fromUtf8("validerButton"));
        validerButton->setGeometry(QRect(230, 120, 191, 41));
        validerButton->setFont(font5);
        dateDebut = new QDateEdit(widget);
        dateDebut->setObjectName(QString::fromUtf8("dateDebut"));
        dateDebut->setGeometry(QRect(360, 60, 131, 22));
        dateFin = new QDateEdit(widget);
        dateFin->setObjectName(QString::fromUtf8("dateFin"));
        dateFin->setGeometry(QRect(520, 60, 131, 22));
        tableView1 = new QTableView(mainbody);
        tableView1->setObjectName(QString::fromUtf8("tableView1"));
        tableView1->setGeometry(QRect(230, 310, 451, 251));
        label = new QLabel(mainbody);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 410, 191, 31));
        label->setFont(font4);

        retranslateUi(congee);

        QMetaObject::connectSlotsByName(congee);
    } // setupUi

    void retranslateUi(QDialog *congee)
    {
        congee->setWindowTitle(QCoreApplication::translate("congee", "Dialog", nullptr));
        logo->setText(QString());
        label_3->setText(QCoreApplication::translate("congee", "MedicaPRO", nullptr));
        pushButton_16->setText(QCoreApplication::translate("congee", "Menu", nullptr));
        pushButton_17->setText(QCoreApplication::translate("congee", "Employ\303\251", nullptr));
        pushButton_18->setText(QCoreApplication::translate("congee", "M\303\251dicaments", nullptr));
        pushButton_19->setText(QCoreApplication::translate("congee", "Fournisseurs", nullptr));
        pushButton_20->setText(QCoreApplication::translate("congee", "Ordonnances", nullptr));
        pushButton_21->setText(QCoreApplication::translate("congee", "Financi\303\250res", nullptr));
        pushButton_22->setText(QCoreApplication::translate("congee", "Se d\303\251connecter", nullptr));
        pushButton_3->setText(QString());
        label_12->setText(QString());
        label_4->setText(QString());
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("congee", "Recherche", nullptr));
        pushButton_4->setText(QString());
        pushButton_15->setText(QString());
        label_23->setText(QString());
        label_24->setText(QString());
        label_5->setText(QCoreApplication::translate("congee", "ID", nullptr));
        label_6->setText(QCoreApplication::translate("congee", "Type", nullptr));
        type->setItemText(0, QCoreApplication::translate("congee", "Annuel", nullptr));
        type->setItemText(1, QCoreApplication::translate("congee", "Paternite/Maternite", nullptr));
        type->setItemText(2, QCoreApplication::translate("congee", "Maladie", nullptr));

        label_7->setText(QCoreApplication::translate("congee", "Date D\303\251part", nullptr));
        label_8->setText(QCoreApplication::translate("congee", "Date Retour", nullptr));
        validerButton->setText(QCoreApplication::translate("congee", "Envoyer la demande", nullptr));
        label->setText(QCoreApplication::translate("congee", "Mes demandes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class congee: public Ui_congee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONGEE_H
