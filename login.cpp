#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
#include<QtDebug>
#include"employee.h"
#include "employeeui.h"
#include <QInputDialog>
int login::Idg=0;
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}
void login::clrinput(){
    ui->line_id->setText("");
    ui->line_password->setText("");

}
void login::on_pushButton_3_clicked()
{
    // Récupération de l'ID et du mot de passe depuis les champs de texte
        int idd = ui->line_id->text().toInt();
        Idg = idd; // Variable globale si nécessaire
        QString password = ui->line_password->text();

        // Requête SQL pour vérifier si l'employé existe avec l'ID et récupérer son poste et mot de passe
        QSqlQuery query;
        query.prepare("SELECT post, password FROM employee WHERE id = :id");
        query.bindValue(":id", idd);

        // Exécution de la requête et vérification si l'ID existe
        if (!query.exec() || !query.next()) {
            QMessageBox::critical(nullptr, QObject::tr("Non valide"),
                                  QObject::tr("Cet ID n'existe pas.\n"
                                              "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
            return;
        }

        // Vérifier si l'employé a le poste "Ressources humaines"
        QString post = query.value("post").toString();
        if (post != "Ressources humaines") {
            QMessageBox::critical(nullptr, QObject::tr("Non valide"),
                                  QObject::tr("Seuls les employés des Ressources humaines peuvent accéder.\n"
                                              "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
            return;
        }

        // Vérifier si le mot de passe est correct
        QString storedPassword = query.value("password").toString();
        if (storedPassword != password) {
            QMessageBox::critical(nullptr, QObject::tr("Non valide"),
                                  QObject::tr("Mot de passe incorrect.\n"
                                              "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
            return;
        }

        // Si toutes les conditions sont remplies, accès autorisé
        clrinput();
        QMessageBox::information(nullptr, QObject::tr("Valide"),
                                  QObject::tr("Accès autorisé : Bienvenue.\n"
                                              "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);

        // Ouvrir la fenêtre principale
        ma = new employeeUI(this);
        ma->show();
        this->close();  // Ferme la fenêtre de login


}

void login::on_forgotPasswordButton_clicked()
{
    // Demander à l'utilisateur d'entrer son ID
       bool ok;
       int id = QInputDialog::getInt(this, tr("Réinitialiser mot de passe"),
                                     tr("Entrez votre ID:"), 0, 0, 9999, 1, &ok);

       if (ok && id > 0) {
           // Vérifier si l'ID existe dans la base de données et récupérer le poste
           QSqlQuery query;
           query.prepare("SELECT post FROM employee WHERE id = :id");
           query.bindValue(":id", id);

           if (!query.exec()) {
               QMessageBox::critical(this, tr("Erreur"), tr("Erreur lors de la vérification de l'ID dans la base de données."));
               return;
           }

           if (!query.next()) { // Si l'ID n'existe pas dans la base de données
               QMessageBox::warning(this, tr("Erreur"), tr("Aucun employé trouvé avec cet ID."));
               return;
           }

           QString post = query.value("post").toString();

           // Vérifier si le poste est "Ressources humaines"
           if (post.toLower() != "ressources humaines") {
               QMessageBox::warning(this, tr("Accès refusé"), tr("Seuls les employés des Ressources humaines peuvent réinitialiser leur mot de passe."));
               return;
           }

           // Demander à l'utilisateur de saisir un nouveau mot de passe
           QString newPassword = QInputDialog::getText(this, tr("Réinitialiser mot de passe"),
                                                       tr("Entrez votre nouveau mot de passe:"), QLineEdit::Password, "", &ok);

           if (ok && !newPassword.isEmpty()) {
               // Vérifier que le mot de passe n'est pas déjà utilisé par un autre employé des "Ressources humaines"
               QSqlQuery checkQuery;
               checkQuery.prepare("SELECT COUNT(*) FROM employee WHERE post = 'Ressources humaines' AND password = :password");
               checkQuery.bindValue(":password", newPassword);

               if (!checkQuery.exec()) {
                   QMessageBox::critical(this, tr("Erreur"), tr("Erreur lors de la vérification du mot de passe dans la base de données."));
                   return;
               }

               checkQuery.next();
               int count = checkQuery.value(0).toInt();

               if (count > 0) { // Si le mot de passe est déjà utilisé
                   QMessageBox::warning(this, tr("Erreur de mot de passe"), tr("Ce mot de passe est déjà utilisé par un autre employé des Ressources humaines."));
                   return;
               }

               // Mettre à jour le mot de passe dans la base de données
               QSqlQuery updateQuery;
               updateQuery.prepare("UPDATE employee SET password = :password WHERE id = :id");
               updateQuery.bindValue(":password", newPassword);
               updateQuery.bindValue(":id", id);

               if (!updateQuery.exec()) {
                   QMessageBox::critical(this, tr("Erreur"), tr("Erreur lors de la mise à jour du mot de passe."));
                   return;
               }

               // Afficher un message de succès
               QMessageBox::information(this, tr("Succès"), tr("Votre mot de passe a été réinitialisé avec succès."));
           }
       }
   }

