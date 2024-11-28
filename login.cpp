#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
#include<QtDebug>
#include"employee.h"
#include "employeeui.h"
#include <QInputDialog>
#include <QIntValidator>
int login::Idg=0;
login::login(QWidget *parent) :
    QDialog(parent),    // Initialisation du parent
    ui(new Ui::login),  // Initialisation de l'interface utilisateur
    serial(new QSerialPort(this))  // Initialisation du port série
{
    ui->setupUi(this);
    openSerialPort(); // Ouvrir le port série dès le début
    ui->line_id->setValidator(new QIntValidator(0,99999999, this));
}

login::~login()
{
    closeSerialPort();
    delete serial;
    delete ui;
}
void login::openSerialPort() {

    if (!serial->isOpen()) {
            serial->setPortName("COM3");  // Changez ce port selon votre système
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);

            qDebug() << "Tentative d'ouverture du port série COM3";

            if (serial->open(QIODevice::ReadOnly)) {
                connect(serial, &QSerialPort::readyRead, this, &login::readSerialData);
                qDebug() << "Port série ouvert avec succès.";
            } else {
                QMessageBox::warning(this, tr("Erreur"), tr("Impossible d'ouvrir le port série."));
                qDebug() << "Erreur lors de l'ouverture du port série: " << serial->errorString();
            }
        }
}

void login::closeSerialPort() {
    if (serial && serial->isOpen()) {
           serial->close();
           qDebug() << "Port série fermé avec succès.";
       }

}
void login::clrinput(){
    ui->line_id->setText("");
    ui->line_password->setText("");

}
bool isArduinoInput = false;
void login::readSerialData()
{
    if (serial && serial->isOpen()) {
            QByteArray data = serial->readAll();
            // Convertir en chaîne et l'insérer dans le champ 'line_id'
            ui->line_id->insert(QString::fromLatin1(data));  // Utilisation de fromLatin1() pour garantir que le texte est bien interprété
            isArduinoInput = true;  // Indique que l'ID a été entré via Arduino
        } else {
            qDebug() << "Port série non ouvert, impossible de lire les données.";
        }
}
void login::resetFields() {
    ui->line_id->clear();  // Effacer le champ de l'ID
    ui->line_id->setFocus();  // Mettre le focus sur le champ de l'ID
}
void login::on_pushButton_3_clicked()
{
        int idd = ui->line_id->text().toInt();
        QString password = ui->line_password->text();

        // Vérification si un mot de passe est nécessaire
        if (!isArduinoInput && password.isEmpty()) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Veuillez entrer un mot de passe."), QMessageBox::Cancel);
            return;
        }

        QSqlQuery query;
        query.prepare("SELECT post, password FROM employee WHERE id = :id");
        query.bindValue(":id", idd);

        if (!query.exec() || !query.next()) {
            QMessageBox::critical(nullptr, QObject::tr("Non valide"),
                                  QObject::tr("Cet ID n'existe pas.\n"
                                              "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
            return;
        }

        QString post = query.value("post").toString();

        if (post != "Ressources humaines") {
            QMessageBox::critical(nullptr, QObject::tr("Non valide"),
                                  QObject::tr("Seuls les employés des Ressources humaines peuvent accéder.\n"
                                              "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
            return;
        }

        // Gestion des accès via Arduino ou manuellement
        if (isArduinoInput || query.value("password").toString() == password) {
            clrinput();  // Réinitialiser les champs de saisie

            QMessageBox::information(nullptr, QObject::tr("Valide"),
                                     QObject::tr("Accès autorisé : Bienvenue.\n"
                                                 "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);

            // Fermer le port série avant de passer à la prochaine fenêtre
            closeSerialPort();

            // Ouvrir la fenêtre principale (employeeUI)
            ma = new employeeUI(this);
            ma->show();

            // Masquer la fenêtre de connexion au lieu de la fermer
            hide();
        } else {
            QMessageBox::critical(nullptr, QObject::tr("Non valide"),
                                  QObject::tr("Mot de passe incorrect.\n"
                                              "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        }
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

