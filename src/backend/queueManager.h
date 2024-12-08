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
    void append(const QVector<song> &s);
    void prepend(const song &s);
    void remove(const song &s);

    void skipForward();
    void skipBackward();

private slots:
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);

public slots:
    void onPlayDirectly(const song &s);
    void onAddToQueue(const song &s);
    void onSkipForward();
    void onSkipBackward();
    void onClearQueue();
    void onRemoveFromQueue(const song &s);

signals:
    void queueChanged();

private:
    static queueManager *instance;
    queueManager();

    QVector<song> queue;
    QVector<song> history;
};



#endif //QUEUEMANAGER_H
