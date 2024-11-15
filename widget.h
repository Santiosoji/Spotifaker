#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSlider>
#include <QPushButton>  // Incluye QPushButton
#include <QMediaPlayer> // Incluye QMediaPlayer para la reproducción de audio
#include <QVideoWidget>
#include <QAudioOutput> // Incluye QAudioOutput para manejar el audio
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QtCore>
#include <QtWidgets>
#include <QtGui>
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class QMediaPlayer;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_play_clicked();

    void on_pushButton_pause_clicked();

    void on_pushButton_stop_clicked();

    void on_open_clicked();

    void on_vol_valueChanged(int value);

    void on_positionChanged(qint64 position);

    void durationChanged(qint64 duration);

    void on_sliderMoved(int value);

    void on_pushButton_mute_clicked();

    void on_pushButton_seekback_clicked();

    void on_pushButton_seek_clicked();

    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::Widget *ui;
    QMediaPlayer *mMediaPlayer;
    QPushButton *open;
    QPushButton *playButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QSlider *vol;
    QAudioOutput *audioOutput;
    QWidget *screen;
    QVideoWidget *videoWidget;
    qint64 mDuration;
    bool IS_Pause = true;
    bool IS_Muted = false;
    qint64 lastSecond = -1;  // Variable para guardar el último segundo mostrado
    QStringListModel *listModel;
    QStringList fileList;


    void updateDuration(qint64 Duration);
};

#endif // WIDGET_H
