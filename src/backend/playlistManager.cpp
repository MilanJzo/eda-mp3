//
// Created by fruit on 10.12.2024.
//

#include "playlistManager.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>

playlistManager *playlistManager::instance = nullptr;

playlistManager::playlistManager() : playlists(QVector<playlist>()) {}

playlistManager* playlistManager::getInstance()
{
    if (instance == nullptr) { instance = new playlistManager(); }
    return instance;
}

void playlistManager::upsertPlaylist(const playlist& playlist) {
    QDir dir("./playlists");
    if (!dir.mkdir(".")) {
        qWarning() << "Failed to create playlists directory";
        return;
    }

    QFile file("./playlists/" + playlist.getName() + ".txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qWarning() << QString("Failed to open " + playlist.getName() + ".txt");
        return;
    }

    file.resize(0);

    QTextStream stream(&file);
    for (const auto& song: playlist) {
        stream << song.toSaveString() << "\n";
    }

    file.close();
}

void playlistManager::createPlaylist(const QString& name, QUrl url) {
    for (const auto& currPlaylist: playlists) {
        if (currPlaylist.getName() == name) {
            qWarning() << "Playlist with name " + name + " already exists";
            return;
        }
    }

    // TODO add coverUrl to playlist
    const auto newPlaylist = playlist(name);

    playlists.append(newPlaylist);
    emit playistsChanged();
    upsertPlaylist(newPlaylist);
}