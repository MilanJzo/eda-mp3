//
// Created by fruit on 10.12.2024.
//

#include "playlistManager.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>

#include "libraryManager.h"

playlistManager *playlistManager::instance = nullptr;

playlistManager::playlistManager() : playlists(QVector<playlist>()) {
    loadPlaylists();
    connect(libraryManager::getInstance(), &libraryManager::libraryChanged, this, &playlistManager::onLibraryChanged);
}

playlistManager* playlistManager::getInstance()
{
    if (instance == nullptr) { instance = new playlistManager(); }
    return instance;
}

//calls the loadPlaylists function
void playlistManager::onLibraryChanged() {
    loadPlaylists();
}

//updates and inserts a playlist
void playlistManager::upsertPlaylist(const playlist& playlist) {
    QDir dir("./playlists");
    if (!dir.exists()) {
        if (!dir.mkpath(".")) {
            qWarning() << "Failed to create playlists directory";
            return;
        }
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

//creates a new playlist and adds it to the playlists vector
void playlistManager::createPlaylist(const QString& name, QUrl url) {
    for (const auto& currPlaylist: playlists) {
        if (currPlaylist.getName() == name) {
            qWarning() << "Playlist with name " + name + " already exists";
            return;
        }
    }

    // TODO add coverUrl to playlist
    const auto newPlaylist = playlist(name);

    upsertPlaylist(newPlaylist);
    playlists.append(newPlaylist);
    emit playlistsChanged();
}

//loads all playlists from the playlists directory into the playlists vector
void playlistManager::loadPlaylists() {
    playlists.clear();

    QDir dir("./playlists");
    if (!dir.exists()) {
        if (!dir.mkpath(".")) {
            qWarning() << "Failed to create playlists directory";
            return;
        }
    }

    for (const auto& file: dir.entryList(QDir::Files)) {
        QFile playlistFile("./playlists/" + file);
        if (!playlistFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qWarning() << QString("Failed to open " + file);
            return;
        }

        QTextStream stream(&playlistFile);
        playlist newPlaylist(file.chopped(4));
        while (!stream.atEnd()) {
            const auto line = stream.readLine();
            auto song = fromSaveString(line);
            newPlaylist.append(song);
        }

        playlists.append(newPlaylist);
        emit playlistsChanged();
    }
}

//returns a song object from a save string so it can be added to a playlist for example
song playlistManager::fromSaveString(const QString& saveString) {
    for (auto& s: libraryManager::getInstance()->getLibrary()) {
        if (s.getUrl() == QUrl(saveString)) {
            return s;
        }
    }
    return song(QUrl(), QPixmap(":image/placeholder.png"), "Not Found", "Not Found", "Not Found");
}

//adds a song to a playlist
void playlistManager::addTrackToPlaylist(const QString& playlistName, const song& s) {
    for (auto& p: playlists) {
        if (p.getName() == playlistName) {
            p.append(s);
            upsertPlaylist(p);
            emit playlistsChanged();
        }
    }
}

//deletes a playlist and removes it from the playlists vector
void playlistManager::deletePlaylist(const int index) {
    if (QFile file("./playlists/" + playlists[index].getName() + ".txt"); !file.remove()) {
        qWarning() << "Failed to delete " + playlists[index].getName() + ".txt";
        return;
    }
    playlists.remove(index);
    emit playlistsChanged();
}

//removes a song from a playlist
void playlistManager::onDeleteSongFromPlaylist(const int playlistIndex, const int songIndex) {
    playlists[playlistIndex].remove(songIndex);
    upsertPlaylist(playlists[playlistIndex]);
    emit playlistsChanged();
}

//calls the deletePlaylist function
void playlistManager::onDeletePlaylist(const int index) {
    deletePlaylist(index);
}