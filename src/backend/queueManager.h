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

    void append(const song &s);
    void prepend(const song &s);

    QUrl pop();

private slots:
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);

private:
    static queueManager *instance;
    queueManager();

    player *Player;
    QVector<song> queue;
};



#endif //QUEUEMANAGER_H
