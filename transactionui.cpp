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

    if (t.ajouter()) {
        sendTransactionEmail(id, montant, type, description, date);
        ui->tableView->setModel(t.afficher());
        QMessageBox::information(this, "Succès", "La transaction a été ajoute avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de la transaction.");
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
        QMessageBox::information(this, "Succès", "La transaction a été mise à jour avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la mise à jour de la transaction.");
    }

}

void transactionUI::on_supp_clicked() {
    QString id = ui->idsupp->text();



    transaction t1;

    // Vérifier si l'ID existe dans la base de données
    if (!t1.existe(id)) {
        QMessageBox::critical(this, "Erreur", "Aucune transaction trouvée avec cet ID.");
        return;
    }

    // Supprimer la transaction
   else if (t1.supprimer(id)) {
        QMessageBox::information(this, "Succès", "La transaction a été supprimée avec succès.");
        // Rafraîchir le tableau
        ui->tableView->setModel(t1.afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression de la transaction.");
    }
}

void transactionUI::on_pushButton_clicked() {
    QString id = ui->linrech->text();
    transaction res;
    QSqlQueryModel* model = res.rechercher(id);

    if (model && model->rowCount() > 0) {
        ui->tableView->setModel(model);
    } else {
        QMessageBox::information(this, "Not Found", "Aucune transaction trouvée avec cet ID.");
        delete model;
    }
}
void transactionUI::on_pushButton_2_clicked() {
    transaction res;
    QSqlQueryModel* model = res.trier();

    if (model && model->rowCount() > 0) {
        ui->tableView->setModel(model);
    } else {
        QMessageBox::information(this, "Not Found", "Aucune transaction trouvée avec cet ID.");
        delete model;
    }
}
void transactionUI::on_pushButton_14_clicked() {
    QBarSet *set = new QBarSet("transaction");

    // Example data: Replace these values with actual data from your database
    *set << 10 << 20 << 15 << 25 << 18; // Example: transaction in different months

    // Find the maximum value for the Y-axis range
    double maxValue = 0;
    for (int i = 0; i < set->count(); ++i) {
        double value = set->at(i);
        if (value > maxValue) {
            maxValue = value;
        }
    }

    // Create a bar series and add the set
    QBarSeries *series = new QBarSeries();
    series->append(set);

    // Create the chart and add the series
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Transactions Statistics");

    // Create Y-axis based on the max value from the dataset
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, maxValue + 5); // Add some padding above max value
    axisY->setTitleText("Number of transaction");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Create X-axis with categories (replace with your actual categories)
    QCategoryAxis *axisX = new QCategoryAxis();
    axisX->append("January", 0);
    axisX->append("February", 1);
    axisX->append("March", 2);
    axisX->append("April", 3);
    axisX->append("May", 4);
    axisX->setTitleText("Months");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Create chart view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Create a new dialog to display the chart
    QDialog *chartDialog = new QDialog(this);
    chartDialog->setWindowTitle("Transactions Statistics");

    // Set layout for the dialog and add the chart view
    QVBoxLayout *layout = new QVBoxLayout(chartDialog);
    layout->addWidget(chartView);
    chartDialog->setLayout(layout);

    // Set a fixed size for the dialog, or use resize if you want adjustable size
    chartDialog->resize(600, 400); // Adjust the size as desired

    // Show the dialog
    chartDialog->exec();
}


void transactionUI::on_pushButton_13_clicked() {
    connect(ui->pushButton_13, &QPushButton::clicked, this, &transactionUI::on_pushButton_13_clicked);
    qDebug() << "Export Button clicked";

    // 1. Choose a location and file name for the PDF
    QString listofcomplaints = QFileDialog::getSaveFileName(this, "Save PDF", "", "*.pdf");
    if (listofcomplaints.isEmpty()) {
        return; // User canceled the dialog
    }

    // Add ".pdf" if the user did not specify it
    if (!listofcomplaints.endsWith(".pdf", Qt::CaseInsensitive)) {
        listofcomplaints += ".pdf";
    }

    // 2. Create a QPdfWriter instance
    QPdfWriter pdfWriter(listofcomplaints);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setPageMargins(QMargins(30, 30, 30, 30)); // Adjust margins as needed

    // 3. Set up QPainter for drawing on the PDF
    QPainter painter(&pdfWriter);
    painter.setPen(Qt::black);

    // Optional: Add a title or header
    QFont titleFont("Arial", 16, QFont::Bold);
    painter.setFont(titleFont);
    painter.drawText(100, 100, "La Liste Des Transactions"); // Position (x, y) and text content

    // Optional: Add a timestamp
    QFont dateFont("Arial", 10);
    painter.setFont(dateFont);
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    painter.drawText(4000, 100, "Generated on: " + timestamp);

    QFont dataFont("Arial", 10);
    painter.setFont(dataFont);

    int rowHeight = 300;
    int xPos = 100;
    int yPos = 300;

    QAbstractItemModel *model = ui->tableView->model();
    for (int row = 0; row < model->rowCount(); ++row) {
        xPos = 100;
        for (int col = 0; col < model->columnCount(); ++col) {
            QString cellData = model->data(model->index(row, col)).toString();
            painter.drawText(xPos, yPos, cellData);
            xPos += 1000; // Adjust column width as needed
        }
        yPos += rowHeight; // Move to the next row
    }

    // 5. End the painting and save the PDF
    painter.end();

    // Optional: Confirm successful export
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

void transactionUI::captureWindowAndSave()
    {
        QString fileName = generateRandomImageName();
        QString filePath = "C:/Users/sarra/Desktop/interfaceSarra/capture/" + fileName;

        QPixmap screenshot = this->grab();

        if (screenshot.save(filePath)) {
            qDebug() << "Screenshot saved successfully to " << filePath;
            QMessageBox::information(this, "Succès", "Capture d'écran enregistrée avec succès..");
        } else {
            qDebug() << "Failed to save screenshot to " << filePath;
            QMessageBox::critical(this, "Error", "Échec de l'enregistrement de la capture d'écran.");
        }
    }


void transactionUI::on_captureButton_clicked()
{
    captureWindowAndSave();
}

