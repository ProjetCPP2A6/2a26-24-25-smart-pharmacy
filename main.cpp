#include "mainwindow.h"
#include "connexion.h"

#include <QApplication>
#include <QMessageBox>

#include "transactionui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    transactionUI tUI;
    connexion c;
    bool test =c.createconnect();
    if(test)
    {
       // w.show();
        tUI.exec();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("connexion failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();
}
