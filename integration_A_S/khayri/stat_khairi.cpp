#include "stat_khairi.h"
#include "ui_stat_khairi.h"
#include <QPainter>
#include <QPaintEvent>
stat_khairi::stat_khairi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat_khairi)
{
    ui->setupUi(this);
}

stat_khairi::~stat_khairi()
{
    delete ui;
}
void stat_khairi::paintEvent(QPaintEvent *)
{

    int A= O.statistique1();
    int B= O.statistique2();
    float s1= A*100 ;
    float s2=B*100;
    float nb = A+B;
    float q2 ;
    q2 = s1/nb ;
    float q3;
    q3=s2/nb;
    float y  ;
    y = (q2*360)/100 ;
    float m;
    m= (q3*360)/100;
    float res1 = 16*y;
    float res2 = 16*m;

    QChartView *chartView = new QChartView(this);
    chartView->setRenderHint(QPainter::Antialiasing);

    QPieSeries *series = new QPieSeries();
    series->append("Prix inférieur a 100", res1);

    series->append("Prix Supérieur a 100", res2);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistique par rapport au prix superieur ou inferieur a 100");

    chartView = new QChartView(chart,ui->label_chat);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(850,600);
    chartView->show();
}
void stat_khairi::on_pushButton_11_clicked()
{
    close();
}

