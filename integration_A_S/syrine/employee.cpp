#include "employee.h"
#include<QtDebug>
#include<QDate>
#include <QSqlError>
#include<QMessageBox>
employee::employee() {
    id = 0;
    nom = "";
    prenom = "";
    post = "";
    sexe = "";
    salaire = 0.0;
    password = "";
    type="";

}


employee::employee(int Id,QString Nom,QString Prenom,QString Post,QString Sexe,float Salaire,QString Password){
    id = Id;
    nom = Nom;
    prenom = Prenom;
    post = Post;
    sexe = Sexe;
    salaire = Salaire;
    password =Password;
}
employee::employee(int Id,QString Nom,QString Prenom,QString Post,QString Sexe,float Salaire){
    id = Id;
    nom = Nom;
    prenom = Prenom;
    post = Post;
    sexe = Sexe;
    salaire = Salaire;

}
employee::employee(int Id,QString Type,QDate DateDebut,QDate DateFin){
   id = Id;
   type=Type;
   dateDebut=DateDebut;
   dateFin=DateFin;


}
// Getters

int employee::getId() {
    return id;
}
QString employee::getNom() {
    return nom;
}
QString employee::getPrenom() {
    return prenom;
}
QString employee::getPost() {
    return post;
}
QString employee::getSexe() {
    return sexe;
}
float employee::getSalaire() {
    return salaire;
}
QString employee::getPassword() {
    return password;
}
QString employee::getType() {
    return type;
}
QDate employee::getDateDebut() {
    return dateDebut;
}
QDate employee::getDateFin() {
    return dateFin;
}

// Setters

void employee::setId(int Id) {
    id = Id;
}
void employee::setNom(QString Nom) {
    nom = Nom;
}
void employee::setPrenom(QString Prenom) {
    prenom = Prenom;
}
void employee::setPost(QString Post) {
    post = Post;
}
void employee::setSexe(QString Sexe) {
    sexe = Sexe;
}
void employee::setSalaire(float Salaire) {
    salaire = Salaire;
}
void employee::setPassword (QString Password) {
    password = Password;
}
void employee::setType(QString Type) {
    type =Type;
}
void employee::setDateDebut(QDate DateDebut)  {
    dateDebut = DateDebut;
}
void employee::setDateFin(QDate DateFin){
    dateFin = DateFin;
}

bool employee::Ajouter()
{
    QSqlQuery query;
QString idstr =QString::number(id);
QString salairestr =QString::number(salaire);



    query.prepare("INSERT INTO employee (id, nom, prenom, post, sexe, salaire ,password) "
                  "VALUES (:id, :nom, :prenom, :post, :sexe, :salaire, :password)");

    query.bindValue(":id", idstr);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":post", post);
    query.bindValue(":sexe", sexe);
    query.bindValue(":salaire", salairestr);
    query.bindValue(":password", password);



    return query.exec();
}


// Afficher

QSqlQueryModel* employee::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT id, nom, prenom, post, sexe, "
                    "TO_CHAR(salaire, 'FM99999999.00') AS salaire "
                    "FROM employee");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poste"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Salaire"));

    return model;
}

// Modifier

bool employee::modifier()
{
    QSqlQuery query;

    query.prepare("UPDATE employee SET nom = :nom, prenom = :prenom, post = :post, sexe = :sexe, "
                  "salaire = :salaire WHERE id = :id");

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":post", post);
    query.bindValue(":sexe", sexe);
    query.bindValue(":salaire", salaire);

    query.bindValue(":id", id);

    return query.exec();
}
//modefier conge
bool employee::modifierconde()
{
    QSqlQuery query;

    // Convertir les dates en chaînes dans le format "yyyy-MM-dd"
    QString datedebutStr = dateDebut.toString("yyyy-MM-dd");
    QString datefinStr = dateFin.toString("yyyy-MM-dd");

    qDebug() << "Date début: " << datedebutStr;
    qDebug() << "Date fin: " << datefinStr;

    // Calculer la durée en jours
    int daysDifference = dateDebut.daysTo(dateFin);

    // Vérifier si la durée du congé dépasse le nombre de jours autorisé
    if (type == "Annuel" && daysDifference > 10) {
        QMessageBox::warning(nullptr, "Erreur", "La durée du congé annuel ne peut pas dépasser 10 jours.");
        return false;
    } else if (type == "Paternité/Maternité" && daysDifference > 15) {
        QMessageBox::warning(nullptr, "Erreur", "La durée du congé de paternité/maternité ne peut pas dépasser 15 jours.");
        return false;
    } else if (type == "Maladie" && daysDifference > 20) {
        QMessageBox::warning(nullptr, "Erreur", "La durée du congé de maladie ne peut pas dépasser 20 jours.");
        return false;
    }

    // Si la durée est correcte, ajuster la date de fin selon le type de congé
    if (type == "Annuel") {
        dateFin = dateDebut.addDays(10);  // Ajoute 10 jours à la date de début
    } else if (type == "Paternité/Maternité") {
        dateFin = dateDebut.addDays(15);  // Ajoute 15 jours à la date de début
    } else if (type == "Maladie") {
        dateFin = dateDebut.addDays(20);  // Ajoute 20 jours à la date de début
    }

    // Mettre à jour la date de fin après ajustement
    datefinStr = dateFin.toString("yyyy-MM-dd");

    // Préparer la requête SQL pour mettre à jour les dates et autres champs
    query.prepare("UPDATE employee SET type = :type, datedebut = :datedebut, datefin = :datefin WHERE id = :id");

    // Lier les valeurs
    query.bindValue(":type", type);
    query.bindValue(":datedebut", dateDebut);
    query.bindValue(":datefin", dateFin);
    query.bindValue(":id", id);

    // Exécuter la requête
    if (!query.exec()) {
        // Afficher l'erreur si la requête échoue
        qDebug() << "Erreur SQL : " << query.lastError().text();
        return false;
    }

    return true;  // Si tout est OK, retourner true
}

