//
// Created by Markus Heming on 03.12.24.
//

#include "libraryManager.h"
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QMediaMetaData>
#include <thread>


#include "metaDataHelper.h"
#include "player.h"
#include "../frontend/library.h"

libraryManager *libraryManager::instance = nullptr;

libraryManager::libraryManager() : library(QVector<song>()){
    loadLibrary();
}

libraryManager* libraryManager::getInstance()
{
    if (instance == nullptr) { instance = new libraryManager(); }
    return instance;
}

void libraryManager::loadDirIntoLibrary(const QString &dir)
{
    const QStringList mp3Files = getMP3FilenamesFromDirectory(dir);
    for (const QString &file : mp3Files) {
        const QUrl url("file:///" + dir + "/" + file);

        // TODO get actual metadata

        auto cover = QPixmap(":/image/placeholder.png").scaled(55, 55);
        auto title = file;
        auto artist = "Unknown Artist";

        library.append(song(url, cover, title, artist));
    }
    emit libraryChanged();
}


//// another Try didn't work
// void libraryManager::loadDirIntoLibrary(const QString &dir)
// {
//     const auto player = player::getInstance();
//     auto mdHelper = metaDataHelper(this, player);
//     auto urls = QVector<QUrl>();
//
//     const QStringList mp3Files = getMP3FilenamesFromDirectory(dir);
//     for (const QString &file : mp3Files) {
//         const QUrl url("file:///" + dir + "/" + file);
//         player->setSource(url);
//         urls.append(url);
//     }
//
//     auto songs = mdHelper.getMetaData();
//     for (int i = 0; i < songs.size(); i++) {
//         songs[i].setUrl(urls[i]);
//     }
//
//     library.append(songs);
//     emit libraryChanged();
// }

void libraryManager::loadLibrary()
{
    QFile file("./libraryDirectories.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qWarning() << "Failed to open libraryDirectories.txt";
        return;
    }

    QTextStream stream(&file);
    while (!stream.atEnd()) {
        loadDirIntoLibrary(stream.readLine());
    }

    file.close();
    qDebug() << "Loaded library";
}

void libraryManager::addDirectory() {
    const QString dir = QFileDialog::getExistingDirectory(nullptr, "Select Directory", QDir::homePath());

    QFile file("./libraryDirectories.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qWarning() << "Failed to open libraryDirectories.txt";
        return;
    }

    QTextStream stream(&file);
    while (!stream.atEnd()) {
        if (stream.readLine().compare(dir) == 0)
        {
            qWarning() << "Directory already in libraryDirectories.txt";
            return;
        }
    }

    stream << dir << "\n";
    file.close();

    loadDirIntoLibrary(dir);
    emit libraryChanged();
    qDebug() << "Added directory to library";
}

QStringList libraryManager::getMP3FilenamesFromDirectory(const QString& pathToDir)
{
    const QDir dir(pathToDir);
    QStringList filters;
    filters<< "*.mp3";
    return dir.entryList(filters, QDir::Files);
}