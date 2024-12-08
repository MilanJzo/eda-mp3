//
// Created by fruit on 08.12.2024.
//

#ifndef QUEUEMANAGER_H
#define QUEUEMANAGER_H
#include <QMediaPlayer>
#include <QObject>

#include "player.h"
#include "song.h"


class queueManager final : public QObject
{
    Q_OBJECT

public:
    static queueManager *getInstance();
    [[nodiscard]] const QVector<song> &getQueue() const { return queue; }

    void append(const song &s);
    void prepend(const song &s);

    void playNext();

private slots:
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);

public slots:
    void onPlayDirectly(const song &s);
    void onAddToQueue(const song &s);

signals:
    void queueChanged();

private:
    static queueManager *instance;
    queueManager();

    player *Player;
    QVector<song> queue;
    QVector<song> history;
};



#endif //QUEUEMANAGER_H
