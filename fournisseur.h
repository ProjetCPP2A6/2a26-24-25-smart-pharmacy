#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
#include <QDate>

class fournisseur
{
private:
    QString nom;
    QString adresse;
    QString code;
    QString produit;
    int contact;
    int quantite;

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

    // Setters
    void setNom(QString nom);
    void setAdresse(QString adresse);
    void setCode(QString code);
    void setProduit(QString produit);
    void setContact(int contact);
    void setQuantite(int quantite);

    // CRUD Operations
    bool Ajouter();
    QSqlQueryModel* afficher();
    bool Supprimer(QString code);
    bool modifier();
    bool reset();
    fournisseur getConstatDetails(int code);
};

#endif // FOURNISSEUR_H
