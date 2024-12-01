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
#include <QPainter>
#include <QPixmap>
#include "qrcode.h"
#include "sms.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QColor>
#include <QBrush>
#include <QPen>

fournisseurUI::fournisseurUI(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::fournisseurUI)
{
    ui->setupUi(this);



}

fournisseurUI::~fournisseurUI()
{
    delete ui;
}

void fournisseurUI::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);
    ui->tableView_f->setModel(f.afficher());
}

void fournisseurUI::on_ajouter_clicked()
{
    QString nom = ui->nom->text();
    QString adresse = ui->adresse->text();
    QString code = ui->code->text();
    int contact = ui->contact->text().toInt();
    int quantite = ui->quantite->text().toInt();
    QString produit = ui->produit->text();

    fournisseur f(nom, adresse, code, produit, contact, quantite);
    bool test;
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




void fournisseurUI::on_qrcode_clicked()
{



        QString text ="produit :"+ ui->tableView_f->model()->data(ui->tableView_f->model()->index(ui->tableView_f->currentIndex().row(),0)).toString();

                        using namespace qrcodegen;
                          // Create the QR Code object
                          QrCode qr = QrCode::encodeText( text.toUtf8().data(), QrCode::Ecc::MEDIUM );
                          qint32 sz = qr.getSize();
                          QImage im(sz,sz, QImage::Format_RGB32);
                            QRgb black = qRgb(  0,  0,  0);
                            QRgb white = qRgb(255,255,255);
                          for (int y = 0; y < sz; y++)
                            for (int x = 0; x < sz; x++)
                              im.setPixel(x,y,qr.getModule(x, y) ? black : white );
                          ui->qr_code->setPixmap( QPixmap::fromImage(im.scaled(256,256,Qt::KeepAspectRatio,Qt::FastTransformation),Qt::MonoOnly) );


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
    // Create a new QGraphicsScene
        QGraphicsScene *scene = new QGraphicsScene(this);

        // Prepare data for the chart
        QMap<QString, int> supplierData;
        QSqlQuery query;
        query.prepare("SELECT nom, quantite FROM fournisseur");
        if (query.exec()) {
            while (query.next()) {
                QString supplierName = query.value(0).toString();
                int quantity = query.value(1).toInt();
                supplierData[supplierName] = quantity;
            }
        } else {
            QMessageBox::critical(this, "Erreur", "Impossible de récupérer les données.");
            return;
        }

        // Determine dimensions and layout
        int maxBarHeight = 250;  // Max height for the bars
        int barWidth = 40;       // Width of each bar
        int spacing = 20;        // Space between bars
        int xPosition = 80;      // Initial position for the first bar
        int maxValue = 0;

        // Find the maximum value for scaling
        for (auto value : supplierData) {
            if (value > maxValue) {
                maxValue = value;
            }
        }

        // Define fonts and colors
        QFont titleFont("Arial", 16, QFont::Bold);
        QFont axisFont("Arial", 10, QFont::Bold);
        QFont labelFont("Arial", 8);
        QColor barColors[] = {Qt::blue, Qt::green, Qt::red, Qt::cyan, Qt::magenta, Qt::yellow};

        // Add a title
        QString title = "Statistiques des Quantités Fournies";
        QGraphicsTextItem *titleItem = new QGraphicsTextItem(title);
        titleItem->setFont(titleFont);
        titleItem->setDefaultTextColor(Qt::black);
        titleItem->setPos(50, -40);  // Position the title above the chart
        scene->addItem(titleItem);

        // Add bars and labels
        int colorIndex = 0;
        for (auto it = supplierData.begin(); it != supplierData.end(); ++it) {
            // Calculate bar height based on value
            int barHeight = static_cast<int>((it.value() / static_cast<double>(maxValue)) * maxBarHeight);

            // Create the bar
            QGraphicsRectItem *bar = new QGraphicsRectItem(xPosition, maxBarHeight - barHeight, barWidth, barHeight);
            bar->setBrush(QBrush(barColors[colorIndex % 6]));  // Cycle through colors
            bar->setPen(Qt::NoPen);
            scene->addItem(bar);

            // Add value label above the bar
            QGraphicsTextItem *valueLabel = new QGraphicsTextItem(QString::number(it.value()));
            valueLabel->setFont(labelFont);
            valueLabel->setDefaultTextColor(Qt::black);
            valueLabel->setPos(xPosition + barWidth / 4, maxBarHeight - barHeight - 20);
            scene->addItem(valueLabel);

            // Add supplier name below the bar
            QGraphicsTextItem *nameLabel = new QGraphicsTextItem(it.key());
            nameLabel->setFont(labelFont);
            nameLabel->setTextWidth(barWidth + 20);
            nameLabel->setDefaultTextColor(Qt::black);
            nameLabel->setPos(xPosition - 10, maxBarHeight + 10);
            scene->addItem(nameLabel);

            // Update X position for the next bar
            xPosition += barWidth + spacing;
            colorIndex++;
        }

        // Draw X and Y axes
        QPen axisPen(Qt::black, 2);
        scene->addLine(50, maxBarHeight, xPosition, maxBarHeight, axisPen);  // X-axis
        scene->addLine(50, 0, 50, maxBarHeight, axisPen);                   // Y-axis

        // Add axis labels
        QGraphicsTextItem *xLabel = new QGraphicsTextItem("Fournisseurs");
        xLabel->setFont(axisFont);
        xLabel->setDefaultTextColor(Qt::black);
        xLabel->setPos((xPosition - 80) / 2, maxBarHeight + 40);  // Center X label
        scene->addItem(xLabel);

        QGraphicsTextItem *yLabel = new QGraphicsTextItem("Quantité");
        yLabel->setFont(axisFont);
        yLabel->setDefaultTextColor(Qt::black);
        yLabel->setRotation(-90);  // Rotate to align vertically
        yLabel->setPos(10, maxBarHeight / 2);  // Center Y label
        scene->addItem(yLabel);

        // Create the QGraphicsView and display it in the stackedWidget
        QGraphicsView *view = new QGraphicsView(scene);
        view->setRenderHint(QPainter::Antialiasing);

        // Add the view to a widget
        QWidget *statPage = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout(statPage);
        layout->addWidget(view);

        // Display the stats page in the stackedWidget
        ui->stackedWidgetStat->addWidget(statPage);
        ui->stackedWidgetStat->setCurrentWidget(statPage);
    }





void fournisseurUI::on_retour_2_clicked()
{
    // Retour à la page principale ou précédente (index 0)
    ui->stackedWidget->setCurrentIndex(0);
}

