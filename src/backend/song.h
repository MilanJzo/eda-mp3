//
// Created by fruit on 06.12.2024.
//

#ifndef SONG_H
#define SONG_H

#include <QPixmap>
#include <QUrl>
#include <QUuid>

class song {
public:
    song(QUrl url, QPixmap cover, QString title, QString artist);
    ~song();

    void setUrl(const QUrl& url) { this->url = url; }

    [[nodiscard]] QUuid getId() const { return id; }
    [[nodiscard]] QUrl getUrl() const { return url; }
    [[nodiscard]] QPixmap getCover() const { return cover; }
    [[nodiscard]] QString getTitle() const { return title; }
    [[nodiscard]] QString getArtist() const { return artist; }
    [[nodiscard]] QString toSaveString() const {
        return url.toString() + ";" + title + ";" + artist;
    }

private:
    QUuid id;
    QUrl url;
    QPixmap cover;
    QString title;
    QString artist;
};

#endif //SONG_H
