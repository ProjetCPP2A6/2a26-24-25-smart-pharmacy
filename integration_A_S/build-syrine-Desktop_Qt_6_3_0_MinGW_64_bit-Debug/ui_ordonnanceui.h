/********************************************************************************
** Form generated from reading UI file 'ordonnanceui.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDONNANCEUI_H
#define UI_ORDONNANCEUI_H

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

class Ui_ordonnanceUI
{
public:
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
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLineEdit *id;
    QLabel *label_6;
    QLineEdit *nomp;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *prix;
    QLabel *label_10;
    QLineEdit *medecin;
    QPushButton *pushButton_add;
    QPushButton *pushButton_edit;
    QDateEdit *datep;
    QFrame *frame_4;
    QLineEdit *lineEdit_10;
    QLabel *label_11;
    QComboBox *comboBox;
    QPushButton *pushButton_5;
    QFrame *frame_8;
    QPushButton *pushButton_11;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit_del;
    QPushButton *pushButton_del;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QTableView *tableView_o;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit_pdf;
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

    void setupUi(QDialog *ordonnanceUI)
    {
        if (ordonnanceUI->objectName().isEmpty())
            ordonnanceUI->setObjectName(QString::fromUtf8("ordonnanceUI"));
        ordonnanceUI->resize(977, 562);
        ordonnanceUI->setStyleSheet(QString::fromUtf8("* {\n"
"    color: #000;\n"
"    border: none;\n"
"}\n"
"ordonnanceUI {\n"
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
"  "
                        "  background-color: #cecece;\n"
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
"#nomp {\n"
"    background: #ffffff;\n"
"}\n"
"#label_6 {\n"
"    color: #000;\n"
"    border: #000;\n"
"}\n"
"#prix {\n"
"    background: #ffffff;\n"
"}\n"
"#label_7 {\n"
"    color: #000;\n"
"    border: #000;\n"
"}\n"
"#medecin {\n"
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
"#pushButton_add {\n"
"    border-radius: 10px;\n"
"    border: 3px solid #2596be;\n"
"}\n"
"#pushButton_4 {\n"
"    border-radius: 10px;\n"
"    border: 3px solid #2596be;\n"
"}\n"
"#pushButton_14{\n"
"    border-radius: 15px;\n"
"    border: 3px solid #2596be;\n"
"}\n"
"#pushButton_13{\n"
"    border-radius: 15px;\n"
"    border: 3px solid #4cd814;\n"
"}\n"
"#retour{\n"
"    border-radius: 10px;\n"
"    border: 3px solid #2596be;\n"
"}\n"
"#pushButton_edit {\n"
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
""
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
"#stackedWidget{\n"
"    background-color: #2596be;\n"
"	color: #000;\n"
"}\n"
"#frame_8 {\n"
"    border-radius: 10px;\n"
"    border: 1px solid #2596be;\n"
"}\n"
"#tableView_o {\n"
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
"#pushButton_2 {\n"
"    border-radius"
                        ": 7px;\n"
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
"    border: 1px"
                        " solid #ffffff;\n"
"    color: #000;\n"
"}\n"
"#pushButton_20 {\n"
"    background-color: #fefeff;\n"
"    padding: 5px;\n"
"    text-align: left;\n"
"    border-top-left-radius: 20px;\n"
"}\n"
"#pushButton_22 {\n"
"    color: #4cd814;\n"
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
"#labe"
                        "l_8{\n"
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
"    border-radius: 10px;\n"
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
        mainbody = new QWidget(ordonnanceUI);
        mainbody->setObjectName(QString::fromUtf8("mainbody"));
        mainbody->setGeometry(QRect(200, 0, 781, 565));
        QFont font;
        font.setBold(false);
        mainbody->setFont(font);
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
        horizontalLayout_8->setSpacing(7);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(10, 10, 10, 10);
        pushButton_3 = new QPushButton(widget_7);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/icone1.jog.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon);
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
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(9, 9, -1, -1);
        frame_2 = new QFrame(widget_8);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(250, 0));
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/icone3.jpg.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon1);
        pushButton_4->setIconSize(QSize(32, 32));

        horizontalLayout_11->addWidget(pushButton_4);

        pushButton_15 = new QPushButton(widget_9);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/icone20"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_15->setIcon(icon2);

        horizontalLayout_11->addWidget(pushButton_15);


        horizontalLayout_7->addWidget(widget_9);

        employe = new QFrame(mainbody);
        employe->setObjectName(QString::fromUtf8("employe"));
        employe->setGeometry(QRect(10, 130, 230, 420));
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
        lineEdit_3->setGeometry(QRect(10, 0, 151, 41));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setStrikeOut(false);
        lineEdit_3->setFont(font1);
        label_5 = new QLabel(employe);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 50, 49, 16));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        label_5->setFont(font2);
        id = new QLineEdit(employe);
        id->setObjectName(QString::fromUtf8("id"));
        id->setGeometry(QRect(30, 70, 171, 22));
        label_6 = new QLabel(employe);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 100, 121, 16));
        label_6->setFont(font2);
        nomp = new QLineEdit(employe);
        nomp->setObjectName(QString::fromUtf8("nomp"));
        nomp->setGeometry(QRect(30, 120, 171, 22));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        nomp->setFont(font3);
        label_7 = new QLabel(employe);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 150, 181, 16));
        label_7->setFont(font2);
        label_8 = new QLabel(employe);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 210, 49, 16));
        label_8->setFont(font2);
        prix = new QLineEdit(employe);
        prix->setObjectName(QString::fromUtf8("prix"));
        prix->setGeometry(QRect(30, 230, 171, 22));
        label_10 = new QLabel(employe);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 260, 181, 16));
        label_10->setFont(font2);
        medecin = new QLineEdit(employe);
        medecin->setObjectName(QString::fromUtf8("medecin"));
        medecin->setGeometry(QRect(30, 290, 171, 22));
        pushButton_add = new QPushButton(employe);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setGeometry(QRect(20, 360, 75, 24));
        pushButton_add->setFont(font2);
        pushButton_edit = new QPushButton(employe);
        pushButton_edit->setObjectName(QString::fromUtf8("pushButton_edit"));
        pushButton_edit->setGeometry(QRect(130, 360, 75, 24));
        pushButton_edit->setFont(font2);
        datep = new QDateEdit(employe);
        datep->setObjectName(QString::fromUtf8("datep"));
        datep->setGeometry(QRect(30, 170, 171, 29));
        frame_4 = new QFrame(mainbody);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(260, 170, 501, 31));
        frame_4->setFrameShape(QFrame::NoFrame);
        lineEdit_10 = new QLineEdit(frame_4);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(30, 0, 301, 31));
        QFont font4;
        font4.setPointSize(13);
        font4.setBold(false);
        lineEdit_10->setFont(font4);
        label_11 = new QLabel(frame_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(0, 3, 25, 25));
        label_11->setMinimumSize(QSize(25, 25));
        label_11->setMaximumSize(QSize(25, 25));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/res/icone8")));
        label_11->setScaledContents(true);
        comboBox = new QComboBox(frame_4);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(330, 6, 91, 20));
        QFont font5;
        font5.setBold(true);
        comboBox->setFont(font5);
        comboBox->setStyleSheet(QString::fromUtf8("#comboBox{\n"
"	background-color: transparent;\n"
"	border-radius: 10px;\n"
"	border: 2px solid  transparent;\n"
"    color: #FF0000;\n"
"}"));
        pushButton_5 = new QPushButton(frame_4);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(420, 0, 81, 31));
        pushButton_5->setStyleSheet(QString::fromUtf8("#pushButton_5 {\n"
"    border-radius: 7px;\n"
"    border: 2px solid #000;\n"
"    background: #ffffff;\n"
"}"));
        frame_8 = new QFrame(mainbody);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setGeometry(QRect(260, 210, 501, 31));
        frame_8->setFrameShape(QFrame::NoFrame);
        pushButton_11 = new QPushButton(frame_8);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(0, 0, 32, 32));
        pushButton_11->setMinimumSize(QSize(32, 32));
        pushButton_11->setMaximumSize(QSize(32, 32));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/icone9"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon3);
        comboBox_2 = new QComboBox(frame_8);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(30, 0, 461, 31));
        comboBox_2->setFont(font4);
        lineEdit_del = new QLineEdit(mainbody);
        lineEdit_del->setObjectName(QString::fromUtf8("lineEdit_del"));
        lineEdit_del->setGeometry(QRect(570, 530, 113, 21));
        lineEdit_del->setFont(font2);
        lineEdit_del->setStyleSheet(QString::fromUtf8("#lineEdit_del{\n"
"	background-color: transparent;\n"
"	border-radius: 10px;\n"
"	border: 2px solid  transparent;\n"
"    color: 4cd814;\n"
"}"));
        pushButton_del = new QPushButton(mainbody);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));
        pushButton_del->setGeometry(QRect(640, 523, 91, 31));
        pushButton_del->setFont(font2);
        pushButton_del->setStyleSheet(QString::fromUtf8("#pushButton_del{\n"
"	background-color: transparent;\n"
"	border-radius: 10px;\n"
"	border: 2px solid  transparent;\n"
"    color: #FF0000;\n"
"}"));
        pushButton_13 = new QPushButton(mainbody);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(310, 70, 75, 41));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/res/icone10"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon4);
        pushButton_13->setIconSize(QSize(32, 32));
        pushButton_14 = new QPushButton(mainbody);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setGeometry(QRect(440, 70, 71, 41));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/res/icone11"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon5);
        pushButton_14->setIconSize(QSize(32, 32));
        label_23 = new QLabel(mainbody);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(690, 50, 51, 91));
        label_23->setPixmap(QPixmap(QString::fromUtf8(":/res/icone16")));
        label_24 = new QLabel(mainbody);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(630, 60, 49, 71));
        label_24->setPixmap(QPixmap(QString::fromUtf8(":/res/icone18")));
        label_25 = new QLabel(mainbody);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(310, 120, 101, 20));
        label_25->setFont(font2);
        label_26 = new QLabel(mainbody);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(440, 120, 101, 16));
        label_26->setFont(font2);
        tableView_o = new QTableView(mainbody);
        tableView_o->setObjectName(QString::fromUtf8("tableView_o"));
        tableView_o->setGeometry(QRect(250, 260, 521, 251));
        pushButton = new QPushButton(mainbody);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 530, 80, 24));
        pushButton_2 = new QPushButton(mainbody);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 530, 80, 24));
        pushButton_6 = new QPushButton(mainbody);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(649, 140, 111, 24));
        lineEdit_pdf = new QLineEdit(mainbody);
        lineEdit_pdf->setObjectName(QString::fromUtf8("lineEdit_pdf"));
        lineEdit_pdf->setGeometry(QRect(200, 80, 111, 24));
        lineEdit_pdf->setFont(font5);
        lineEdit_pdf->setStyleSheet(QString::fromUtf8("#lineEdit_pdf{\n"
"	background-color: transparent;\n"
"	border-radius: 10px;\n"
"	border: 2px solid  transparent;\n"
"    color: 4cd814;\n"
"}"));
        leftmenu = new QWidget(ordonnanceUI);
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
        frame_10->setGeometry(QRect(0, 0, 160, 61));
        frame_10->setFrameShape(QFrame::NoFrame);
        logo = new QLabel(frame_10);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(0, 10, 51, 41));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/res/image22")));
        label_3 = new QLabel(frame_10);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(true);
        label_3->setGeometry(QRect(60, 20, 101, 31));
        QFont font6;
        font6.setPointSize(13);
        font6.setBold(true);
        font6.setItalic(true);
        label_3->setFont(font6);
        pushButton_16 = new QPushButton(frame_11);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setGeometry(QRect(40, 70, 75, 24));
        QFont font7;
        font7.setPointSize(10);
        font7.setBold(true);
        font7.setItalic(true);
        pushButton_16->setFont(font7);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/res/icone23"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_16->setIcon(icon6);
        pushButton_17 = new QPushButton(frame_11);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        pushButton_17->setGeometry(QRect(30, 110, 101, 41));
        QFont font8;
        font8.setPointSize(10);
        font8.setBold(true);
        font8.setItalic(true);
        font8.setUnderline(false);
        pushButton_17->setFont(font8);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/res/icone27"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_17->setIcon(icon7);
        pushButton_18 = new QPushButton(frame_11);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        pushButton_18->setGeometry(QRect(20, 160, 121, 31));
        pushButton_18->setFont(font8);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/res/icone26"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_18->setIcon(icon8);
        pushButton_19 = new QPushButton(frame_11);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        pushButton_19->setGeometry(QRect(0, 213, 171, 31));
        pushButton_19->setFont(font7);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/res/icone25"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_19->setIcon(icon9);
        pushButton_20 = new QPushButton(frame_11);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));
        pushButton_20->setGeometry(QRect(0, 260, 181, 31));
        pushButton_20->setFont(font7);
        pushButton_20->setIcon(icon6);
        pushButton_21 = new QPushButton(frame_11);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));
        pushButton_21->setGeometry(QRect(20, 310, 121, 24));
        pushButton_21->setFont(font7);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/res/icone24"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_21->setIcon(icon10);
        pushButton_22 = new QPushButton(frame_11);
        pushButton_22->setObjectName(QString::fromUtf8("pushButton_22"));
        pushButton_22->setGeometry(QRect(10, 470, 151, 41));
        pushButton_22->setFont(font7);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/res/icone30"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_22->setIcon(icon11);

        verticalLayout_2->addWidget(frame_11);


        verticalLayout->addWidget(frame_9);


        retranslateUi(ordonnanceUI);

        QMetaObject::connectSlotsByName(ordonnanceUI);
    } // setupUi

    void retranslateUi(QDialog *ordonnanceUI)
    {
        ordonnanceUI->setWindowTitle(QCoreApplication::translate("ordonnanceUI", "Dialog", nullptr));
        pushButton_3->setText(QString());
        label_12->setText(QString());
        label_4->setText(QString());
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("ordonnanceUI", "Recherche", nullptr));
        pushButton_4->setText(QString());
        pushButton_15->setText(QString());
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("ordonnanceUI", "Ajouter ordonnance", nullptr));
        label_5->setText(QCoreApplication::translate("ordonnanceUI", "ID", nullptr));
        id->setPlaceholderText(QCoreApplication::translate("ordonnanceUI", "id...", nullptr));
        label_6->setText(QCoreApplication::translate("ordonnanceUI", " Nom  patient", nullptr));
        nomp->setPlaceholderText(QCoreApplication::translate("ordonnanceUI", "nom...", nullptr));
        label_7->setText(QCoreApplication::translate("ordonnanceUI", " Date prescription", nullptr));
        label_8->setText(QCoreApplication::translate("ordonnanceUI", "Prix", nullptr));
        prix->setPlaceholderText(QCoreApplication::translate("ordonnanceUI", "prix...", nullptr));
        label_10->setText(QCoreApplication::translate("ordonnanceUI", "M\303\251decin prescripteur", nullptr));
        medecin->setText(QString());
        medecin->setPlaceholderText(QCoreApplication::translate("ordonnanceUI", "quantit\303\251...", nullptr));
        pushButton_add->setText(QCoreApplication::translate("ordonnanceUI", "ajouer", nullptr));
        pushButton_edit->setText(QCoreApplication::translate("ordonnanceUI", "editer", nullptr));
        lineEdit_10->setText(QString());
        lineEdit_10->setPlaceholderText(QCoreApplication::translate("ordonnanceUI", "chercher m\303\251decament...", nullptr));
        label_11->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("ordonnanceUI", "ID", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("ordonnanceUI", "Nom", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("ordonnanceUI", "Medecin", nullptr));

        pushButton_5->setText(QCoreApplication::translate("ordonnanceUI", "Search", nullptr));
        pushButton_11->setText(QString());
        comboBox_2->setItemText(0, QCoreApplication::translate("ordonnanceUI", "prix croissants", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("ordonnanceUI", "prix decroissants", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("ordonnanceUI", "nomp decroissants", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("ordonnanceUI", "nomp croissants", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("ordonnanceUI", "datep decroissants", nullptr));
        comboBox_2->setItemText(5, QCoreApplication::translate("ordonnanceUI", "datep croissants", nullptr));

        lineEdit_del->setPlaceholderText(QCoreApplication::translate("ordonnanceUI", "Identifiant", nullptr));
        pushButton_del->setText(QCoreApplication::translate("ordonnanceUI", "Supprimer", nullptr));
        pushButton_13->setText(QString());
        pushButton_14->setText(QString());
        label_23->setText(QString());
        label_24->setText(QString());
        label_25->setText(QCoreApplication::translate("ordonnanceUI", "Exportation", nullptr));
        label_26->setText(QCoreApplication::translate("ordonnanceUI", "Statistiques", nullptr));
        pushButton->setText(QCoreApplication::translate("ordonnanceUI", "MP3", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ordonnanceUI", "MP4", nullptr));
        pushButton_6->setText(QCoreApplication::translate("ordonnanceUI", "refresh", nullptr));
        lineEdit_pdf->setPlaceholderText(QCoreApplication::translate("ordonnanceUI", "id ordonance pdf", nullptr));
        logo->setText(QString());
        label_3->setText(QCoreApplication::translate("ordonnanceUI", "MedicaPRO", nullptr));
        pushButton_16->setText(QCoreApplication::translate("ordonnanceUI", "Menu", nullptr));
        pushButton_17->setText(QCoreApplication::translate("ordonnanceUI", "Employ\303\251", nullptr));
        pushButton_18->setText(QCoreApplication::translate("ordonnanceUI", "M\303\251dicaments", nullptr));
        pushButton_19->setText(QCoreApplication::translate("ordonnanceUI", "Fournisseurs", nullptr));
        pushButton_20->setText(QCoreApplication::translate("ordonnanceUI", "Ordonnances", nullptr));
        pushButton_21->setText(QCoreApplication::translate("ordonnanceUI", "Financi\303\250res", nullptr));
        pushButton_22->setText(QCoreApplication::translate("ordonnanceUI", "Se d\303\251connecter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ordonnanceUI: public Ui_ordonnanceUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDONNANCEUI_H
