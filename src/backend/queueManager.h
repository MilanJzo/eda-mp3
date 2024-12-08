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

    void append(const song& s);
    void prepend(const song& s);
    void remove(const song& s);

    [[nodiscard]] QVector<song> getQueue() const { return queue; }

private slots:
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);

public slots:
    void onPlayDirectlyClicked();
    void onSkipForwardClicked();
    void onSkipBackwardClicked();
    void onClearQueueClicked();
    void onAddToQueueClicked();

signals:
    void queueChanged();

private:
    static queueManager *instance;
    queueManager();

    QVector<song> queue;
    QVector<song> history;
};



#endif //QUEUEMANAGER_H
