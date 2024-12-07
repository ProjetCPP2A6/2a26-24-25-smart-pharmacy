#include "fournisseurui.h"
#include "ui_fournisseurui.h"
#include <QSqlQueryModel>
#include <QSqlError>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QMessageBox>
#include <QFileDialog>
#include <QtDebug>
#include <QImage>

#include <QPixmap>
#include "sms.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QColor>
#include <QBrush>
#include <QPen>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "statranim.h"
#include "../syrine/login.h"
#include "../abdou/medicament_ui.h"
#include "../syrine/employeeui.h"
fournisseurUI::fournisseurUI(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::fournisseurUI), // Initialize the UI pointer
      serial(new QSerialPort(this)), // Initialize the serial port
      f() // Correctly initialize `f`
{
    ui->setupUi(this);

    // Initialize the serial port
    setupSerial();

    // Connect serial port signals to slots
    connect(serial, &QSerialPort::readyRead, this, &fournisseurUI::readWeight);
    ui->tableView_f->setModel(f.afficher());
   // Fixer un style par défaut pour le stackedWidget
    ui->stackedWidget->setStyleSheet("background-color: white;");
    ui->tableView_f->setStyleSheet("background-color: #2596be;");
}







fournisseurUI::~fournisseurUI()
{    if (serial->isOpen()) {
        serial->close();
    }
    delete serial;
    delete ui;
}


void fournisseurUI::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);
    ui->tableView_f->setModel(f.afficher());
}

void fournisseurUI::on_ajouter_clicked()
{
    // Récupération des valeurs des champs
       QString nom = ui->nom->text();
       QString adresse = ui->adresse->text();
       QString code = ui->code->text();
       QString produit = ui->produit->text();
       QString contactText = ui->contact->text();
       QString quantiteText = ui->quantite->text();

       // Vérification de la validité des champs
       bool isContactValid = !contactText.isEmpty() && contactText.toInt() != 0;
       bool isQuantiteValid = !quantiteText.isEmpty() && quantiteText.toInt() > 0;

       // Validation des champs obligatoires
       if (nom.isEmpty() || adresse.isEmpty() || code.isEmpty() || produit.isEmpty() || !isContactValid || !isQuantiteValid) {
           QMessageBox::critical(this, QObject::tr("Erreur !"),
                                 QObject::tr("Veuillez remplir tous les champs correctement."),
                                 QMessageBox::Cancel);
           return;  // Sort de la méthode si les champs sont invalides
       }

       // Récupération des valeurs des champs de contact et quantité
       int contact = contactText.toInt();
       int quantite = quantiteText.toInt();

       // Création de l'objet fournisseur
       fournisseur f(nom, adresse, code, produit, contact, quantite);

       // Tentative d'ajout du fournisseur
       bool test = f.Ajouter();
       if (test) {
           // Message de bienvenue personnalisé
           QString welcomeMessage = "Bienvenue " + nom + " à notre pharmacie ! Nous sommes ravis de vous compter parmi nos fournisseurs.";

           // Envoi de l'SMS (commenté pour l'instant)
           sms s;
           // s.sendSMS("+21651928110", welcomeMessage);  // Décommentez si vous voulez envoyer un SMS

           // Affichage du message de succès
           QMessageBox::information(this, QObject::tr("Ajout Réussi"),
                                    QObject::tr("Fournisseur ajouté avec succès !"), QMessageBox::Cancel);

           // Mise à jour de la vue des fournisseurs
           ui->tableView_f->setModel(f.afficher());
       } else {
           // Si l'ajout échoue, affichage d'un message d'erreur
           QMessageBox::critical(this, QObject::tr("Erreur !!"),
                                 QObject::tr("Impossible d'ajouter le fournisseur."), QMessageBox::Cancel);
       }
}
void fournisseurUI::setupSerial()
{
    if (serial->isOpen()) {
            qDebug() << "Port série déjà ouvert.";
            return;  // Ne rien faire si le port est déjà ouvert
        }

        serial->setPortName("COM3");  // Change to the appropriate port for your system
        serial->setBaudRate(QSerialPort::Baud57600);  // Set the baud rate to match Arduino (57600)
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);

        if (!serial->open(QIODevice::ReadWrite)) {
            qDebug() << "Failed to open serial port!";
            ui->statusLabel->setText("Error: Serial port not connected");
        } else {
            qDebug() << "Arduino connected!";
            ui->statusLabel->setText("Arduino connected");

            // Connect the readyRead signal to a slot to read incoming data
            connect(serial, &QSerialPort::readyRead, this, &fournisseurUI::readData);
        }
}
void fournisseurUI::readData()
{
    if (!serial->isOpen()) {
            qDebug() << "Serial port is not open!";
            ui->statusLabel->setText("Error: Serial port not open");
            return;
        }

        QByteArray data = serial->readLine();
        if (data.isEmpty()) {
            qDebug() << "No data received";
            ui->statusLabel->setText("No data received");
        } else {
            qDebug() << "Data received: " << data;
            // Process data as needed
        }
}
void fournisseurUI::readWeight()
{
    // Read all available data from the serial buffer
        QByteArray data = serial->readAll();
        QString weightString = QString::fromUtf8(data).trimmed();  // Convert to QString and trim whitespace

        qDebug() << "Received data:" << weightString;

        // Check if the data contains a unit like "grams" or "kg" and extract the numeric part
        if (weightString.contains("grams") || weightString.contains("kg")) {
            weightString = weightString.split(" ")[0];  // Get the numeric part
        }

        // Convert the string to a float and check validity
        bool ok;
        float weightValue = weightString.toFloat(&ok);

        if (ok && weightValue >= 0) {  // Update the label only for valid, non-negative weights
            ui->labelWeight->setText("Current Weight: " + QString::number(weightValue, 'f', 2) + " kg");
        } else {
            ui->labelWeight->setText("Invalid weight received");
            qDebug() << "Invalid data received:" << weightString;  // Debug invalid data
        }
    }



