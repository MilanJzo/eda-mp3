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

    connect(Player, &QMediaPlayer::mediaStatusChanged, this, &queueManager::onMediaStatusChanged);
}

void queueManager::append(const song &s)
{
    queue.append(s);
}

void queueManager::prepend(const song &s)
{
    queue.prepend(s);
}

QUrl queueManager::pop()
{
    if (queue.isEmpty())
    {
        return QUrl();
    }
    QUrl url = queue.first().getUrl();
    queue.removeFirst();
    return url;
}

void queueManager::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::MediaStatus::EndOfMedia && !queue.isEmpty()) {
        Player->setSource(pop());
        Player->play();
    }
}
