//
// Created by fruit on 06.12.2024.
//

#ifndef SONG_H
#define SONG_H
#include <qimage.h>
#include <QUrl>
#include <QUuid>

#include "../frontend/controls.h"


class song {
public:
    song(QUrl url, const QImage& cover, QString title, QString artist);
    ~song();

    [[nodiscard]] QUuid getId() const { return id; }
    [[nodiscard]] QUrl getUrl() const { return url; }
    [[nodiscard]] QImage getCover() const { return cover; }
    [[nodiscard]] QString getTitle() const { return title; }
    [[nodiscard]] QString getArtist() const { return artist; }
    [[nodiscard]] QString toSaveString() const {
        return url.toString() + ";" + title + ";" + artist;
    }

private:
    QUuid id;
    QUrl url;
    QImage cover;
    QString title;
    QString artist;
    QString album;
};



#endif //SONG_H
