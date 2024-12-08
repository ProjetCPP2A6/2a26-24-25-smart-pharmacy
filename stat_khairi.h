#ifndef STAT_KHAIRI_H
#define STAT_KHAIRI_H

#include <QDialog>
#include <QtCharts>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

#include "ordonnance.h"
namespace Ui {
class stat_khairi;
}

class stat_khairi : public QDialog
{
    Q_OBJECT

public:
    explicit stat_khairi(QWidget *parent = nullptr);
    ~stat_khairi();
protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_11_clicked();

private:
    Ui::stat_khairi *ui;
    QVector<QPointF> dataPoints;
    QChartView *chartView;
    QLineSeries *series;
    ordonnance O;
};

#endif // STAT_KHAIRI_H
