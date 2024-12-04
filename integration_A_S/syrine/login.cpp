#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
#include<QtDebug>
#include"employee.h"
#include "employeeui.h"
#include <QInputDialog>
#include <QIntValidator>
#include <QVBoxLayout>
#include "../abdou/medicament_ui.h"
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
            qDebug() << "Tentative d'ouverture du port série COM3 avec baud rate 9600";
            serial->setPortName("COM3");
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);

            if (serial->open(QIODevice::ReadOnly)) {
                qDebug() << "Port série ouvert avec succès.";
                connect(serial, &QSerialPort::readyRead, this, &login::readSerialData);
            } else {
                qDebug() << "Erreur lors de l'ouverture du port série : " << serial->errorString();
            }
        } else {
            qDebug() << "Le port série est déjà ouvert.";
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
            if (serial->bytesAvailable() > 0) {
                QByteArray data = serial->readAll();
                // Convertir en chaîne et l'insérer dans le champ 'line_id'
                ui->line_password->insert(QString::fromLatin1(data).trimmed());  // Utilisation de fromLatin1() pour garantir que le texte est bien interprété
                isArduinoInput = true;  // Indique que l'ID a été entré via Arduino
            } else {
                qDebug() << "Aucune donnée disponible à lire dans le tampon.";
            }
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
    // Fermer le port série si ouvert
        closeSerialPort();

        // Récupérer l'ID et le mot de passe de l'utilisateur
        int idd = ui->line_id->text().toInt();
        QString password = ui->line_password->text();

        // Vérification selon l'origine de l'entrée (Arduino ou PC)
        QSqlQuery query;

        if (isArduinoInput) {
            // Si l'entrée provient du clavier numérique (Arduino), ignorer l'ID
            query.prepare("SELECT nom, prenom, post, password FROM employee WHERE password = :password");
            query.bindValue(":password", password); // Chercher par mot de passe uniquement
        } else {
            // Si l'entrée provient du clavier standard (PC), vérifier l'ID et le mot de passe
            query.prepare("SELECT nom, prenom, post, password FROM employee WHERE id = :id AND password = :password");
            query.bindValue(":id", idd);
            query.bindValue(":password", password);
        }

        if (!query.exec() || !query.next()) {
            // Si la requête échoue ou l'utilisateur n'est pas trouvé, afficher une erreur
            QMessageBox::critical(nullptr, QObject::tr("Non valide"),
                                  QObject::tr("Cet ID ou mot de passe est incorrect.\nCliquez sur Annuler pour quitter."),
                                  QMessageBox::Cancel);
            return;
        }

        // Récupérer les informations de l'utilisateur
        QString nom = query.value("nom").toString();
        QString prenom = query.value("prenom").toString();
        QString post = query.value("post").toString();

        // Affichage du message de bienvenue avec couleurs et formatage HTML
        QDialog *dialog = new QDialog(this);
        dialog->setWindowTitle(tr("Valide"));
        dialog->resize(400, 200);

        QString htmlText = QString(
            "<p style='font-size:18px; font-weight:bold; text-align:center;'>"
            "Bienvenue"
            "</p>"
            "<p style='font-size:16px; text-align:center;'>"
            "<span style='color:blue;'>%1</span> <span style='color:blue;'>%2</span><br>"
            "Poste : <span style='color:red;'>%3</span>"
            "</p>")
            .arg(nom)
            .arg(prenom)
            .arg(post);

        QLabel *label = new QLabel(dialog);
        label->setText(htmlText);
        label->setAlignment(Qt::AlignCenter);

        QVBoxLayout *layout = new QVBoxLayout(dialog);
        layout->addWidget(label);

        QPushButton *button = new QPushButton(tr("OK"), dialog);
        connect(button, &QPushButton::clicked, dialog, &QDialog::accept);
        layout->addWidget(button);

        dialog->exec();

        // Gestion des interfaces selon le poste
        if (post == "Ressources humaines") {
            ma = new employeeUI(this);
            ma->show();
        } else if (post == "Responsable Stock") {
            maStock = new medicament_UI(this);
            maStock->show();
        } else {
            QMessageBox::critical(nullptr, QObject::tr("Non valide"),
                                  QObject::tr("Accès refusé : Poste non autorisé."),
                                  QMessageBox::Cancel);
            return;
        }

        hide(); // Masquer la fenêtre de connexion
}

void login::on_forgotPasswordButton_clicked()
{
    // Demander à l'utilisateur d'entrer son ID
       bool ok;
       int id = QInputDialog::getInt(this, tr("Réinitialiser mot de passe"),
                                     tr("Entrez votre ID:"), 0, 0, 99999999, 1, &ok);

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

