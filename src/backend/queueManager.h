//
// Created by fruit on 08.12.2024.
//

#ifndef QUEUEMANAGER_H
#define QUEUEMANAGER_H
#include <QMediaPlayer>
#include <QObject>

#include "player.h"
#include "playlist.h"
#include "song.h"


class queueManager final : public QObject
{
    Q_OBJECT

public:
    static queueManager *getInstance();
    [[nodiscard]] const QVector<song> &getQueue() const { return queue; }

    void append(const song &s);
    void append(const QVector<song> &s);
    void prepend(const song &s);
    void prepend(const QVector<song> &s);
    void remove(int index);

    void skipForward();
    void skipBackward();

    void setLooping(const bool loop) { looping = loop; }
    [[nodiscard]] bool isLooping() const { return looping; }

private slots:
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);

public slots:
    void onPlayDirectly(const song &s);
    void onAddToQueue(const song &s);
    void onSkipForward();
    void onSkipBackward();
    void onClearQueue();
    void onRemoveFromQueue(int index);
    void onPlayPlaylistDirectly(const playlist &p);
    void onQueuePlaylist(const playlist &p);
    void onShuffleStateChanged(bool shuffle);

signals:
    void queueChanged();

private:
    static queueManager *instance;
    queueManager();
    bool looping = false;

    QVector<song> queue;
    QVector<song> history;
    QVector<song> originalQueue;
};



#endif //QUEUEMANAGER_H
