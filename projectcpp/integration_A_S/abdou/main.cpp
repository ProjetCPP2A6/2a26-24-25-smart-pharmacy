#include "medicament_ui.h"

#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include <QTimer>
#include "QSqlRecord"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    medicament_UI mUI;
    connexion c;
    bool test =c.createconnect();
    if(test)
    {
        //w.show();
        mUI.exec();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("connexion failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();
}
