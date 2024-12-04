//
// Created by fruit on 02.12.24.
//

#include "player.h"

player::player(): M_Player(new QMediaPlayer()), audioOutput(new QAudioOutput()),isPlaying(false)
{
    M_Player->setAudioOutput(audioOutput);
}

player *player::instance = nullptr;

void player::togglePlay()
{
    if (isPlaying)
    {
        M_Player->pause();
    }
    else
    {
        M_Player->play();
    }
    isPlaying = !isPlaying;
}

player* player::getInstance()
{
    if (instance == nullptr){ instance = new player(); }
    return instance;
}
void player::setVolume(const int volume) const
{
    audioOutput->setVolume(volume);
}
void player::setPosition(const int value) const
{
    M_Player->setPosition(value);
}




