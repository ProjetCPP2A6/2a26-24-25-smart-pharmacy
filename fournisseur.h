#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
#include <QDate>
#include <QSqlQuery>
#include <QSqlError>  // For lastError() method
#include <QDebug>     // For qDebug()


class fournisseur
{
private:
    QString nom;
    QString adresse;
    QString code;
    QString produit;
    int contact;
    int quantite;
    int poidsProduit;

public:
    fournisseur();
    fournisseur(QString Nom, QString Adresse, QString Code, QString Produit, int Contact, int Quantite);

    // Getters
    QString getNom();
    QString getAdresse();
    QString getCode();
    QString getProduit();
    int getContact();
    int getQuantite();
     int getPoidsProduit();

    // Setters
    void setNom(QString nom);
    void setAdresse(QString adresse);
    void setCode(QString code);
    void setProduit(QString produit);
    void setContact(int contact);
    void setQuantite(int quantite);
    void setPoidsProduit(int poids);

    // CRUD Operations
    bool Ajouter();
    QSqlQueryModel* afficher();
    bool Supprimer(QString code);
    bool modifier();
    bool reset();

    fournisseur getConstatDetails(int code);
    bool updatePoidsProduit(QString code, int poids);

};

#endif // FOURNISSEUR_H
