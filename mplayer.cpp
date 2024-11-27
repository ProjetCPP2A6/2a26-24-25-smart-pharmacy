#include "mplayer.h"
#include "ui_mplayer.h"

#include <QAudioOutput>

mplayer::mplayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mplayer)
{
    ui->setupUi(this);
    audioOutput = new QAudioOutput(this);
    M_player = new QMediaPlayer(this);
    M_player->setAudioOutput(audioOutput);

    audioOutput->setVolume(ui->horizontalSlider_volume->value() / 100.0);

    ui->label_2->setVisible(true);
    ui->label_2->setText("50%");
}

mplayer::~mplayer()
{
    delete ui;
}

void mplayer::on_pushButton_play_clicked()
{
    M_player->play();
}

void mplayer::on_pushButton_pause_clicked()
{
    M_player->pause();
}

void mplayer::on_pushButton_stop_clicked()
{
    M_player->stop();
}

void mplayer::on_horizontalSlider_volume_valueChanged(int value)
{
    audioOutput->setVolume(value / 100.0);
    QString volval = QString::number(value);
    ui->label_2->setText(volval + "%");
}

void mplayer::on_pushButton_clicked()
{
    M_player->stop();
    close();
}

void mplayer::on_pushButton_2_clicked()
{
    QString FileName = QFileDialog::getOpenFileName(this,tr("Select Audio File"),"",tr("MP3 Files (*.MP3)"));
    M_player->setSource(QUrl::fromLocalFile(FileName));
    QFileInfo File(FileName);
    ui->label_value->setText(File.fileName());
}

void mplayer::on_pushButton_3_clicked()
{
    close();
}
