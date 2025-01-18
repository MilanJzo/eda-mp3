//
// Created by fruit on 08.12.2024.
//

#include "queueManager.h"

#include "playlistManager.h"

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

//adds a song to the end of the queue
void queueManager::append(const song &s)
{
    queue.append(s);
    emit queueChanged();
}

//adds a vector of songs to the end of the queue
void queueManager::append(const QVector<song> &s)
{
    queue.append(s);
    emit queueChanged();
}

//adds a song to the beginning of the queue
void queueManager::prepend(const song &s)
{
    if (queue.isEmpty()) queue.append(s);
    else queue.insert(1, s);
    emit queueChanged();
}

//adds a vector of songs to the beginning of the queue
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

//removes a song from the queue
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

//skips to the next song in the queue
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

//skips to the previous song in the queue
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

//manages what happens when a song ends and checks if the queue is looping
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

//plays the clicked song instantly
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

//calls the append function and starts playing the first song if the queue is empty
void queueManager::onAddToQueue(const song &s)
{
    append(s);
    if (queue.size() == 1) {
        player::getInstance()->setSource(queue.first().getUrl());
        player::getInstance()->play();
    }
}

//calls the skip function if queue is not empty or looping
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

//calls the skip backward function
void queueManager::onSkipBackward() {
    skipBackward();
}

//removes all songs from the queue
void queueManager::onClearQueue()
{
    queue.clear();
    history.clear();
    player::getInstance()->stop();
    player::getInstance()->setSource(QUrl());
    emit queueChanged();
}

//clears the queue, appends the playlist and plays the first song
void queueManager::onPlayPlaylistDirectly(const playlist &p)
{
    if (!p.isEmpty())
    {
        queue.clear();
        history.clear();
        append(p);

        player::getInstance()->setSource(queue.first().getUrl());
        player::getInstance()->play();
    }
}

//appends the playlist to the queue and starts playing the first song if the queue is empty
void queueManager::onQueuePlaylist(const playlist &p)
{
    if (!p.isEmpty())
    {
        if (queue.isEmpty())
        {
            append(p);
            player::getInstance()->setSource(queue.first().getUrl());
            player::getInstance()->play();
        } else append(p);
    }
}

//removes a song from the queue
void queueManager::onRemoveFromQueue(const int index)
{
    remove(index);
}