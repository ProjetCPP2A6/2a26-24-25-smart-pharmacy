#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QDialog>
#include <QtCharts>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

#include "medicament.h"

namespace Ui {
class statistique;
}

class statistique : public QDialog
{
    Q_OBJECT

public:
    explicit statistique(QWidget *parent = nullptr);
    ~statistique();

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_11_clicked();
    void closeEvent(QCloseEvent *event);
private:
    Ui::statistique *ui;
    QVector<QPointF> dataPoints;
    QChartView *chartView;
    QLineSeries *series;
    medicament m;
};

#endif // STATISTIQUE_H
