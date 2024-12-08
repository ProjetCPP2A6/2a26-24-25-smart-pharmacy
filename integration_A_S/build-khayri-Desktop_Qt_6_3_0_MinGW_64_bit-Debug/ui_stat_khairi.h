/********************************************************************************
** Form generated from reading UI file 'stat_khairi.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAT_KHAIRI_H
#define UI_STAT_KHAIRI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_stat_khairi
{
public:
    QLabel *label_chat;
    QPushButton *pushButton_11;

    void setupUi(QDialog *stat_khairi)
    {
        if (stat_khairi->objectName().isEmpty())
            stat_khairi->setObjectName(QString::fromUtf8("stat_khairi"));
        stat_khairi->resize(896, 693);
        label_chat = new QLabel(stat_khairi);
        label_chat->setObjectName(QString::fromUtf8("label_chat"));
        label_chat->setGeometry(QRect(20, 10, 850, 600));
        pushButton_11 = new QPushButton(stat_khairi);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(760, 640, 111, 31));
        pushButton_11->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(stat_khairi);

        QMetaObject::connectSlotsByName(stat_khairi);
    } // setupUi

    void retranslateUi(QDialog *stat_khairi)
    {
        stat_khairi->setWindowTitle(QCoreApplication::translate("stat_khairi", "Dialog", nullptr));
        label_chat->setText(QString());
        pushButton_11->setText(QCoreApplication::translate("stat_khairi", "Fermer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stat_khairi: public Ui_stat_khairi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAT_KHAIRI_H
