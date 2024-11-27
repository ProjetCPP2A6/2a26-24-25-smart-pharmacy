#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class transaction
{
private:
    QString id, type, description, categorie, modepaiment;
    QDate datep;
    float prix;

public:
    transaction();
    transaction(QString, QString, QString, QString, QString, QDate, float);

    // Getters
    QString getId();
    QString getType();
    QString getDescription();
    QString getCategorie();
    QString getModePaiment();
    QDate getDatep();
    float getPrix();

    // Setters
    void setId(QString Id);
    void setType(QString Type);
    void setDescription(QString Description);
    void setCategorie(QString Categorie);
    void setModePaiment(QString ModePaiment);
    void setDatep(QDate Datep);
    void setPrix(float Prix);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier();
    bool reset();
};

#endif // TRANSACTION_H
