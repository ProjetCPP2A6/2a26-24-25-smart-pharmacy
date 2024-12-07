#include "medicament_ui.h"
#include "ui_medicament_ui.h"
#include "statistique.h"
#include "qrcodedialog.h"
#include "arduino.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QSqlRecord>

#include <QFile>
#include <QPixmap>
#include <QPainter>
#include <QPrinter>
#include "../syrine/login.h"
#include "../syrine/employeeui.h"
medicament_UI::medicament_UI(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::medicament_UI)
{
    ui->setupUi(this);
    arduino.connect_arduino();
    QTimer *dataTimer = new QTimer(this);
    connect(dataTimer, &QTimer::timeout, this, &medicament_UI::handleArduinoData);
    dataTimer->start(1000);
}

void medicament_UI::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);
    ui->tableView->setModel(m.afficher());
    QSqlQueryModel* model = m.checkExpiration();

    if (model->rowCount() > 0) {
        int expiredCount = 0;
        int nearExpiredCount = 0;

        for (int i = 0; i < model->rowCount(); ++i) {
            QDate expiryDate = model->record(i).value("date_p").toDate();

            if (expiryDate < QDate::currentDate()) {
                expiredCount++;
            } else if (expiryDate <= QDate::currentDate().addDays(5)) {
                nearExpiredCount++;
            }
        }

        QString message = QString("Il y a %1 médicament(s) expiré(s) et %2 médicament(s) qui vont expirer dans 5 jours.")
                              .arg(expiredCount)
                              .arg(nearExpiredCount);

        QSystemTrayIcon* trayIcon = new QSystemTrayIcon(this);
        trayIcon->setIcon(QIcon(":/image/iconMed.png"));
        trayIcon->show();

        trayIcon->showMessage("Avertissement d'expiration",
                              message,
                              QSystemTrayIcon::Warning,
                              10000);

        ui->pushButton_Notif->setVisible(true);
        ui->pushButton_noNotif->setVisible(false);


        QTimer::singleShot(11000, trayIcon, &QSystemTrayIcon::hide);
    } else {
        ui->pushButton_Notif->setVisible(false);
        ui->pushButton_noNotif->setVisible(true);
    }
}


medicament_UI::~medicament_UI()
{
    delete ui;
}

void medicament_UI::resetInput()
{
    ui->id->setText("");
     ui->nom->setText("");
      ui->prix->setText("");
       ui->quantite->setText("");
}


void medicament_UI::on_add_clicked()
{
        int id = ui->id->text().toInt();
        QString nom = ui->nom->text();
        QDate date_p = ui->date_p->date();
        float prix = ui->prix->text().toFloat();
        QDate date_e = ui->date_e->date();
        int quantite = ui->quantite->text().toInt();

        if (nom.isEmpty() || prix <= 0 || quantite <= 0) {
            QMessageBox::warning(this, QObject::tr("Entrée invalide"),
                                 QObject::tr("Veuillez remplir correctement tous les champs."));
            return;
        }

        medicament m(id, nom, date_p, prix, date_e, quantite);
        bool test = m.Ajouter();

        if (test) {
            ui->tableView->setModel(m.afficher());
            resetInput();
            QMessageBox::information(this, QObject::tr("Succès"),
                                     QObject::tr("Le médicament a été ajouté avec succès."));
        } else {
            QMessageBox::critical(this, QObject::tr("Erreur !!"),
                                 QObject::tr("Impossible d'ajouter le médicament."), QMessageBox::Cancel);
            resetInput();
        }
}

void medicament_UI::on_edit_clicked()
{
        int id = ui->id->text().toInt();
        QString nom = ui->nom->text();
        QDate date_p = ui->date_p->date();
        float prix = ui->prix->text().toFloat();
        QDate date_e = ui->date_e->date();
        int quantite = ui->quantite->text().toInt();
        medicament m(id, nom, date_p, prix, date_e, quantite);
        bool test = m.modifier();

        if (test) {
            ui->tableView->setModel(m.afficher());
            resetInput();
            QMessageBox::information(this, QObject::tr("Succès"),
                                     QObject::tr("Le médicament a été modifié avec succès."));
        }
        else {
            QMessageBox::critical(this, QObject::tr("Erreur !!"),
                                  QObject::tr("Impossible de modifier le médicament."), QMessageBox::Cancel);
            resetInput();
        }

}

void medicament_UI::on_supp_button_clicked()
{
         medicament m1;
        m1.setId(ui->supp->text().toInt());
        bool suppressionReussie = m1.Supprime(m1.getId());

        if (suppressionReussie) {
            ui->tableView->setModel(m.afficher());
            ui->supp->setText("");
            QMessageBox::information(this, QObject::tr("Succès"),
                                     QObject::tr("Le médicament a été supprimé avec succès."));
        } else {
            QMessageBox::critical(this, QObject::tr("Erreur !!"),
                                  QObject::tr("Impossible de supprimer le médicament."), QMessageBox::Cancel);
        }
}


