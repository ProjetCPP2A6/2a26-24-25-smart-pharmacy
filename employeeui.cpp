#include "employeeui.h"
#include "ui_employeeui.h"
#include <QSqlError>
#include <QMessageBox>
#include <QtDebug>
#include "congee.h"
#include "login.h"
#include <QtCharts>
employeeUI::employeeUI(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::employeeUI)
{
    ui->setupUi(this);
    connect(ui->lineEdit_recherche, &QLineEdit::textChanged, this, &employeeUI::on_lineEdit_recherche_textChanged);
    ui->tableView->setModel(e.afficher());
    connect(ui->pushButton_22, &QPushButton::clicked, this, &employeeUI::on_pushButton_22_clicked);


}

employeeUI::~employeeUI()
{
    delete ui;
}

void employeeUI::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);
    ui->tableView->setModel(e.afficher());
}

void employeeUI::clrinput(){
    ui->id->setText("");
    ui->nom->setText("");
    ui->prenom->setText("");
    ui->comboBox->setCurrentIndex(-1);
    ui->sexe->setText("");
    ui->salaire->setText("");
    ui->password->setText("");
}

void employeeUI::on_ajouter_clicked()
{
    // Vérification des champs obligatoires (hors mot de passe)
        if (ui->id->text().isEmpty() ||
            ui->nom->text().isEmpty() ||
            ui->prenom->text().isEmpty() ||
            ui->comboBox->currentText().isEmpty() ||
            ui->sexe->text().isEmpty() ||
            ui->salaire->text().isEmpty()) {
            QMessageBox::warning(this, tr("Erreur de saisie"), tr("Veuillez remplir tous les champs obligatoires."));
            return;
        }

        // Récupération des valeurs
        QString idText = ui->id->text();
        int id = idText.toInt();
        QString nom = ui->nom->text();
        QString prenom = ui->prenom->text();
        QString post = ui->comboBox->currentText();
        QString sexe = ui->sexe->text().toLower(); // Convertir en minuscules pour simplifier la vérification
        float salaire = ui->salaire->text().toFloat();
        QString password = ui->password->text();

        // Vérification de la validité de l'ID (exactement 8 chiffres)
        if (idText.length() != 8 || !idText.toUInt()) {
            QMessageBox::warning(this, tr("Erreur de saisie"), tr("L'ID doit contenir exactement 8 chiffres."));
            return;
        }

        // Vérification du sexe (doit être "homme" ou "femme")
        if (sexe != "homme" && sexe != "femme") {
            QMessageBox::warning(this, tr("Erreur de saisie"), tr("Le sexe doit être 'homme' ou 'femme'."));
            return;
        }

        // Vérification de la validité du salaire
        if (salaire < 0) {
            QMessageBox::warning(this, tr("Erreur de saisie"), tr("Le salaire doit être un nombre positif."));
            return;
        }

        // Vérification du mot de passe pour "Ressources humaines"
        if (post == "Ressources humaines" && password.isEmpty()) {
            QMessageBox::warning(this, tr("Erreur de saisie"), tr("Le mot de passe est obligatoire pour le poste 'Ressources humaines'."));
            return;
        }

        // Vérification que le mot de passe n'est pas identique pour un autre employé dans "Ressources humaines"
        if (post == "Ressources humaines") {
            QSqlQuery query;
            query.prepare("SELECT COUNT(*) FROM employee WHERE post = 'Ressources humaines' AND password = :password");
            query.bindValue(":password", password);
            if (!query.exec()) {
                qDebug() << "Erreur de requête SQL:" << query.lastError();
                return;
            }
            query.next();
            int count = query.value(0).toInt();
            if (count > 0) {
                QMessageBox::warning(this, tr("Erreur de saisie"), tr("Le mot de passe doit être unique pour le poste 'Ressources humaines'."));
                return;
            }
        }

        // Vérification que le mot de passe ne soit pas rempli pour les autres postes
        if (post != "Ressources humaines" && !password.isEmpty()) {
            QMessageBox::warning(this, tr("Erreur de saisie"), tr("Le mot de passe ne doit pas être rempli pour ce poste."));
            return;
        }

        // Création et ajout de l'employé
        employee e(id, nom, prenom, post, sexe, salaire, password);
        bool test = e.Ajouter();
        if (test) {
            ui->tableView->setModel(e.afficher()); // Mise à jour de l'affichage
            clrinput(); // Réinitialisation des champs
        } else {
            QMessageBox::critical(this, tr("Erreur !!"), tr("Impossible d'ajouter l'employé."), QMessageBox::Cancel);
            clrinput(); // Réinitialisation des champs en cas d'erreur
        }
}



