/********************************************************************************
** Form generated from reading UI file 'medicament_ui.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDICAMENT_UI_H
#define UI_MEDICAMENT_UI_H

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

class Ui_medicament_UI
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
    QLabel *label;
    QLabel *statusLabel;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButton_4;
    QPushButton *pushButton_15;
    QFrame *employe;
    QFrame *frame_3;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLineEdit *id;
    QLabel *label_6;
    QLineEdit *nom;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *prix;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *quantite;
    QPushButton *add;
    QPushButton *edit;
    QDateEdit *date_e;
    QDateEdit *date_p;
    QFrame *frame_4;
    QLabel *label_11;
    QComboBox *comboBox;
    QLineEdit *lineEdit_10;
    QPushButton *pushButton;
    QFrame *frame_8;
    QLineEdit *lineEdit_20;
    QPushButton *pushButton_11;
    QComboBox *comboBox_2;
    QLineEdit *supp;
    QPushButton *supp_button;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QTableView *tableView;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_5;
    QPushButton *pushButton_noNotif;
    QPushButton *pushButton_Notif;
    QPushButton *pushButton_6;

    void setupUi(QDialog *medicament_UI)
    {
        if (medicament_UI->objectName().isEmpty())
            medicament_UI->setObjectName(QString::fromUtf8("medicament_UI"));
        medicament_UI->resize(981, 565);
        medicament_UI->setStyleSheet(QString::fromUtf8("* {\n"
"    color: #000;\n"
"    border: none;\n"
"}\n"
"medicament_UI {\n"
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
" "
                        "   background-color: #cecece;\n"
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
"#prix{\n"
"	background: #ffffff;\n"
"}\n"
"#quantite{\n"
"	background: #ffffff;\n"
"}\n"
"#label_9 {\n"
"    co"
                        "lor: #000;\n"
"    border: #000;\n"
"}\n"
"#salaire {\n"
"    background: #ffffff;\n"
"}\n"
"#label_10 {\n"
"    color: #000;\n"
"    border: #000;\n"
"}\n"
"#add{\n"
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
"#edit {\n"
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
""
                        "    background: #cecece;\n"
"}\n"
"#widget_3 {\n"
"    background-color: #fefeff;\n"
"}\n"
"#mainbody {\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"#frame_8 {\n"
"    border-radius: 10px;\n"
"    border: 1px solid #2596be;\n"
"}\n"
"#tableView {\n"
"    background-color: #2596be;\n"
"}\n"
"#supp {\n"
"    border-radius: 6px;\n"
"    border: 1px solid #4cd814;\n"
"    background: #ffffff;\n"
"}\n"
"#supp_button {\n"
"    border-radius: 10px;\n"
"    border: 2px solid #090909;\n"
"    background: #fffff;\n"
"}\n"
"#pushButton_13 {\n"
"    border-radius: 20px;\n"
"    border: 2px solid #4cd814;\n"
"    background: #ffffff;\n"
"}\n"
"#pushButton_14 {\n"
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
"  "
                        "  color: #000;\n"
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
"#pushButton_18 {\n"
"    background-color: #fefeff;\n"
"    padding: 5px;\n"
"    text-align: left;\n"
"    border-top-left-radius: 20px;\n"
"}\n"
"#pushButton_22 {\n"
"    color:"
                        " #4cd814;\n"
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
"    bo"
                        "rder-radius: 10px;\n"
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
"}\n"
"#tableView {\n"
"    background-color: #2596be;\n"
"}\n"
"#add{\n"
"    background: #cecece;\n"
"}\n"
"#edit{\n"
"    background: #cecece;\n"
"}"));
        leftmenu = new QWidget(medicament_UI);
        leftmenu->setObjectName(QString::fromUtf8("leftmenu"));
        leftmenu->setGeometry(QRect(0, 0, 200, 565));
        leftmenu->setMinimumSize(QSize(100, 0));
        leftmenu->setMaximumSize(QSize(200, 16777215));
        verticalLayout = new QVBoxLayout(leftmenu);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
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
        frame_10->setGeometry(QRect(10, 0, 160, 61));
        frame_10->setFrameShape(QFrame::NoFrame);
        logo = new QLabel(frame_10);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(0, 10, 51, 41));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/res/image22")));
        label_3 = new QLabel(frame_10);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(true);
        label_3->setGeometry(QRect(60, 20, 101, 31));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setItalic(true);
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
        pushButton_17->setGeometry(QRect(30, 120, 111, 31));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setUnderline(false);
        pushButton_17->setFont(font2);
        pushButton_17->setStyleSheet(QString::fromUtf8("#pushButton_17{\n"
"    background-color: #2596be;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/icone27"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_17->setIcon(icon1);
        pushButton_18 = new QPushButton(frame_11);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        pushButton_18->setGeometry(QRect(0, 163, 181, 31));
        pushButton_18->setFont(font2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/icone26"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_18->setIcon(icon2);
        pushButton_19 = new QPushButton(frame_11);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        pushButton_19->setGeometry(QRect(20, 220, 131, 24));
        pushButton_19->setFont(font1);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/icone25"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_19->setIcon(icon3);
        pushButton_20 = new QPushButton(frame_11);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));
        pushButton_20->setGeometry(QRect(20, 270, 131, 24));
        pushButton_20->setFont(font1);
        pushButton_20->setIcon(icon);
        pushButton_21 = new QPushButton(frame_11);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));
        pushButton_21->setGeometry(QRect(20, 330, 121, 24));
        pushButton_21->setFont(font1);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/res/icone24"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_21->setIcon(icon4);
        pushButton_22 = new QPushButton(frame_11);
        pushButton_22->setObjectName(QString::fromUtf8("pushButton_22"));
        pushButton_22->setGeometry(QRect(10, 470, 151, 41));
        pushButton_22->setFont(font1);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/res/icone30"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_22->setIcon(icon5);

        verticalLayout_2->addWidget(frame_11);


        verticalLayout->addWidget(frame_9);

        mainbody = new QWidget(medicament_UI);
        mainbody->setObjectName(QString::fromUtf8("mainbody"));
        mainbody->setGeometry(QRect(200, 0, 781, 565));
        QFont font3;
        font3.setBold(false);
        mainbody->setFont(font3);
        widget_3 = new QWidget(mainbody);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(0, 0, 671, 50));
        widget_3->setMinimumSize(QSize(400, 0));
        widget_3->setMaximumSize(QSize(800, 135));
        horizontalLayout_7 = new QHBoxLayout(widget_3);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        widget_7 = new QWidget(widget_3);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_8 = new QHBoxLayout(widget_7);
        horizontalLayout_8->setSpacing(25);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(50, 10, 50, 10);
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


        horizontalLayout_7->addWidget(widget_7);

        widget_8 = new QWidget(widget_3);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setMaximumSize(QSize(553, 16777215));
        horizontalLayout_9 = new QHBoxLayout(widget_8);
        horizontalLayout_9->setSpacing(50);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(9, 9, -1, -1);
        label = new QLabel(widget_8);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_9->addWidget(label);

        statusLabel = new QLabel(widget_8);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setMinimumSize(QSize(20, 0));
        statusLabel->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_9->addWidget(statusLabel);


        horizontalLayout_7->addWidget(widget_8);

        widget_9 = new QWidget(widget_3);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setMinimumSize(QSize(200, 0));
        horizontalLayout_11 = new QHBoxLayout(widget_9);
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(50, 0, 0, 0);
        pushButton_4 = new QPushButton(widget_9);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(32, 32));
        pushButton_4->setMaximumSize(QSize(32, 32));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/res/icone3.jpg.png"), QSize(), QIcon::Normal, QIcon::Off);
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
        employe->setGeometry(QRect(10, 140, 230, 420));
        employe->setMinimumSize(QSize(230, 420));
        employe->setMaximumSize(QSize(150, 600));
        employe->setFrameShape(QFrame::NoFrame);
        frame_3 = new QFrame(employe);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(0, 0, 151, 41));
        frame_3->setMaximumSize(QSize(200, 16777215));
        frame_3->setFrameShape(QFrame::NoFrame);
        lineEdit_3 = new QLineEdit(frame_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(10, 4, 131, 31));
        QFont font4;
        font4.setPointSize(9);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setStrikeOut(false);
        lineEdit_3->setFont(font4);
        label_5 = new QLabel(employe);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 50, 49, 16));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(true);
        label_5->setFont(font5);
        id = new QLineEdit(employe);
        id->setObjectName(QString::fromUtf8("id"));
        id->setGeometry(QRect(30, 70, 171, 22));
        label_6 = new QLabel(employe);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 100, 49, 16));
        label_6->setFont(font5);
        nom = new QLineEdit(employe);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(30, 120, 171, 22));
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(false);
        nom->setFont(font6);
        label_7 = new QLabel(employe);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 150, 181, 16));
        label_7->setFont(font5);
        label_8 = new QLabel(employe);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 200, 49, 16));
        label_8->setFont(font5);
        prix = new QLineEdit(employe);
        prix->setObjectName(QString::fromUtf8("prix"));
        prix->setGeometry(QRect(30, 220, 171, 22));
        label_9 = new QLabel(employe);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 250, 111, 16));
        label_9->setFont(font5);
        label_10 = new QLabel(employe);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 300, 91, 16));
        label_10->setFont(font5);
        quantite = new QLineEdit(employe);
        quantite->setObjectName(QString::fromUtf8("quantite"));
        quantite->setGeometry(QRect(30, 320, 171, 22));
        add = new QPushButton(employe);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(30, 360, 75, 24));
        add->setFont(font5);
        edit = new QPushButton(employe);
        edit->setObjectName(QString::fromUtf8("edit"));
        edit->setGeometry(QRect(120, 360, 81, 24));
        edit->setFont(font5);
        date_e = new QDateEdit(employe);
        date_e->setObjectName(QString::fromUtf8("date_e"));
        date_e->setGeometry(QRect(30, 270, 171, 29));
        date_p = new QDateEdit(employe);
        date_p->setObjectName(QString::fromUtf8("date_p"));
        date_p->setGeometry(QRect(30, 170, 171, 29));
        frame_4 = new QFrame(mainbody);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(260, 180, 501, 31));
        frame_4->setFrameShape(QFrame::NoFrame);
        label_11 = new QLabel(frame_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 0, 25, 25));
        label_11->setMinimumSize(QSize(25, 25));
        label_11->setMaximumSize(QSize(25, 25));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/res/icone8")));
        label_11->setScaledContents(true);
        comboBox = new QComboBox(frame_4);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(30, 6, 131, 16));
        comboBox->setFont(font3);
        lineEdit_10 = new QLineEdit(frame_4);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(190, 0, 211, 30));
        QFont font7;
        font7.setPointSize(9);
        font7.setBold(false);
        lineEdit_10->setFont(font7);
        pushButton = new QPushButton(frame_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(410, 3, 80, 24));
        frame_8 = new QFrame(mainbody);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setGeometry(QRect(260, 220, 501, 31));
        frame_8->setFrameShape(QFrame::NoFrame);
        lineEdit_20 = new QLineEdit(frame_8);
        lineEdit_20->setObjectName(QString::fromUtf8("lineEdit_20"));
        lineEdit_20->setGeometry(QRect(30, 0, 261, 31));
        QFont font8;
        font8.setPointSize(9);
        lineEdit_20->setFont(font8);
        pushButton_11 = new QPushButton(frame_8);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(0, 0, 32, 32));
        pushButton_11->setMinimumSize(QSize(32, 32));
        pushButton_11->setMaximumSize(QSize(32, 32));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/res/icone9"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon9);
        comboBox_2 = new QComboBox(frame_8);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(309, 0, 191, 31));
        supp = new QLineEdit(mainbody);
        supp->setObjectName(QString::fromUtf8("supp"));
        supp->setGeometry(QRect(270, 530, 141, 21));
        supp->setFont(font5);
        supp_button = new QPushButton(mainbody);
        supp_button->setObjectName(QString::fromUtf8("supp_button"));
        supp_button->setGeometry(QRect(450, 520, 91, 31));
        supp_button->setFont(font5);
        pushButton_13 = new QPushButton(mainbody);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(380, 80, 75, 41));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/res/icone10"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon10);
        pushButton_13->setIconSize(QSize(32, 32));
        pushButton_14 = new QPushButton(mainbody);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setGeometry(QRect(480, 80, 71, 41));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/res/icone11"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon11);
        pushButton_14->setIconSize(QSize(32, 32));
        label_23 = new QLabel(mainbody);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(680, 50, 51, 91));
        label_23->setPixmap(QPixmap(QString::fromUtf8(":/res/icone16")));
        label_24 = new QLabel(mainbody);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(620, 60, 49, 71));
        label_24->setPixmap(QPixmap(QString::fromUtf8(":/res/icone18")));
        label_25 = new QLabel(mainbody);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(380, 130, 101, 20));
        label_25->setFont(font5);
        label_26 = new QLabel(mainbody);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(480, 130, 101, 16));
        label_26->setFont(font5);
        tableView = new QTableView(mainbody);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(260, 260, 501, 251));
        tableView->setStyleSheet(QString::fromUtf8(""));
        pushButton_2 = new QPushButton(mainbody);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(639, 149, 121, 24));
        QFont font9;
        font9.setPointSize(13);
        font9.setBold(true);
        pushButton_2->setFont(font9);
        lineEdit = new QLineEdit(mainbody);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(250, 90, 113, 24));
        QFont font10;
        font10.setPointSize(12);
        font10.setBold(true);
        lineEdit->setFont(font10);
        pushButton_5 = new QPushButton(mainbody);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(650, 520, 101, 31));
        pushButton_5->setFont(font10);
        pushButton_noNotif = new QPushButton(mainbody);
        pushButton_noNotif->setObjectName(QString::fromUtf8("pushButton_noNotif"));
        pushButton_noNotif->setGeometry(QRect(710, 5, 61, 51));
        pushButton_noNotif->setStyleSheet(QString::fromUtf8("image: url(:/new/notif/images1ring.png);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 255));\n"
"selection-background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(255, 255, 255);"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/img32/images1ring.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_noNotif->setIcon(icon12);
        pushButton_Notif = new QPushButton(mainbody);
        pushButton_Notif->setObjectName(QString::fromUtf8("pushButton_Notif"));
        pushButton_Notif->setGeometry(QRect(710, 5, 61, 51));
        pushButton_Notif->setStyleSheet(QString::fromUtf8("image: url(:/new/ring/images2ring.png);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 255));\n"
"selection-background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(255, 255, 255);"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/imggg33/images2ring.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Notif->setIcon(icon13);
        pushButton_Notif->setIconSize(QSize(50, 50));
        pushButton_6 = new QPushButton(mainbody);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 60, 121, 31));

        retranslateUi(medicament_UI);

        QMetaObject::connectSlotsByName(medicament_UI);
    } // setupUi

    void retranslateUi(QDialog *medicament_UI)
    {
        medicament_UI->setWindowTitle(QCoreApplication::translate("medicament_UI", "Dialog", nullptr));
        logo->setText(QString());
        label_3->setText(QCoreApplication::translate("medicament_UI", "MedicaPRO", nullptr));
        pushButton_16->setText(QCoreApplication::translate("medicament_UI", "Menu", nullptr));
        pushButton_17->setText(QCoreApplication::translate("medicament_UI", "Employ\303\251", nullptr));
        pushButton_18->setText(QCoreApplication::translate("medicament_UI", "M\303\251dicaments", nullptr));
        pushButton_19->setText(QCoreApplication::translate("medicament_UI", "Fournisseurs", nullptr));
        pushButton_20->setText(QCoreApplication::translate("medicament_UI", "Ordonnances", nullptr));
        pushButton_21->setText(QCoreApplication::translate("medicament_UI", "Financi\303\250res", nullptr));
        pushButton_22->setText(QCoreApplication::translate("medicament_UI", "Se d\303\251connecter", nullptr));
        pushButton_3->setText(QString());
        label_12->setText(QString());
        label->setText(QCoreApplication::translate("medicament_UI", "     Arduino :", nullptr));
        statusLabel->setText(QString());
        pushButton_4->setText(QString());
        pushButton_15->setText(QString());
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("medicament_UI", "Ajouter medicament", nullptr));
        label_5->setText(QCoreApplication::translate("medicament_UI", "ID", nullptr));
        id->setPlaceholderText(QCoreApplication::translate("medicament_UI", "id...", nullptr));
        label_6->setText(QCoreApplication::translate("medicament_UI", "Nom", nullptr));
        nom->setPlaceholderText(QCoreApplication::translate("medicament_UI", "nom...", nullptr));
        label_7->setText(QCoreApplication::translate("medicament_UI", " Date de p\303\251remption", nullptr));
        label_8->setText(QCoreApplication::translate("medicament_UI", "Prix", nullptr));
        prix->setPlaceholderText(QCoreApplication::translate("medicament_UI", "prix...", nullptr));
        label_9->setText(QCoreApplication::translate("medicament_UI", "Date d'entr\303\251", nullptr));
        label_10->setText(QCoreApplication::translate("medicament_UI", "Quantit\303\251", nullptr));
        quantite->setText(QString());
        quantite->setPlaceholderText(QCoreApplication::translate("medicament_UI", "quantit\303\251...", nullptr));
        add->setText(QCoreApplication::translate("medicament_UI", "Valider", nullptr));
        edit->setText(QCoreApplication::translate("medicament_UI", "Modifier", nullptr));
        label_11->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("medicament_UI", "ID", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("medicament_UI", "Nom", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("medicament_UI", "Quantite", nullptr));

        lineEdit_10->setText(QString());
        lineEdit_10->setPlaceholderText(QCoreApplication::translate("medicament_UI", "chercher m\303\251decament...", nullptr));
        pushButton->setText(QCoreApplication::translate("medicament_UI", "Recherche", nullptr));
        lineEdit_20->setPlaceholderText(QCoreApplication::translate("medicament_UI", "Trier  la liste des medicaments par leur:", nullptr));
        pushButton_11->setText(QString());
        comboBox_2->setItemText(0, QCoreApplication::translate("medicament_UI", "prix croissants", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("medicament_UI", "prix decroissants", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("medicament_UI", "nom decroissants", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("medicament_UI", "nom croissants", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("medicament_UI", "quantite croissants", nullptr));
        comboBox_2->setItemText(5, QCoreApplication::translate("medicament_UI", "quantite decroissants", nullptr));

        supp->setPlaceholderText(QCoreApplication::translate("medicament_UI", "Id...", nullptr));
        supp_button->setText(QCoreApplication::translate("medicament_UI", "Supprimer", nullptr));
        pushButton_13->setText(QString());
        pushButton_14->setText(QString());
        label_23->setText(QString());
        label_24->setText(QString());
        label_25->setText(QCoreApplication::translate("medicament_UI", "Exportation", nullptr));
        label_26->setText(QCoreApplication::translate("medicament_UI", "Statistiques", nullptr));
#if QT_CONFIG(tooltip)
        tableView->setToolTip(QCoreApplication::translate("medicament_UI", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_2->setText(QCoreApplication::translate("medicament_UI", "Rafreshir", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("medicament_UI", "id...", nullptr));
        pushButton_5->setText(QCoreApplication::translate("medicament_UI", "QR Code", nullptr));
        pushButton_noNotif->setText(QString());
        pushButton_Notif->setText(QString());
        pushButton_6->setText(QCoreApplication::translate("medicament_UI", "liste incendie", nullptr));
    } // retranslateUi

};

namespace Ui {
    class medicament_UI: public Ui_medicament_UI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDICAMENT_UI_H
