//
// Created by Markus Heming on 03.12.24.
//

#include "libraryManager.h"
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QProcess>
#include <QFile>
#include <QDir>
#include <QMediaMetaData>
#include <thread>


#include "player.h"
#include "playlistManager.h"
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

//adds metadata to song object and appends it to library
void libraryManager::loadDirIntoLibrary(const QString &dir)
{
    const QStringList mp3Files = getMP3FilenamesFromDirectory(dir);
    for (const QString &file : mp3Files) {
        const QUrl url("file:///" + dir + "/" + file);

        auto tempPlayer = new QMediaPlayer();
        tempPlayer->setSource(url);

        connect(tempPlayer, &QMediaPlayer::metaDataChanged, this, [this, tempPlayer, url, file](){
            const auto metadata = tempPlayer->metaData();
            const auto cover = metadata.value(QMediaMetaData::ThumbnailImage).value<QPixmap>().isNull() ? QPixmap(":/image/placeholder.png") : metadata.value(QMediaMetaData::ThumbnailImage).value<QPixmap>();
            const auto title = metadata.stringValue(QMediaMetaData::Title) == "" ? file.chopped(4) : metadata.stringValue(QMediaMetaData::Title);
            const auto artist = metadata.stringValue(QMediaMetaData::ContributingArtist) == "" ? "Unknown Artist" : metadata.stringValue(QMediaMetaData::ContributingArtist);
            const auto duration = metadata.stringValue(QMediaMetaData::Duration) == "" ? "00:00" : metadata.stringValue(QMediaMetaData::Duration);

            library.prepend(song(url, cover, title, artist, duration));
            emit libraryChanged();
            tempPlayer->deleteLater();
        });
    }
}

//loads library from libraryDirectories.txt
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
}

void libraryManager::addDirectory()
{
    const QString dir = QFileDialog::getExistingDirectory(nullptr, "Select Directory", QDir::homePath());
    addDirectoryFromUrl(dir);
}

//adds new directory so all songs in it will be added to library
void libraryManager::addDirectoryFromUrl(const QString &dir) {
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
}

//searches for mp3 files in directory
QStringList libraryManager::getMP3FilenamesFromDirectory(const QString& pathToDir)
{
    const QDir dir(pathToDir);
    QStringList filters;
    filters<< "*.mp3";
    return dir.entryList(filters, QDir::Files);
}

void libraryManager::loadSongIntoLibrary(const QUrl &url)
{
    auto tempPlayer = new QMediaPlayer();
    tempPlayer->setSource(url);

    connect(tempPlayer, &QMediaPlayer::metaDataChanged, this, [this, tempPlayer, url](){
        const auto metadata = tempPlayer->metaData();
        const auto cover = metadata.value(QMediaMetaData::ThumbnailImage).value<QPixmap>().isNull() ? QPixmap(":/image/placeholder.png") : metadata.value(QMediaMetaData::ThumbnailImage).value<QPixmap>();
        const auto title = metadata.stringValue(QMediaMetaData::Title) == "" ? url.fileName().chopped(4) : metadata.stringValue(QMediaMetaData::Title);
        const auto artist = metadata.stringValue(QMediaMetaData::ContributingArtist) == "" ? "Unknown Artist" : metadata.stringValue(QMediaMetaData::ContributingArtist);
        const auto duration = metadata.stringValue(QMediaMetaData::Duration) == "" ? "00:00" : metadata.stringValue(QMediaMetaData::Duration);

        library.prepend(song(url, cover, title, artist, duration));
        emit libraryChanged();
        tempPlayer->deleteLater();
    });
}

//downloads song from url
void libraryManager::onSongDownloadRequested(const QString &url)
{

    auto ytdlp = new QProcess(this);
    ytdlp->start("yt-dlp", QStringList() << "-x" << "--audio-format" << "mp3" << "-o" << QDir::currentPath().append("/yt-dlp/%(title)s by %(uploader)s") << "--no-mtime" << url);

    addDirectoryFromUrl(QDir::currentPath().append("/yt-dlp"));
    connect(ytdlp , &QProcess::finished, this, [this, ytdlp](){
        ytdlp->deleteLater();

        loadLibrary();
        // QDir dir(QDir::currentPath().append("/yt-dlp"));
        // dir.setNameFilters(QStringList() << "*.mp3");
        // dir.setSorting(QDir::Time);
        //
        // const QUrl newestSong = QUrl::fromLocalFile("file:///" + dir.path() + "/" + dir.entryList().first());
        // loadSongIntoLibrary(newestSong);
    });
}