#ifndef STATRANIM_H
#define STATRANIM_H

#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
namespace Ui {
class statranim;
}

class statranim : public QDialog
{
    Q_OBJECT

public:
    explicit statranim(QWidget *parent = nullptr);
    ~statranim();

private slots:
    void on_pushButton_stat_clicked();

private:
    Ui::statranim *ui;
};

#endif // STATRANIM_H
