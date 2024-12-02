//
// Created by fruit on 02.12.24.
//

#include "player.h"

void player::togglePlay()
{
    if (isPlaying)
    {
        M_PLayer->pause();
    }
    else
    {
        M_PLayer->play();
    }
    isPlaying = !isPlaying;
}

player::player(): M_PLayer(new QMediaPlayer()), isPlaying(false)
{
}

player* player::getInstance()
{
    if (instance == nullptr){ instance = new player(); }
    return instance;
}

