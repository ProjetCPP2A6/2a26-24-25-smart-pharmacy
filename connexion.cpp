#include "connexion.h"

connexion::connexion()
{

}

bool connexion::createconnect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projetcpp2a26");
    db.setUserName("a26user");//inserer nom de l'utilisateur
    db.setPassword("oracle");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;

    return  test;
}