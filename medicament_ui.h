#ifndef MEDICAMENT_UI_H
#define MEDICAMENT_UI_H

#include "medicament.h"
#include "arduino.h"
#include <QDialog>

namespace Ui {
class medicament_UI;
}

class medicament_UI : public QDialog
{
    Q_OBJECT

public:
    explicit medicament_UI(QWidget *parent = nullptr);
    ~medicament_UI();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void on_add_clicked();

    void on_edit_clicked();

    void on_supp_button_clicked();

    void resetInput();

    void on_pushButton_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_pushButton_13_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_noNotif_clicked();

    void on_pushButton_Notif_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void handleArduinoData();

    void handleFlameDetected();

    void on_pushButton_6_clicked();

private:
    Ui::medicament_UI *ui;
    medicament m;
    arduino arduino;
};

#endif // MEDICAMENT_UI_H
