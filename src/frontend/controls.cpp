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
}

controls::~controls() {
    delete ui;
}

void controls::on_playPause_clicked()
{
    player::getInstance()->togglePlay();
}


void controls::on_skipBackwards_clicked()
{

}


void controls::on_skipForwards_clicked()
{

}


void controls::on_shuffle_clicked()
{

}


void controls::on_progress_valueChanged(int value)
{
    player::getInstance()->setPosition(value);
}


void controls::on_volumeButton_clicked()
{

}


void controls::on_volumeSlider_valueChanged(int value)
{

}

