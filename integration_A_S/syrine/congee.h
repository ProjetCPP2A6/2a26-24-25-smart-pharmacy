#ifndef CONGEE_H
#define CONGEE_H

#include <QDialog>

namespace Ui {
class congee;
}

class congee : public QDialog
{
    Q_OBJECT

public:
    explicit congee(QWidget *parent = nullptr);
    ~congee();

private slots:


    void on_validerButton_clicked();


private:
    Ui::congee *ui;
};

#endif // CONGEE_H
