#ifndef EMPLOYEEUI_H
#define EMPLOYEEUI_H
#include <QDialog>
#include "employee.h"
#include "congee.h"
#include <QSerialPort>
#include "../ranim/fournisseurui.h"
#include "../abdou/medicament_ui.h"
namespace Ui {
class employeeUI;
}

class employeeUI : public QDialog
{
    Q_OBJECT

public:
    explicit employeeUI(QWidget *parent = nullptr);
    ~employeeUI();
    void closeSerialPort();


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

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

private:
    Ui::employeeUI *ui;
    congee *c;
    employee e;
    QSerialPort *serial;
    medicament_UI *medicamentWindow = nullptr;
    fournisseurUI *fournisseurWindow = nullptr;
    QSerialPort serialPort;

};

#endif // EMPLOYEEUI_H
