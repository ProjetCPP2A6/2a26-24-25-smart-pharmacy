#ifndef MPLAYER_H
#define MPLAYER_H

#include <QMediaPlayer>
#include <QtMultimedia/QMediaPlayer>
#include <QFileDialog>
#include <QStyle>

namespace Ui {
class mplayer;
}

class mplayer : public QDialog
{
    Q_OBJECT

public:
    explicit mplayer(QWidget *parent = nullptr);
    ~mplayer();

private slots:

    void on_pushButton_play_clicked();

    void on_pushButton_pause_clicked();

    void on_horizontalSlider_volume_valueChanged(int value);

    void on_pushButton_stop_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:

    Ui::mplayer *ui;
    QMediaPlayer *M_player;
    QAudioOutput *audioOutput;
};

#endif // MPLAYER_H