void fournisseurUI::on_modifier_clicked()
{
    QString nom = ui->nom->text();
        QString adresse = ui->adresse->text();
        QString code = ui->code->text();
        int contact = ui->contact->text().toInt();
        int quantite = ui->quantite->text().toInt();
        QString produit = ui->produit->text();


        // Validate input
        if (code.isEmpty() || nom.isEmpty() || adresse.isEmpty() || produit.isEmpty()) {
            QMessageBox::warning(this, tr("Avertissement"), tr("Veuillez remplir tous les champs nécessaires avant de modifier."));
            return;
        }

        // Display a confirmation message
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(
            this,
            tr("Confirmation de modification"),
            tr("Êtes-vous sûr de vouloir modifier le fournisseur avec le code %1 ?").arg(code),
            QMessageBox::Yes | QMessageBox::No
        );

        // Proceed with modification if "Yes" is selected
        if (reply == QMessageBox::Yes) {
            fournisseur f(nom, adresse, code, produit, contact, quantite);
            bool test = f.modifier();

            if (test) {
                QMessageBox::information(this, tr("Succès"), tr("Le fournisseur a été modifié avec succès."));
                ui->tableView_f->setModel(f.afficher());
            } else {
                QMessageBox::critical(this, tr("Erreur"), tr("Impossible de modifier le fournisseur. Vérifiez les informations."));
            }
        } else {
            QMessageBox::information(this, tr("Annulé"), tr("La modification a été annulée."));
        }
    }


