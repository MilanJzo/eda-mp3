//
// Created by Markus Heming on 03.12.24.
//

#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include <QMediaPlayer>
#include <QObject>
#include <QStringList>

#include "song.h"

class libraryManager final : public QObject {
    Q_OBJECT
public:
    void addDirectory();
    void addDirectoryFromUrl(const QString &dir);
    static libraryManager* getInstance();
    static QStringList  getMP3FilenamesFromDirectory(const QString &pathToDir);
    [[nodiscard]] QVector<song> getLibrary() const { return library; };

signals:
    void libraryChanged();
    void setStatusText(const QString &statusText);

public slots:
    void onSongDownloadRequested(const QString &url);

private:
    static libraryManager* instance;
    QVector<song> library;
    QString status = "Downloading: 000/000   0.0%";

    libraryManager();
    void loadLibrary();
    void loadSongIntoLibrary(const QUrl &url);
    void loadDirIntoLibrary(const QString &dir);

};

#endif //LIBRARYMANAGER_H
