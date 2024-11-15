#include "widget.h"              // Cabecera de la clase Widget definida en el proyecto.
#include "ui_widget.h"           // Interfaz de usuario generada por Qt Designer para la clase Widget.
#include <QMediaPlayer>          // Proporciona funcionalidades para reproducir archivos multimedia (audio y video).
#include <QAudioOutput>          // Maneja la salida de audio, controlando el volumen, el formato, etc.
#include <QFileDialog>           // Proporciona una interfaz para abrir o guardar archivos (por ejemplo, seleccionar archivos multimedia).
#include <QDebug>                // Facilita la depuración, permite imprimir información en la consola (qDebug).
#include <QSlider>               // Permite crear y manejar un control deslizante (slider), usado para el control de volumen o avance en la reproducción.
#include <QVideoWidget>          // Proporciona un widget para mostrar videos.
#include <QMainWindow>           // Clase base para ventanas principales en aplicaciones Qt, proporciona la funcionalidad de una ventana principal.
#include <QtMultimedia>          // Proporciona soporte general para multimedia en Qt (audio, video, etc.).
#include <QtMultimediaWidgets>   // Proporciona widgets adicionales para multimedia (como QVideoWidget).
#include <QtCore>                // Contiene clases básicas de Qt, como manipulación de cadenas, colecciones, etc.
#include <QtWidgets>             // Contiene clases para crear interfaces gráficas (widgets), como QPushButton, QLabel, etc.
#include <QtGui>                 // Proporciona clases para la gestión de imágenes, fuentes, colores, gráficos, etc.
#include <QStringListModel>      // Permite usar los elementos de listview.
#include <QFileInfo>

Widget::Widget(QWidget *parent)
    : QWidget(parent)            // Llama al constructor de la clase base QWidget.
    , ui(new Ui::Widget)         // Crea una nueva instancia de la interfaz de usuario definida en 'ui_widget.h'.
    , listModel(new QStringListModel(this))
{
    ui->setupUi(this);           // Configura los elementos de la interfaz de usuario definidos en 'form.ui' en el widget actual (este objeto de clase Widget)

    ui->listView->setModel(listModel);  // Configura el modelo en el QListView

    ui->progressSlider->setRange(0, 1000);    // Rango del slider de progreso
    ui->pushButton_play->setIcon(QIcon(":/icons/reproducir.png")); // Pone un Icono al Boton Play

    // Inicializar el reproductor y la salida de audio.
    mMediaPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    mMediaPlayer->setAudioOutput(audioOutput);

    // Configuración de iconos.
    ui->pushButton_play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButton_pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    ui->pushButton_seekback->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    ui->pushButton_seek->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
    ui->pushButton_stop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    ui->pushButton_mute->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));

    // Busca y configura el widget de pantalla de video.
    screen = findChild<QWidget*>("screen");
    videoWidget = new QVideoWidget(screen);
    mMediaPlayer->setVideoOutput(videoWidget);  // Asocia el reproductor al videoWidget
    videoWidget->setGeometry(0, 0, screen->width(), screen->height());

    // Conectar los botones a sus respectivos slots
    connect(ui->open, &QPushButton::clicked, this, &Widget::on_open_clicked);
    disconnect(ui->open, &QPushButton::clicked, this, &Widget::on_open_clicked);
    connect(ui->pushButton_play, &QPushButton::clicked, this, &Widget::on_pushButton_play_clicked);
    connect(ui->pushButton_pause, &QPushButton::clicked, this, &Widget::on_pushButton_pause_clicked);
    connect(ui->pushButton_stop, &QPushButton::clicked, this, &Widget::on_pushButton_stop_clicked);
    connect(ui->vol, &QSlider::valueChanged, this, &Widget::on_vol_valueChanged);

    // Conectar la posición de la canción y el slider de progreso
    connect(mMediaPlayer, &QMediaPlayer::positionChanged, this, &Widget::on_positionChanged);
    connect(ui->progressSlider, &QSlider::sliderMoved, this, &Widget::on_sliderMoved);
    connect(mMediaPlayer, &QMediaPlayer::positionChanged, this, &Widget::updateDuration);

    connect(ui->listView, &QListView::clicked, this, &Widget::on_listView_clicked);

    // Configuración inicial del volumen
    ui->vol->setRange(0, 100); // Rango de volumen de 0 a 100
    ui->vol->setValue(50); // Valor inicial en 50
}

