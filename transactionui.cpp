#include "transactionui.h"
#include "ui_transactionui.h"


#include <QSqlError>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QMessageBox>
#include <QDateTime>

#include <QTcpSocket>
#include <QDebug>
#include <QMessageBox>

#include <QDateTime>
#include <QRandomGenerator>

#include <QUuid>
#include <QDateTime>



transactionUI::transactionUI(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::transactionUI)
{
    ui->setupUi(this);
    a.connect_arduino();
    a.read_from_arduino();
}

transactionUI::~transactionUI()
{
    delete ui;
}

void transactionUI::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);
    ui->tableView->setModel(t.afficher());
    initializeComboBox();
    ui->labelcombo->setVisible(false);
}

void transactionUI::on_type_currentTextChanged(const QString &arg1)
{
    ui->labelcombo->setText(arg1);
}

void transactionUI::initializeComboBox()
{
    QStringList options;
    options << "Depense" << "Revenue";
    ui->type->addItems(options);
}

void transactionUI::on_ajouter_clicked()
{
    QString id = ui->id->text();
    QDate date = ui->dateEdit->date();
    float montant = ui->montant->text().toFloat();
    QString type = ui->labelcombo->text();
    QString description = ui->description->text();
    QString categorie = ui->categorie->text();
    QString modepaiment = ui->modepaiment->text();

    transaction t(id, type, description, categorie, modepaiment, date, montant);
    bool test = false;
    test = handleArduinoData();
    if(test)
    {
    if (t.ajouter()) {
        QMessageBox::information(this, "Permission", "Bonne carte merci!");
        sendTransactionEmail(id, montant, type, description, date);
        ui->tableView->setModel(t.afficher());
    } else {
        QMessageBox::critical(this, "Error", "Failed to add transaction.");
    }
    }else {
        QMessageBox::critical(this, "Permission Error", "Passer la carte avant pour confirmer !");
    }

}


void transactionUI::on_editer_clicked()
{
    QString id = ui->id->text();
    QDate date = ui->dateEdit->date();
    float montant = ui->montant->text().toFloat();
    QString type = ui->labelcombo->text();
    QString description = ui->description->text();
    QString categorie = ui->categorie->text();
    QString modepaiment = ui->modepaiment->text();

    transaction t(id, type, description, categorie, modepaiment, date, montant);

    if (t.modifier()) {
        sendEditedTransactionEmail(id, montant, type, description, date);
        ui->tableView->setModel(t.afficher());
    } else {
        QMessageBox::critical(this, "Error", "Failed to update transaction.");
    }

}

