#include "medicament.h"
#include "QRegularExpression"
#include <QMessageBox>
medicament::medicament() {
    id = 0;
    quantite = 0;
    nom = "";
    date_p = QDate();
    date_e = QDate();
    prix = 0.0f;
}

medicament::medicament(int Id,QString Nom,QDate DateP,float Prix,QDate DateE,int Quantite) {
    id = Id;
    nom = Nom;
    date_p = DateP;
    prix = Prix;
    date_e = DateE;
    quantite = Quantite;
}

// Getters
int medicament::getId() {
    return id;
}
int medicament::getQuantite() {
    return quantite;
}
QString medicament::getNom() {
    return nom;
}
QDate medicament::getDateP() {
    return date_p;
}
QDate medicament::getDateE() {
    return date_e;
}
float medicament::getPrix() {
    return prix;
}

// Setters
void medicament::setId(int id) {
    this->id = id;
}
void medicament::setQuantite(int quantite) {
    this->quantite = quantite;
}
void medicament::setNom(QString nom) {
    this->nom = nom;
}
void medicament::setDateP(QDate date_p) {
    this->date_p = date_p;
}
void medicament::setDateE(QDate date_e) {
    this->date_e = date_e;
}
void medicament::setPrix(float prix) {
    this->prix = prix;
}

// CRUD
// Create :


#include <QMessageBox>
#include <QRegularExpression>

bool medicament::Ajouter()
{

    if (id <= 0) {
        QMessageBox::warning(nullptr, "Erreur de saisie", "L'ID doit être un entier positif et non nul. Veuillez entrer un ID valide.");
        return false;
    }


    QRegularExpression regexId(R"(^\d+$)");
    if (!regexId.match(QString::number(id)).hasMatch()) {
        QMessageBox::warning(nullptr, "Erreur de saisie", "L'ID doit contenir uniquement des chiffres sans caractères spéciaux ni lettres.");
        return false;
    }


    QRegularExpression regexNom(R"(^[a-zA-ZÀ-ÿ\s]+$)");
    if (!regexNom.match(nom).hasMatch()) {
        QMessageBox::warning(nullptr, "Erreur de saisie", "Le nom doit contenir uniquement des lettres alphabétiques.");
        return false;
    }


    QRegularExpression regexPrix(R"(^\d+,\d{3}$)");
    QString prixStr = QString::number(prix, 'f', 3).replace('.', ',');  // Conversion du prix en chaîne avec une virgule
    if (!regexPrix.match(prixStr).hasMatch()) {
        QMessageBox::warning(nullptr, "Erreur de saisie", "Le prix doit contenir une virgule et exactement trois chiffres après la virgule. Exemple : 123,456");
        return false;
    }


    prixStr.replace(',', '.');
    double prixPourBaseDeDonnees = prixStr.toDouble();


    if (quantite <= 0) {
        QMessageBox::warning(nullptr, "Erreur de saisie", "La quantité doit être un entier positif. Veuillez entrer une quantité valide.");
        return false;
    }


    QRegularExpression regexQuantite(R"(^\d+$)");
    if (!regexQuantite.match(QString::number(quantite)).hasMatch()) {
        QMessageBox::warning(nullptr, "Erreur de saisie", "La quantité doit contenir uniquement des chiffres.");
        return false;
    }


    QSqlQuery query;
    query.prepare("INSERT INTO medicament (id, nom, date_p, prix, date_e, quantite) "
                  "VALUES (:id, :nom, :date_p, :prix, :date_e, :quantite)");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":date_p", date_p);
    query.bindValue(":prix", prixPourBaseDeDonnees);  // Insertion du prix converti
    query.bindValue(":date_e", date_e);
    query.bindValue(":quantite", quantite);


    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Erreur de base de données", "L'insertion dans la base de données a échoué. Vérifiez les données et réessayez.");
        return false;
    }

    QMessageBox::information(nullptr, "Succès", "Le médicament a été ajouté avec succès.");
    return true;
}


// Afficher

QSqlQueryModel *medicament::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id, nom, TO_CHAR(date_p, 'DD-MM-YYYY') AS date_p, "
                    "TO_CHAR(prix, 'FM9999999990.000') AS prix, "  // Formattage du prix
                    "TO_CHAR(date_e, 'DD-MM-YYYY') AS date_e, quantite FROM medicament");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Péremption"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Entrée"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Quantité"));

    return model;
}



