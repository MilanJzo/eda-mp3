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

    ui->progress->setRange(0, static_cast<int>(player::getInstance()->getDuration() / 1000));
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
    player::getInstance()->skipToLastSong();
}


void controls::on_skipForwards_clicked()
{
    player::getInstance()->skipToNextSong();
}


void controls::on_shuffle_clicked()
{
    player::getInstance()->toggleShuffle();
}


void controls::on_progress_valueChanged(const int value) const
{
    if (ui->progress->isSliderDown())
    {
        player::getInstance()->setPosition(value);
    }
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