// Supprimer

bool employee::Supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM employee WHERE id = :id");
    query.bindValue(":id", id);
    return query.exec();
}

//reset

bool employee::reset()
{
    QSqlQuery query;
    query.prepare("delete employee");
    return query.exec();
}

bool employee::doesIDExist(int idd) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM employee WHERE id = :id");
    query.bindValue(":id", idd);

    if (query.exec()) {
        if (query.next()) {
            int count = query.value(0).toInt();
            return count > 0; // Retourne true si l'ID existe
        }
    } else {
        qDebug() << "Erreur SQL dans doesIDExist:" ;
    }

    return false;
}

bool employee::isPasswordCorrect(int idd, const QString& password) {
    QSqlQuery query;
    query.prepare("SELECT password FROM employee WHERE id = :id");
    query.bindValue(":id", idd);

    if (query.exec()) {
        if (query.next()) {
            QString dbPassword = query.value(0).toString();
            return dbPassword == password;
        }
    } else {
        qDebug() << "Erreur SQL dans isPasswordCorrect:";
    }

    return false;
}

QSqlQueryModel* employee::affichercongee()
{
    QSqlQueryModel *model = new QSqlQueryModel();

        // Créer un objet QSqlQuery
        QSqlQuery query;

        // Préparer la requête avec un paramètre :id
        query.prepare("SELECT id, type, datedebut, datefin FROM employee");

        // Lier la valeur du paramètre :id à la variable id (si nécessaire)
        query.bindValue(":id", id);

        // Exécuter la requête
        if (!query.exec()) {
            qDebug() << "Erreur de requête SQL:" << query.lastError();
            return nullptr; // En cas d'erreur, retourner nullptr
        }

        // Définir le modèle avec les résultats de la requête
        model->setQuery(query);

        // Définir les en-têtes de colonne
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));          // Colonne 0 pour ID
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));        // Colonne 1 pour Type
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Départ")); // Colonne 2 pour Date Départ
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Fin"));    // Colonne 3 pour Date Fin

        return model;
}

QList<QPair<QString, int>> employee::getStatistics()
{
    QList<QPair<QString, int>> statistics;

        QSqlQuery query;
        query.prepare("SELECT salaire FROM employee"); // On récupère uniquement les salaires

        // Exécuter la requête
        if (!query.exec()) {
            qDebug() << "Erreur lors de l'exécution de la requête:" << query.lastError().text();
            return statistics;
        }

        // Dictionnaire pour stocker les occurrences par salaire
        QMap<int, int> salaireCount;

        // Traiter les résultats
        while (query.next()) {
            int salaire = query.value("salaire").toInt();

            if (salaire > 0) {
                // Incrementer le compteur pour ce salaire
                salaireCount[salaire]++;
            }
        }

        // Convertir le QMap en QList de paires (Salaire, Nombre d'employés)
        for (auto it = salaireCount.begin(); it != salaireCount.end(); ++it) {
            statistics.append(QPair<QString, int>(QString::number(it.key()), it.value()));
        }

        // Affichage pour le débogage
        for (const auto &stat : statistics) {
            qDebug() << "Salaire:" << stat.first << ", Nombre d'employés:" << stat.second;
        }

        return statistics;
}