void transactionUI::on_supp_clicked()
{
    transaction t1;
    t1.setId(ui->idsupp->text());
    t1.supprimer(t1.getId());
    ui->tableView->setModel(t.afficher());
}
void transactionUI::on_pushButton_clicked() {
    QString id = ui->linrech->text();
    QDate date = ui->daterech->date();
    QString modepaiment = ui->mdprech->text();
    transaction res;
    QSqlQueryModel* model = nullptr;

    // Combine search results into a single model
    if (!id.isEmpty()) {
        model = res.rechercher(id);
    } else if (date.isValid()) {
        model = res.rechercherd(date);
    } else if (!modepaiment.isEmpty()) {
        model = res.rechercherp(modepaiment);
    }

    if (model && model->rowCount() > 0) {
        ui->tableView->setModel(model);
    } else {
        QMessageBox::information(this, "Not Found", "No transaction found with the given criteria.");
        delete model; // Clean up memory if model is unused
    }

}
void transactionUI::on_pushButton_2_clicked() {
    transaction res;
    QSqlQueryModel* model = res.trier();

    if (model && model->rowCount() > 0) {
        ui->tableView->setModel(model);
    } else {
        QMessageBox::information(this, "Not Found", "No transaction found with that ID.");
        delete model;
    }
}
void transactionUI::on_pushButton_14_clicked() {
    // Utilisation de la connexion existante
    QSqlDatabase db = QSqlDatabase::database(); // Récupère la connexion par défaut
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Database Error", "Database connection is not open.");
        return;
    }

    // Requête pour récupérer les données des transactions par mois
    QSqlQuery query;
    if (!query.exec("SELECT TO_CHAR(datep, 'Month') AS month, COUNT(*) AS transaction_count, TO_CHAR(datep, 'MM') AS month_number FROM transaction GROUP BY TO_CHAR(datep, 'Month'), TO_CHAR(datep, 'MM') ORDER BY TO_CHAR(datep, 'MM')")) {
        QMessageBox::critical(this, "Query Error", "Failed to execute query: " + query.lastError().text());
        return;
    }

    // Liste des mois dans l'ordre
    QStringList monthsOrdered = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // Préparer les données pour le graphique
    QMap<QString, int> transactionsByMonth; // Map pour stocker les transactions par mois
    while (query.next()) {
        QString month = query.value("month").toString().trimmed(); // Mois (nom)
        int count = query.value("transaction_count").toInt(); // Nombre de transactions
        transactionsByMonth[month] = count; // Stocker les données
    }

    QBarSet *set = new QBarSet("Transactions");
    QStringList visibleMonths; // Mois visibles sur l'axe X
    double maxValue = 0;

    // Ajouter les données dans l'ordre des mois
    for (const QString &month : monthsOrdered) {
        int count = transactionsByMonth.value(month, 0); // Valeur par défaut 0 si mois non trouvé
        *set << count;
        visibleMonths.append(month);
        if (count > maxValue) {
            maxValue = count; // Mettre à jour la valeur maximale
        }
    }

    // Créer une série de barres
    QBarSeries *series = new QBarSeries();
    series->append(set);

    // Créer le graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Transactions Statistics");

    // Axe Y
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, maxValue + 5); // Ajouter un peu de marge
    axisY->setTitleText("Number of Transactions");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Axe X
    QCategoryAxis *axisX = new QCategoryAxis();
    for (int i = 0; i < visibleMonths.size(); ++i) {
        axisX->append(visibleMonths[i], i); // Ajouter les mois dans l'ordre
    }
    axisX->setTitleText("Months");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Ajouter les labels pour les nombres de transactions au-dessus des barres
    QChartView *chartView = new QChartView(chart);
    for (int i = 0; i < visibleMonths.size(); ++i) {
        int value = (*set)[i];
        QGraphicsSimpleTextItem *label = new QGraphicsSimpleTextItem(QString::number(value));
        QPointF position = chart->mapToPosition(QPointF(i, value), series);
        label->setPos(position.x() - 10, position.y() - 20); // Ajuster la position pour centrer au-dessus
        chart->scene()->addItem(label);
    }

    // Afficher le graphique dans une boîte de dialogue
    chartView->setRenderHint(QPainter::Antialiasing);

    QDialog *chartDialog = new QDialog(this);
    chartDialog->setWindowTitle("Transactions Statistics");
    QVBoxLayout *layout = new QVBoxLayout(chartDialog);
    layout->addWidget(chartView);
    chartDialog->setLayout(layout);
    chartDialog->resize(1200, 600);
    chartDialog->exec();
}





