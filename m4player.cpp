#include "m4player.h"
#include "ui_m4player.h"
#include <QVBoxLayout>
#include <QFileDialog>
#include <QAudioOutput>

m4player::m4player(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::m4player)
{
    ui->setupUi(this);

    videoWidget = new QVideoWidget(this);

    M_player = new QMediaPlayer();
    M_player->setVideoOutput(videoWidget);

    audioOutput = new QAudioOutput(this);
    M_player->setAudioOutput(audioOutput);

    audioOutput->setVolume(ui->horizontalSlider_volume->value() / 100.0);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(videoWidget);
    ui->videoContainer->setLayout(layout);

    ui->label_2->setVisible(true);
    ui->label_2->setText("50%");
}

m4player::~m4player()
{
    delete ui;
}

void m4player::on_pushButton_play_clicked()
{
    M_player->play();
}

void m4player::on_pushButton_pause_clicked()
{
    M_player->pause();
}

void m4player::on_pushButton_stop_clicked()
{
    M_player->stop();
}

void m4player::on_horizontalSlider_volume_valueChanged(int value)
{
    audioOutput->setVolume(value / 100.0);
    QString volval = QString::number(value);
    ui->label_2->setText(volval + "%");
}

void m4player::on_pushButton_clicked()
{
    M_player->stop();
    close();
}

void m4player::on_pushButton_2_clicked()
{
    QString FileName = QFileDialog::getOpenFileName(this, tr("Select Video File"), "", tr("MP4 Files (*.MP4);;All Files (*)"));
    if (!FileName.isEmpty()) {
        M_player->setSource(QUrl::fromLocalFile(FileName));
        QFileInfo File(FileName);
        ui->label_value->setText(File.fileName());
    }
}

void m4player::on_pushButton_3_clicked()
{
    close();
}
