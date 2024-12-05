//
// Created by fruit on 02.12.24.
//

#include "player.h"
#include <QMediaPlayer>
#include <QAudioOutput>

player *player::instance = nullptr;

player::player(): M_Player(new QMediaPlayer()), audioOutput(new QAudioOutput()),isPlaying(false), isMuted(false)
{
    volScale = 100;
    vol = static_cast<qfloat16>(10/volScale);
    audioOutput->setVolume(vol);
    M_Player->setAudioOutput(audioOutput);
}


void player::setSong(QString filePath) const
{
    M_Player->setSource(QUrl::fromLocalFile(filePath));
}


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
void player::setVolume(const int value)
{
    vol = static_cast<qfloat16>(value/volScale);
    audioOutput->setVolume(vol);
    M_Player->setAudioOutput(audioOutput);
}
void player::setPosition(const int value) const
{
    M_Player->setPosition(value * 1000);
}

void player::skipToNextSong()
{
    //TODO: Implement
}

void player::skipToLastSong()
{
    //TODO: Implement
}

void player::toggleShuffle()
{
    //TODO: Implement
}

void player::toggleMute()
{
    isMuted = !isMuted;
    audioOutput->setMuted(isMuted);
}

void player::durationChanged(const qint64 duration)
{
    //TODO: Implement
}

void player::positionChanged(const qint64 progress)
{
    //TODO: Implement
}