void employeeUI::on_editer_clicked()
{
    // Vérification de l'ID non vide
        if (ui->id->text().isEmpty()) {
            QMessageBox::warning(this, tr("Erreur de saisie"), tr("Veuillez entrer un ID."));
            return;
        }

        // Récupération de l'ID
        int id = ui->id->text().toInt();

        // Vérification de la validité de l'ID
        if (id <= 0) {
            QMessageBox::warning(this, tr("Erreur de saisie"), tr("L'ID doit être un nombre positif."));
            return;
        }

        // Récupération des données de l'employé à partir de la base de données
        QSqlQuery query;
        query.prepare("SELECT nom, prenom, post, sexe, salaire, password FROM employee WHERE id = :id");
        query.bindValue(":id", id);

        if (!query.exec()) {
            QMessageBox::critical(this, tr("Erreur"), tr("Échec de la requête SQL."));
            return;
        }

        if (!query.next()) { // Si aucune ligne n'est retournée, l'employé n'existe pas
            QMessageBox::warning(this, tr("Erreur"), tr("Aucun employé trouvé avec cet ID."));
            return;
        }

        // Récupérer les valeurs actuelles de l'employé
        QString nom = ui->nom->text().isEmpty() ? query.value(0).toString() : ui->nom->text();
        QString prenom = ui->prenom->text().isEmpty() ? query.value(1).toString() : ui->prenom->text();
        QString post = ui->comboBox->currentText().isEmpty() ? query.value(2).toString() : ui->comboBox->currentText();
        QString sexe = ui->sexe->text().isEmpty() ? query.value(3).toString() : ui->sexe->text();
        float salaire = ui->salaire->text().isEmpty() ? query.value(4).toFloat() : ui->salaire->text().toFloat();
        QString password = ui->password->text().isEmpty() ? query.value(5).toString() : ui->password->text();

        // Vérification de la validité du salaire
        if (salaire < 0) {
            QMessageBox::warning(this, tr("Erreur de saisie"), tr("Le salaire doit être un nombre positif."));
            return;
        }

        // Gestion du mot de passe en fonction du poste
        if (post == "Ressources humaines" && password.isEmpty()) {
            QMessageBox::warning(this, tr("Erreur de saisie"), tr("Le mot de passe est obligatoire pour le poste 'Ressources humaines'."));
            return;
        }

        // Vérification de l'unicité du mot de passe pour le poste "Ressources humaines"
        if (post == "Ressources humaines") {
            QSqlQuery queryCheck;
            queryCheck.prepare("SELECT COUNT(*) FROM employee WHERE post = 'Ressources humaines' AND password = :password AND id != :id");
            queryCheck.bindValue(":password", password);
            queryCheck.bindValue(":id", id);
            if (!queryCheck.exec()) {
                qDebug() << "Erreur de requête SQL:" << queryCheck.lastError();
                return;
            }
            queryCheck.next();
            int count = queryCheck.value(0).toInt();
            if (count > 0) {
                QMessageBox::warning(this, tr("Erreur de saisie"), tr("Le mot de passe doit être unique pour le poste 'Ressources humaines'."));
                return;
            }
        }

        // Vérification que le mot de passe ne soit pas rempli pour les autres postes
        if (post != "Ressources humaines" && !password.isEmpty()) {
            QMessageBox::warning(this, tr("Erreur de saisie"), tr("Le mot de passe ne doit pas être rempli pour ce poste."));
            return;
        }

        // Création et modification de l'employé avec les valeurs mises à jour
        employee e(id, nom, prenom, post, sexe, salaire, password);
        bool test = e.modifier();
        if (test) {
            ui->tableView->setModel(e.afficher()); // Mise à jour de l'affichage
            clrinput(); // Réinitialisation des champs
            QMessageBox::information(this, tr("Succès"), tr("Employé modifié avec succès."));
        } else {
            QMessageBox::critical(this, tr("Erreur !!"), tr("Impossible de modifier l'employé."), QMessageBox::Cancel);
            clrinput(); // Réinitialisation des champs en cas d'échec
        }
}




