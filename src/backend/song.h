//
// Created by fruit on 06.12.2024.
//

#ifndef SONG_H
#define SONG_H
#include <qimage.h>
#include <QUrl>


class song {
public:
    song(QUrl url, QImage cover, QString title, QString artist);
    ~song();

    [[nodiscard]] QUrl getUrl() const { return url; }
    [[nodiscard]] QImage getCover() const { return cover; }
    [[nodiscard]] QString getTitle() const { return title; }
    [[nodiscard]] QString getArtist() const { return artist; }

    QString toSaveString() const {
        return url.toString() + ";" + title + ";" + artist;
    }

private:
    QUrl url;
    QImage cover;
    QString title;
    QString artist;
    QString album;
};



#endif //SONG_H
