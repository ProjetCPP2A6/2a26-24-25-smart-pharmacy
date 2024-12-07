#ifndef FOURNISSEURUI_H
#define FOURNISSEURUI_H

#include <QDialog>
#include "fournisseur.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include "sms.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QDebug>
#include "statranim.h"


namespace Ui {
class fournisseurUI;
}

class fournisseurUI : public QDialog
{
    Q_OBJECT

public:
    explicit fournisseurUI(QWidget *parent = nullptr);
    ~fournisseurUI();
    int close_arduino();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void on_ajouter_clicked();
    void on_modifier_clicked();
    void on_del_button_clicked();
    void on_lineEdit_recherche_textChanged(const QString &text);
    void on_comboBox_tri_currentIndexChanged();
    void on_pushButton_exportation_clicked();
    void on_sendChatBtn_clicked();
    void on_retour_clicked();
    void on_chatBot_2_clicked();
    void on_pushButton_stat_clicked();
    void on_retour_2_clicked();

    // Slot to handle incoming serial data and update weight
    void readData();  // To process the data from Arduino
    void readWeight(); // To trigger serial read from Arduino

     void onSerialDataReceived();
     void setupSerial();

     void on_connectArduino_clicked();

     void refreshFournisseurTable();


     void on_saveWeightButton_clicked();

     void on_pushButton_32_clicked();

     void on_pushButton_29_clicked();


private:
    Ui::fournisseurUI *ui;
    statranim *statistiqueWindow = nullptr;
    QSerialPort *serial;
    QGraphicsScene *chartScene;
    fournisseur f;

    QSerialPort *serialPort;  // Serial port for communication
    QTimer *timer;  // Timer for periodically reading data
    // Function to set up the serial port

    void showBarChart(const QMap<QString, int> &data); // Function to create a bar chart

};

#endif // FOURNISSEURUI_H
