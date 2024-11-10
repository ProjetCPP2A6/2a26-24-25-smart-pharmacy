#include "employee.h"

employee::employee() {
    id = 0;
    nom = "";
    prenom = "";
    post = "";
    sexe = "";
    salaire = 0.0;
}

employee::employee(int Id,QString Nom,QString Prenom,QString Post,QString Sexe,float Salaire){
    id = Id;
    nom = Nom;
    prenom = Prenom;
    post = Post;
    sexe = Sexe;
    salaire = Salaire;
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

// CRUD
// Create :

bool employee::Ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO employee (id, nom, prenom, post, sexe, salaire) "
                  "VALUES (:id, :nom, :prenom, :post, :sexe, :salaire)");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":post", post);
    query.bindValue(":sexe", sexe);
    query.bindValue(":salaire", salaire);

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