void transactionUI::on_pushButton_13_clicked() {
    qDebug() << "Export Button clicked";

    // 1. Choisir l'emplacement et nom du fichier PDF
    QString filePath = QFileDialog::getSaveFileName(this, "Save PDF", "", "*.pdf");
    if (filePath.isEmpty()) return;
    if (!filePath.endsWith(".pdf", Qt::CaseInsensitive)) filePath += ".pdf";

    // 2. Initialiser QPdfWriter et QPainter
    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setPageMargins(QMargins(30, 30, 30, 30));
    QPainter painter(&pdfWriter);

    int xStart = 50;
    int yStart = 300;
    int rowHeight = 200;
    int colWidth = 1200;
    int currentY = yStart;

    QAbstractItemModel *model = ui->tableView->model();
    if (!model) {
        QMessageBox::warning(this, "Export Failed", "No data available in the table.");
        return;
    }

    // Polices
    QFont titleFont("Times New Roman", 20, QFont::Bold);
    QFont headerFont("Arial", 12, QFont::Bold);
    QFont dataFont("Arial", 10);

    // Dessiner le titre principal
    painter.setFont(titleFont);
    painter.drawText(xStart, 150, "Liste des Transactions par Mois");

    // Grouper les données par mois
    QMap<QString, QList<QList<QString>>> transactionsByMonth;
    for (int row = 0; row < model->rowCount(); ++row) {
        QString dateStr = model->data(model->index(row, 5)).toString();
        QDate date = QDate::fromString(dateStr, "yyyy-MM-dd");
        QString month = date.toString("MMMM yyyy");

        QList<QString> rowData;
        for (int col = 0; col < model->columnCount(); ++col) {
            rowData.append(model->data(model->index(row, col)).toString());
        }
        transactionsByMonth[month].append(rowData);
    }

    // Définir les couleurs
    QColor headerColor(200, 200, 250);  // Violet clair pour les en-têtes
    QColor rowColor1(240, 240, 240);    // Gris clair pour les lignes impaires
    QColor rowColor2(255, 255, 255);    // Blanc pour les lignes paires
    QColor borderColor(0, 0, 0);        // Noir pour les bordures

    // Dessiner les données regroupées par mois
    for (auto month : transactionsByMonth.keys()) {
        // Dessiner le titre du mois
        painter.setFont(headerFont);
        painter.drawText(xStart, currentY, month);
        currentY += rowHeight;

        // Dessiner l'en-tête avec fond coloré
        painter.fillRect(xStart, currentY, model->columnCount() * colWidth, rowHeight, headerColor);
        painter.setPen(Qt::black);
        painter.drawRect(xStart, currentY, model->columnCount() * colWidth, rowHeight);

        for (int col = 0; col < model->columnCount(); ++col) {
            QString headerText = model->headerData(col, Qt::Horizontal).toString();
            painter.drawText(xStart + col * colWidth + 20, currentY + rowHeight / 2, headerText);
        }
        currentY += rowHeight;

        // Dessiner les lignes de données
        painter.setFont(dataFont);
        for (int i = 0; i < transactionsByMonth[month].size(); ++i) {
            QList<QString> rowData = transactionsByMonth[month][i];

            // Alterner les couleurs de fond
            QColor rowColor = (i % 2 == 0) ? rowColor1 : rowColor2;
            painter.fillRect(xStart, currentY, model->columnCount() * colWidth, rowHeight, rowColor);

            // Dessiner chaque cellule
            for (int col = 0; col < rowData.size(); ++col) {
                painter.drawRect(xStart + col * colWidth, currentY, colWidth, rowHeight); // Bordure
                painter.drawText(xStart + col * colWidth + 20, currentY + rowHeight / 2, rowData[col]);
            }
            currentY += rowHeight;

            // Gérer le passage à une nouvelle page
            if (currentY > pdfWriter.height() - 300) {
                pdfWriter.newPage();
                currentY = yStart;
            }
        }
        currentY += rowHeight; // Espace après chaque mois
    }

    painter.end();
    QMessageBox::information(this, "Export Successful", "PDF file has been successfully created.");
}