void medicament_UI::on_pushButton_clicked()
{
    QString val=ui->lineEdit_10->text();
    QString option=ui->comboBox->currentText();

    if((val!="")&&(option=="ID"))
    {        ui->tableView->setModel(m.afficher_id(val));}
    else if((val!="")&&(option=="Nom"))
    {
        ui->tableView->setModel(m.afficher_nom(val));
    }
    else if((val!="")&&(option=="Quantite"))
    {
        ui->tableView->setModel(m.afficher_quantite(val));
    }
}


void medicament_UI::on_pushButton_14_clicked()
{
        statistique s;
        s.exec();  // Cela ouvre la fenêtre modale
}


void medicament_UI::on_pushButton_2_clicked()
{
  ui->tableView->setModel(m.afficher());
}


void medicament_UI::on_comboBox_2_currentIndexChanged(int index)
{
    QString choix=ui->comboBox_2->currentText();
    ui->tableView->setModel(m.afficher_choix(choix));
}


void medicament_UI::on_pushButton_13_clicked()
{
        int id = ui->lineEdit->text().toInt();
        medicament *Med;
        Med = m.readmedicament(id);

        QString id_string = QString::number(Med->getId());
        QString nom_string = Med->getNom();
        QString date_p_string = Med->getDateP().toString("dd-MM-yyyy");
        QString date_e_string = Med->getDateE().toString("dd-MM-yyyy");
        QString quantite_string = QString::number(Med->getQuantite());
        QString prix_string = QString::number(Med->getPrix(), 'f', 2);

        // Modifier le chemin pour exporter le PDF sur le bureau
        QString pdfFilePath = "C:/Users/sirine/Desktop/" + nom_string + "_" + id_string + ".pdf";

        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(pdfFilePath);

        QPainter painter;
        if (!painter.begin(&printer))
        {
            qWarning() << "Échec de l'ouverture du fichier PDF pour l'écriture";
            return;
        }

        painter.setFont(QFont("Bahnschrift Light", 25));
        painter.setPen(Qt::blue);
        painter.drawText(130, 230, "Informations sur le médicament");
        painter.setPen(Qt::black);
        painter.drawText(120, 150, "Système de gestion des médicaments");

        painter.drawText(150, 300, "ID: " + id_string);
        painter.drawText(150, 400, "Nom: " + nom_string);
        painter.drawText(150, 500, "Date Entrée: " + date_e_string);
        painter.drawText(150, 600, "Date de Péremption: " + date_p_string);
        painter.drawText(150, 700, "Quantité: " + quantite_string);
        painter.drawText(150, 800, "Prix: " + prix_string);

        painter.end();

        // Afficher un message de confirmation
        QMessageBox::information(this, "Exportation réussie", "Le fichier PDF a été enregistré avec succès sur votre bureau.");
}

void medicament_UI::on_pushButton_5_clicked()
{
    QRCodeDialog *qrDialog = new QRCodeDialog(this);  // Utilisez 'this' pour lier au parent
    qrDialog->show();
}

void medicament_UI::on_pushButton_noNotif_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Success"),
                             QObject::tr("Tout les medicament sont on bonne etat."), QMessageBox::Ok);

}


#include <QSystemTrayIcon>
#include <QSqlRecord>

void medicament_UI::on_pushButton_Notif_clicked()
{
    QSqlQueryModel* model = m.checkExpiration();

    if (model->rowCount() > 0) {
        QString warningMessage = "Les médicaments suivants sont proches de leur date de péremption :\n";
        QString criticalMessage = "Les médicaments suivants sont périmés :\n";
        bool hasWarning = false;
        bool hasCritical = false;

        for (int i = 0; i < model->rowCount(); ++i) {
            QString name = model->record(i).value("nom").toString();
            QDate expiryDate = model->record(i).value("date_p").toDate();

            if (expiryDate < QDate::currentDate()) {
                hasCritical = true;
                criticalMessage += name + " (Périmé le " + expiryDate.toString("dd/MM/yyyy") + ")\n";
            } else {
                hasWarning = true;
                warningMessage += name + " (Expire le " + expiryDate.toString("dd/MM/yyyy") + ")\n";
            }
        }

        QSystemTrayIcon* trayIcon = new QSystemTrayIcon(this);
        trayIcon->setIcon(QIcon(":/image/iconMed.png"));
        trayIcon->show();

        if (hasCritical) {
            trayIcon->showMessage("Critique : Médicaments périmés",
                                  criticalMessage,
                                  QSystemTrayIcon::Critical,
                                  10000);
        }

        if (hasWarning) {
            trayIcon->showMessage("Attention : Médicaments proches de la péremption",
                                  warningMessage,
                                  QSystemTrayIcon::Warning,
                                  10000);
        }
        } else {
            QSystemTrayIcon* trayIcon = new QSystemTrayIcon(this);
            trayIcon->setIcon(QIcon(":/image/iconMed.png"));
            trayIcon->show();
            trayIcon->showMessage("Succès",
                                  "Tous les médicaments sont en bon état.",
                                  QSystemTrayIcon::Information,
                                  5000);
        }
}



