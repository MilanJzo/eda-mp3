//
// Created by fruit on 10.12.2024.
//

#ifndef PLAYLISTMANAGER_H
#define PLAYLISTMANAGER_H
#include <QObject>

#include "playlist.h"
#include "song.h"

class playlistManager final : public QObject {
    Q_OBJECT
public:
    static playlistManager* getInstance();

    [[nodiscard]] QVector<playlist> getPlaylists() const { return playlists; }

    void addTrackToPlaylist(const QString& playlistName, const song& s);

    void upsertPlaylist(const playlist& playlist);

    void createPlaylist(const QString& name, QUrl url);

signals:
    void playlistsChanged();

private:
    static playlistManager *instance;
    QVector<playlist> playlists;

    playlistManager();
    void loadPlaylists();
    song fromSaveString(const QString& saveString);
};

#endif //PLAYLISTMANAGER_H
