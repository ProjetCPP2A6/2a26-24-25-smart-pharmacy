#include "transaction.h"

// Default constructor
transaction::transaction() {
    id = "";
    type = "";
    description = "";
    categorie = "";
    modepaiment = "";
    datep = QDate::currentDate();
    prix = 0.0;
}

transaction::transaction(QString Id, QString Type, QString Description, QString Categorie, QString ModePaiment, QDate Datep, float Prix) {
    id = Id;
    type = Type;
    description = Description;
    categorie = Categorie;
    modepaiment = ModePaiment;
    datep = Datep;
    prix = Prix;
}

// Getters

QString transaction::getId() {
    return id;
}
QString transaction::getType() {
    return type;
}
QString transaction::getDescription() {
    return description;
}
QString transaction::getCategorie() {
    return categorie;
}
QString transaction::getModePaiment() {
    return modepaiment;
}
QDate transaction::getDatep() {
    return datep;
}
float transaction::getPrix() {
    return prix;
}

// Setters

void transaction::setId(QString Id) {
    id = Id;
}
void transaction::setType(QString Type) {
    type = Type;
}
void transaction::setDescription(QString Description) {
    description = Description;
}
void transaction::setCategorie(QString Categorie) {
    categorie = Categorie;
}
void transaction::setModePaiment(QString ModePaiment) {
    modepaiment = ModePaiment;
}
void transaction::setDatep(QDate Datep) {
    datep = Datep;
}
void transaction::setPrix(float Prix) {
    prix = Prix;
}

// CRUD Operations

bool transaction::ajouter() {
    QSqlQuery query;

    query.prepare("INSERT INTO transaction (id, type, description, categorie, modepaiment, datep, prix) "
                  "VALUES (:id, :type, :description, :categorie, :modepaiment, :datep, :prix)");

    query.bindValue(":id", id);
    query.bindValue(":type", type);
    query.bindValue(":description", description);
    query.bindValue(":categorie", categorie);
    query.bindValue(":modepaiment", modepaiment);
    query.bindValue(":datep", datep);
    query.bindValue(":prix", prix);

    return query.exec();
}

QSqlQueryModel* transaction::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT id, type, description, categorie, modepaiment, "
                    "TO_CHAR(datep, 'YYYY-MM-DD') AS datep, "
                    "TO_CHAR(prix, 'FM99999999.00') AS prix FROM transaction");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Catégorie"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Mode de Paiement"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Prix"));

    return model;
}


bool transaction::modifier() {
    QSqlQuery query;

    query.prepare("UPDATE transaction SET type = :type, description = :description, categorie = :categorie, "
                  "modepaiment = :modepaiment, datep = :datep, prix = :prix WHERE id = :id");

    query.bindValue(":type", type);
    query.bindValue(":description", description);
    query.bindValue(":categorie", categorie);
    query.bindValue(":modepaiment", modepaiment);
    query.bindValue(":datep", datep);
    query.bindValue(":prix", prix);
    query.bindValue(":id", id);

    return query.exec();
}

bool transaction::supprimer(QString transactionId) {
    QSqlQuery query;

    query.prepare("DELETE FROM transaction WHERE id = :id");
    query.bindValue(":id", transactionId);

    return query.exec();
}

bool transaction::reset() {
    QSqlQuery query;

    return query.exec("DELETE FROM transaction");
}
