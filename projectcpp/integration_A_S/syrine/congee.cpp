#include "congee.h"
#include "ui_congee.h"
#include <QMessageBox>
#include <QDate>
#include<QSqlQuery>
#include "employee.h"
#include <QDebug>
#include "login.h"
#include <QSqlError>
congee::congee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::congee)
{
    ui->setupUi(this);
    employee e;

    ui->tableView1->setModel(e.affichercongee());
}

congee::~congee()
{
    delete ui;
}

void congee::on_validerButton_clicked() {
    // Récupérer l'ID saisi par l'utilisateur
       int id = ui->id->text().toInt();
       if (id <= 0) {
           QMessageBox::warning(this, tr("Erreur"), tr("Veuillez entrer un ID valide."));
           return;
       }

       // Requête pour récupérer les informations de l'employé à partir de l'ID
       QSqlQuery query;
       query.prepare("SELECT nom, prenom, post, sexe, salaire FROM employee WHERE id = :id");
       query.bindValue(":id", id);

       if (!query.exec()) { // Vérifier si la requête s'exécute correctement
           QMessageBox::critical(this, tr("Erreur"), tr("Échec de l'exécution de la requête : ") + query.lastError().text());
           return;
       }

       if (!query.next()) { // Vérifier si un résultat est retourné
           QMessageBox::warning(this, tr("Erreur"), tr("Aucun employé trouvé avec cet ID."));
           return;
       }

       // Lecture des données de l'employé
       QString nom = query.value("nom").toString();
       QString prenom = query.value("prenom").toString();
       QString post = query.value("post").toString();
       QString sexe = query.value("sexe").toString();
       double salaire = query.value("salaire").toDouble();

       // Debug : afficher les informations de l'employé dans la console
       qDebug() << "Employé trouvé : " << nom << prenom << post << sexe << salaire;

       // Continuer avec les informations saisies par l'utilisateur
       QString type = ui->type->currentText().trimmed().toLower(); // Normalisation du type de congé
       QDate dateDebut = ui->dateDebut->date();
       QDate dateFin = ui->dateFin->date();

       // Vérification des dates
       if (!dateDebut.isValid() || !dateFin.isValid()) {
           QMessageBox::warning(this, tr("Erreur"), tr("Les dates sont invalides."));
           return;
       }

       if (dateDebut > dateFin) {
           QMessageBox::warning(this, tr("Erreur"), tr("La date de début doit être antérieure ou égale à la date de fin."));
           return;
       }

       // Calculer la différence en jours entre dateDébut et dateFin
       int nombreDeJours = dateDebut.daysTo(dateFin) + 1; // +1 pour inclure les deux dates
       qDebug() << "Type du congé : " << type;
       qDebug() << "Nombre de jours calculé : " << nombreDeJours;

       // Vérifier les limites selon le type de congé
       if (type == "annuel" && nombreDeJours > 10) {
           QMessageBox::warning(this, tr("Erreur"), tr("Le congé annuel ne peut pas dépasser 10 jours."));
           return;
       } else if (type == "paternite/maternite" && nombreDeJours > 15) {
           QMessageBox::warning(this, tr("Erreur"), tr("Le congé de paternité/maternité ne peut pas dépasser 15 jours."));
           return;
       } else if (type == "maladie" && nombreDeJours > 20) {
           QMessageBox::warning(this, tr("Erreur"), tr("Le congé de maladie ne peut pas dépasser 20 jours."));
           return;
       }

       // Création de l'objet employé avec les données du congé
       employee e(id, type, dateDebut, dateFin);

       // Appel de la méthode pour ajouter/modifier le congé
       bool test = e.modifierconde();
       if (test) {
           ui->tableView1->setModel(e.affichercongee()); // Mise à jour de l'affichage
           QMessageBox::information(this, tr("Succès"), tr("Congé ajouté avec succès."));
       } else {
           QMessageBox::critical(this, tr("Erreur !!"), tr("Impossible d'ajouter le congé."), QMessageBox::Cancel);
       }
}

