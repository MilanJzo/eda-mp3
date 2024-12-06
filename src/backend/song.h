//
// Created by fruit on 06.12.2024.
//

#ifndef SONG_H
#define SONG_H
#include <QUrl>


class song {
public:
    song(QUrl url, QString title, QString artist, QString album);
    ~song();

    [[nodiscard]] QUrl getUrl() const { return url; }
    [[nodiscard]] QString getTitle() const { return title; }
    [[nodiscard]] QString getArtist() const { return artist; }

private:
    QUrl url;
    QString title;
    QString artist;
    QString album;
};



#endif //SONG_H