void fournisseurUI::on_del_button_clicked()
{
    // Get the fournisseur code to delete
        QString codeToDelete = ui->lineEdit_supp->text();

        // Check if the input field is empty
        if (codeToDelete.isEmpty()) {
            QMessageBox::warning(this, tr("Avertissement"), tr("Veuillez entrer un code pour supprimer."));
            return;
        }

        // Display a confirmation message
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(
            this,
            tr("Confirmation de suppression"),
            tr("Êtes-vous sûr de vouloir supprimer le fournisseur avec le code %1 ?").arg(codeToDelete),
            QMessageBox::Yes | QMessageBox::No
        );

        // Proceed with deletion if "Yes" is selected
        if (reply == QMessageBox::Yes) {
            fournisseur F1;
            F1.setCode(codeToDelete);

            // Attempt to delete the fournisseur
            if (F1.Supprimer(F1.getCode())) {
                QMessageBox::information(this, tr("Succès"), tr("Le fournisseur a été supprimé avec succès."));
            } else {
                QMessageBox::critical(this, tr("Erreur"), tr("Impossible de supprimer le fournisseur. Vérifiez le code."));
            }

            // Refresh the table view
            ui->tableView_f->setModel(f.afficher());
        } else {
            QMessageBox::information(this, tr("Annulé"), tr("La suppression a été annulée."));
        }
}


void fournisseurUI::on_lineEdit_recherche_textChanged(const QString &text )
{
    QString critere = ui->comboBox_critere->currentText();
        QSqlQueryModel *model = new QSqlQueryModel();

        QString queryStr = "SELECT  nom, produit, code, adresse, contact,quantite FROM fournisseur WHERE ";

        if (critere == "nom") {
            queryStr += "nom LIKE '%" + text + "%'";
        } else if (critere == "produit") {
            queryStr += "produit LIKE '%" + text + "%'";
        } else if (critere == "code") {
            queryStr += "code LIKE '%" + text + "%'";
        }

        model->setQuery(queryStr);

        if (model->query().lastError().isValid()) {
            qDebug() << "Error executing query:" << model->query().lastError().text();
        } else {
            ui->tableView_f->setModel(model);
        }
}



void fournisseurUI::on_comboBox_tri_currentIndexChanged()
{
    QString critere = ui->comboBox_tri->currentText();

        // Créer une requête SQL pour trier les fournisseurs selon le critère choisi
        QString queryStr = "SELECT code, nom, produit, adresse, contact,quantite FROM fournisseur ";

        // Appliquer le tri en fonction du critère sélectionné
        if (critere == "quantite") {
            queryStr += "ORDER BY quantite";
        } else if (critere == "code") {
            queryStr += "ORDER BY code";
        } else if (critere == "produit") {
            queryStr += "ORDER BY produit";
        }

        // Créer un modèle de requête
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(queryStr);

        // Vérifier les erreurs de la requête
        if (model->query().lastError().isValid()) {
            qDebug() << "Erreur lors de l'exécution de la requête :" << model->query().lastError().text();
        } else {
            // Mettre à jour la vue avec le modèle trié
            ui->tableView_f->setModel(model);
        }
}


