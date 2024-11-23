#ifndef EMPLOYEEUI_H
#define EMPLOYEEUI_H
#include <QDialog>
#include "employee.h"
#include "congee.h"

namespace Ui {
class employeeUI;
}

class employeeUI : public QDialog
{
    Q_OBJECT

public:
    explicit employeeUI(QWidget *parent = nullptr);
    ~employeeUI();

protected:
    void showEvent(QShowEvent *event) override;


private slots:
    void on_ajouter_clicked();

    void on_editer_clicked();

    void on_supp_clicked();

    void clrinput();



    void on_lineEdit_recherche_textChanged(const QString &arg1);



    void on_comboBox_tri_currentIndexChanged();









    void on_Demande_conge_clicked();

    void on_statistiqueButton_clicked();

    void on_retour_clicked();

    void on_stat_btn_clicked();

    void on_ExportationButton_clicked();

    void on_pushButton_22_clicked();

private:
    Ui::employeeUI *ui;
    congee *c;
    employee e;


};

#endif // EMPLOYEEUI_H