void transactionUI::sendTransactionEmail(const QString &id, float montant, const QString &type, const QString &description, const QDate &date)
{
    QString smtpServer = "localhost";
    int smtpPort = 1025;

    QString subject = "New Transaction Added";
    QString body = QString("Transaction ID: %1\nAmount: %2\nType: %3\nDescription: %4\nDate: %5")
                       .arg(id)
                       .arg(montant)
                       .arg(type)
                       .arg(description)
                       .arg(date.toString());

    QString from = "no-reply@yourdomain.com";
    QString to = "youremail@domain.com";

    QTcpSocket socket;
    socket.connectToHost(smtpServer, smtpPort);

    if (!socket.waitForConnected(5000)) {
        qDebug() << "Failed to connect to MailHog SMTP server!";
        QMessageBox::critical(this, "Error", "Failed to connect to MailHog SMTP server.");
        return;
    } else {
        qDebug() << "Connected to MailHog SMTP server.";
    }

    socket.write("HELO localhost\r\n");
    if (!socket.waitForBytesWritten()) {
        qDebug() << "Failed to send HELO command!";
        socket.disconnectFromHost();
        return;
    }

    if (socket.waitForReadyRead()) {
        qDebug() << "Response to HELO: " << socket.readAll();
    }

    socket.write(QString("MAIL FROM:<%1>\r\n").arg(from).toUtf8());
    if (!socket.waitForBytesWritten()) {
        qDebug() << "Failed to send MAIL FROM command!";
        socket.disconnectFromHost();
        return;
    }

    if (socket.waitForReadyRead()) {
        qDebug() << "Response to MAIL FROM: " << socket.readAll();
    }

    socket.write(QString("RCPT TO:<%1>\r\n").arg(to).toUtf8());
    if (!socket.waitForBytesWritten()) {
        qDebug() << "Failed to send RCPT TO command!";
        socket.disconnectFromHost();
        return;
    }

    if (socket.waitForReadyRead()) {
        qDebug() << "Response to RCPT TO: " << socket.readAll();
    }

    socket.write("DATA\r\n");
    if (!socket.waitForBytesWritten()) {
        qDebug() << "Failed to send DATA command!";
        socket.disconnectFromHost();
        return;
    }

    if (socket.waitForReadyRead()) {
        qDebug() << "Response to DATA: " << socket.readAll();
    }

    QString emailData = QString("Subject: %1\r\n")
                            .arg(subject)
                        + QString("From: %1\r\n")
                              .arg(from)
                        + QString("To: %1\r\n")
                              .arg(to)
                        + "\r\n" + body + "\r\n.\r\n";

    socket.write(emailData.toUtf8());
    if (!socket.waitForBytesWritten()) {
        qDebug() << "Failed to send email content!";
        socket.disconnectFromHost();
        return;
    }

    if (socket.waitForReadyRead()) {
        qDebug() << "Response to email content: " << socket.readAll();
    }

    socket.write("QUIT\r\n");
    if (!socket.waitForBytesWritten()) {
        qDebug() << "Failed to send QUIT command!";
        socket.disconnectFromHost();
        return;
    }

    qDebug() << "Email sent successfully!";
    socket.disconnectFromHost();
}

