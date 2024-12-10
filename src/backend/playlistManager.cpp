//
// Created by fruit on 10.12.2024.
//

#include "playlistManager.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

playlistManager *playlistManager::instance = nullptr;

playlistManager::playlistManager() : playlists(QVector<playlist>()) {}

playlistManager* playlistManager::getInstance()
{
    if (instance == nullptr) { instance = new playlistManager(); }
    return instance;
}

void playlistManager::upsertPlaylist(const QUuid id) {
    for (const auto& playlist: playlists) {
        if (playlist.getId() == id) {
            QFile file("./playlists/" + playlist.getName() + ".txt");
            if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                qWarning() << QString("Failed to open " + playlist.getName() + ".txt");
                return;
            }
            file.resize(0);

            QTextStream stream(&file);
            for (const auto& song: playlist) {
                stream << song.getUrl().toString() << "\n";
            }

            file.close();

            return;
        }
    }
}