void fournisseurUI::on_pushButton_exportation_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save PDF"), "", tr("PDF Files (*.pdf);;All Files (*)"));
        if (filePath.isEmpty()) {
            return; // Quitter si l'utilisateur annule
        }

        // 2. Initialiser le QPdfWriter et QPainter
        QPdfWriter pdfWriter(filePath);
        pdfWriter.setPageSize(QPageSize(QPageSize::A4));
        pdfWriter.setTitle("Demande de Fourniture");
        QPainter painter(&pdfWriter);

        // 3. Dimensions et marges
        int margin = 50;                     // Marge autour du contenu
        int yPosition = margin;              // Position Y actuelle
        int rowHeight = 1500;                  // Hauteur des lignes du tableau
        int tableWidth = pdfWriter.width() - 2 * margin; // Largeur totale du tableau
        int colWidth1 = tableWidth / 3;      // Largeur de la première colonne (Produit)
        int colWidth2 = tableWidth / 3;      // Largeur de la deuxième colonne (Quantité)
        int colWidth3 = tableWidth / 3;      // Largeur de la troisième colonne (Date de Livraison)

        // 4. Couleurs et polices
        QColor headerColor = QColor(0, 102, 204); // Bleu pour l'en-tête
        QColor rowColor1 = QColor(230, 240, 255); // Bleu clair pour les lignes impaires
        QColor rowColor2 = QColor(255, 255, 255); // Blanc pour les lignes paires
        QFont titleFont("Arial", 14, QFont::Bold);
        QFont headerFont("Arial", 10, QFont::Bold);
        QFont bodyFont("Arial", 9);

        // 5. Dessiner le titre
        painter.setFont(titleFont);
        painter.drawText(margin, yPosition, pdfWriter.width() - 2 * margin, rowHeight, Qt::AlignCenter, tr("Demande de Fourniture"));
        yPosition += rowHeight + 20; // Ajouter un espace après le titre

        // 6. Ajouter la date de livraison
        QDate dateLivraison = QDate::currentDate();  // Date de livraison par défaut (aujourd'hui)
        painter.setFont(headerFont);
        painter.drawText(margin, yPosition, pdfWriter.width() - 2 * margin, rowHeight, Qt::AlignLeft, tr("Date de Livraison: %1").arg(dateLivraison.toString("dd/MM/yyyy")));
        yPosition += rowHeight + 10; // Ajouter un espace après la date de livraison

        // 7. Dessiner l'en-tête du tableau
        painter.setBrush(headerColor);
        painter.setPen(Qt::NoPen);
        painter.drawRect(margin, yPosition, tableWidth, rowHeight);
        painter.setPen(Qt::white);
        painter.setFont(headerFont);
        painter.drawText(margin + 5, yPosition + rowHeight - 15, tr("Produit"));
        painter.drawText(margin + colWidth1 + 5, yPosition + rowHeight - 15, tr("Quantité"));
        painter.drawText(margin + colWidth1 + colWidth2 + 5, yPosition + rowHeight - 15, tr("Date de Livraison"));
        yPosition += rowHeight;

        // 8. Récupérer les données de la base de données et dessiner les lignes du tableau
        QSqlQuery query;
        query.prepare("SELECT produit, quantite FROM fournisseur");
        if (!query.exec()) {
            QMessageBox::critical(this, tr("Erreur"), tr("Impossible de récupérer les données."));
            return;
        }

        painter.setFont(bodyFont);
        int row = 0;
        while (query.next()) {
            QColor rowColor = (row % 2 == 0) ? rowColor1 : rowColor2;
            painter.setBrush(rowColor);
            painter.setPen(Qt::NoPen);
            painter.drawRect(margin, yPosition, tableWidth, rowHeight);

            painter.setPen(Qt::black);

            // Récupérer les données "Produit" et "Quantité"
            QString produit = query.value(0).toString();
            QString quantite = query.value(1).toString();

            // Dessiner les données dans les colonnes
            painter.drawText(margin + 5, yPosition + rowHeight - 15, produit);
            painter.drawText(margin + colWidth1 + 5, yPosition + rowHeight - 15, quantite);

            // Ajouter la date de livraison (ici, je mets une date fixe ou une logique pour chaque produit)
            painter.drawText(margin + colWidth1 + colWidth2 + 5, yPosition + rowHeight - 15, dateLivraison.toString("dd/MM/yyyy"));

            yPosition += rowHeight;
            row++;

            // 9. Vérifier si une nouvelle page est nécessaire
            if (yPosition + rowHeight > pdfWriter.height() - margin) {
                pdfWriter.newPage();
                yPosition = margin; // Réinitialiser la position en haut
            }
        }

        // 10. Terminer le dessin
        painter.end();

        // 11. Confirmation à l'utilisateur
        QMessageBox::information(this, tr("Exportation réussie"), tr("Le fichier PDF a été exporté avec succès."));
    }







