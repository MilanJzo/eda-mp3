//
// Created by fruit on 08.12.2024.
//

#include "queueManager.h"

queueManager *queueManager::instance = nullptr;

queueManager *queueManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new queueManager();
    }
    return instance;
}

queueManager::queueManager() : queue(QVector<song>())
{
    Player = player::getInstance();

    connect(Player, QMediaPlayer::mediaStatusChanged, this, &queueManager::onMediaStatusChanged);
}

void queueManager::append(const song &s)
{
    queue.append(s);
    emit queueChanged();
}

void queueManager::prepend(const song &s)
{
    if (queue.isEmpty()) queue.append(s);
    else queue.insert(1, s);
    emit queueChanged();
}

void queueManager::playNext()
{
    if (queue.size() > 1)
    {
        history.append(queue.first());
        queue.removeFirst();
        Player->setSource(queue.first().getUrl());
        Player->play();
        emit queueChanged();
    }

    Player->setSource(queue.first().getUrl());
    Player->play();
}

void queueManager::onMediaStatusChanged(const QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::MediaStatus::EndOfMedia) {
        playNext();
    }
}

void queueManager::onPlayDirectly(const song &s)
{
    prepend(s);
    playNext();
}

void queueManager::onAddToQueue(const song &s)
{
    append(s);
}
