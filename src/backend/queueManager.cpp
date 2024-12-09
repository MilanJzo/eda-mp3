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
    connect(player::getInstance(), &QMediaPlayer::mediaStatusChanged, this, &queueManager::onMediaStatusChanged);
}

void queueManager::append(const song &s)
{
    queue.append(s);
    emit queueChanged();
}

void queueManager::append(const QVector<song> &s)
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

void queueManager::prepend(const QVector<song> &s)
{
    if (queue.isEmpty()) queue.append(s);
    else {
        for (int i = 0; i < s.size(); i++)
        {
            queue.insert(i + 1, s.at(i));
        }
    }
    emit queueChanged();
}

void queueManager::remove(const int index)
{
    queue.remove(index);
    if (index == 0 && !queue.isEmpty())
    {
        player::getInstance()->setSource(queue.first().getUrl());
        player::getInstance()->play();
    } else if (queue.isEmpty())
    {
        player::getInstance()->stop();
        player::getInstance()->setSource(QUrl());
    }
    emit queueChanged();
}

void queueManager::skipForward()
{
    if (queue.size() > 1)
    {
        history.append(queue.first());
        queue.removeFirst();
        player::getInstance()->setSource(queue.first().getUrl());
        player::getInstance()->play();
        emit queueChanged();
    }
}

void queueManager::skipBackward()
{
    if (!history.isEmpty())
    {
        queue.prepend(history.last());
        history.removeLast();
        player::getInstance()->setSource(queue.first().getUrl());
        player::getInstance()->play();
        emit queueChanged();
    }
}

void queueManager::onMediaStatusChanged(const QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::MediaStatus::EndOfMedia && isLooping() && queue.size() == 1) {
        history.append(queue.first());
        prepend(history);
        history.clear();
        queue.removeFirst();
        player::getInstance()->setSource(queue.first().getUrl());
        player::getInstance()->play();
        emit queueChanged();
    } else if (status == QMediaPlayer::MediaStatus::EndOfMedia && player::getInstance()->loops() != QMediaPlayer::Infinite){
        skipForward();
    }
}

void queueManager::onPlayDirectly(const song &s)
{
    prepend(s);
    if (queue.size() == 1)
    {
        player::getInstance()->setSource(queue.first().getUrl());
        player::getInstance()->play();
        return;
    }
    skipForward();
}

void queueManager::onAddToQueue(const song &s)
{
    append(s);
    if (queue.size() == 1) {
        player::getInstance()->setSource(queue.first().getUrl());
        player::getInstance()->play();
    }
}

void queueManager::onSkipForward() {
    if (isLooping() && queue.size() == 1) {
        history.append(queue.first());
        prepend(history);
        history.clear();
        queue.removeFirst();
        player::getInstance()->setSource(queue.first().getUrl());
        player::getInstance()->play();
        emit queueChanged();
    } else skipForward();
}

void queueManager::onSkipBackward() {
    skipBackward();
}

void queueManager::onClearQueue()
{
    queue.clear();
    history.clear();
    player::getInstance()->stop();
    player::getInstance()->setSource(QUrl());
    emit queueChanged();
}

void queueManager::onRemoveFromQueue(const int index)
{
    remove(index);
}