//
// Created by Markus Heming on 03.12.24.
//

#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include <QStringList>


class libraryManager {
public:
    static void addDirectory();
    static libraryManager* getInstance();
    static QStringList  getMP3FilesFromDirectory(const QString &pathToDir);

private:
    static libraryManager* instance;
    static QStringList library;

    libraryManager();
    static void loadLibrary();

};



#endif //LIBRARYMANAGER_H
