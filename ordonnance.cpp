#include "ordonnance.h"
#include <QMessageBox>
#include <QRegularExpression> // Include this for QRegularExpression
// Constructors
ordonnance::ordonnance() {
    id = "";
    nomp = "";
    medecin = "";
    prix = 0.0;
    datep = QDate();
}

ordonnance::ordonnance(QString Id, QString Nomp, QString Medecin, float Prix, QDate Datep) {
    id = Id;
    nomp = Nomp;
    medecin = Medecin;
    prix = Prix;
    datep = Datep;
}

// Getters

QString ordonnance::getId() {
    return id;
}

QString ordonnance::getNomp() {
    return nomp;
}

QString ordonnance::getMedecin() {
    return medecin;
}

float ordonnance::getPrix() {
    return prix;
}

QDate ordonnance::getDatep() {
    return datep;
}

// Setters

void ordonnance::setId(QString Id) {
    id = Id;
}

void ordonnance::setNomp(QString Nomp) {
    nomp = Nomp;
}

void ordonnance::setMedecin(QString Medecin) {
    medecin = Medecin;
}

void ordonnance::setPrix(float Prix) {
    prix = Prix;
}

void ordonnance::setDatep(QDate Datep) {
    datep = Datep;
}

// CRUD Operations




bool ordonnance::Ajouter() {
    // Validate that id is numeric
    bool ok;
    int idValue = id.toInt(&ok);
    if (!ok) {
        QMessageBox::warning(nullptr, QObject::tr("Erreur de saisie"),
                             QObject::tr("L'ID doit contenir uniquement des chiffres."), QMessageBox::Ok);
        return false;
    }

    // Validate that nomp contains only letters and allowed characters
    QRegularExpression nameRegex("^[A-Za-zÀ-ÿ '-]+$"); // Allows letters, spaces, hyphens, and apostrophes
    if (!nameRegex.match(nomp).hasMatch()) {
        QMessageBox::warning(nullptr, QObject::tr("Erreur de saisie"),
                             QObject::tr("Le nom du patient ne doit contenir que des lettres, des espaces, des apostrophes et des tirets."), QMessageBox::Ok);
        return false; // Return false to indicate failure
    }

    QSqlQuery query;
    query.prepare("INSERT INTO ordonnance (id, nomp, medecin, prix, datep) "
                  "VALUES (:id, :nomp, :medecin, :prix, :datep)");

    query.bindValue(":id", idValue);
    query.bindValue(":nomp", nomp);
    query.bindValue(":medecin", medecin);
    query.bindValue(":prix", prix);
    query.bindValue(":datep", datep);

    return query.exec();
}

// Afficher
QSqlQueryModel* ordonnance::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id, nomp, medecin, prix, datep FROM ordonnance");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom du Patient"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Medecin"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de Prescription"));

    return model;
}

// Modifier
bool ordonnance::modifier() {
    QSqlQuery query;

    query.prepare("UPDATE ordonnance SET nomp = :nomp, medecin = :medecin, prix = :prix, datep = :datep "
                  "WHERE id = :id");

    query.bindValue(":id", id);
    query.bindValue(":nomp", nomp);
    query.bindValue(":medecin", medecin);
    query.bindValue(":prix", prix);
    query.bindValue(":datep", datep);

    return query.exec();
}



bool ordonnance::Supprimer(QString Id) {
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM ordonnance WHERE id = :id");
    checkQuery.bindValue(":id", Id);

    // Execute the query to check if the ID exists
    if (!checkQuery.exec() || !checkQuery.next() || checkQuery.value(0).toInt() == 0) {
        // If the query fails or the ID doesn't exist, show an error message
        QMessageBox::warning(nullptr, QObject::tr("Erreur de suppression"),
                             QObject::tr("L'ID spécifié n'existe pas dans la base de données."), QMessageBox::Ok);
        return false; // Return false to indicate failure
    }

    // Proceed to delete the record since the ID exists
    QSqlQuery query;
    query.prepare("DELETE FROM ordonnance WHERE id = :id");
    query.bindValue(":id", Id);

    return query.exec(); // Execute the delete query
}