Widget::~Widget()
{
    delete ui;
}

// Listas para almacenar los nombres de archivo y sus rutas completas
QStringList fileNameList;  // Nombres de archivo para mostrar en la interfaz
QStringList filePathList;  // Rutas completas de los archivos para reproducción

void Widget::on_pushButton_play_clicked()
{
    mMediaPlayer->play();
}

void Widget::on_pushButton_pause_clicked()
{
    mMediaPlayer->pause();
}

void Widget::on_pushButton_stop_clicked()
{
    mMediaPlayer->stop();
}

void Widget::on_open_clicked()
{
    // Abre un archivo de audio o video
    QString fileName = QFileDialog::getOpenFileName(this, "Selecciona un archivo de audio o video", QString(), "Media Files (*.mp3 *.mp4 *.wav)");

    if (!fileName.isEmpty())
    {
        QFileInfo fileInfo(fileName);

        // Agregar el nombre y la ruta completa a sus respectivas listas
        fileNameList.append(fileInfo.fileName());
        filePathList.append(fileName);

        // Actualiza el modelo de la vista de la lista solo con los nombres
        listModel->setStringList(fileNameList);

        // Configura el archivo en el reproductor y actualiza la etiqueta
        mMediaPlayer->setSource(QUrl::fromLocalFile(fileName));
        ui->label_file_name->setText(fileInfo.fileName());
        qDebug() << "Archivo cargado:" << fileName;
    }
}

void Widget::on_vol_valueChanged(int value)
{
    audioOutput->setVolume(value / 100.0); // Ajustar el volumen de 0.0 a 1.0
}

void Widget::on_positionChanged(qint64 position)
{
    // Actualiza el slider de progreso de acuerdo con la posición actual de la canción
    if (mMediaPlayer->duration() > 0) {
        ui->progressSlider->setValue(static_cast<int>((position * 1000) / mMediaPlayer->duration()));
    }
}

void Widget::on_sliderMoved(int value)
{
    // Cambia la posición de la canción de acuerdo con el valor del slider
    qint64 newPosition = (value * mMediaPlayer->duration()) / 1000;
    mMediaPlayer->setPosition(newPosition);
}

void Widget::on_pushButton_mute_clicked()
{
    IS_Muted = !IS_Muted;
    audioOutput->setMuted(IS_Muted);
    ui->pushButton_mute->setIcon(style()->standardIcon(IS_Muted ? QStyle::SP_MediaVolumeMuted : QStyle::SP_MediaVolume));
}

void Widget::on_pushButton_seekback_clicked()
{
    qint64 newPosition = mMediaPlayer->position() - 5000;  // Retrocede 5 segundos
    if (newPosition >= 0)
    {
        mMediaPlayer->setPosition(newPosition);
    }
}

void Widget::on_pushButton_seek_clicked()
{
    qint64 newPosition = mMediaPlayer->position() + 5000;  // Adelanta 5 segundos
    if (newPosition <= mMediaPlayer->duration())
    {
        mMediaPlayer->setPosition(newPosition);
    }
}

void Widget::durationChanged(qint64 duration)
{
    mDuration = duration;  // Ahora en milisegundos
    ui->progressSlider->setMaximum(mDuration);
}

void Widget::updateDuration(qint64 position)
{
    qint64 currentSecond = (position / 1000);  // Convierte posición de milisegundos a segundos

    if (currentSecond != lastSecond)  // Solo actualiza si el segundo ha cambiado
    {
        lastSecond = currentSecond;   // Actualiza la última posición del segundo

        QTime currentTime((position / 3600000) % 60, (position / 60000) % 60, (position / 1000) % 60);
        QString format = mDuration > 3600 ? "hh:mm:ss" : "mm:ss";

        ui->label_time->setText(currentTime.toString(format));
    }
}

void Widget::on_listView_clicked(const QModelIndex &index)
{
    // Obtiene la ruta completa del archivo basado en el índice de la lista
    QString selectedFilePath = filePathList.at(index.row());

    // Configura la fuente del archivo seleccionado y actualiza la etiqueta con el nombre del archivo
    mMediaPlayer->setSource(QUrl::fromLocalFile(selectedFilePath));
    ui->label_file_name->setText(fileNameList.at(index.row()));

    // Reproduce el archivo seleccionado
    mMediaPlayer->play();
}
