#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class employee
{
private:
    int id;
    QString nom,prenom,post,sexe;
    float salaire;

public:
    employee();
    employee(int,QString,QString,QString,QString,float);

    // Getters
    int getId();
    QString getNom();
    QString getPrenom();
    QString getPost();
    QString getSexe();
    float getSalaire();

    // Setters
    void setId(int id);
    void setNom(QString nom);
    void setPrenom(QString prenom);
    void setPost(QString post);
    void setSexe(QString sexe);
    void setSalaire(float salaire);

    //CRUD
    bool Ajouter();
    QSqlQueryModel* afficher();
    bool Supprimer(int);
    bool modifier();
    bool reset();

};

#endif // EMPLOYEE_H