//Modifier



bool medicament::modifier()
{
    QSqlQuery query;

    query.prepare("UPDATE medicament SET nom = :nom, date_p = :date_p, prix = :prix, date_e = :date_e, quantite = :quantite WHERE id = :id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":date_p", date_p);
    query.bindValue(":prix", prix);
    query.bindValue(":date_e", date_e);
    query.bindValue(":quantite", quantite);

    if (query.exec()) {
        QMessageBox::information(nullptr, "Modification réussie", "Les informations du médicament ont été modifiées avec succès.");
        return true;
    } else {
        QMessageBox::critical(nullptr, "Erreur de modification", "La modification des informations du médicament a échoué. Veuillez réessayer.");
        return false;
    }
}



// Supprimer

bool medicament::Supprime(int id)
{
    QSqlQuery query;


    query.prepare("SELECT COUNT(*) FROM medicament WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Erreur de base de données", "La vérification de l'existence de l'ID a échoué. Veuillez réessayer.");
        return false;
    }

    query.next();
    int count = query.value(0).toInt();

    if (count == 0) {
        QMessageBox::warning(nullptr, "Erreur de suppression", "Aucun médicament trouvé avec cet ID. Veuillez vérifier et réessayer.");
        return false;
    }


    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Confirmation de suppression",
                                  "Êtes-vous sûr de vouloir supprimer ce médicament ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) {
        return false;
    }


    query.prepare("DELETE FROM medicament WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        QMessageBox::information(nullptr, "Suppression réussie", "Le médicament a été supprimé avec succès.");
        return true;
    } else {
        QMessageBox::critical(nullptr, "Erreur de suppression", "La suppression du médicament a échoué. Veuillez réessayer.");
        return false;
    }
}



//reset

bool medicament::reset()
{
    QSqlQuery query;
    query.prepare("delete medicament");
    return query.exec();
}

// ## Recherche ## //

QSqlQueryModel *medicament::afficher_id(QString ch)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id, nom, TO_CHAR(date_p, 'DD-MM-YYYY') AS date_p, "
                    "TO_CHAR(prix, 'FM9999999990.000') AS prix, "
                    "TO_CHAR(date_e, 'DD-MM-YYYY') AS date_e, quantite FROM medicament where id = '"+ch+"'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Péremption"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Entrée"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Quantité"));

    return model;
}
QSqlQueryModel *medicament::afficher_nom(QString ch)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id, nom, TO_CHAR(date_p, 'DD-MM-YYYY') AS date_p, "
                    "TO_CHAR(prix, 'FM9999999990.000') AS prix, "
                    "TO_CHAR(date_e, 'DD-MM-YYYY') AS date_e, quantite FROM medicament where nom = '"+ch+"'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Péremption"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Entrée"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Quantité"));

    return model;
}

QSqlQueryModel *medicament::afficher_quantite(QString ch)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id, nom, TO_CHAR(date_p, 'DD-MM-YYYY') AS date_p, "
                    "TO_CHAR(prix, 'FM9999999990.000') AS prix, "
                    "TO_CHAR(date_e, 'DD-MM-YYYY') AS date_e, quantite FROM medicament where quantite = '"+ch+"'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Péremption"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Entrée"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Quantité"));

    return model;
}


// ## Tri ## //

