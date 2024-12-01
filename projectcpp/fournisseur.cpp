#include "fournisseur.h"

fournisseur::fournisseur() {
    nom = "";
    adresse = "";
    code = "";
    produit = "";
    contact = 0;
    quantite = 0;
}

fournisseur::fournisseur(QString Nom, QString Adresse, QString Code, QString Produit, int Contact, int Quantite) {
    nom = Nom;
    adresse = Adresse;
    code = Code;
    produit = Produit;
    contact = Contact;
    quantite = Quantite;
}

// Getters

QString fournisseur::getNom() {
    return nom;
}

QString fournisseur::getAdresse() {
    return adresse;
}

QString fournisseur::getCode() {
    return code;
}

QString fournisseur::getProduit() {
    return produit;
}

int fournisseur::getContact() {
    return contact;
}

int fournisseur::getQuantite() {
    return quantite;
}

// Setters

void fournisseur::setNom(QString Nom) {
    nom = Nom;
}

void fournisseur::setAdresse(QString Adresse) {
    adresse = Adresse;
}

void fournisseur::setCode(QString Code) {
    code = Code;
}

void fournisseur::setProduit(QString Produit) {
    produit = Produit;
}

void fournisseur::setContact(int Contact) {
    contact = Contact;
}

void fournisseur::setQuantite(int Quantite) {
    quantite = Quantite;
}

// CRUD Operations

// Ajouter

bool fournisseur::Ajouter() {
    QSqlQuery query;

    query.prepare("INSERT INTO fournisseur (nom, adresse, code, produit, contact, quantite) "
                  "VALUES (:nom, :adresse, :code, :produit, :contact, :quantite)");

    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":code", code);
    query.bindValue(":produit", produit);
    query.bindValue(":contact", contact);
    query.bindValue(":quantite", quantite);

    return query.exec();
}

// Afficher

QSqlQueryModel* fournisseur::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT nom, adresse, code, produit, "
                    "TO_CHAR(contact) AS contact, "
                    "TO_CHAR(quantite) AS quantite "
                    "FROM fournisseur");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Code"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Produit"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Contact"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Quantité"));

    return model;
}

// Modifier

bool fournisseur::modifier() {
    QSqlQuery query;

    query.prepare("UPDATE fournisseur SET nom = :nom, adresse = :adresse, produit = :produit, "
                  "contact = :contact, quantite = :quantite "
                  "WHERE code = :code");

    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":produit", produit);
    query.bindValue(":contact", contact);
    query.bindValue(":quantite", quantite);
    query.bindValue(":code", code);

    return query.exec();
}

// Supprimer

bool fournisseur::Supprimer(QString code) {
    QSqlQuery query;
    query.prepare("DELETE FROM fournisseur WHERE code = :code");
    query.bindValue(":code", code);
    return query.exec();
}

// Reset

bool fournisseur::reset() {
    QSqlQuery query;
    query.prepare("DELETE FROM fournisseur");
    return query.exec();
}
fournisseur fournisseur::getConstatDetails(int code){
    fournisseur f;
    f.setCode(QString::number(-1));

    QSqlQuery query;
    query.prepare("SELECT * FROM fournisseur WHERE code = :code");
    query.bindValue(":code",code);
    if (query.exec()) {
        if (query.next()) {

            f.setCode(query.value(1).toString());
            f.setNom(query.value(3).toString());
            f.setAdresse(query.value(4).toString());
            f.setProduit(query.value(5).toString());

        }
    }
    return f;
}