void transactionUI::sendEditedTransactionEmail(const QString &id, float montant, const QString &type, const QString &description, const QDate &date)
{
    QString smtpServer = "localhost";
    int smtpPort = 1025;

    QString subject = "Transaction Updated";
    QString body = QString("Transaction ID: %1\nAmount: %2\nType: %3\nDescription: %4\nDate: %5")
                       .arg(id)
                       .arg(montant)
                       .arg(type)
                       .arg(description)
                       .arg(date.toString());

    QString from = "no-reply@yourdomain.com";
    QString to = "youremail@domain.com";

    QTcpSocket socket;
    socket.connectToHost(smtpServer, smtpPort);

    if (!socket.waitForConnected(5000)) {
        qDebug() << "Failed to connect to MailHog SMTP server!";
        QMessageBox::critical(this, "Error", "Failed to connect to MailHog SMTP server.");
        return;
    } else {
        qDebug() << "Connected to MailHog SMTP server.";
    }

    socket.write("HELO localhost\r\n");
    if (!socket.waitForBytesWritten()) {
        qDebug() << "Failed to send HELO command!";
        socket.disconnectFromHost();
        return;
    }

    if (socket.waitForReadyRead()) {
        qDebug() << "Response to HELO: " << socket.readAll();
    }

    socket.write(QString("MAIL FROM:<%1>\r\n").arg(from).toUtf8());
    if (!socket.waitForBytesWritten()) {
        qDebug() << "Failed to send MAIL FROM command!";
        socket.disconnectFromHost();
        return;
    }

    if (socket.waitForReadyRead()) {
        qDebug() << "Response to MAIL FROM: " << socket.readAll();
    }

    socket.write(QString("RCPT TO:<%1>\r\n").arg(to).toUtf8());
    if (!socket.waitForBytesWritten()) {
        qDebug() << "Failed to send RCPT TO command!";
        socket.disconnectFromHost();
        return;
    }

    if (socket.waitForReadyRead()) {
        qDebug() << "Response to RCPT TO: " << socket.readAll();
    }

    socket.write("DATA\r\n");
    if (!socket.waitForBytesWritten()) {
        qDebug() << "Failed to send DATA command!";
        socket.disconnectFromHost();
        return;
    }

    if (socket.waitForReadyRead()) {
        qDebug() << "Response to DATA: " << socket.readAll();
    }

    QString emailData = QString("Subject: %1\r\n")
                            .arg(subject)
                        + QString("From: %1\r\n")
                              .arg(from)
                        + QString("To: %1\r\n")
                              .arg(to)
                        + "\r\n" + body + "\r\n.\r\n";

    socket.write(emailData.toUtf8());
    if (!socket.waitForBytesWritten()) {
        qDebug() << "Failed to send email content!";
        socket.disconnectFromHost();
        return;
    }

    if (socket.waitForReadyRead()) {
        qDebug() << "Response to email content: " << socket.readAll();
    }

    socket.write("QUIT\r\n");
    if (!socket.waitForBytesWritten()) {
        qDebug() << "Failed to send QUIT command!";
        socket.disconnectFromHost();
        return;
    }

    qDebug() << "Email sent successfully!";
    socket.disconnectFromHost();
}

    QString generateRandomImageName()
    {
        QString fileName = QUuid::createUuid().toString();
        fileName = fileName.mid(1, fileName.length() - 2);
        return fileName + ".png";
    }

/*void transactionUI::captureWindowAndSave()
    {
        QString fileName = generateRandomImageName();
        QString filePath = "C:/Users/mehdi/OneDrive/Desktop/newProject/interfaceges/interfaceSarra/capture/" + fileName;

        QPixmap screenshot = this->grab();

        if (screenshot.save(filePath)) {
            qDebug() << "Screenshot saved successfully to " << filePath;
        } else {
            qDebug() << "Failed to save screenshot to " << filePath;
            QMessageBox::critical(this, "Error", "Failed to save screenshot.");
        }
    }


void transactionUI::on_captureButton_clicked()
{
    captureWindowAndSave();
}*/

bool transactionUI::handleArduinoData()
{
    QDateTime PassTime = QDateTime::currentDateTime();
    static QByteArray buffer;

    QByteArray data = a.read_from_arduino();

    if (!data.isEmpty()) {
            if (data == "Authorized\r\n") {
                QSqlQuery query;
                query.prepare("INSERT INTO refid (time, status) VALUES (:time, :status)");
                query.bindValue(":time", PassTime.toString("HH:mm:ss"));
                query.bindValue(":status", "Authorized Card");
                qDebug() << "ok";
                if (!query.exec()) {
                    qDebug() << "Failed to insert start event into database:" << query.lastError();
                return true;
                }
            } else if (data == "Refused\r\n") {
                QSqlQuery query;
                query.prepare("INSERT INTO refid (time, status) VALUES (:time, :status)");
                query.bindValue(":time", PassTime.toString("HH:mm:ss"));
                query.bindValue(":status", "Refused Card");
                qDebug() << "ok";
                if (!query.exec()) {
                    qDebug() << "Failed to insert start event into database:" << query.lastError();
                }
                return false;
            }
    }else {return false;}

    }

void transactionUI::on_pushButton_5_clicked()
{
    a.close_arduino();
    a.connect_arduino();
}


void transactionUI::on_pushButton_6_clicked()
{
    CalendarDialog Cd;
    Cd.exec();
}

