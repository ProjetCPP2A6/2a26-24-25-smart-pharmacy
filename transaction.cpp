#include "transaction.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>

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



bool transaction::ajouter() {
    if (id.isEmpty()) {
        QMessageBox::critical(nullptr, "Erreur", "L'ID de la transaction est requis.");
        return false;
    }
    if (type.isEmpty()) {
        QMessageBox::critical(nullptr, "Erreur", "Le type de transaction est requis.");
        return false;
    }
    if (description.isEmpty()) {
        QMessageBox::critical(nullptr, "Erreur", "La description de la transaction est requise.");
        return false;
    }
    if (categorie.isEmpty()) {
        QMessageBox::critical(nullptr, "Erreur", "La catégorie de transaction est requise.");
        return false;
    }
    if (modepaiment.isEmpty()) {
        QMessageBox::critical(nullptr, "Erreur", "Le mode de paiement est requis.");
        return false;
    }

    // Vérifier que la date est valide (et pas vide)
    if (!datep.isValid()) {
        QMessageBox::critical(nullptr, "Erreur", "La date de la transaction est invalide.");
        return false;
    }

    // Vérifier que le prix est positif
    if (prix <= 0) {
        QMessageBox::critical(nullptr, "Erreur", "Le prix doit être supérieur à zéro.");
        return false;
    }
    QSqlQuery query;

    query.prepare("INSERT INTO transaction (id_trans, type, description, categorie, modepaiment, datep, prix) "
                  "VALUES (:id_trans, :type, :description, :categorie, :modepaiment, :datep, :prix)");

    query.bindValue(":id_trans", id);
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


    model->setQuery("SELECT id_trans, type, description, categorie, modepaiment, "
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
                  "modepaiment = :modepaiment, datep = :datep, prix = :prix WHERE id_trans = :id_trans");

    query.bindValue(":type", type);
    query.bindValue(":description", description);
    query.bindValue(":categorie", categorie);
    query.bindValue(":modepaiment", modepaiment);
    query.bindValue(":datep", datep);
    query.bindValue(":prix", prix);
    query.bindValue(":id_trans", id);

    return query.exec();
}

bool transaction::supprimer(QString transactionId) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM transaction WHERE id_trans = :id_trans");
    query.bindValue(":id_trans", transactionId);

    if (!query.exec()) {
        // Si la requête échoue, afficher l'erreur
        QMessageBox::critical(nullptr, "Erreur", "Erreur lors de la vérification de la transaction : " + query.lastError().text());
        return false;
    }

    // Si aucune transaction n'est trouvée avec cet ID
    query.next();  // Avancer au premier (et unique) résultat
    if (query.value(0).toInt() == 0) {
        QMessageBox::critical(nullptr, "Erreur", "La transaction avec l'ID spécifié n'existe pas.");
        return false;
    }

    // Si la transaction existe, procéder à la suppression
    query.prepare("DELETE FROM transaction WHERE id_trans = :id_trans");
    query.bindValue(":id_trans", transactionId);

    if (query.exec()) {
        QMessageBox::information(nullptr, "Succès", "La transaction a été supprimée avec succès.");
        return true;
    } else {
        // Si la suppression échoue, afficher l'erreur
        QString errorMessage = query.lastError().text();
        qDebug() << "Erreur lors de la suppression de la transaction : " << errorMessage;
        QMessageBox::critical(nullptr, "Erreur", "Échec de la suppression de la transaction : " + errorMessage);
        return false;
    }
}

bool transaction::reset() {
    QSqlQuery query;

    return query.exec("DELETE FROM transaction");
}
QSqlQueryModel* transaction::rechercher(QString id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM transaction WHERE id_trans = :id_trans"); // Ensure placeholder matches bindValue key
    query.bindValue(":id_trans", id);

    // Execute the query
    if (!query.exec()) {
        // Handle the error if the query execution fails
        qDebug() << "Query execution failed:" << query.lastError().text();
        return nullptr;
    }

    // Create a new model to hold the results
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);

    return model;
}
QSqlQueryModel* transaction::trier() {
    QSqlQuery query;
    query.prepare("SELECT * FROM transaction ORDER BY type ASC, prix ASC");

    // Exécuter la requête
    if (!query.exec()) {
        // Gérer l'erreur si l'exécution de la requête échoue
        qDebug() << "Query execution failed:" << query.lastError().text();
        return nullptr;
    }

    // Créer un nouveau modèle pour contenir les résultats
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);

    return model;
}

bool transaction::existe(const QString& id) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM transaction WHERE id_trans = :id_trans");
    query.bindValue(":id_trans", id);
    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0; // Retourne vrai si au moins une ligne existe
    }
    return false; // En cas d'erreur ou d'ID inexistant
}