void medicament_UI::on_tableView_clicked(const QModelIndex &index)
{
    int row = index.row();
    QAbstractItemModel *model = ui->tableView->model();


    ui->id->setText(model->index(row, 0).data().toString());
    ui->nom->setText(model->index(row, 1).data().toString());
    ui->date_p->setDate(QDate::fromString(model->index(row, 2).data().toString(), "dd-MM-yyyy"));
    ui->prix->setText(model->index(row, 3).data().toString());
    ui->date_e->setDate(QDate::fromString(model->index(row, 4).data().toString(), "dd-MM-yyyy"));
    ui->quantite->setText(model->index(row, 5).data().toString());
}


void medicament_UI::handleArduinoData()
{
    static QByteArray buffer;
    QByteArray data = arduino.read_from_arduino();

    if (!data.isEmpty()) {
        buffer += data;


        QList<QByteArray> messages = buffer.split('\r\n');

        for (int i = 0; i < messages.size() - 1; ++i) {
            QByteArray message = messages[i].trimmed();

            if (message == "FLAME") {
                handleFlameDetected();
            } else {
                ui->statusLabel->setText("Aucun incendie");
            }
        }
        buffer = messages.last();
    }
}

#include <QTimer>

void medicament_UI::handleFlameDetected()
{
    static bool messageBlocked = false;
    static QTimer* cooldownTimer = nullptr;

    if (!messageBlocked) {
        messageBlocked = true;

        if (!cooldownTimer) {
            cooldownTimer = new QTimer(this);
            cooldownTimer->setSingleShot(true);
            connect(cooldownTimer, &QTimer::timeout, [=]() {
                messageBlocked = false;
            });
        }
        cooldownTimer->start(5000);

        QDateTime flameStartTime = QDateTime::currentDateTime();
        QDate flameDate = QDate::currentDate();
        ui->statusLabel->setText("Incendie !");

        QSystemTrayIcon* trayIcon = new QSystemTrayIcon(this);
        trayIcon->setIcon(QIcon(":/image/iconMed.png"));
        trayIcon->show();
        QString criticalMessage1 = "Un incendie est en cours.\n";
        trayIcon->showMessage("Attention : incendie détecté !!",
                              criticalMessage1,
                              QSystemTrayIcon::Warning,
                              5000);

        qDebug() << "Flame started at:" << flameStartTime.toString();

        QSqlQuery query;
        query.prepare("INSERT INTO flame_events (start_time, start_date, status) VALUES (:start_time, :start_date, :status)");
        query.bindValue(":start_time", flameStartTime.toString("HH:mm:ss"));
        query.bindValue(":start_date", flameDate);
        query.bindValue(":status", "Incendie !");
        if (!query.exec()) {
            qDebug() << "Failed to insert start event into database:" << query.lastError();
        }
    }
}


void medicament_UI::on_pushButton_6_clicked()
{
    ui->tableView->setModel(m.afficher_flame());
}


void medicament_UI::on_pushButton_22_clicked()
{
        // Confirmation de déconnexion
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Déconnexion", "Êtes-vous sûr de vouloir vous déconnecter ?",
                                                                  QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            // Déconnexion de l'Arduino
            if (arduino.close_arduino() == 0) {
                qDebug() << "Port série déconnecté avec succès.";
            } else {
                qDebug() << "Le port série n'était pas ouvert ou n'a pas pu être fermé.";
            }

            // Fermer l'interface actuelle (medicament_UI)
            this->close();

            // Ouvrir la fenêtre de login
            login *loginWindow = new login();
            loginWindow->show();

            // Optionnel : garantir que la fenêtre login soit bien visible
            loginWindow->raise();
            loginWindow->activateWindow();
        }
}
void medicament_UI::closeMedicamentWindow()
{
    // Si l'interface medicamentWindow existe, la supprimer
    if (medicamentWindow != nullptr) {
        delete medicamentWindow;
        medicamentWindow = nullptr;  // Libérer la mémoire
    }
    this->close();  // Fermer la fenêtre actuelle
}

employeeUI* employeeWindow = nullptr;
void medicament_UI::on_pushButton_17_clicked()
{
    // Fermer le port série avant de passer à l'interface employeeUI
        if (employeeWindow) {
             employeeWindow->closeSerialPort();
        }

        if (!employeeWindow || !employeeWindow->isVisible()) {
            // Créez une nouvelle instance si elle n'existe pas encore ou si elle a été fermée
            employeeWindow = new employeeUI();
            employeeWindow->show();
        } else {
            // Si l'interface existe déjà, ramenez-la au premier plan
            employeeWindow->raise();
            employeeWindow->activateWindow();
        }

        // Fermez la fenêtre actuelle
        this->hide();
}

