/********************************************************************************
** Form generated from reading UI file 'transactionui.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSACTIONUI_H
#define UI_TRANSACTIONUI_H

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

class Ui_transactionUI
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
    QFrame *transaction;
    QLabel *label_5;
    QLineEdit *id;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *montant;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *description;
    QLabel *label_10;
    QLineEdit *categorie;
    QPushButton *ajouter;
    QPushButton *editer;
    QComboBox *type;
    QLineEdit *lineEdit_7;
    QLineEdit *modepaiment;
    QFrame *frame_3;
    QLineEdit *lineEdit_3;
    QDateEdit *dateEdit;
    QFrame *frame_4;
    QLineEdit *lineEdit_10;
    QLabel *label_11;
    QLineEdit *linrech;
    QPushButton *pushButton;
    QFrame *frame_8;
    QLineEdit *lineEdit_20;
    QPushButton *pushButton_11;
    QPushButton *pushButton_2;
    QLineEdit *idsupp;
    QPushButton *supp;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QTableView *tableView;
    QLabel *labelcombo;
    QWidget *leftmenu;
    QVBoxLayout *verticalLayout;
    QFrame *frame_9;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_11;
    QFrame *frame_10;
    QLabel *logo;
    QLabel *label_3;
    QPushButton *menu;
    QPushButton *finance;
    QPushButton *medica;
    QPushButton *fourni;
    QPushButton *ordo;
    QPushButton *empl;
    QPushButton *quitter;

    void setupUi(QDialog *transactionUI)
    {
        if (transactionUI->objectName().isEmpty())
            transactionUI->setObjectName("transactionUI");
        transactionUI->resize(871, 572);
        transactionUI->setStyleSheet(QString::fromUtf8("*{\n"
"	color: #000;\n"
"	border: none;\n"
"}\n"
"#centralwidget{\n"
"	background-color: #eff99fe\n"
"}\n"
"#leftmenu{\n"
"	background-color: #2596be;\n"
"}\n"
"QLineEdit{\n"
"	background: transparent;\n"
"}\n"
"QFrame{\n"
"	border-radius: 10px;\n"
"	border: 2px solid #2596be;\n"
"}\n"
"QLabel{\n"
"	color: #2596be;\n"
"}\n"
"#employe{\n"
"	background-color: #cecece;\n"
"}\n"
"lineEdit_2{\n"
"	background: transparent;\n"
"}\n"
"#label_3{\n"
"	color: #000;\n"
"	border: #000;\n"
"}\n"
"#lineEdit_3{\n"
"	background: #ffffff;\n"
"	background: transparent;\n"
"}\n"
"#label_4{\n"
"	color: #000;\n"
"	border: #000;\n"
"}\n"
"#lineEdit_4{\n"
"	background: #ffffff;\n"
"}\n"
"#label_5{\n"
"	color: #000;\n"
"	border: #000;\n"
"}\n"
"#lineEdit_5{\n"
"	background: #ffffff;\n"
"}\n"
"#label_6{\n"
"	color: #000;\n"
"	border: #000;\n"
"}\n"
"#lineEdit_6{\n"
"	background: #ffffff;\n"
"}\n"
"#label_7{\n"
"	color: #000;\n"
"	border: #000;\n"
"}\n"
"#lineEdit_7{\n"
"	background: #ffffff;\n"
"}\n"
"#label_8{\n"
"	color: #000;\n"
"	b"
                        "order: #000;\n"
"}\n"
"#lineEdit_8{\n"
"	background: #ffffff;\n"
"}\n"
"#label_9{\n"
"	color: #000;\n"
"	border: #000;\n"
"}\n"
"#lineEdit_9{\n"
"	background: #ffffff;\n"
"}\n"
"#label_10{\n"
"	color: #000;\n"
"	border: #000;\n"
"}\n"
"#pushButton_3{\n"
"	border-radius: 10px;\n"
"	border: 3px solid  #2596be;\n"
"}\n"
"#pushButton_4{\n"
"	border-radius: 10px;\n"
"	border: 3px solid  #2596be;\n"
"}\n"
"#pushButton_5{\n"
"	border-radius: 10px;\n"
"	border: 3px solid  #2596be;\n"
"}\n"
"#pushButton_6{\n"
"	border-radius: 10px;\n"
"	border: 3px solid  #2596be;\n"
"}\n"
"#label_11{\n"
"	border: #000;\n"
"}\n"
"#label_12{\n"
"	border: #000;\n"
"}\n"
"#label_23{\n"
"	border: #000;\n"
"}\n"
"#frame_4{\n"
"	border-radius: 10px;\n"
"	border: 1px solid #2596be;\n"
"}\n"
"#LineEdit_10{\n"
"	background: #CECECE;\n"
"}\n"
"#widget_3{\n"
"	background-color: #fefeff;\n"
"}\n"
"#mainbody{\n"
"	background-color: #ffffff;\n"
"}\n"
"#frame_8{\n"
"	border-radius: 10px;\n"
"	border: 1px solid #2596be;\n"
"}\n"
"#affichage{\n"
"	back"
                        "ground-color: #2596be;\n"
"}\n"
"#lineEdit_21{\n"
"	border-radius: 6px;\n"
"	border: 1px solid  #4cd814;\n"
"	background: #fffff;\n"
"}\n"
"#pushButton_12{\n"
"	border-radius: 10px;\n"
"	border: 2px solid  #090909;\n"
"	background: #fffff;\n"
"}\n"
"#pushButton_13{\n"
"	border-radius: 20px;\n"
"	border: 2px solid  #4cd814;\n"
"	background: #fffff;\n"
"}\n"
"#pushButton_14{\n"
"	border-radius: 20px;\n"
"	border: 2px solid  #2596be;\n"
"	background: #fffff;\n"
"}\n"
"#label_24{\n"
"	color: #000;\n"
"	border: #000;\n"
"}\n"
"#label_25{\n"
"	color: #000;\n"
"	border: #000;\n"
"}\n"
"#label_26{\n"
"	color: #000;\n"
"	border: #000;\n"
"}\n"
"#logo{\n"
"	border-radius: 6px;\n"
"	border: 3px solid  #4cd814;\n"
"	background: #fffff;\n"
"}\n"
"#sous{\n"
"	background-color: #cecece;\n"
"}\n"
"#label_27{\n"
"	border-radius: 1px;\n"
"	border: 1px solid  #ffffff;\n"
"	color: #000;\n"
"}\n"
"#label_28{\n"
"	border-radius: 1px;\n"
"	border: 1px solid  #ffffff;\n"
"	color: #000;\n"
"}\n"
"#label_29{\n"
"	border-radius: 1px;\n"
""
                        "	border: 1px solid  #ffffff;\n"
"	color: #000;\n"
"}\n"
"#label_30{\n"
"	border-radius: 1px;\n"
"	border: 1px solid  #ffffff;\n"
"	color: #000;\n"
"}\n"
"#label_31{\n"
"	border-radius: 1px;\n"
"	border: 1px solid  #ffffff;\n"
"	color: #000;\n"
"}\n"
"#label_32{\n"
"	border-radius: 1px;\n"
"	border: 1px solid  #ffffff;\n"
"	color: #000;\n"
"}\n"
"#pushButton_17{\n"
"	background-color: #fefeff;\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"	border-top-left-radius: 20px;\n"
"}\n"
"#pushButton_22{\n"
"	color: #4cd814;\n"
"}\n"
""));
        mainbody = new QWidget(transactionUI);
        mainbody->setObjectName("mainbody");
        mainbody->setGeometry(QRect(200, 0, 671, 565));
        QFont font;
        font.setBold(false);
        mainbody->setFont(font);
        widget_3 = new QWidget(mainbody);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(0, 0, 671, 50));
        widget_3->setMinimumSize(QSize(400, 0));
        widget_3->setMaximumSize(QSize(800, 135));
        horizontalLayout_7 = new QHBoxLayout(widget_3);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        widget_7 = new QWidget(widget_3);
        widget_7->setObjectName("widget_7");
        horizontalLayout_8 = new QHBoxLayout(widget_7);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        pushButton_3 = new QPushButton(widget_7);
        pushButton_3->setObjectName("pushButton_3");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/icone1.jog.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon);
        pushButton_3->setIconSize(QSize(24, 24));

        horizontalLayout_8->addWidget(pushButton_3);

        label_12 = new QLabel(widget_7);
        label_12->setObjectName("label_12");
        label_12->setMinimumSize(QSize(10, 0));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/res/icone7")));
        label_12->setScaledContents(false);
        label_12->setWordWrap(false);

        horizontalLayout_8->addWidget(label_12);


        horizontalLayout_7->addWidget(widget_7);

        widget_8 = new QWidget(widget_3);
        widget_8->setObjectName("widget_8");
        widget_8->setMaximumSize(QSize(553, 16777215));
        horizontalLayout_9 = new QHBoxLayout(widget_8);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(9, 9, -1, -1);
        frame_2 = new QFrame(widget_8);
        frame_2->setObjectName("frame_2");
        frame_2->setMinimumSize(QSize(250, 0));
        frame_2->setStyleSheet(QString::fromUtf8(""));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_10 = new QHBoxLayout(frame_2);
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(30, 30));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/res/icone2.jpg.png")));
        label_4->setScaledContents(true);

        horizontalLayout_10->addWidget(label_4);

        lineEdit_2 = new QLineEdit(frame_2);
        lineEdit_2->setObjectName("lineEdit_2");

        horizontalLayout_10->addWidget(lineEdit_2);


        horizontalLayout_9->addWidget(frame_2);


        horizontalLayout_7->addWidget(widget_8);

        widget_9 = new QWidget(widget_3);
        widget_9->setObjectName("widget_9");
        widget_9->setMinimumSize(QSize(200, 0));
        horizontalLayout_11 = new QHBoxLayout(widget_9);
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(widget_9);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(32, 32));
        pushButton_4->setMaximumSize(QSize(32, 32));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/icone3.jpg.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon1);
        pushButton_4->setIconSize(QSize(32, 32));

        horizontalLayout_11->addWidget(pushButton_4);

        pushButton_15 = new QPushButton(widget_9);
        pushButton_15->setObjectName("pushButton_15");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/icone20"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_15->setIcon(icon2);

        horizontalLayout_11->addWidget(pushButton_15);


        horizontalLayout_7->addWidget(widget_9);

        transaction = new QFrame(mainbody);
        transaction->setObjectName("transaction");
        transaction->setGeometry(QRect(10, 110, 230, 451));
        transaction->setMinimumSize(QSize(230, 420));
        transaction->setMaximumSize(QSize(150, 600));
        transaction->setStyleSheet(QString::fromUtf8("background-color: rgb(206, 206, 206);"));
        transaction->setFrameShape(QFrame::Shape::StyledPanel);
        transaction->setFrameShadow(QFrame::Shadow::Raised);
        label_5 = new QLabel(transaction);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 50, 91, 16));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        label_5->setFont(font1);
        id = new QLineEdit(transaction);
        id->setObjectName("id");
        id->setGeometry(QRect(30, 70, 171, 22));
        id->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_6 = new QLabel(transaction);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 100, 111, 16));
        label_6->setFont(font1);
        label_7 = new QLabel(transaction);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 150, 131, 16));
        label_7->setFont(font1);
        montant = new QLineEdit(transaction);
        montant->setObjectName("montant");
        montant->setGeometry(QRect(30, 170, 171, 22));
        montant->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_8 = new QLabel(transaction);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 200, 111, 16));
        label_8->setFont(font1);
        label_9 = new QLabel(transaction);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 250, 151, 16));
        label_9->setFont(font1);
        description = new QLineEdit(transaction);
        description->setObjectName("description");
        description->setGeometry(QRect(30, 270, 171, 22));
        description->setStyleSheet(QString::fromUtf8("\n"
"\n"
"background-color: rgb(255, 255, 255);"));
        label_10 = new QLabel(transaction);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 300, 141, 16));
        label_10->setFont(font1);
        categorie = new QLineEdit(transaction);
        categorie->setObjectName("categorie");
        categorie->setGeometry(QRect(30, 320, 171, 22));
        categorie->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 255, 255);"));
        ajouter = new QPushButton(transaction);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(20, 410, 75, 24));
        ajouter->setFont(font1);
        ajouter->setStyleSheet(QString::fromUtf8("background-color :gray;\n"
""));
        editer = new QPushButton(transaction);
        editer->setObjectName("editer");
        editer->setGeometry(QRect(120, 410, 75, 24));
        editer->setFont(font1);
        editer->setStyleSheet(QString::fromUtf8("background-color :gray;"));
        type = new QComboBox(transaction);
        type->addItem(QString());
        type->setObjectName("type");
        type->setGeometry(QRect(30, 220, 171, 22));
        type->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_7 = new QLineEdit(transaction);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(20, 350, 181, 21));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(false);
        lineEdit_7->setFont(font2);
        lineEdit_7->setStyleSheet(QString::fromUtf8("background-color: rgb(206, 206, 206);"));
        modepaiment = new QLineEdit(transaction);
        modepaiment->setObjectName("modepaiment");
        modepaiment->setGeometry(QRect(20, 380, 171, 22));
        modepaiment->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        frame_3 = new QFrame(transaction);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(0, 0, 181, 41));
        frame_3->setMaximumSize(QSize(200, 16777215));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_3 = new QLineEdit(frame_3);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(10, 10, 161, 21));
        lineEdit_3->setFont(font2);
        dateEdit = new QDateEdit(transaction);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(30, 120, 171, 25));
        frame_4 = new QFrame(mainbody);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(250, 150, 411, 51));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_10 = new QLineEdit(frame_4);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(30, 10, 221, 31));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        lineEdit_10->setFont(font3);
        label_11 = new QLabel(frame_4);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(0, 0, 25, 25));
        label_11->setMinimumSize(QSize(25, 25));
        label_11->setMaximumSize(QSize(25, 25));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/res/icone8")));
        label_11->setScaledContents(true);
        linrech = new QLineEdit(frame_4);
        linrech->setObjectName("linrech");
        linrech->setGeometry(QRect(250, 10, 81, 31));
        linrech->setStyleSheet(QString::fromUtf8("color: rgb(206, 206, 206);"));
        pushButton = new QPushButton(frame_4);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(340, 20, 61, 21));
        pushButton->setStyleSheet(QString::fromUtf8("font: 700 9pt \"Segoe UI\";\n"
"background-color :gray;"));
        frame_8 = new QFrame(mainbody);
        frame_8->setObjectName("frame_8");
        frame_8->setGeometry(QRect(250, 210, 411, 41));
        frame_8->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";"));
        frame_8->setFrameShape(QFrame::Shape::StyledPanel);
        frame_8->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_20 = new QLineEdit(frame_8);
        lineEdit_20->setObjectName("lineEdit_20");
        lineEdit_20->setGeometry(QRect(20, 10, 291, 21));
        pushButton_11 = new QPushButton(frame_8);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(0, 10, 32, 32));
        pushButton_11->setMinimumSize(QSize(32, 32));
        pushButton_11->setMaximumSize(QSize(32, 32));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/icone9"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon3);
        pushButton_2 = new QPushButton(frame_8);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(320, 10, 61, 24));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 700 9pt \"Segoe UI\";\n"
"background-color :gray;"));
        idsupp = new QLineEdit(mainbody);
        idsupp->setObjectName("idsupp");
        idsupp->setGeometry(QRect(410, 530, 113, 21));
        idsupp->setFont(font1);
        idsupp->setStyleSheet(QString::fromUtf8("color: rgb(206, 206, 206);"));
        supp = new QPushButton(mainbody);
        supp->setObjectName("supp");
        supp->setGeometry(QRect(540, 523, 91, 31));
        supp->setFont(font1);
        supp->setStyleSheet(QString::fromUtf8("background-color :gray;"));
        pushButton_13 = new QPushButton(mainbody);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(270, 80, 75, 41));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/res/icone10"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon4);
        pushButton_13->setIconSize(QSize(32, 32));
        pushButton_14 = new QPushButton(mainbody);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(360, 80, 71, 41));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/res/icone11"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon5);
        pushButton_14->setIconSize(QSize(32, 32));
        label_23 = new QLabel(mainbody);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(600, 50, 51, 91));
        label_23->setPixmap(QPixmap(QString::fromUtf8(":/res/icone16")));
        label_24 = new QLabel(mainbody);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(540, 60, 49, 71));
        label_24->setPixmap(QPixmap(QString::fromUtf8(":/res/icone18")));
        label_25 = new QLabel(mainbody);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(270, 130, 71, 20));
        label_25->setFont(font1);
        label_26 = new QLabel(mainbody);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(360, 130, 81, 16));
        label_26->setFont(font1);
        tableView = new QTableView(mainbody);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(250, 260, 401, 251));
        labelcombo = new QLabel(mainbody);
        labelcombo->setObjectName("labelcombo");
        labelcombo->setGeometry(QRect(50, 70, 161, 31));
        leftmenu = new QWidget(transactionUI);
        leftmenu->setObjectName("leftmenu");
        leftmenu->setGeometry(QRect(0, 0, 200, 565));
        leftmenu->setMinimumSize(QSize(100, 0));
        leftmenu->setMaximumSize(QSize(200, 16777215));
        verticalLayout = new QVBoxLayout(leftmenu);
        verticalLayout->setObjectName("verticalLayout");
        frame_9 = new QFrame(leftmenu);
        frame_9->setObjectName("frame_9");
        frame_9->setFrameShape(QFrame::Shape::StyledPanel);
        frame_9->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_9);
        verticalLayout_2->setObjectName("verticalLayout_2");
        frame_11 = new QFrame(frame_9);
        frame_11->setObjectName("frame_11");
        frame_11->setFrameShape(QFrame::Shape::StyledPanel);
        frame_11->setFrameShadow(QFrame::Shadow::Raised);
        frame_10 = new QFrame(frame_11);
        frame_10->setObjectName("frame_10");
        frame_10->setGeometry(QRect(0, 0, 160, 61));
        frame_10->setFrameShape(QFrame::Shape::StyledPanel);
        frame_10->setFrameShadow(QFrame::Shadow::Raised);
        logo = new QLabel(frame_10);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(0, 10, 51, 41));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/res/icone21")));
        label_3 = new QLabel(frame_10);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 15, 101, 31));
        QFont font4;
        font4.setPointSize(13);
        font4.setBold(true);
        label_3->setFont(font4);
        menu = new QPushButton(frame_11);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(40, 70, 75, 24));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(true);
        font5.setItalic(true);
        menu->setFont(font5);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/res/icone23"), QSize(), QIcon::Normal, QIcon::Off);
        menu->setIcon(icon6);
        finance = new QPushButton(frame_11);
        finance->setObjectName("finance");
        finance->setGeometry(QRect(0, 330, 161, 31));
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(true);
        font6.setItalic(true);
        font6.setUnderline(false);
        finance->setFont(font6);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/res/icone27"), QSize(), QIcon::Normal, QIcon::Off);
        finance->setIcon(icon7);
        medica = new QPushButton(frame_11);
        medica->setObjectName("medica");
        medica->setGeometry(QRect(20, 170, 111, 24));
        medica->setFont(font6);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/res/icone26"), QSize(), QIcon::Normal, QIcon::Off);
        medica->setIcon(icon8);
        fourni = new QPushButton(frame_11);
        fourni->setObjectName("fourni");
        fourni->setGeometry(QRect(20, 220, 111, 24));
        fourni->setFont(font5);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/res/icone25"), QSize(), QIcon::Normal, QIcon::Off);
        fourni->setIcon(icon9);
        ordo = new QPushButton(frame_11);
        ordo->setObjectName("ordo");
        ordo->setGeometry(QRect(30, 270, 101, 24));
        ordo->setFont(font5);
        ordo->setIcon(icon6);
        empl = new QPushButton(frame_11);
        empl->setObjectName("empl");
        empl->setGeometry(QRect(20, 130, 101, 24));
        empl->setFont(font5);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/res/icone24"), QSize(), QIcon::Normal, QIcon::Off);
        empl->setIcon(icon10);
        quitter = new QPushButton(frame_11);
        quitter->setObjectName("quitter");
        quitter->setGeometry(QRect(20, 460, 121, 41));
        quitter->setFont(font5);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/res/icone30"), QSize(), QIcon::Normal, QIcon::Off);
        quitter->setIcon(icon11);

        verticalLayout_2->addWidget(frame_11);


        verticalLayout->addWidget(frame_9);


        retranslateUi(transactionUI);

        QMetaObject::connectSlotsByName(transactionUI);
    } // setupUi

    void retranslateUi(QDialog *transactionUI)
    {
        transactionUI->setWindowTitle(QCoreApplication::translate("transactionUI", "Dialog", nullptr));
        pushButton_3->setText(QString());
        label_12->setText(QString());
        label_4->setText(QString());
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("transactionUI", "Recherche", nullptr));
        pushButton_4->setText(QString());
        pushButton_15->setText(QString());
        label_5->setText(QCoreApplication::translate("transactionUI", "id_transaction", nullptr));
        id->setText(QString());
        label_6->setText(QCoreApplication::translate("transactionUI", "date_transaction", nullptr));
        label_7->setText(QCoreApplication::translate("transactionUI", "montant_transaction", nullptr));
        label_8->setText(QCoreApplication::translate("transactionUI", "type_transaction", nullptr));
        label_9->setText(QCoreApplication::translate("transactionUI", "description_transaction", nullptr));
        label_10->setText(QCoreApplication::translate("transactionUI", "categorie_transaction", nullptr));
        ajouter->setText(QCoreApplication::translate("transactionUI", "Ajouter", nullptr));
        editer->setText(QCoreApplication::translate("transactionUI", "Editer", nullptr));
        type->setItemText(0, QString());

        lineEdit_7->setText(QCoreApplication::translate("transactionUI", "mode_paiement_transaction", nullptr));
        lineEdit_7->setPlaceholderText(QCoreApplication::translate("transactionUI", "Ajouter un employ\303\251 ", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("transactionUI", "Ajouter une transaction", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("transactionUI", "Ajouter un employ\303\251 ", nullptr));
        lineEdit_10->setText(QCoreApplication::translate("transactionUI", " Recherche d\342\200\231une transaction par id ", nullptr));
        lineEdit_10->setPlaceholderText(QCoreApplication::translate("transactionUI", "Rechercher un employ\303\251 \303\240 partir de son ID", nullptr));
        label_11->setText(QString());
        linrech->setText(QString());
        linrech->setPlaceholderText(QCoreApplication::translate("transactionUI", "id a chercher", " "));
        pushButton->setText(QCoreApplication::translate("transactionUI", "Chercher", nullptr));
        lineEdit_20->setText(QCoreApplication::translate("transactionUI", "Tri des transactions selon le montant et le type ", nullptr));
        lineEdit_20->setPlaceholderText(QCoreApplication::translate("transactionUI", "Trier la liste des employ\303\251s par leur:", nullptr));
        pushButton_11->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("transactionUI", "Trier", nullptr));
        idsupp->setText(QString());
        idsupp->setPlaceholderText(QCoreApplication::translate("transactionUI", "Identifiant", nullptr));
        supp->setText(QCoreApplication::translate("transactionUI", "Supprimer", nullptr));
        pushButton_13->setText(QString());
        pushButton_14->setText(QString());
        label_23->setText(QString());
        label_24->setText(QString());
        label_25->setText(QCoreApplication::translate("transactionUI", "Exportation", nullptr));
        label_26->setText(QCoreApplication::translate("transactionUI", "Statistiques", nullptr));
        labelcombo->setText(QString());
        logo->setText(QString());
        label_3->setText(QCoreApplication::translate("transactionUI", "MedicaPRO", nullptr));
        menu->setText(QCoreApplication::translate("transactionUI", "Menu", nullptr));
        finance->setText(QCoreApplication::translate("transactionUI", "Financi\303\250res", nullptr));
        medica->setText(QCoreApplication::translate("transactionUI", "M\303\251dicaments", nullptr));
        fourni->setText(QCoreApplication::translate("transactionUI", "Fournisseurs", nullptr));
        ordo->setText(QCoreApplication::translate("transactionUI", "Ordonnances", nullptr));
        empl->setText(QCoreApplication::translate("transactionUI", "Employ\303\251", nullptr));
        quitter->setText(QCoreApplication::translate("transactionUI", "Se d\303\251connecter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class transactionUI: public Ui_transactionUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSACTIONUI_H