/********************************************************************************
** Form generated from reading UI file 'mplayer.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MPLAYER_H
#define UI_MPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_mplayer
{
public:
    QPushButton *pushButton_3;
    QLabel *label_name;
    QPushButton *pushButton_play;
    QPushButton *pushButton_2;
    QLabel *label_value;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_pause;
    QLabel *label_3;
    QSlider *horizontalSlider_volume;
    QPushButton *pushButton_stop;

    void setupUi(QDialog *mplayer)
    {
        if (mplayer->objectName().isEmpty())
            mplayer->setObjectName(QString::fromUtf8("mplayer"));
        mplayer->resize(568, 266);
        pushButton_3 = new QPushButton(mplayer);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(500, 3, 51, 31));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/images/goBack.jpg.png);"));
        label_name = new QLabel(mplayer);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(20, 60, 151, 41));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setItalic(true);
        font.setKerning(true);
        label_name->setFont(font);
        pushButton_play = new QPushButton(mplayer);
        pushButton_play->setObjectName(QString::fromUtf8("pushButton_play"));
        pushButton_play->setGeometry(QRect(260, 180, 51, 51));
        pushButton_play->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/images/play.png);"));
        pushButton_2 = new QPushButton(mplayer);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(7, 7, 51, 41));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(true);
        font1.setUnderline(false);
        font1.setKerning(true);
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/images/open.png);"));
        label_value = new QLabel(mplayer);
        label_value->setObjectName(QString::fromUtf8("label_value"));
        label_value->setGeometry(QRect(130, 60, 421, 41));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setKerning(true);
        label_value->setFont(font2);
        label_2 = new QLabel(mplayer);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(638, 139, 51, 31));
        QFont font3;
        font3.setBold(true);
        label_2->setFont(font3);
        pushButton = new QPushButton(mplayer);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(990, 30, 31, 31));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix2/ressources/mplayer/exit.png);"));
        pushButton_pause = new QPushButton(mplayer);
        pushButton_pause->setObjectName(QString::fromUtf8("pushButton_pause"));
        pushButton_pause->setGeometry(QRect(100, 180, 51, 51));
        pushButton_pause->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/images/pause.png);"));
        label_3 = new QLabel(mplayer);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 140, 41, 31));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/images/vol.png);"));
        horizontalSlider_volume = new QSlider(mplayer);
        horizontalSlider_volume->setObjectName(QString::fromUtf8("horizontalSlider_volume"));
        horizontalSlider_volume->setGeometry(QRect(83, 130, 381, 31));
        horizontalSlider_volume->setStyleSheet(QString::fromUtf8(""));
        horizontalSlider_volume->setMinimum(1);
        horizontalSlider_volume->setMaximum(100);
        horizontalSlider_volume->setValue(50);
        horizontalSlider_volume->setOrientation(Qt::Orientation::Horizontal);
        pushButton_stop = new QPushButton(mplayer);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(420, 180, 51, 51));
        pushButton_stop->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/images/stop.png);"));

        retranslateUi(mplayer);

        QMetaObject::connectSlotsByName(mplayer);
    } // setupUi

    void retranslateUi(QDialog *mplayer)
    {
        mplayer->setWindowTitle(QCoreApplication::translate("mplayer", "Dialog", nullptr));
        pushButton_3->setText(QCoreApplication::translate("mplayer", "Exit", nullptr));
        label_name->setText(QCoreApplication::translate("mplayer", "Audio File Name :", nullptr));
        pushButton_play->setText(QCoreApplication::translate("mplayer", "Play", nullptr));
        pushButton_2->setText(QCoreApplication::translate("mplayer", "Load", nullptr));
        label_value->setText(QCoreApplication::translate("mplayer", "FILE_NAME", nullptr));
        label_2->setText(QString());
        pushButton->setText(QString());
        pushButton_pause->setText(QCoreApplication::translate("mplayer", "Pause", nullptr));
        label_3->setText(QString());
        pushButton_stop->setText(QCoreApplication::translate("mplayer", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mplayer: public Ui_mplayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MPLAYER_H
