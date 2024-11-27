#ifndef TRANSACTIONUI_H
#define TRANSACTIONUI_H

#include <QDialog>

#include "transaction.h"

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

private:
    Ui::transactionUI *ui;
    transaction t;
};

#endif // TRANSACTIONUI_H