void employeeUI::on_supp_clicked()
{
    // Récupérer l'ID de l'utilisateur depuis le QLineEdit
    bool ok;
    int id = ui->lineEdit_supp->text().toInt(&ok);  // Assurez-vous que l'ID est un entier valide

    if (!ok || id <= 0) {
        // Si l'ID n'est pas valide, afficher un message d'erreur
        QMessageBox::warning(this, QObject::tr("Erreur de saisie"),
                             QObject::tr("Veuillez entrer un ID valide."),
                             QMessageBox::Ok);
        return;
    }

    employee E1;
    E1.setId(id);

    // Créer une requête pour vérifier si l'ID existe
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM employee WHERE id = :id");
    query.bindValue(":id", E1.getId());

    if (!query.exec()) {
        // Si la requête échoue, afficher une erreur
        QMessageBox::critical(this, QObject::tr("Erreur de requête"),
                              QObject::tr("Une erreur est survenue lors de la vérification de l'ID."),
                              QMessageBox::Cancel);
        return;
    }

    query.next();
    int count = query.value(0).toInt();

    // Si l'ID n'existe pas dans la base de données
    if (count == 0) {
        QMessageBox::warning(this, QObject::tr("Erreur de suppression"),
                             QObject::tr("L'ID spécifié n'existe pas ."),
                             QMessageBox::Ok);
        return;
    }

    // Si l'ID existe, procéder à la suppression
    if (E1.Supprimer(E1.getId())) {
        // Afficher un message de succès après la suppression
        QMessageBox::information(this, QObject::tr("Suppression réussie"),
                                 QObject::tr("L'employé a été supprimé avec succès."),
                                 QMessageBox::Ok);

        // Rafraîchir la vue pour afficher les données mises à jour
        ui->tableView->setModel(E1.afficher());
    } else {
        // Afficher un message d'erreur si la suppression échoue
        QMessageBox::critical(this, QObject::tr("Erreur de suppression"),
                              QObject::tr("Une erreur est survenue lors de la suppression de l'employé."),
                              QMessageBox::Cancel);
    }

    // Réinitialiser le champ de saisie
    ui->lineEdit_supp->clear();
}



void employeeUI::on_lineEdit_recherche_textChanged(const QString &text)
{
    QString critere = ui->comboBox_critere->currentText();
        QSqlQueryModel *model = new QSqlQueryModel();

        QString queryStr = "SELECT id, nom, prenom, post, sexe, salaire FROM employee WHERE ";

        if (critere == "id") {
            queryStr += "id LIKE '%" + text + "%'";
        } else if (critere == "post") {
            queryStr += "post LIKE '%" + text + "%'";
        } else if (critere == "salaire") {
            queryStr += "salaire LIKE '%" + text + "%'";
        }

        model->setQuery(queryStr);

        if (model->query().lastError().isValid()) {
            qDebug() << "Error executing query:" << model->query().lastError().text();
        } else {
            ui->tableView->setModel(model);
        }
}


void employeeUI::on_comboBox_tri_currentIndexChanged()
{
    // Récupérer le critère de tri sélectionné
        QString critere = ui->comboBox_tri->currentText();

        // Créer une requête SQL pour trier les employés selon le critère choisi
        QString queryStr = "SELECT id, nom, prenom, post, sexe, salaire FROM employee ";

        // Appliquer le tri en fonction du critère sélectionné
        if (critere == "id") {
            queryStr += "ORDER BY id";
        } else if (critere == "nom") {
            queryStr += "ORDER BY nom";
        } else if (critere == "salaire") {
            queryStr += "ORDER BY salaire";
        }

        // Créer un modèle de requête
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(queryStr);

        // Vérifier les erreurs de la requête
        if (model->query().lastError().isValid()) {
            qDebug() << "Error executing query:" << model->query().lastError().text();
        } else {
            // Mettre à jour la vue avec le modèle trié
            ui->tableView->setModel(model);
        }
}





    void employeeUI::on_Demande_conge_clicked()
    {
        congee *c = new congee(this);
        c->exec();


    }

