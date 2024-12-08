/********************************************************************************
** Form generated from reading UI file 'm4player.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_M4PLAYER_H
#define UI_M4PLAYER_H

#include <QtCore/QVariant>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_m4player
{
public:
    QPushButton *pushButton_play;
    QPushButton *pushButton_pause;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QSlider *horizontalSlider_volume;
    QLabel *label_2;
    QLabel *label_value;
    QVideoWidget *videoContainer;

    void setupUi(QDialog *m4player)
    {
        if (m4player->objectName().isEmpty())
            m4player->setObjectName(QString::fromUtf8("m4player"));
        m4player->resize(946, 605);
        pushButton_play = new QPushButton(m4player);
        pushButton_play->setObjectName(QString::fromUtf8("pushButton_play"));
        pushButton_play->setGeometry(QRect(40, 470, 80, 24));
        pushButton_pause = new QPushButton(m4player);
        pushButton_pause->setObjectName(QString::fromUtf8("pushButton_pause"));
        pushButton_pause->setGeometry(QRect(140, 470, 80, 24));
        pushButton_stop = new QPushButton(m4player);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(240, 470, 80, 24));
        pushButton_2 = new QPushButton(m4player);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(840, 470, 80, 24));
        pushButton = new QPushButton(m4player);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(840, 510, 80, 24));
        pushButton_3 = new QPushButton(m4player);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(840, 550, 80, 24));
        horizontalSlider_volume = new QSlider(m4player);
        horizontalSlider_volume->setObjectName(QString::fromUtf8("horizontalSlider_volume"));
        horizontalSlider_volume->setGeometry(QRect(40, 520, 251, 16));
        horizontalSlider_volume->setValue(50);
        horizontalSlider_volume->setOrientation(Qt::Orientation::Horizontal);
        label_2 = new QLabel(m4player);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(300, 520, 71, 16));
        label_value = new QLabel(m4player);
        label_value->setObjectName(QString::fromUtf8("label_value"));
        label_value->setGeometry(QRect(110, 550, 471, 31));
        videoContainer = new QVideoWidget(m4player);
        videoContainer->setObjectName(QString::fromUtf8("videoContainer"));
        videoContainer->setGeometry(QRect(20, 10, 911, 441));

        retranslateUi(m4player);

        QMetaObject::connectSlotsByName(m4player);
    } // setupUi

    void retranslateUi(QDialog *m4player)
    {
        m4player->setWindowTitle(QCoreApplication::translate("m4player", "Dialog", nullptr));
        pushButton_play->setText(QCoreApplication::translate("m4player", "Play", nullptr));
        pushButton_pause->setText(QCoreApplication::translate("m4player", "Pause", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("m4player", "Stop", nullptr));
        pushButton_2->setText(QCoreApplication::translate("m4player", "Load", nullptr));
        pushButton->setText(QCoreApplication::translate("m4player", "Stop&Close", nullptr));
        pushButton_3->setText(QCoreApplication::translate("m4player", "Close", nullptr));
        label_2->setText(QCoreApplication::translate("m4player", "50%", nullptr));
        label_value->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class m4player: public Ui_m4player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_M4PLAYER_H
