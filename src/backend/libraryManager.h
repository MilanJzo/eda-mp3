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
    static libraryManager* getInstance();
    static QStringList  getMP3FilenamesFromDirectory(const QString &pathToDir);
    [[nodiscard]] QVector<song> getLibrary() const { return library; };

signals:
    void libraryChanged();

private:
    static libraryManager* instance;
    QVector<song> library;

    libraryManager();
    void loadLibrary();
    void loadDirIntoLibrary(const QString &dir);

};

#endif //LIBRARYMANAGER_H
