/********************************************************************************
** Form generated from reading UI file 'fournisseurui.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOURNISSEURUI_H
#define UI_FOURNISSEURUI_H

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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fournisseurUI
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
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_23;
    QLineEdit *lineEdit_13;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *pushButton_8;
    QPushButton *pushButton_19;
    QFrame *employe_2;
    QFrame *frame_6;
    QLineEdit *lineEdit_12;
    QLabel *label_15;
    QLineEdit *nom;
    QLabel *label_16;
    QLineEdit *adresse;
    QLabel *label_18;
    QLineEdit *contact;
    QLabel *label_19;
    QLineEdit *quantite;
    QPushButton *ajouter;
    QPushButton *modifier;
    QLabel *label_20;
    QLineEdit *produit;
    QLineEdit *code;
    QLabel *label_17;
    QPushButton *pushButton_exportation;
    QPushButton *pushButton_stat;
    QLabel *label_29;
    QLabel *label_30;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QFrame *frame_7;
    QLabel *label_21;
    QComboBox *comboBox_critere;
    QLineEdit *lineEdit_recherche;
    QPushButton *del_button;
    QLineEdit *lineEdit_supp;
    QFrame *frame_12;
    QLineEdit *lineEdit_22;
    QPushButton *pushButton_23;
    QComboBox *comboBox_tri;
    QTableView *tableView_f;
    QPushButton *chatBot_2;
    QWidget *page_2;
    QLabel *labelCache;
    QPushButton *ajoutEmpDesc_4;
    QPlainTextEdit *chatBot;
    QPushButton *sendChatBtn;
    QLineEdit *inputChatbot;
    QPushButton *retour;
    QLabel *labelWeight;
    QPushButton *connectArduino;
    QLabel *statusLabel;
    QPushButton *saveWeightButton;
    QLineEdit *lineEditFournisseurCode;
    QPushButton *compareButton;
    QLabel *label_27;
    QLabel *label_28;

    void setupUi(QDialog *fournisseurUI)
    {
        if (fournisseurUI->objectName().isEmpty())
            fournisseurUI->setObjectName(QString::fromUtf8("fournisseurUI"));
        fournisseurUI->resize(980, 621);
        fournisseurUI->setStyleSheet(QString::fromUtf8("* {\n"
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
"#logo_2 {\n"
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
"#checkBox_20\n"
"{\n"
"	background-color:#fefeff;\n"
"	padding:5px;\n"
"	text-align: left;\n"
"	border-top-left-raduis: 20px;\n"
"}\n"
"#pushButton_20 {\n"
"    background-color: #fefeff;\n"
"    padding: 5px;\n"
"    text-align: left;\n"
"    border-top-left-radius: 20px;\n"
"}\n"
"#pushButton_exportation {\n"
""
                        "    border-radius: 20px;\n"
"    border: 2px solid #4cd814;\n"
"    background: #ffffff;\n"
"}\n"
"#pushButton_stat {\n"
"    border-radius: 20px;\n"
"    border: 2px solid #2596be;\n"
"    background: #ffffff;\n"
"}\n"
"#pushButton_32{\n"
"\n"
"    color: #4cd814;\n"
"\n"
"}\n"
"#frame_13{\n"
"    background-color: #2596be;\n"
"}\n"
"#frame_14 {\n"
"    background-color: #2596be;\n"
"}\n"
"#frame_15 {\n"
"    background-color: #2596be;\n"
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
"}\n"
"#label_22 {\n"
"    color: #000;\n"
"    border: #000;\n"
""
                        "} \n"
"#frame_6{\n"
"	background-color: #cecece;\n"
"}\n"
"#lineEdit_12{\n"
"	background-color: #cecece;\n"
"}\n"
"#label_15{\n"
"	background-color: #cecece;\n"
"}\n"
"#label_16{\n"
"	background-color: #cecece;\n"
"}\n"
"#label_17{\n"
"	background-color: #cecece;\n"
"}\n"
"#label_18{\n"
"	background-color: #cecece;\n"
"}\n"
"#label_19{\n"
"	background-color: #cecece;\n"
"}\n"
"\n"
"#label_20{\n"
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
"} \n"
"#code,#nom, #adresse, #contact, #quantite, #produit {\n"
"    background: #ffffff;\n"
"}\n"
"#label_22\n"
"{\n"
"	 background-color: #2596be;\n"
"}\n"
"#label_21\n"
"{\n"
"	 background-color: transparent;\n"
"}\n"
"#pushButton_23\n"
"{\n"
"	 background-color: transparent;\n"
"} \n"
"#modifier {\n"
"     background-color: #cecece;\n"
"}\n"
"#label_13\n"
""
                        "{\n"
"	 background-color: transparent;\n"
"} \n"
"#pushButton_19\n"
"{\n"
"	 background-color: transparent;\n"
"} "));
        leftmenu = new QWidget(fournisseurUI);
        leftmenu->setObjectName(QString::fromUtf8("leftmenu"));
        leftmenu->setGeometry(QRect(0, 0, 200, 621));
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
        label_22->setGeometry(QRect(60, 0, 91, 61));
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
        pushButton_30->setGeometry(QRect(30, 270, 111, 24));
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
        pushButton_20->setGeometry(QRect(0, 213, 161, 31));
        pushButton_20->setFont(font1);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/res/icone25"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_20->setIcon(icon5);

        verticalLayout_4->addWidget(frame_14);


        verticalLayout_3->addWidget(frame_13);

        mainbody = new QWidget(fournisseurUI);
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
        horizontalLayout_17 = new QHBoxLayout(frame_5);
        horizontalLayout_17->setSpacing(0);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(frame_5);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMaximumSize(QSize(30, 30));
        label_23->setPixmap(QPixmap(QString::fromUtf8(":/res/icone2.jpg.png")));
        label_23->setScaledContents(true);

        horizontalLayout_17->addWidget(label_23);

        lineEdit_13 = new QLineEdit(frame_5);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));

        horizontalLayout_17->addWidget(lineEdit_13);


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

        employe_2 = new QFrame(mainbody);
        employe_2->setObjectName(QString::fromUtf8("employe_2"));
        employe_2->setGeometry(QRect(10, 180, 230, 420));
        employe_2->setMinimumSize(QSize(230, 420));
        employe_2->setMaximumSize(QSize(150, 600));
        employe_2->setFrameShape(QFrame::NoFrame);
        frame_6 = new QFrame(employe_2);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(0, 0, 181, 41));
        frame_6->setMaximumSize(QSize(200, 16777215));
        frame_6->setFrameShape(QFrame::NoFrame);
        lineEdit_12 = new QLineEdit(frame_6);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(10, 10, 151, 20));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setItalic(false);
        lineEdit_12->setFont(font4);
        label_15 = new QLabel(employe_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 100, 49, 16));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(true);
        label_15->setFont(font5);
        nom = new QLineEdit(employe_2);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(30, 120, 171, 22));
        label_16 = new QLabel(employe_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 150, 61, 16));
        label_16->setFont(font5);
        adresse = new QLineEdit(employe_2);
        adresse->setObjectName(QString::fromUtf8("adresse"));
        adresse->setGeometry(QRect(30, 170, 171, 22));
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(false);
        adresse->setFont(font6);
        label_18 = new QLabel(employe_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(20, 200, 61, 16));
        label_18->setFont(font5);
        contact = new QLineEdit(employe_2);
        contact->setObjectName(QString::fromUtf8("contact"));
        contact->setGeometry(QRect(30, 220, 171, 22));
        label_19 = new QLabel(employe_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(20, 245, 71, 21));
        label_19->setFont(font5);
        quantite = new QLineEdit(employe_2);
        quantite->setObjectName(QString::fromUtf8("quantite"));
        quantite->setGeometry(QRect(30, 270, 171, 22));
        ajouter = new QPushButton(employe_2);
        ajouter->setObjectName(QString::fromUtf8("ajouter"));
        ajouter->setGeometry(QRect(30, 370, 75, 24));
        ajouter->setFont(font5);
        modifier = new QPushButton(employe_2);
        modifier->setObjectName(QString::fromUtf8("modifier"));
        modifier->setGeometry(QRect(120, 370, 75, 24));
        modifier->setFont(font5);
        label_20 = new QLabel(employe_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(20, 295, 61, 21));
        label_20->setFont(font5);
        produit = new QLineEdit(employe_2);
        produit->setObjectName(QString::fromUtf8("produit"));
        produit->setGeometry(QRect(30, 320, 171, 22));
        code = new QLineEdit(employe_2);
        code->setObjectName(QString::fromUtf8("code"));
        code->setGeometry(QRect(30, 70, 171, 22));
        label_17 = new QLabel(employe_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(20, 50, 71, 16));
        label_17->setFont(font5);
        pushButton_exportation = new QPushButton(mainbody);
        pushButton_exportation->setObjectName(QString::fromUtf8("pushButton_exportation"));
        pushButton_exportation->setGeometry(QRect(30, 80, 75, 41));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/res/icone10"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_exportation->setIcon(icon9);
        pushButton_exportation->setIconSize(QSize(32, 32));
        pushButton_stat = new QPushButton(mainbody);
        pushButton_stat->setObjectName(QString::fromUtf8("pushButton_stat"));
        pushButton_stat->setGeometry(QRect(150, 80, 71, 41));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/res/icone11"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_stat->setIcon(icon10);
        pushButton_stat->setIconSize(QSize(32, 32));
        label_29 = new QLabel(mainbody);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(30, 130, 101, 20));
        label_29->setFont(font5);
        label_30 = new QLabel(mainbody);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(140, 130, 101, 20));
        label_30->setFont(font5);
        stackedWidget = new QStackedWidget(mainbody);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(250, 200, 521, 411));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        frame_7 = new QFrame(page);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setGeometry(QRect(20, 10, 461, 31));
        frame_7->setFrameShape(QFrame::NoFrame);
        label_21 = new QLabel(frame_7);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 0, 25, 25));
        label_21->setMinimumSize(QSize(25, 25));
        label_21->setMaximumSize(QSize(25, 25));
        label_21->setStyleSheet(QString::fromUtf8("#label_21\n"
"{\n"
"	  background: transparent;\n"
"}"));
        label_21->setPixmap(QPixmap(QString::fromUtf8(":/res/icone8")));
        label_21->setScaledContents(true);
        comboBox_critere = new QComboBox(frame_7);
        comboBox_critere->addItem(QString());
        comboBox_critere->addItem(QString());
        comboBox_critere->addItem(QString());
        comboBox_critere->setObjectName(QString::fromUtf8("comboBox_critere"));
        comboBox_critere->setGeometry(QRect(380, 4, 61, 20));
        lineEdit_recherche = new QLineEdit(frame_7);
        lineEdit_recherche->setObjectName(QString::fromUtf8("lineEdit_recherche"));
        lineEdit_recherche->setGeometry(QRect(40, 0, 261, 26));
        lineEdit_recherche->setStyleSheet(QString::fromUtf8("#lineEdit_recherche\n"
"{\n"
"  background: transparent;\n"
"}"));
        del_button = new QPushButton(page);
        del_button->setObjectName(QString::fromUtf8("del_button"));
        del_button->setGeometry(QRect(390, 353, 91, 31));
        del_button->setFont(font5);
        lineEdit_supp = new QLineEdit(page);
        lineEdit_supp->setObjectName(QString::fromUtf8("lineEdit_supp"));
        lineEdit_supp->setGeometry(QRect(260, 360, 113, 21));
        lineEdit_supp->setFont(font5);
        frame_12 = new QFrame(page);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setGeometry(QRect(20, 50, 461, 31));
        frame_12->setFrameShape(QFrame::NoFrame);
        lineEdit_22 = new QLineEdit(frame_12);
        lineEdit_22->setObjectName(QString::fromUtf8("lineEdit_22"));
        lineEdit_22->setGeometry(QRect(42, 0, 271, 22));
        lineEdit_22->setStyleSheet(QString::fromUtf8("#lineEdit_22\n"
"{\n"
"	  background: transparent;\n"
"}"));
        pushButton_23 = new QPushButton(frame_12);
        pushButton_23->setObjectName(QString::fromUtf8("pushButton_23"));
        pushButton_23->setGeometry(QRect(10, 0, 32, 32));
        pushButton_23->setMinimumSize(QSize(32, 32));
        pushButton_23->setMaximumSize(QSize(32, 32));
        pushButton_23->setStyleSheet(QString::fromUtf8("#pushButton_23\n"
"{\n"
"	  background: transparent;\n"
"}"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/res/icone9"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_23->setIcon(icon11);
        comboBox_tri = new QComboBox(frame_12);
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->setObjectName(QString::fromUtf8("comboBox_tri"));
        comboBox_tri->setGeometry(QRect(350, 5, 91, 21));
        tableView_f = new QTableView(page);
        tableView_f->setObjectName(QString::fromUtf8("tableView_f"));
        tableView_f->setGeometry(QRect(20, 100, 491, 241));
        chatBot_2 = new QPushButton(page);
        chatBot_2->setObjectName(QString::fromUtf8("chatBot_2"));
        chatBot_2->setGeometry(QRect(40, 360, 93, 28));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        labelCache = new QLabel(page_2);
        labelCache->setObjectName(QString::fromUtf8("labelCache"));
        labelCache->setGeometry(QRect(370, 20, 41, 20));
        ajoutEmpDesc_4 = new QPushButton(page_2);
        ajoutEmpDesc_4->setObjectName(QString::fromUtf8("ajoutEmpDesc_4"));
        ajoutEmpDesc_4->setGeometry(QRect(10, 30, 181, 31));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("century gothic")});
        font7.setPointSize(10);
        font7.setBold(true);
        ajoutEmpDesc_4->setFont(font7);
        ajoutEmpDesc_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: 2px solid  rgb(0, 0, 255);\n"
"font-family:century gothic;\n"
"background:transparent;\n"
"color: rgb(0, 0, 255);\n"
"\n"
"}"));
        chatBot = new QPlainTextEdit(page_2);
        chatBot->setObjectName(QString::fromUtf8("chatBot"));
        chatBot->setGeometry(QRect(10, 80, 411, 221));
        chatBot->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"font: 12pt \"MS Shell Dlg 2\";\n"
"color: black;"));
        sendChatBtn = new QPushButton(page_2);
        sendChatBtn->setObjectName(QString::fromUtf8("sendChatBtn"));
        sendChatBtn->setGeometry(QRect(290, 320, 111, 31));
        sendChatBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 10px;\n"
"border: 1px solid  rgb(0, 0, 255);\n"
"background: transparent;\n"
"color:  rgb(0, 0, 255);\n"
"}\n"
"QPushButton:hover{\n"
"background:  rgb(0, 0, 255);\n"
"color: #FFFFFF;\n"
"}\n"
""));
        inputChatbot = new QLineEdit(page_2);
        inputChatbot->setObjectName(QString::fromUtf8("inputChatbot"));
        inputChatbot->setGeometry(QRect(20, 320, 241, 31));
        inputChatbot->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font-family:century gothic;\n"
"background:transparent;\n"
"border:none;\n"
"color: #000000;\n"
"border-radius: 10px;\n"
"border: 1px solid  rgb(0, 0, 255);\n"
"}"));
        retour = new QPushButton(page_2);
        retour->setObjectName(QString::fromUtf8("retour"));
        retour->setGeometry(QRect(230, 20, 75, 24));
        retour->setFont(font5);
        stackedWidget->addWidget(page_2);
        labelWeight = new QLabel(mainbody);
        labelWeight->setObjectName(QString::fromUtf8("labelWeight"));
        labelWeight->setGeometry(QRect(520, 80, 231, 111));
        connectArduino = new QPushButton(mainbody);
        connectArduino->setObjectName(QString::fromUtf8("connectArduino"));
        connectArduino->setGeometry(QRect(350, 120, 75, 24));
        connectArduino->setFont(font5);
        statusLabel = new QLabel(mainbody);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(310, 150, 181, 20));
        saveWeightButton = new QPushButton(mainbody);
        saveWeightButton->setObjectName(QString::fromUtf8("saveWeightButton"));
        saveWeightButton->setGeometry(QRect(570, 50, 131, 24));
        saveWeightButton->setFont(font5);
        lineEditFournisseurCode = new QLineEdit(mainbody);
        lineEditFournisseurCode->setObjectName(QString::fromUtf8("lineEditFournisseurCode"));
        lineEditFournisseurCode->setGeometry(QRect(340, 90, 100, 18));
        lineEditFournisseurCode->setMinimumSize(QSize(100, 0));
        lineEditFournisseurCode->setMaximumSize(QSize(50, 16777215));
        lineEditFournisseurCode->setStyleSheet(QString::fromUtf8("background-color: rgb(206, 206, 206);"));
        compareButton = new QPushButton(mainbody);
        compareButton->setObjectName(QString::fromUtf8("compareButton"));
        compareButton->setGeometry(QRect(310, 70, 150, 18));
        compareButton->setMinimumSize(QSize(150, 0));
        compareButton->setMaximumSize(QSize(150, 16777215));
        compareButton->setFont(font5);
        label_27 = new QLabel(mainbody);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(680, 0, 60, 60));
        label_27->setMinimumSize(QSize(60, 60));
        label_27->setMaximumSize(QSize(60, 60));
        label_27->setPixmap(QPixmap(QString::fromUtf8(":/res/icone16")));
        label_28 = new QLabel(mainbody);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(730, 0, 60, 60));
        label_28->setMinimumSize(QSize(60, 60));
        label_28->setMaximumSize(QSize(60, 60));
        label_28->setPixmap(QPixmap(QString::fromUtf8(":/res/icone18")));

        retranslateUi(fournisseurUI);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(fournisseurUI);
    } // setupUi

    void retranslateUi(QDialog *fournisseurUI)
    {
        fournisseurUI->setWindowTitle(QCoreApplication::translate("fournisseurUI", "Dialog", nullptr));
        logo_2->setText(QString());
        label_22->setText(QCoreApplication::translate("fournisseurUI", "MedicaPRO", nullptr));
        pushButton_27->setText(QCoreApplication::translate("fournisseurUI", "Menu", nullptr));
        pushButton_28->setText(QCoreApplication::translate("fournisseurUI", "Employ\303\251", nullptr));
        pushButton_29->setText(QCoreApplication::translate("fournisseurUI", "M\303\251dicaments", nullptr));
        pushButton_30->setText(QCoreApplication::translate("fournisseurUI", "Ordonnances", nullptr));
        pushButton_31->setText(QCoreApplication::translate("fournisseurUI", "Financi\303\250res", nullptr));
        pushButton_32->setText(QCoreApplication::translate("fournisseurUI", "Se d\303\251connecter", nullptr));
        pushButton_20->setText(QCoreApplication::translate("fournisseurUI", "Fournisseurs", nullptr));
        pushButton_7->setText(QString());
        label_13->setText(QString());
        label_23->setText(QString());
        lineEdit_13->setText(QString());
        lineEdit_13->setPlaceholderText(QCoreApplication::translate("fournisseurUI", "Recherche", nullptr));
        pushButton_8->setText(QString());
        pushButton_19->setText(QString());
        lineEdit_12->setText(QCoreApplication::translate("fournisseurUI", "ajouter fournisseurs", nullptr));
        lineEdit_12->setPlaceholderText(QCoreApplication::translate("fournisseurUI", "Ajouter un employ\303\251 ", nullptr));
        label_15->setText(QCoreApplication::translate("fournisseurUI", "nom", nullptr));
        label_16->setText(QCoreApplication::translate("fournisseurUI", "adresse", nullptr));
        label_18->setText(QCoreApplication::translate("fournisseurUI", "contact", nullptr));
        label_19->setText(QCoreApplication::translate("fournisseurUI", "quantite", nullptr));
        ajouter->setText(QCoreApplication::translate("fournisseurUI", "ajouter", nullptr));
        modifier->setText(QCoreApplication::translate("fournisseurUI", "Edit", nullptr));
        label_20->setText(QCoreApplication::translate("fournisseurUI", "produit", nullptr));
        label_17->setText(QCoreApplication::translate("fournisseurUI", "code", nullptr));
        pushButton_exportation->setText(QString());
        pushButton_stat->setText(QString());
        label_29->setText(QCoreApplication::translate("fournisseurUI", "Exportation", nullptr));
        label_30->setText(QCoreApplication::translate("fournisseurUI", " Allez au stat ", nullptr));
        label_21->setText(QString());
        comboBox_critere->setItemText(0, QCoreApplication::translate("fournisseurUI", "nom", nullptr));
        comboBox_critere->setItemText(1, QCoreApplication::translate("fournisseurUI", "produit", nullptr));
        comboBox_critere->setItemText(2, QCoreApplication::translate("fournisseurUI", "code", nullptr));

        lineEdit_recherche->setText(QString());
        del_button->setText(QCoreApplication::translate("fournisseurUI", "Supprimer", nullptr));
        lineEdit_supp->setText(QString());
        lineEdit_supp->setPlaceholderText(QCoreApplication::translate("fournisseurUI", "code", nullptr));
        lineEdit_22->setText(QString());
        lineEdit_22->setPlaceholderText(QString());
        pushButton_23->setText(QString());
        comboBox_tri->setItemText(0, QCoreApplication::translate("fournisseurUI", "quantite", nullptr));
        comboBox_tri->setItemText(1, QCoreApplication::translate("fournisseurUI", "code", nullptr));
        comboBox_tri->setItemText(2, QCoreApplication::translate("fournisseurUI", "produit", nullptr));

        chatBot_2->setText(QCoreApplication::translate("fournisseurUI", "chat Bot", nullptr));
        labelCache->setText(QString());
        ajoutEmpDesc_4->setText(QCoreApplication::translate("fournisseurUI", "CHAT BOT", nullptr));
        sendChatBtn->setText(QCoreApplication::translate("fournisseurUI", "Envoyer", nullptr));
        inputChatbot->setPlaceholderText(QCoreApplication::translate("fournisseurUI", "  Posez Une Question !", nullptr));
        retour->setText(QCoreApplication::translate("fournisseurUI", "Retour", nullptr));
        labelWeight->setText(QString());
        connectArduino->setText(QCoreApplication::translate("fournisseurUI", "arduino", nullptr));
        statusLabel->setText(QString());
        saveWeightButton->setText(QCoreApplication::translate("fournisseurUI", "enregistrement ", nullptr));
        compareButton->setText(QCoreApplication::translate("fournisseurUI", "code", nullptr));
        label_27->setText(QString());
        label_28->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class fournisseurUI: public Ui_fournisseurUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOURNISSEURUI_H
