#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "employeeui.h"
#include <QSerialPort>
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    static int Idg;
    void resetFields();
private slots:
    void on_pushButton_3_clicked();
    void clrinput();
    void on_forgotPasswordButton_clicked();
    void readSerialData();

    void openSerialPort();

    void closeSerialPort();

private:
    Ui::login *ui;
    employeeUI *ma;
    QSerialPort *serial;


};

#endif // LOGIN_H
