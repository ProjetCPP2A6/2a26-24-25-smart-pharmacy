#include "ordonnanceui.h"
#include "ui_ordonnanceui.h"
#include "stat_khairi.h"
#include "mplayer.h"
#include "m4player.h"
#include <QMessageBox>
#include <QFile>
#include <QPixmap>
#include <QPainter>
#include <QPrinter>
#include "../syrine/login.h"
#include "../abdou/arduino.h"
#include "../ranim/fournisseurui.h"
ordonnanceUI::ordonnanceUI(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ordonnanceUI)
{
    ui->setupUi(this);
}

ordonnanceUI::~ordonnanceUI()
{
    delete ui;
}

void ordonnanceUI::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);
    ui->tableView_o->setModel(ord.afficher());
}

void ordonnanceUI::on_pushButton_add_clicked()
{
    QString id = ui->id->text();
    QString nomp = ui->nomp->text();
    QString medecin = ui->medecin->text();
    float prix = ui->prix->text().toFloat();
    QDate datep = ui->datep->date();

    ordonnance ord(id, nomp, medecin, prix, datep);
    bool test = ord.Ajouter();

    if (test) {
        ui->tableView_o->setModel(ord.afficher());
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Error !!"),
                              QObject::tr("Cannot add ordonnance."), QMessageBox::Cancel);
    }
}


void ordonnanceUI::on_pushButton_edit_clicked()
{
    QString id = ui->id->text();
    QString nomp = ui->nomp->text();
    QString medecin = ui->medecin->text();
    float prix = ui->prix->text().toFloat();
    QDate datep = ui->datep->date();

    ordonnance ord(id, nomp, medecin, prix, datep);
    bool test = ord.modifier();

    if (test) {
        ui->tableView_o->setModel(ord.afficher());
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Error !!"),
                              QObject::tr("Cannot edit ordonnance."), QMessageBox::Cancel);
    }
}


void ordonnanceUI::on_pushButton_del_clicked()
{
    QString id = ui->lineEdit_del->text();
    bool test = ord.Supprimer(id);

    if (test) {
        ui->tableView_o->setModel(ord.afficher());
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Error !!"),
                              QObject::tr("Cannot delete ordonnance."), QMessageBox::Cancel);
    }
}


void ordonnanceUI::on_pushButton_clicked()
{
    mplayer mp3;
    mp3.exec();
}


void ordonnanceUI::on_pushButton_2_clicked()
{
    m4player mp4;
    mp4.exec();
}

void ordonnanceUI::on_pushButton_5_clicked()
{
    QString val=ui->lineEdit_10->text();
    QString option=ui->comboBox->currentText();

    if((val!="")&&(option=="ID"))
    {        ui->tableView_o->setModel(ord.afficher_id(val));}
    else if((val!="")&&(option=="Nom"))
    {
        ui->tableView_o->setModel(ord.afficher_nomp(val));
    }
    else if((val!="")&&(option=="Medecin"))
    {
        ui->tableView_o->setModel(ord.afficher_Medecin(val));
    }
}

void ordonnanceUI::on_pushButton_14_clicked()
{
    stat_khairi S;
    S.exec();
}


void ordonnanceUI::on_pushButton_6_clicked()
{
    ui->tableView_o->setModel(ord.afficher());
}

void ordonnanceUI::on_comboBox_2_currentIndexChanged(int index)
{
    QString choix=ui->comboBox_2->currentText();
    ui->tableView_o->setModel(ord.afficher_choix(choix));
}


void ordonnanceUI::on_pushButton_13_clicked()
{
    int id = ui->lineEdit_pdf->text().toInt();
    ordonnance *Ord;
    Ord = ord.readordonnance(id); // Call the adapted read method for ordonnance

    // Retrieve the ordonnance details
    QString id_string = Ord->getId();
    QString nomp_string = Ord->getNomp();  // Patient's name
    QString medecin_string = Ord->getMedecin();  // Doctor's name
    QString datep_string = Ord->getDatep().toString("dd-MM-yyyy");  // Prescription date
    QString prix_string = QString::number(Ord->getPrix(), 'f', 2);  // Price

    // Create the path for the PDF file
    QString pdfFilePath = "C:/Users/mehdi/OneDrive/Desktop/newProject/interface khayri2/interface khayri/pdf/" + nomp_string + "_" + id_string + ".pdf";

    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(pdfFilePath);

    QPainter painter;
    if (!painter.begin(&printer))
    {
        qWarning() << "Failed to open PDF file for writing";
        return;
    }

    painter.setFont(QFont("Bahnschrift Light", 25));
    painter.setPen(Qt::blue);
    painter.drawText(130, 230, "Ordonnance Information");  // Update title
    painter.setPen(Qt::black);
    painter.drawText(120, 150, "Ordonnance Management System");  // Update header

    painter.drawText(150, 300, "ID: " + id_string);
    painter.drawText(150, 400, "Patient Name: " + nomp_string);  // Display patient name
    painter.drawText(150, 500, "Doctor: " + medecin_string);  // Display doctor's name
    painter.drawText(150, 600, "Prescription Date: " + datep_string);  // Display prescription date
    painter.drawText(150, 700, "Price: " + prix_string);  // Display price

    painter.end();
}

void ordonnanceUI::on_pushButton_22_clicked()
{
    // Confirmation de déconnexion
        QMessageBox::StandardButton reply = QMessageBox::question(
            this, "Déconnexion", "Êtes-vous sûr de vouloir vous déconnecter ?",
            QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            // Accéder à une instance de login
            login *loginWindow = new login();

            // Appeler la méthode closeSerialPort() de login avant de continuer
            loginWindow->closeSerialPort();

            // Fermer l'interface actuelle (ordonnanceUI)
            this->close();

            // Ouvrir l'interface login
            loginWindow->show();

            // Optionnel : S'assurer que l'interface login est bien visible
            loginWindow->raise();
            loginWindow->activateWindow();
        }
}

fournisseurUI* fournisseurWindow1 = nullptr;
void ordonnanceUI::on_pushButton_19_clicked()
{
    // Vérifier si l'instance de fournisseurUI existe déjà
        if (fournisseurWindow1 == nullptr) {
            // Créer l'instance seulement si elle n'existe pas encore
            fournisseurWindow1 = new fournisseurUI(this);  // 'this' comme parent
        }

        // Vérifier si la fenêtre est déjà visible avant de l'afficher
        if (!fournisseurWindow1->isVisible()) {
            // Cacher l'interface employeeUI avant d'ouvrir fournisseurUI
            this->hide();  // Cache l'interface actuelle (employeeUI)
            fournisseurWindow1->show();  // Affiche l'interface fournisseurUI
        }
}

