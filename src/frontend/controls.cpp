//
// Created by fruit on 03.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_controls.h" resolved

#include "controls.h"

#include <QMediaMetaData>

#include "ui_controls.h"

#include "../backend/player.h"


controls::controls(QWidget *parent) :
    QWidget(parent), ui(new Ui::controls) {
    ui->setupUi(this);

    // Player connects
    connect(player::getInstance(), QMediaPlayer::durationChanged, this, &controls::onDurationChanged);
    connect(player::getInstance(), QMediaPlayer::playbackStateChanged, this, &controls::onPlaybackStateChanged);
    connect(player::getInstance(), QMediaPlayer::positionChanged, this, &controls::onPositionChanged);
    connect(player::getInstance(), QMediaPlayer::metaDataChanged, this, &controls::onMetaDataChanged);

    // Audio output connects
    connect(player::getInstance()->audioOutput(), QAudioOutput::mutedChanged, this, &controls::onMutedChanged);

    // Button connects
    connect(ui->playPause, QPushButton::clicked, this, &controls::onPlayPauseClicked);
    connect(ui->volumeButton, QPushButton::clicked, this, &controls::onVolumeButtonClicked);
    connect(ui->skipForwards, QPushButton::clicked, queueManager::getInstance(), &queueManager::onSkipForwardClicked);
    connect(ui->skipBackwards, QPushButton::clicked, queueManager::getInstance(), &queueManager::onSkipBackwardClicked);


    // Slider connects
    connect(ui->volumeSlider, QSlider::valueChanged, this, &controls::onVolumeSliderValueChanged);
    connect(ui->progressSlider, QSlider::sliderReleased, this, &controls::onProgressSliderReleased);
    connect(ui->progressSlider, QSlider::valueChanged, this, &controls::onProgressSliderValueChanged);

    ui->volumeSlider->setValue(50); // 5% volume
}

void controls::onDurationChanged(const qint64 duration) const
{
    ui->progressSlider->setMaximum(static_cast<int>(duration));

    const QString format = duration > 3600000 ? "hh:mm:ss" : "mm:ss";
    ui->totalTime->setText(QTime(0, 0).addMSecs(static_cast<int>(duration)).toString(format));
}

void controls::onPlaybackStateChanged(const QMediaPlayer::PlaybackState state) const
{
    if (state == QMediaPlayer::PlayingState)
    {
        ui->playPause->setIcon(QIcon(":icon/pause.svg"));
    }
    else
    {
        ui->playPause->setIcon(QIcon(":icon/play.svg"));
    }
}

void controls::onPositionChanged(const qint64 progress) const
{
    if (!ui->progressSlider->isSliderDown())
    {
        ui->progressSlider->setValue(static_cast<int>(progress));
    }
}

void controls::onMutedChanged(const bool muted) const
{
    if (muted)
    {
        ui->volumeButton->setIcon(QIcon(":icon/volume-off.svg"));
    }
    else
    {
        ui->volumeButton->setIcon(QIcon(":icon/volume-on.svg"));
    }
}

void controls::onPlayPauseClicked() const
{
    if (player::getInstance()->isPlaying()) {
        player::getInstance()->pause();
    } else {
        player::getInstance()->play();
    }
}

void controls::onVolumeButtonClicked() const
{
    player::getInstance()->toggleMute();
}

void controls::onVolumeSliderValueChanged(const int value) const
{
    player::getInstance()->audioOutput()->setVolume(static_cast<float>(value / 1000.0));
}

void controls::onProgressSliderReleased() const
{
    player::getInstance()->setPosition(ui->progressSlider->value());
}

void controls::onProgressSliderValueChanged(const int value) const
{
    const QString format = value > 3600000 ? "hh:mm:ss" : "mm:ss";
    ui->currentTime->setText(QTime(0, 0).addMSecs(static_cast<int>(value)).toString(format));
}

void controls::onMetaDataChanged() const
{
    const QMediaMetaData metaData = player::getInstance()->metaData();
    const QString title = metaData.value(QMediaMetaData::Title).toString();
    const QString artist = metaData.value(QMediaMetaData::ContributingArtist).toString();

    // TODO set cover but it no works :(
    ui->title->setText(title != "" ? title : "Unknown Title");
    ui->artist->setText(artist != "" ? artist : "Unknown Artist");
}

controls::~controls() {
    delete ui;
}