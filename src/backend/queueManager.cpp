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

queueManager::queueManager() : queue(QVector<song>()), history(QVector<song>())
{
    connect(player::getInstance(), QMediaPlayer::mediaStatusChanged, this, &queueManager::onMediaStatusChanged);
}

void queueManager::append(const song& s)
{
    queue.append(s);

    emit queueChanged();
}

void queueManager::prepend(const song& s)
{
    if (queue.isEmpty()) {
        queue.append(s);
    } else {
        queue.insert(1, s);
    }

    emit queueChanged();
}

void queueManager::remove(const song& s)
{
    queue.removeOne(s);

    emit queueChanged();
}

void queueManager::onMediaStatusChanged(const QMediaPlayer::MediaStatus status)
{
    const auto Player = player::getInstance();

    if (status == QMediaPlayer::MediaStatus::EndOfMedia && !queue.isEmpty()) {
        queue.removeFirst();
        Player->setSource(queue.first().getUrl());
        Player->play();

        emit queueChanged();
    }
}

void queueManager::onPlayDirectlyClicked()
{
    const auto Player = player::getInstance();

    if (player::getInstance()->mediaStatus() == QMediaPlayer::MediaStatus::NoMedia)
    {
        Player->setSource(queue.first().getUrl());
        Player->play();
    }
}

void queueManager::onSkipForwardClicked()
{
    const auto Player = player::getInstance();

    if (queue.size() > 1)
    {
        history.append(queue.first());
        queue.removeFirst();
        Player->setSource(queue.first().getUrl());
        Player->play();

        emit queueChanged();
    }
}

void queueManager::onSkipBackwardClicked()
{
    const auto Player = player::getInstance();

    if (!history.isEmpty())
    {
        queue.prepend(history.last());
        history.removeLast();
        Player->setSource(queue.first().getUrl());
        Player->play();

        emit queueChanged();
    }
}

void queueManager::onClearQueueClicked()
{
    queue.clear();
    player::getInstance()->stop();

    emit queueChanged();
}

void queueManager::onAddToQueueClicked()
{
    const auto Player = player::getInstance();

    if (queue.size() == 1)
    {
        Player->setSource(queue.first().getUrl());
        Player->play();
    }
}