QSqlQueryModel *medicament:: afficher_choix(QString choix)
{
    QSqlQueryModel * model =new QSqlQueryModel();

    if(choix=="prix croissants")
    {
        model->setQuery("SELECT id, nom, TO_CHAR(date_p, 'DD-MM-YYYY') AS date_p, "
                        "TO_CHAR(prix, 'FM9999999990.000') AS prix, "
                        "TO_CHAR(date_e, 'DD-MM-YYYY') AS date_e, quantite FROM medicament ORDER BY prix ASC");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Péremption"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Entrée"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Quantité"));
    }
    else if(choix=="prix decroissants")
    {
        model->setQuery("SELECT id, nom, TO_CHAR(date_p, 'DD-MM-YYYY') AS date_p, "
                        "TO_CHAR(prix, 'FM9999999990.000') AS prix, "
                        "TO_CHAR(date_e, 'DD-MM-YYYY') AS date_e, quantite FROM medicament ORDER BY prix DESC");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Péremption"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Entrée"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Quantité"));
    }
    else if(choix=="nom decroissants")
    {
        model->setQuery("SELECT id, nom, TO_CHAR(date_p, 'DD-MM-YYYY') AS date_p, "
                        "TO_CHAR(prix, 'FM9999999990.000') AS prix, "
                        "TO_CHAR(date_e, 'DD-MM-YYYY') AS date_e, quantite FROM medicament ORDER BY nom DESC");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Péremption"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Entrée"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Quantité"));
    }
    else if(choix=="nom croissants")
    {
        model->setQuery("SELECT id, nom, TO_CHAR(date_p, 'DD-MM-YYYY') AS date_p, "
                        "TO_CHAR(prix, 'FM9999999990.000') AS prix, "
                        "TO_CHAR(date_e, 'DD-MM-YYYY') AS date_e, quantite FROM medicament ORDER BY nom ASC");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Péremption"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Entrée"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Quantité"));

    }
    else if(choix=="quantite decroissants")
    {
        model->setQuery("SELECT id, nom, TO_CHAR(date_p, 'DD-MM-YYYY') AS date_p, "
                        "TO_CHAR(prix, 'FM9999999990.000') AS prix, "
                        "TO_CHAR(date_e, 'DD-MM-YYYY') AS date_e, quantite FROM medicament ORDER BY quantite DESC");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Péremption"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Entrée"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Quantité"));
    }
    else if(choix=="quantite croissants")
    {
        model->setQuery("SELECT id, nom, TO_CHAR(date_p, 'DD-MM-YYYY') AS date_p, "
                        "TO_CHAR(prix, 'FM9999999990.000') AS prix, "
                        "TO_CHAR(date_e, 'DD-MM-YYYY') AS date_e, quantite FROM medicament ORDER BY quantite ASC");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Péremption"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Entrée"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Quantité"));

    }
    return model ;
}

// ## Statistique ## //

int medicament::statistique1(){
    int count = 0;

    QSqlQuery requete("SELECT * FROM medicament WHERE quantite < 30");

    while(requete.next()) {
        count++;
    }

    return count;
}


int medicament::statistique2(){
    int count = 0;

    QSqlQuery requete("SELECT * FROM medicament WHERE quantite >= 30");

    while(requete.next()) {
        count++;
    }

    return count;
}


// PDF
medicament* medicament::readmedicament(int val)
{
    QSqlQuery query;
    query.prepare("SELECT id, nom, TO_CHAR(date_p, 'DD-MM-YYYY') AS date_p, "
                  "TO_CHAR(prix, 'FM9999999990.000') AS prix, "
                  "TO_CHAR(date_e, 'DD-MM-YYYY') AS date_e, quantite FROM medicament WHERE id = :val");

    query.bindValue(":val", val);

    if (query.exec())
    {
        while (query.next())
        {
            setId(query.value(0).toInt());
            setNom(query.value(1).toString());
            QDate dateP = QDate::fromString(query.value(2).toString(), "dd-MM-yyyy");
            QDate dateE = QDate::fromString(query.value(4).toString(), "dd-MM-yyyy");
            setDateP(dateP);
            setDateE(dateE);
            setPrix(query.value(3).toFloat());
            setQuantite(query.value(5).toInt());
        }
    }
    return this;
}

//Notification
QSqlQueryModel* medicament::checkExpiration() {
    QSqlQueryModel* model = new QSqlQueryModel();

    QDate currentDate = QDate::currentDate();
    QDate nearExpirationDate = currentDate.addDays(5);

    QString queryString =
        "SELECT id, nom, date_p FROM medicament "
        "WHERE date_p <= :near_exp OR date_p < :expired";

    QSqlQuery query;
    query.prepare(queryString);
    query.bindValue(":near_exp", nearExpirationDate);
    query.bindValue(":expired", currentDate);

    if (query.exec()) {
        model->setQuery(std::move(query));
    } else {
        qDebug() << "Query failed: " << query.lastError().text();
    }

    return model;
}

QSqlQueryModel *medicament::afficher_flame()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT start_time, start_date, status FROM FLAME_EVENTS");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Temps de l'incendie"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date de l'incendie"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Message"));

    return model;
}

