//
// Created by fruit on 02.12.24.
//

#include "player.h"
#include <QMediaPlayer>
#include <QAudioOutput>

player *player::instance = nullptr;

player::player() {

    setAudioOutput(new QAudioOutput);
    audioOutput()->setVolume(0.1);
}

player *player::getInstance() {
    if (instance == nullptr) { instance = new player(); }
    return instance;
}

void player::toggleMute() {
    audioOutput()->setMuted(!audioOutput()->isMuted());
}










