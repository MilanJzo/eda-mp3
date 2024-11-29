//
// Created by fruit on 29.11.24.
//

#ifndef QUEUE_H
#define QUEUE_H
#include <QWidget>

class queue final : QWidget {
    public:
        QUrl getNextSong();
        void addSong(QUrl song);
        void addSongs(QList<QUrl> songs);

    private:
        QList<QUrl> songQueue;

        void removeSong(QUrl song);
        void clearQueue();
};

#endif //QUEUE_H