void fournisseurUI::on_sendChatBtn_clicked()
{
    QString text, space = "";
        float rassemblance = 0;
        int tr = 0;
        QString msg = ui->inputChatbot->text();
        ui->chatBot->appendPlainText(space);
        ui->chatBot->appendPlainText(msg);

        fournisseur f;
        QSqlQuery qry, query;

        if (msg[0] != QChar('#')) {
            qry.prepare("SELECT * FROM chatbot");
            if (!qry.exec()) {
                qDebug() << "Error executing query: " << qry.lastError();
                return;
            }

            while (qry.next() && tr == 0) {
                QString quest = qry.value(0).toString();
                int eq = 0, dif = 0;
                for (int i = 0; i < std::min(msg.size(), quest.size()); i++) {
                    if (quest[i] == msg[i])
                        eq++;
                    else
                        dif++;
                }
                rassemblance = (eq / static_cast<float>(msg.size())) * 100;
                if (rassemblance > 80) {
                    if (qry.value(1).toString() == "Details") {
                        QString id = msg.mid(18, msg.length() - 18);
                        fournisseur constatChat = f.getConstatDetails(id.toInt());
                        if (constatChat.getCode().toInt() != -1) {
                            ui->chatBot->appendPlainText("\n Le Constat demandé est : \n Code : " + constatChat.getCode() + ", nom : " + constatChat.getNom());
                        } else {
                            ui->chatBot->appendPlainText("\n Le Constat n'existe pas !");
                        }
                    } else {
                        ui->chatBot->appendPlainText("\n" + qry.value(1).toString());
                    }
                    tr = 1;
                }
            }

            if (tr == 0) {
                ui->chatBot->appendPlainText("Voulez-vous ajouter un nouveau mot ? Écrivez votre réponse avec un # au début.");
                ui->labelCache->setText(msg);
            }
        } else {
            QString msg1 = msg.mid(1);
            if (msg1.isEmpty()) {
                ui->chatBot->appendPlainText("Vous n'avez pas entré de réponse valide.");
                return;
            }

            query.prepare("INSERT INTO chatbot (quest, rep) VALUES (:quest, :rep)");
            query.bindValue(":quest", ui->labelCache->text());
            query.bindValue(":rep", msg1);
            if (!query.exec()) {
                qDebug() << "Error executing query: " << query.lastError();
                return;
            }

            ui->chatBot->appendPlainText("\nMerci ! Pour cette information");
        }
}


void fournisseurUI::on_retour_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void fournisseurUI::on_chatBot_2_clicked()
{
  ui->stackedWidget->setCurrentIndex(1);
}


void fournisseurUI::on_pushButton_stat_clicked()
{
    if (!statistiqueWindow) {
            statistiqueWindow = new statranim(this);
            connect(statistiqueWindow, &statranim::destroyed, this, [this]() {
                statistiqueWindow = nullptr;  // Reset pointer when the window is closed
            });
        }
        statistiqueWindow->show();  // Show the statistique window
}





void fournisseurUI::on_retour_2_clicked()
{
    // Retour à la page principale ou précédente (index 0)
    ui->stackedWidget->setCurrentIndex(0);
}
void fournisseurUI::onSerialDataReceived()
{
    // Check if data is available in the serial buffer
    QByteArray data = serial->readAll();

    // Convert the data to a string (assumes the data is sent as a string)
    QString weightData = QString::fromUtf8(data);

    // Optional: Trim any extra whitespace or line breaks
    weightData = weightData.trimmed();

    // Check if the received data is a valid number
    bool ok;
    int weight = weightData.toInt(&ok);

    if (ok) {
        // Update the label with the received weight
        ui->labelWeight->setText("Poids: " + QString::number(weight) + " kg");
    } else {
        // Handle the case when the data is invalid or not a number
        ui->labelWeight->setText("Poids: Données invalides");
    }
}


