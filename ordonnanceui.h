#ifndef ORDONNANCEUI_H
#define ORDONNANCEUI_H

#include <QDialog>
#include "ordonnance.h"

namespace Ui {
class ordonnanceUI;
}

class ordonnanceUI : public QDialog
{
    Q_OBJECT

public:
    explicit ordonnanceUI(QWidget *parent = nullptr);
    ~ordonnanceUI();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_edit_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_5_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_6_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_pushButton_13_clicked();

private:
    Ui::ordonnanceUI *ui;
    ordonnance ord;
};

#endif // ORDONNANCEUI_H
