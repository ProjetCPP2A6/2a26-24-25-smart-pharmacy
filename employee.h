#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>
class employee
{
private:
    int id;
    QString nom,prenom,post,sexe,password,type;
    float salaire;
    QDate dateDebut,dateFin;

public:
    employee();
    employee(int,QString,QString,QString,QString,float,QString);
    employee(int,QString,QString,QString,QString,float);
    employee(int,QString ,QDate,QDate);
    bool Ajouter(int employeeId, QDate dateDebut, QDate dateFin, QString typeConge);

    // Getters
    int getId();
    QString getNom();
    QString getPrenom();
    QString getPost();
    QString getSexe();
    float getSalaire();
    QString getPassword();
    QString getType();
    QDate getDateDebut();
    QDate getDateFin();
    bool doesIDExist(int idd);
    bool isPasswordCorrect(int idd, const QString& password);

    // Setters
    void setId(int id);
    void setNom(QString nom);
    void setPrenom(QString prenom);
    void setPost(QString post);
    void setSexe(QString sexe);
    void setSalaire(float salaire);
    void setPassword(QString password);
    void setType(QString type);
    void setDateDebut(QDate dateDebut);
    void setDateFin(QDate dateFin);


    //CRUD
    bool Ajouter();
    QSqlQueryModel* afficher();
    bool Supprimer(int);
    bool modifier();
    bool reset();
    bool modifierconde();
    QSqlQueryModel* affichercongee();
    QList<QPair<QString, int>> getStatistics();

};

#endif // EMPLOYEE_H