void fournisseurUI::on_connectArduino_clicked()
{
    ui->connectArduino->setEnabled(false);
        ui->statusLabel->setText("Connecting to Arduino...");

        if (!serial->isOpen()) {
            serial->setPortName("COM3");  // Adjust port name as needed
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);

            if (serial->open(QIODevice::ReadWrite)) {
                qDebug() << "Arduino connected!";
                ui->statusLabel->setText("Arduino connected!");
            } else {
                qDebug() << "Failed to open serial port!";
                ui->statusLabel->setText("Failed to connect to Arduino!");
                return;
            }
        }
    }




void fournisseurUI::on_saveWeightButton_clicked()
{
    QString fournisseurCode = ui->lineEditFournisseurCode->text().trimmed();
        if (fournisseurCode.isEmpty()) {
            ui->statusLabel->setText("Please enter a fournisseur code.");
            return;
        }

        // Get the weight from the label (e.g., "Current Weight: 10.28 kg")
        QString weightText = ui->labelWeight->text().trimmed();
        qDebug() << "Weight label text: " << weightText;

        // Extract the numeric value of the weight
        QStringList parts = weightText.split(":");
        if (parts.size() < 2) {
            ui->statusLabel->setText("Invalid weight format.");
            return;
        }

        QString weightString = parts[1].split("kg")[0].trimmed(); // Remove "kg" and spaces
        bool conversionSuccess = false;
        float weightValue = weightString.toFloat(&conversionSuccess);

        if (!conversionSuccess || weightValue <= 0) {
            ui->statusLabel->setText("Invalid weight data.");
            return;
        }

        // Prepare the SQL query to update the weight in the database
        QSqlQuery query;
        query.prepare("UPDATE fournisseur SET poids = :poids WHERE code = :code");
        query.bindValue(":poids", weightValue);
        query.bindValue(":code", fournisseurCode);

        // Execute the query and handle the result
        if (query.exec()) {
            ui->statusLabel->setText("Weight saved successfully!");
            qDebug() << "Weight saved for fournisseur code:" << fournisseurCode;

            // Refresh the table to show the updated weight
            refreshFournisseurTable();
        } else {
            ui->statusLabel->setText("Failed to save weight.");
            qDebug() << "Error saving weight:" << query.lastError().text();
        }
}
int fournisseurUI::close_arduino()

{

    if(serial->isOpen()){
        serial->close();
        return 0;
    }
    return 1;


}

void fournisseurUI::refreshFournisseurTable()
{
    // Assuming you have a QTableView widget named "tableViewFournisseurs" in your UI
    QSqlQueryModel *model = new QSqlQueryModel();

    // Query to fetch the updated data from the database
    model->setQuery("SELECT nom, adresse, code, produit, contact, quantite, poids FROM fournisseur");

    // Set headers for the table view
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Code"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Produit"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Contact"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Quantité"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Poids"));

    // Attach the model to the table view
    ui->tableView_f->setModel(model);

    // Optional: Resize columns to fit the content
    ui->tableView_f->resizeColumnsToContents();
}

void fournisseurUI::on_pushButton_32_clicked()
{
    // Confirmation de déconnexion
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Déconnexion", "Êtes-vous sûr de vouloir vous déconnecter ?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        // Déconnexion de l'Arduino
        if (close_arduino() == 0) {
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

medicament_UI *medicamentWindow = nullptr;
void fournisseurUI::on_pushButton_29_clicked()
{
    // Vérifier si l'instance de medicament_ui existe déjà
        if (medicamentWindow == nullptr) {
            // Créer l'instance seulement si elle n'existe pas encore
            medicamentWindow = new medicament_UI(this);  // 'this' comme parent
        }

        // Vérifier si la fenêtre est déjà visible avant de l'afficher
        if (!medicamentWindow->isVisible()) {
            // Cacher l'interface employeeUI avant d'ouvrir medicamentUI
            this->hide();  // Cache l'interface actuelle (employeeUI)
            medicamentWindow->show();  // Affiche l'interface medicament_ui
        }
}


