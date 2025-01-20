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
    song(QUrl url, const QPixmap& cover, QString title, QString artist, QString duration);
    ~song();

    void setUrl(const QUrl& url) { this->url = url; }

    [[nodiscard]] QUuid getId() const { return id; }
    [[nodiscard]] QUrl getUrl() const { return url; }
    [[nodiscard]] QPixmap getCover() const { return cover; }
    [[nodiscard]] QString getTitle() const { return title; }
    [[nodiscard]] QString getArtist() const { return artist; }
    [[nodiscard]] QString getDuration() const { return duration; }
    [[nodiscard]] QString toSaveString() const {
        return url.toString();
    }

    bool operator==(const song& other) const
    {
        return getUrl() == other.getUrl();
    }

private:
    QUuid id;
    QUrl url;
    QPixmap cover;
    QString title;
    QString artist;
    QString duration;
};

#endif //SONG_H