#include <QStackedWidget>
void employeeUI::on_statistiqueButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void employeeUI::on_retour_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void employeeUI::on_stat_btn_clicked()
{
    employee a;
        QLayoutItem* item;

        // Récupérer les statistiques
        QList<QPair<QString, int>> statistics = a.getStatistics();

        // Nettoyer les anciens widgets du layout
        while ((item = ui->horizontalLayout_3->takeAt(0)) != nullptr) {
            delete item->widget(); // Supprime le widget
            delete item;           // Supprime l'élément de mise en page
        }

        // Vérifier si des statistiques sont disponibles
        if (statistics.isEmpty()) {
            qDebug() << "Aucune donnée disponible pour les statistiques.";
            QLabel *label = new QLabel("Aucune statistique à afficher");
            label->setAlignment(Qt::AlignCenter);
            ui->horizontalLayout_3->addWidget(label);
            return;
        }

        // Créer une série pour le graphique circulaire
        QPieSeries *series = new QPieSeries();

        // Remplir la série avec les statistiques
        for (const QPair<QString, int> &pair : statistics) {
            series->append("Salaire " + pair.first + " : " + QString::number(pair.second) + " employés", pair.second);
        }

        // Personnaliser les tranches du graphique
        int colorIndex = 0;
        QList<QColor> colors = {
            QColor("#2196F3"),  // Exemple de bleu
            QColor("#E91E63"),  // Exemple de rose
            QColor("#4CAF50"),  // Exemple de vert
            QColor("#FFEB3B"),  // Exemple de jaune
            QColor("#FF5722")   // Exemple de orange
        };

        for (QPieSlice *slice : series->slices()) {
            slice->setExploded(true); // Met en évidence chaque tranche
            slice->setLabelVisible(true); // Affiche le label avec le nombre d'employés

            // Appliquer une couleur spécifique à chaque tranche
            if (colorIndex < colors.size()) {
                slice->setColor(colors[colorIndex]);
                colorIndex++;
            }
        }

        // Créer le graphique
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Statistiques des employés par Salaire");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        // Créer une vue pour afficher le graphique
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        // Ajouter le graphique au layout
        ui->horizontalLayout_3->addWidget(chartView);
}



void employeeUI::on_ExportationButton_clicked()
{
    QPdfWriter pdf("C:/Users/sirine/Desktop/Liste_Conge.pdf");
        QPainter painter(&pdf);
        int yInitial = 4300; // Position initiale pour les lignes de données
        int lineSpacing = 500; // Espacement vertical entre les lignes

        // En-têtes (date, titre, etc.)
        QColor dateColor(0x4a5bcf);
        painter.setPen(dateColor);
        painter.setFont(QFont("Montserrat SemiBold", 11));
        QDate cd = QDate::currentDate();
        painter.drawText(8400, 250, cd.toString("Tunis"));
        painter.drawText(8100, 500, cd.toString("dd/MM/yyyy"));

        QColor titleColor(0x341763);
        painter.setPen(titleColor);
        painter.setFont(QFont("Montserrat SemiBold", 25));
        painter.drawText(3000, 2700, "Liste des Congés");

        // Dessin des colonnes
        painter.setPen(Qt::black);
        painter.setFont(QFont("Time New Roman", 15));
        painter.drawRect(100, 3300, 9400, 500);

        painter.setFont(QFont("Montserrat SemiBold", 10));
        painter.drawText(500, 3600, "ID");
        painter.drawText(2000, 3600, "Type");
        painter.drawText(3500, 3600, "Date Début");
        painter.drawText(5800, 3600, "Date Fin");

        painter.setFont(QFont("Montserrat", 10));
        painter.drawRect(100, 3300, 9400, 9000); // Rectangle global des données

        // Récupération des données depuis affichercongee
        QSqlQuery query;
        query.prepare("SELECT id, type, datedebut, datefin FROM employee WHERE type IS NOT NULL AND datedebut IS NOT NULL AND datefin IS NOT NULL");
        if (!query.exec()) {
            QMessageBox::warning(this, tr("Erreur"), tr("Impossible de récupérer les données des congés."));
            return;
        }

        // Récupération et dessin des lignes
        int y = yInitial; // Position verticale pour chaque ligne
        bool hasData = false; // Pour vérifier si des données ont été récupérées

        while (query.next()) {
            hasData = true; // Indique qu'il y a au moins une ligne de données

            // Dessiner une ligne horizontale séparatrice
            painter.drawLine(100, y, 9490, y);

            // Écriture des données dans les colonnes
            painter.drawText(500, y, query.value(0).toString());   // ID
            painter.drawText(2000, y, query.value(1).toString()); // Type
            painter.drawText(3500, y, query.value(2).toString()); // Date Début
            painter.drawText(5800, y, query.value(3).toString()); // Date Fin

            // Passer à la ligne suivante
            y += lineSpacing;
        }

        // Vérifier s'il n'y a pas de données
        if (!hasData) {
            painter.drawText(2000, yInitial, "Aucun congé à afficher.");
        }

        // Afficher un message de confirmation
        QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
                                 QObject::tr("PDF Enregistré!.\n" "Cliquez sur OK pour continuer."),
                                 QMessageBox::Ok);
}

void employeeUI::on_pushButton_22_clicked()
{
    // Créer une instance de l'interface login
        login *loginWindow = new login();  // Si votre classe s'appelle "login", sinon remplacez-le par "loginUI"

        // Afficher l'interface login
        loginWindow->show();

        // Fermer l'interface actuelle (employeeUI)
        this->close();
}

