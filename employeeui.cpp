#include "employeeui.h"
#include "ui_employeeui.h"
#include <QSqlError>
#include <QMessageBox>

employeeUI::employeeUI(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::employeeUI)
{
    ui->setupUi(this);
    connect(ui->lineEdit_recherche, &QLineEdit::textChanged, this, &employeeUI::on_lineEdit_recherche_textChanged);
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
    ui->post->setText("");
    ui->sexe->setText("");
    ui->salaire->setText("");
}

void employeeUI::on_ajouter_clicked()
{
    // Vérification des champs vides
    if (ui->id->text().isEmpty() ||
        ui->nom->text().isEmpty() ||
        ui->prenom->text().isEmpty() ||
        ui->post->text().isEmpty() ||
        ui->sexe->text().isEmpty() ||
        ui->salaire->text().isEmpty()) {
        QMessageBox::warning(this, tr("Erreur de saisie"), tr("Veuillez remplir tous les champs."));
        return;
    }

    // Récupération des valeurs
    int id = ui->id->text().toInt();
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
    QString post = ui->post->text();
    QString sexe = ui->sexe->text();
    float salaire = ui->salaire->text().toFloat();

    // Vérification de la validité de l'ID et du salaire
    if (id <= 0) {
        QMessageBox::warning(this, tr("Erreur de saisie"), tr("L'ID doit être un nombre positif."));
        return;
    }

    if (salaire < 0) {
        QMessageBox::warning(this, tr("Erreur de saisie"), tr("Le salaire doit être un nombre positif."));
        return;
    }

    employee e(id, nom, prenom, post, sexe, salaire);
    bool test = e.Ajouter();
    if (test) {
        ui->tableView->setModel(e.afficher());
        clrinput();
    } else {
        QMessageBox::critical(this, tr("Erreur !!"), tr("Impossible d'ajouter l'employé."), QMessageBox::Cancel);
        clrinput();
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
    query.prepare("SELECT nom, prenom, post, sexe, salaire FROM employee WHERE id = :id");
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
    QString post = ui->post->text().isEmpty() ? query.value(2).toString() : ui->post->text();
    QString sexe = ui->sexe->text().isEmpty() ? query.value(3).toString() : ui->sexe->text();
    float salaire = ui->salaire->text().isEmpty() ? query.value(4).toFloat() : ui->salaire->text().toFloat();

    // Vérification de la validité du salaire
    if (salaire < 0) {
        QMessageBox::warning(this, tr("Erreur de saisie"), tr("Le salaire doit être un nombre positif."));
        return;
    }

    // Création d'un nouvel employé avec les valeurs mises à jour
    employee e(id, nom, prenom, post, sexe, salaire);

    // Appel de la méthode de modification
    bool test = e.modifier();
    if (test) {
        ui->tableView->setModel(e.afficher());
        clrinput();
        QMessageBox::information(this, tr("Succès"), tr("Employé modifié avec succès."));
    } else {
        QMessageBox::critical(this, tr("Erreur !!"), tr("Impossible de modifier l'employé."), QMessageBox::Cancel);
        clrinput();
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

