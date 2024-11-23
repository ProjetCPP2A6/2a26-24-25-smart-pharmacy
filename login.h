#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "employeeui.h"

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
private slots:
    void on_pushButton_3_clicked();
    void clrinput();

    void on_forgotPasswordButton_clicked();

private:
    Ui::login *ui;
    employeeUI *ma;



};

#endif // LOGIN_H