// Reset
bool ordonnance::reset() {
    QSqlQuery query;
    query.prepare("DELETE FROM ordonnance");
    return query.exec();
}

// ## Recherche ## //

QSqlQueryModel *ordonnance::afficher_id(QString ch)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id, nomp, medecin, prix, datep FROM ordonnance WHERE id = '" + ch + "'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom du Patient"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Médecin"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de Prescription"));

    return model;
}

QSqlQueryModel *ordonnance::afficher_nomp(QString ch)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id, nomp, medecin, prix, datep FROM ordonnance WHERE nomp = '" + ch + "'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom du Patient"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Médecin"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de Prescription"));

    return model;
}

QSqlQueryModel *ordonnance::afficher_Medecin(QString ch)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id, nomp, medecin, prix, datep FROM ordonnance WHERE medecin = '" + ch + "'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom du Patient"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Médecin"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de Prescription"));

    return model;
}

QSqlQueryModel *ordonnance::afficher_choix(QString choix)
{
    QSqlQueryModel *model = new QSqlQueryModel();

    if(choix == "prix croissants")
    {
        model->setQuery("SELECT id, nomp, medecin, prix, datep FROM ordonnance ORDER BY prix ASC");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom du Patient"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Médecin"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de Prescription"));
    }
    else if(choix == "prix decroissants")
    {
        model->setQuery("SELECT id, nomp, medecin, prix, datep FROM ordonnance ORDER BY prix DESC");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom du Patient"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Médecin"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de Prescription"));
    }
    else if(choix == "nomp decroissants")
    {
        model->setQuery("SELECT id, nomp, medecin, prix, datep FROM ordonnance ORDER BY nomp DESC");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom du Patient"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Médecin"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de Prescription"));
    }
    else if(choix == "nomp croissants")
    {
        model->setQuery("SELECT id, nomp, medecin, prix, datep FROM ordonnance ORDER BY nomp ASC");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom du Patient"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Médecin"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de Prescription"));
    }
    else if(choix == "datep decroissants")
    {
        model->setQuery("SELECT id, nomp, medecin, prix, datep FROM ordonnance ORDER BY datep DESC");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom du Patient"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Médecin"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de Prescription"));
    }
    else if(choix == "datep croissants")
    {
        model->setQuery("SELECT id, nomp, medecin, prix, datep FROM ordonnance ORDER BY datep ASC");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom du Patient"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Médecin"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de Prescription"));
    }

    return model;
}

// ## Statistique ## //

int ordonnance::statistique1(){
    int count = 0;

    QSqlQuery requete("SELECT * FROM ordonnance WHERE prix < 100");

    while(requete.next()) {
        count++;
    }

    return count;
}


int ordonnance::statistique2(){
    int count = 0;

    QSqlQuery requete("SELECT * FROM ordonnance WHERE prix >= 100");

    while(requete.next()) {
        count++;
    }

    return count;
}

// PDF
ordonnance* ordonnance::readordonnance(int val)
{
    QSqlQuery query;
    query.prepare("SELECT id, nomp, medecin, TO_CHAR(prix, 'FM9999999990.000') AS prix, "
                  "TO_CHAR(datep, 'DD-MM-YYYY') AS datep FROM ordonnance WHERE id = :val");

    query.bindValue(":val", val);

    if (query.exec())
    {
        while (query.next())
        {
            setId(query.value(0).toString());
            setNomp(query.value(1).toString());
            setMedecin(query.value(2).toString());
            QDate dateP = QDate::fromString(query.value(4).toString(), "dd-MM-yyyy");
            setDatep(dateP);
            setPrix(query.value(3).toFloat());
        }
    }
    return this;
}




