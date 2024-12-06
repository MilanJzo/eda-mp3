//
// Created by fruit on 03.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_controls.h" resolved

#include "controls.h"
#include "ui_controls.h"

#include "../backend/player.h"


controls::controls(QWidget *parent) :
    QWidget(parent), ui(new Ui::controls) {
    ui->setupUi(this);

    // connect(player::getInstance(), &player::positionChanged, this, &controls::updateTimeLabels);
    // connect(player::getInstance(), &player::setDuration, this, &controls::setProgressRange);
}

controls::~controls() {
    delete ui;
}

void controls::on_playPause_clicked() const
{
    player::getInstance()->togglePlay();

    if (player::getInstance()->getIsPlaying())
    {
        ui->playPause->setIcon(QIcon(":icon/pause.svg"));
    }
    else
    {
        ui->playPause->setIcon(QIcon(":icon/play.svg"));
    }
}


void controls::on_skipBackwards_clicked()
{
    //TODO: Implement
    player::getInstance()->skipToLastSong();
}


void controls::on_skipForwards_clicked()
{
    //TODO: Implement
    player::getInstance()->skipToNextSong();
}


void controls::on_shuffle_clicked()
{
    //TODO: Implement
    player::getInstance()->toggleShuffle();
}


void controls::on_volumeButton_clicked() const
{
    player::getInstance()->toggleMute();

    if (player::getInstance()->getIsMuted())
    {
        ui->volumeButton->setIcon(QIcon(":icon/volume-on.svg"));
    }
    else
    {
        ui->volumeButton->setIcon(QIcon(":icon/volume-off.svg"));
    }
}


void controls::on_volumeSlider_valueChanged(const int value)
{
    player::getInstance()->setVolume(value);
}


void controls::on_progress_valueChanged(const int value) const
{
    if (ui->progress->isSliderDown())
    {
        player::getInstance()->setPosition(value);
    }
    else
    {
        ui->progress->setValue(value);
    }
}


void controls::setProgressRange(const int value) const
{
    ui->progress->setMaximum(value / 1000);
}


void controls::updateTimeLabels(const int progress) const
{
    const QTime currentTime((progress/3600) % 60,(progress/60) % 60,progress % 60,(progress * 1000) % 1000);
    const int duration = static_cast<int>(player::getInstance()->getDuration());
    const QTime totalTime((duration/3600) % 60,(duration/60) % 60,duration % 60,(duration * 1000) % 1000);
    QString format = "mm:ss";
    if (duration > 3600)
        format = "hh:mm:ss";
    ui->currentTime->setText(currentTime.toString(format));
    ui->totalTime->setText(totalTime.toString(format));
}


void controls::on_progress_sliderReleased() const
{
    player::getInstance()->setPosition(ui->progress->value());
}

