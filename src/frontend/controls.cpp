//
// Created by fruit on 03.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_controls.h" resolved

#include "controls.h"

#include <QMediaMetaData>

#include "ui_controls.h"

#include "../backend/player.h"
#include "../backend/queueManager.h"


controls::controls(QWidget *parent) :
    QWidget(parent), ui(new Ui::controls) {
    ui->setupUi(this);

    // Player connects
    connect(player::getInstance(), &QMediaPlayer::durationChanged, this, &controls::onDurationChanged);
    connect(player::getInstance(), &QMediaPlayer::playbackStateChanged, this, &controls::onPlaybackStateChanged);
    connect(player::getInstance(), &QMediaPlayer::positionChanged, this, &controls::onPositionChanged);
    connect(player::getInstance(), &QMediaPlayer::metaDataChanged, this, &controls::onMetaDataChanged);

    // Audio output connects
    connect(player::getInstance()->audioOutput(), &QAudioOutput::mutedChanged, this, &controls::onMutedChanged);

    // Button connects
    connect(ui->playPause, &QPushButton::clicked, this, &controls::onPlayPauseClicked);
    connect(ui->volumeButton, &QPushButton::clicked, this, &controls::onVolumeButtonClicked);
    connect(ui->skipForwards, &QPushButton::clicked, queueManager::getInstance(), &queueManager::onSkipForward);
    connect(ui->skipBackwards, &QPushButton::clicked, queueManager::getInstance(), &queueManager::onSkipBackward);
    connect(ui->repeat, &QPushButton::clicked, this, &controls::onLoopStateToggled);

    // Slider connects
    connect(ui->volumeSlider, &QSlider::valueChanged, this, &controls::onVolumeSliderValueChanged);
    connect(ui->progressSlider, &QSlider::sliderReleased, this, &controls::onProgressSliderReleased);
    connect(ui->progressSlider, &QSlider::valueChanged, this, &controls::onProgressSliderValueChanged);

    ui->volumeSlider->setValue(25); // 25% volume
    ui->cover->setPixmap(QPixmap(":image/placeholder.png").scaled(55, 55));
}

//manages the duration display and the progress slider range
void controls::onDurationChanged(const qint64 duration) const
{
    ui->progressSlider->setMaximum(static_cast<int>(duration));

    const QString format = duration > 3600000 ? "hh:mm:ss" : "mm:ss";
    ui->totalTime->setText(QTime(0, 0).addMSecs(static_cast<int>(duration)).toString(format));
}

//manages the play/pause button icon
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

//manages the progress slider position
void controls::onPositionChanged(const qint64 progress) const
{
    if (!ui->progressSlider->isSliderDown())
    {
        ui->progressSlider->setValue(static_cast<int>(progress));
    }
}

//manages the mute button icon
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

//plays/pauses the media player when the play/pause button is clicked
void controls::onPlayPauseClicked() const
{
    auto Player = player::getInstance();
    if (Player->isPlaying()) {
        Player->pause();
    } else {
        Player->play();
    }
}

//mutes/unmutes the media player when the volume button is clicked by calling the toggleMute function
void controls::onVolumeButtonClicked() const
{
    player::getInstance()->toggleMute();
}

//sets the volume of the media player (song) to the value of the volume slider
void controls::onVolumeSliderValueChanged(const int value) const
{
    player::getInstance()->audioOutput()->setVolume(static_cast<float>(value / 1000.0));
}

//sets the position of the media player (song) to the value of the progress slider
void controls::onProgressSliderReleased() const
{
    player::getInstance()->setPosition(ui->progressSlider->value());
}

//manages the current time display of the song
void controls::onProgressSliderValueChanged(const int value) const
{
    const QString format = value > 3600000 ? "hh:mm:ss" : "mm:ss";
    ui->currentTime->setText(QTime(0, 0).addMSecs(static_cast<int>(value)).toString(format));
}

//manages the metadata display of the song
void controls::onMetaDataChanged() const
{
    if (player::getInstance()->source() == QUrl()) {
        ui->cover->setPixmap(QPixmap(":/image/placeholder.png").scaled(55, 55));
        ui->title->setText("Select some Media");
        ui->artist->setText("NA");
        return;
    }

    const QMediaMetaData metaData = player::getInstance()->metaData();
    const auto cover = metaData.value(QMediaMetaData::ThumbnailImage).value<QPixmap>();
    const auto title = metaData.value(QMediaMetaData::Title).toString();
    const auto artist = metaData.value(QMediaMetaData::ContributingArtist).toString();

    if (!cover.isNull()) {
        ui->cover->setPixmap(cover.scaled(55, 55));
    } else {
        ui->cover->setPixmap(QPixmap(":image/placeholder.png").scaled(55, 55));
    }
    ui->title->setText(title != "" ? title : "Unknown Title");
    ui->artist->setText(artist != "" ? artist : "Unknown Artist");
}

//sets the icon to the corresponding loop state
void controls::onLoopStateToggled() {
    if (loopState == LoopingState::None)
    {
        loopState = LoopingState::Loop;
        queueManager::getInstance()->setLooping(true);
        ui->repeat->setIcon(QIcon(":icon/list-repeat.svg"));
    }
    else if (loopState == LoopingState::Loop)
    {
        loopState = LoopingState::LoopOne;
        player::getInstance()->setLoops(QMediaPlayer::Infinite);
        queueManager::getInstance()->setLooping(false);
        ui->repeat->setIcon(QIcon(":icon/repeat-1.svg"));
    }
    else
    {
        loopState = LoopingState::None;
        player::getInstance()->setLoops(1);
        ui->repeat->setIcon(QIcon(":icon/list.svg"));
    }
}

controls::~controls() {
    delete ui;
}