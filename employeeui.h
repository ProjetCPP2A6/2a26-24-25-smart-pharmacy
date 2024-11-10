#ifndef EMPLOYEEUI_H
#define EMPLOYEEUI_H

#include <QDialog>
#include "employee.h"

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

private:
    Ui::employeeUI *ui;
    employee e;
};

#endif // EMPLOYEEUI_H
