/********************************************************************************
** Form generated from reading UI file 'employeeui.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEUI_H
#define UI_EMPLOYEEUI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_employeeUI
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
    QFrame *employe;
    QFrame *frame_3;
    QLabel *label;
    QLabel *label_5;
    QLineEdit *id;
    QLabel *label_6;
    QLineEdit *nom;
    QLabel *label_7;
    QLineEdit *prenom;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *sexe;
    QLabel *label_10;
    QLineEdit *salaire;
    QPushButton *ajouter;
    QPushButton *editer;
    QLabel *label_13;
    QLineEdit *password;
    QComboBox *comboBox;
    QPushButton *ExportationButton;
    QPushButton *statistiqueButton;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QPushButton *Demande_conge;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QFrame *frame_4;
    QLineEdit *lineEdit_recherche;
    QLabel *label_11;
    QComboBox *comboBox_critere;
    QPushButton *supp;
    QTableView *tableView;
    QLineEdit *lineEdit_supp;
    QFrame *frame_8;
    QLineEdit *lineEdit_tri;
    QPushButton *pushButton_11;
    QComboBox *comboBox_tri;
    QWidget *page_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *stat_btn;
    QPushButton *retour;

    void setupUi(QDialog *employeeUI)
    {
        if (employeeUI->objectName().isEmpty())
            employeeUI->setObjectName(QString::fromUtf8("employeeUI"));
        employeeUI->resize(913, 565);
        employeeUI->setStyleSheet(QString::fromUtf8("* {\n"
"    color: #000;\n"
"    border: none;\n"
"}\n"
"employeeUI {\n"
"    background-color: #eff99fe;\n"
"}\n"
"#leftmenu {\n"
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
"#label_3 {\n"
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
"#employe {\n"
"    "
                        "background-color: #cecece;\n"
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
"#label_4 {\n"
"    color: #000;\n"
"    border: #000;\n"
"}\n"
"#label_13{\n"
"    color: #000;\n"
"    border: #000;\n"
"}\n"
"#id {\n"
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
"#password{\n"
"    background: #ffffff;\n"
"}\n"
"#sexe{\n"
"    background: #ffffff;\n"
"}\n"
"#label_9 {\n"
"    color: #000;\n"
"    border: #000;\n"
"}\n"
"#salaire {\n"
"    background: #ffffff;\n"
"}\n"
""
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
"#stat_btn {\n"
"    border-radius: 10px;\n"
"    border: 3px solid #2596be;\n"
"}\n"
"#retour{\n"
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
"	background-color: transparent;\n"
"}\n"
"#pushButton_11 {\n"
"    border: #000;\n"
"	background-color: transparent;\n"
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
""
                        "}\n"
"#mainbody {\n"
"    background-color: #ffffff;\n"
"}\n"
"#stackedWidget{\n"
"    background-color: #2596be;\n"
"	color: #000;\n"
"}\n"
"#frame_8 {\n"
"    border-radius: 10px;\n"
"    border: 1px solid #2596be;\n"
"}\n"
"#tableView {\n"
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
"#pushButton {\n"
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
"    "
                        "color: #000;\n"
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
"#label_27 {\n"
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
"    color: #"
                        "4cd814;\n"
"}\n"
"#pushButton_22 {\n"
"     background-color: transparent;\n"
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
" 	color: #000;\n"
"   border: #000;\n"
"}\n"
"#lineEdit_10 {\n"
"    background: transparent;\n"
"}\n"
"#pushButton_3 {\n"
"    border-radius: 10px;\n"
"    border: 3px solid #2596be;\n"
"}\n"
"#employe{\n"
"	background-color: #cecece;\n"
"}\n"
"#frame_3{\n"
"	background-color: #cecece;\n"
"}\n"
"#label{\n"
"	background-color: #cecece;\n"
"}\n"
"#label_5{\n"
"	background-color: #cecece;\n"
"}\n"
"#label_6{\n"
"	background-color: #cecece;\n"
"}\n"
"#label_7{\n"
"	background-color: #cecece;\n"
"}\n"
"#label_8{\n"
"	background-color: #cecece;\n"
"}\n"
"#label_9{\n"
"	background-color: #cecece;\n"
"}\n"
"#label_13{\n"
"	background-color: #cecece;\n"
"}\n"
"#label_10{\n"
"	background-color: #cecece;\n"
"}\n"
"#ajouter {\n"
"    bord"
                        "er-radius: 10px;\n"
"    border: 3px solid #2596be;\n"
"	background-color: #cecece;\n"
"}\n"
"#editer {\n"
"    border-radius: 10px;\n"
"    border: 3px solid #2596be;\n"
"	background-color: #cecece;\n"
"}\n"
"#pushButton_4 {\n"
"    border-radius: 10px;\n"
"    border: 3px solid #2596be;\n"
"}"));
        leftmenu = new QWidget(employeeUI);
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
        pushButton_18->setGeometry(QRect(20, 170, 111, 24));
        pushButton_18->setFont(font2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/icone26"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_18->setIcon(icon2);
        pushButton_19 = new QPushButton(frame_11);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        pushButton_19->setGeometry(QRect(20, 220, 111, 24));
        pushButton_19->setFont(font1);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/icone25"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_19->setIcon(icon3);
        pushButton_20 = new QPushButton(frame_11);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));
        pushButton_20->setGeometry(QRect(10, 270, 131, 24));
        pushButton_20->setFont(font1);
        pushButton_20->setIcon(icon);
        pushButton_21 = new QPushButton(frame_11);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));
        pushButton_21->setGeometry(QRect(10, 330, 131, 24));
        pushButton_21->setFont(font1);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/res/icone24"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_21->setIcon(icon4);
        pushButton_22 = new QPushButton(frame_11);
        pushButton_22->setObjectName(QString::fromUtf8("pushButton_22"));
        pushButton_22->setGeometry(QRect(20, 470, 121, 41));
        pushButton_22->setFont(font1);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/res/icone30"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_22->setIcon(icon5);

        verticalLayout_2->addWidget(frame_11);


        verticalLayout->addWidget(frame_9);

        mainbody = new QWidget(employeeUI);
        mainbody->setObjectName(QString::fromUtf8("mainbody"));
        mainbody->setGeometry(QRect(200, 0, 721, 565));
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

        horizontalLayout_11->addWidget(pushButton_4);

        pushButton_15 = new QPushButton(widget_9);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/res/icone20"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_15->setIcon(icon8);

        horizontalLayout_11->addWidget(pushButton_15);


        horizontalLayout_7->addWidget(widget_9);

        employe = new QFrame(mainbody);
        employe->setObjectName(QString::fromUtf8("employe"));
        employe->setGeometry(QRect(10, 110, 230, 451));
        employe->setMinimumSize(QSize(230, 420));
        employe->setMaximumSize(QSize(150, 600));
        employe->setFrameShape(QFrame::NoFrame);
        frame_3 = new QFrame(employe);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(0, 0, 151, 41));
        frame_3->setMaximumSize(QSize(200, 16777215));
        frame_3->setFrameShape(QFrame::NoFrame);
        label = new QLabel(frame_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 4, 131, 31));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        label->setFont(font4);
        label_5 = new QLabel(employe);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 50, 49, 16));
        label_5->setFont(font4);
        id = new QLineEdit(employe);
        id->setObjectName(QString::fromUtf8("id"));
        id->setGeometry(QRect(30, 70, 171, 22));
        label_6 = new QLabel(employe);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 100, 49, 16));
        label_6->setFont(font4);
        nom = new QLineEdit(employe);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(30, 120, 171, 22));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(false);
        nom->setFont(font5);
        label_7 = new QLabel(employe);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 150, 81, 16));
        label_7->setFont(font4);
        prenom = new QLineEdit(employe);
        prenom->setObjectName(QString::fromUtf8("prenom"));
        prenom->setGeometry(QRect(30, 170, 171, 22));
        label_8 = new QLabel(employe);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 200, 49, 16));
        label_8->setFont(font4);
        label_9 = new QLabel(employe);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 250, 49, 16));
        label_9->setFont(font4);
        sexe = new QLineEdit(employe);
        sexe->setObjectName(QString::fromUtf8("sexe"));
        sexe->setGeometry(QRect(30, 270, 171, 22));
        label_10 = new QLabel(employe);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 350, 49, 16));
        label_10->setFont(font4);
        salaire = new QLineEdit(employe);
        salaire->setObjectName(QString::fromUtf8("salaire"));
        salaire->setGeometry(QRect(30, 370, 171, 22));
        ajouter = new QPushButton(employe);
        ajouter->setObjectName(QString::fromUtf8("ajouter"));
        ajouter->setGeometry(QRect(30, 410, 70, 24));
        ajouter->setFont(font4);
        editer = new QPushButton(employe);
        editer->setObjectName(QString::fromUtf8("editer"));
        editer->setGeometry(QRect(120, 410, 75, 24));
        editer->setFont(font4);
        label_13 = new QLabel(employe);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 300, 121, 21));
        label_13->setFont(font4);
        password = new QLineEdit(employe);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(30, 320, 171, 22));
        comboBox = new QComboBox(employe);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(40, 220, 161, 22));
        ExportationButton = new QPushButton(mainbody);
        ExportationButton->setObjectName(QString::fromUtf8("ExportationButton"));
        ExportationButton->setGeometry(QRect(270, 80, 75, 41));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/res/icone10"), QSize(), QIcon::Normal, QIcon::Off);
        ExportationButton->setIcon(icon9);
        ExportationButton->setIconSize(QSize(32, 32));
        statistiqueButton = new QPushButton(mainbody);
        statistiqueButton->setObjectName(QString::fromUtf8("statistiqueButton"));
        statistiqueButton->setGeometry(QRect(360, 80, 71, 41));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/res/icone11"), QSize(), QIcon::Normal, QIcon::Off);
        statistiqueButton->setIcon(icon10);
        statistiqueButton->setIconSize(QSize(32, 32));
        label_23 = new QLabel(mainbody);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(600, 40, 51, 91));
        label_23->setPixmap(QPixmap(QString::fromUtf8(":/res/icone16")));
        label_24 = new QLabel(mainbody);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(540, 50, 49, 71));
        label_24->setPixmap(QPixmap(QString::fromUtf8(":/res/icone18")));
        label_25 = new QLabel(mainbody);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(270, 130, 71, 20));
        label_25->setFont(font4);
        label_26 = new QLabel(mainbody);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(360, 130, 81, 16));
        label_26->setFont(font4);
        Demande_conge = new QPushButton(mainbody);
        Demande_conge->setObjectName(QString::fromUtf8("Demande_conge"));
        Demande_conge->setGeometry(QRect(500, 120, 181, 31));
        Demande_conge->setFont(font4);
        stackedWidget = new QStackedWidget(mainbody);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(250, 170, 441, 381));
        stackedWidget->setStyleSheet(QString::fromUtf8("#stackedWidget{\n"
"    background-color: #2596be;\n"
"	color: #000;\n"
"}"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        frame_4 = new QFrame(page);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(0, 0, 391, 31));
        frame_4->setFrameShape(QFrame::NoFrame);
        lineEdit_recherche = new QLineEdit(frame_4);
        lineEdit_recherche->setObjectName(QString::fromUtf8("lineEdit_recherche"));
        lineEdit_recherche->setGeometry(QRect(40, 0, 341, 20));
        lineEdit_recherche->setFont(font5);
        label_11 = new QLabel(frame_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 0, 25, 25));
        label_11->setMinimumSize(QSize(25, 25));
        label_11->setMaximumSize(QSize(25, 25));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/res/icone8")));
        label_11->setScaledContents(true);
        comboBox_critere = new QComboBox(frame_4);
        comboBox_critere->addItem(QString());
        comboBox_critere->addItem(QString());
        comboBox_critere->addItem(QString());
        comboBox_critere->setObjectName(QString::fromUtf8("comboBox_critere"));
        comboBox_critere->setGeometry(QRect(270, 1, 71, 21));
        comboBox_critere->setFont(font4);
        supp = new QPushButton(page);
        supp->setObjectName(QString::fromUtf8("supp"));
        supp->setGeometry(QRect(280, 343, 91, 31));
        supp->setFont(font4);
        tableView = new QTableView(page);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 80, 431, 251));
        lineEdit_supp = new QLineEdit(page);
        lineEdit_supp->setObjectName(QString::fromUtf8("lineEdit_supp"));
        lineEdit_supp->setGeometry(QRect(150, 350, 113, 21));
        lineEdit_supp->setFont(font4);
        frame_8 = new QFrame(page);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setGeometry(QRect(0, 40, 421, 31));
        frame_8->setFrameShape(QFrame::NoFrame);
        lineEdit_tri = new QLineEdit(frame_8);
        lineEdit_tri->setObjectName(QString::fromUtf8("lineEdit_tri"));
        lineEdit_tri->setGeometry(QRect(42, 0, 311, 22));
        pushButton_11 = new QPushButton(frame_8);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(10, 0, 32, 32));
        pushButton_11->setMinimumSize(QSize(32, 32));
        pushButton_11->setMaximumSize(QSize(32, 32));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/res/icone9"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon11);
        comboBox_tri = new QComboBox(frame_8);
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->setObjectName(QString::fromUtf8("comboBox_tri"));
        comboBox_tri->setGeometry(QRect(340, 1, 71, 20));
        comboBox_tri->setFont(font4);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        horizontalLayoutWidget_2 = new QWidget(page_2);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 90, 391, 231));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        stat_btn = new QPushButton(page_2);
        stat_btn->setObjectName(QString::fromUtf8("stat_btn"));
        stat_btn->setGeometry(QRect(160, 340, 93, 28));
        retour = new QPushButton(page_2);
        retour->setObjectName(QString::fromUtf8("retour"));
        retour->setGeometry(QRect(30, 30, 93, 28));
        stackedWidget->addWidget(page_2);

        retranslateUi(employeeUI);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(employeeUI);
    } // setupUi

    void retranslateUi(QDialog *employeeUI)
    {
        employeeUI->setWindowTitle(QCoreApplication::translate("employeeUI", "Dialog", nullptr));
        logo->setText(QString());
        label_3->setText(QCoreApplication::translate("employeeUI", "MedicaPRO", nullptr));
        pushButton_16->setText(QCoreApplication::translate("employeeUI", "Menu", nullptr));
        pushButton_17->setText(QCoreApplication::translate("employeeUI", "Employ\303\251", nullptr));
        pushButton_18->setText(QCoreApplication::translate("employeeUI", "M\303\251dicaments", nullptr));
        pushButton_19->setText(QCoreApplication::translate("employeeUI", "Fournisseurs", nullptr));
        pushButton_20->setText(QCoreApplication::translate("employeeUI", "Ordonnances", nullptr));
        pushButton_21->setText(QCoreApplication::translate("employeeUI", "Financi\303\250res", nullptr));
        pushButton_22->setText(QCoreApplication::translate("employeeUI", "Se d\303\251connecter", nullptr));
        pushButton_3->setText(QString());
        label_12->setText(QString());
        label_4->setText(QString());
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("employeeUI", "Recherche", nullptr));
        pushButton_4->setText(QString());
        pushButton_15->setText(QString());
        label->setText(QCoreApplication::translate("employeeUI", "Ajouter un employ\303\251  :", nullptr));
        label_5->setText(QCoreApplication::translate("employeeUI", "ID", nullptr));
        label_6->setText(QCoreApplication::translate("employeeUI", "Nom", nullptr));
        label_7->setText(QCoreApplication::translate("employeeUI", "Pr\303\251nom", nullptr));
        label_8->setText(QCoreApplication::translate("employeeUI", "Poste", nullptr));
        label_9->setText(QCoreApplication::translate("employeeUI", "Sexe", nullptr));
        label_10->setText(QCoreApplication::translate("employeeUI", "Salaire", nullptr));
        ajouter->setText(QCoreApplication::translate("employeeUI", "Ajouter", nullptr));
        editer->setText(QCoreApplication::translate("employeeUI", "Editer", nullptr));
#if QT_CONFIG(statustip)
        label_13->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        label_13->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        label_13->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        label_13->setText(QCoreApplication::translate("employeeUI", "Mot de passe", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("employeeUI", "Pharmacien", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("employeeUI", "Preparateur", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("employeeUI", "Ressources humaines", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("employeeUI", "Responsable Stock", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("employeeUI", "Assistant", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("employeeUI", "Responsable des achats", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("employeeUI", "Technicien", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("employeeUI", "comptable", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("employeeUI", "Agent de nettoyage", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("employeeUI", "Fournisseur", nullptr));

        ExportationButton->setText(QString());
        statistiqueButton->setText(QString());
        label_23->setText(QString());
        label_24->setText(QString());
        label_25->setText(QCoreApplication::translate("employeeUI", "Exportation", nullptr));
        label_26->setText(QCoreApplication::translate("employeeUI", "Statistiques", nullptr));
        Demande_conge->setText(QCoreApplication::translate("employeeUI", "Demander un cong\303\251", nullptr));
        lineEdit_recherche->setText(QString());
        lineEdit_recherche->setPlaceholderText(QCoreApplication::translate("employeeUI", "Rechercher un employ\303\251 \303\240 partir de son ID", nullptr));
        label_11->setText(QString());
        comboBox_critere->setItemText(0, QCoreApplication::translate("employeeUI", "id", nullptr));
        comboBox_critere->setItemText(1, QCoreApplication::translate("employeeUI", "post", nullptr));
        comboBox_critere->setItemText(2, QCoreApplication::translate("employeeUI", "salaire", nullptr));

        supp->setText(QCoreApplication::translate("employeeUI", "Supprimer", nullptr));
        lineEdit_supp->setPlaceholderText(QCoreApplication::translate("employeeUI", "Identifiant", nullptr));
        lineEdit_tri->setPlaceholderText(QCoreApplication::translate("employeeUI", "Trier la liste des employ\303\251s selon l'ordre croissant par leur:", nullptr));
        pushButton_11->setText(QString());
        comboBox_tri->setItemText(0, QCoreApplication::translate("employeeUI", "id", nullptr));
        comboBox_tri->setItemText(1, QCoreApplication::translate("employeeUI", "nom", nullptr));
        comboBox_tri->setItemText(2, QCoreApplication::translate("employeeUI", "salaire", nullptr));

        stat_btn->setText(QCoreApplication::translate("employeeUI", "statistique", nullptr));
        retour->setText(QCoreApplication::translate("employeeUI", "Retour", nullptr));
    } // retranslateUi

};

namespace Ui {
    class employeeUI: public Ui_employeeUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEUI_H
