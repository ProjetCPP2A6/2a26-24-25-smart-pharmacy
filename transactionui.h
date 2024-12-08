#ifndef TRANSACTIONUI_H
#define TRANSACTIONUI_H

#include <QDialog>

#include "transaction.h"
#include "arduino.h"
#include "calendardialog.h"
namespace Ui {
class transactionUI;
}

class transactionUI : public QDialog
{
    Q_OBJECT

public:
    explicit transactionUI(QWidget *parent = nullptr);
    ~transactionUI();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void on_ajouter_clicked();

    void on_editer_clicked();

    void on_supp_clicked();

    void initializeComboBox();


    void on_type_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_13_clicked() ;

    void sendTransactionEmail(const QString &id, float montant, const QString &type, const QString &description, const QDate &date);

    void sendEditedTransactionEmail(const QString &id, float montant, const QString &type, const QString &description, const QDate &date);

    //void captureWindowAndSave();

    //void on_captureButton_clicked();

    bool handleArduinoData();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::transactionUI *ui;
    transaction t;
    arduino a;
    CalendarDialog CD;
};

#endif // TRANSACTIONUI_H
