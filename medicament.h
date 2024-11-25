#ifndef MEDICAMENT_H
#define MEDICAMENT_H

#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QSqlQueryModel>
#include <QDate>

#include "qrcodegen.hpp"

using namespace qrcodegen;

class medicament
{

private:
    int id,quantite;
    QString nom;
    QDate date_p,date_e;
    float prix;

public:
    medicament();
    medicament(int,QString,QDate,float,QDate,int);
    medicament(QString name);

    // Getters
    int getId();
    int getQuantite();
    QString getNom();
    QDate getDateP();
    QDate getDateE();
    float getPrix();

    // Setters
    void setId(int id);
    void setQuantite(int quantite);
    void setNom(QString nom);
    void setDateP(QDate date_p);
    void setDateE(QDate date_e);
    void setPrix(float prix);

    //CRUD
    bool Ajouter();
    QSqlQueryModel* afficher();
    bool Supprime(int);
    bool modifier();
    bool reset();

    /*Recherche*/
    QSqlQueryModel *afficher_id(QString ch);
    QSqlQueryModel *afficher_nom(QString ch);
    QSqlQueryModel *afficher_quantite(QString ch);
    /*Tri*/
    QSqlQueryModel *afficher_choix(QString choix);
    /*Statistique*/
    int statistique1();
    int statistique2();
    /*PDF*/
    medicament* readmedicament (int val);
    //Notification
    QSqlQueryModel* checkExpiration();

    QSqlQueryModel* afficher_flame();


};



#endif // MEDICAMENT_H
