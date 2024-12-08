//
// Created by fruit on 02.12.24.
//

#include "player.h"
#include <QMediaPlayer>
#include <QAudioOutput>

player *player::instance = nullptr;

player::player() {

    setAudioOutput(new QAudioOutput);
}

player *player::getInstance() {
    if (instance == nullptr) { instance = new player(); }
    return instance;
}

void player::toggleMute() const {
    audioOutput()->setMuted(!audioOutput()->isMuted());
}










