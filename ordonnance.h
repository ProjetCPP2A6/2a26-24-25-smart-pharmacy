#ifndef ORDONNANCE_H
#define ORDONNANCE_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QSqlQuery>

class ordonnance
{
private:
    QString id;
    QString nomp;
    QString medecin;
    float prix;
    QDate datep;

public:

    ordonnance();
    ordonnance(QString Id, QString Nomp, QString Medecin, float Prix, QDate Datep);

    // Getters
    QString getId();
    QString getNomp();
    QString getMedecin();
    float getPrix();
    QDate getDatep();

    // Setters
    void setId(QString id);
    void setNomp(QString nomp);
    void setMedecin(QString medecin);
    void setPrix(float prix);
    void setDatep(QDate datep);

    bool Ajouter();
    QSqlQueryModel* afficher();
    bool Supprimer(QString id);
    bool modifier();
    bool reset();

    /*Recherche*/
    QSqlQueryModel *afficher_id(QString ch);
    QSqlQueryModel *afficher_nomp(QString ch);
    QSqlQueryModel *afficher_Medecin(QString ch);
    /*Tri*/
    QSqlQueryModel *afficher_choix(QString choix);
    /*Statistique*/
    int statistique1();
    int statistique2();
    /*PDF*/
    ordonnance* readordonnance (int val);
};

#endif // ORDONNANCE_H
