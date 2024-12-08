/********************************************************************************
** Form generated from reading UI file 'mp3.ui'
**
** Created by: Qt User Interface Compiler version 6.2.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MP3_H
#define UI_MP3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_mp3
{
public:
    QPushButton *pushButton_play;
    QPushButton *pushButton_pause;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_load;
    QSlider *horizontalSlider;
    QLabel *label_status;
    QLabel *label_trackName;

    void setupUi(QDialog *mp3)
    {
        if (mp3->objectName().isEmpty())
            mp3->setObjectName(QString::fromUtf8("mp3"));
        mp3->resize(758, 145);
        pushButton_play = new QPushButton(mp3);
        pushButton_play->setObjectName(QString::fromUtf8("pushButton_play"));
        pushButton_play->setGeometry(QRect(60, 60, 80, 24));
        pushButton_pause = new QPushButton(mp3);
        pushButton_pause->setObjectName(QString::fromUtf8("pushButton_pause"));
        pushButton_pause->setGeometry(QRect(360, 60, 80, 24));
        pushButton_stop = new QPushButton(mp3);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(620, 60, 80, 24));
        pushButton_load = new QPushButton(mp3);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));
        pushButton_load->setGeometry(QRect(620, 14, 121, 24));
        horizontalSlider = new QSlider(mp3);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(60, 100, 661, 16));
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        label_status = new QLabel(mp3);
        label_status->setObjectName(QString::fromUtf8("label_status"));
        label_status->setGeometry(QRect(30, 10, 161, 31));
        label_trackName = new QLabel(mp3);
        label_trackName->setObjectName(QString::fromUtf8("label_trackName"));
        label_trackName->setGeometry(QRect(210, 10, 391, 31));

        retranslateUi(mp3);

        QMetaObject::connectSlotsByName(mp3);
    } // setupUi

    void retranslateUi(QDialog *mp3)
    {
        mp3->setWindowTitle(QCoreApplication::translate("mp3", "Dialog", nullptr));
        pushButton_play->setText(QCoreApplication::translate("mp3", "Play", nullptr));
        pushButton_pause->setText(QCoreApplication::translate("mp3", "Pause", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("mp3", "Stop", nullptr));
        pushButton_load->setText(QCoreApplication::translate("mp3", "Load Music", nullptr));
        label_status->setText(QString());
        label_trackName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mp3: public Ui_mp3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MP3_H
