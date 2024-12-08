//#include "mainwindow.h"
#include "employeeui.h"
#include "login.h"
#include "connexion.h"

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    login l;
    connexion c;
    bool test =c.createconnect();
    if(test)
    {
        //  w.show();
        l.show();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("connexion failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();
}

