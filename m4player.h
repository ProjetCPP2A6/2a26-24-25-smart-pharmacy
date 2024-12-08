#ifndef M4PLAYER_H
#define M4PLAYER_H

#include <QDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QAudioOutput>

namespace Ui {
class m4player;
}

class m4player : public QDialog
{
    Q_OBJECT

public:
    explicit m4player(QWidget *parent = nullptr);
    ~m4player();

private slots:
    void on_pushButton_play_clicked();
    void on_pushButton_pause_clicked();
    void on_pushButton_stop_clicked();
    void on_horizontalSlider_volume_valueChanged(int value);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::m4player *ui;
    QMediaPlayer *M_player;
    QVideoWidget *videoWidget;
    QAudioOutput *audioOutput;
};

#endif // M4PLAYER_H
