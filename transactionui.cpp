#include "transactionui.h"
#include "ui_transactionui.h"

#include <QMessageBox>

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
        ui->tableView->setModel(t.afficher());
    } else {
        QMessageBox::critical(this, "Error", "Failed to add transaction.");
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

