//
// Created by Markus Heming on 03.12.24.
//

#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include <QStringList>


class libraryManager {
public:
    static void addDirectory();
    static QStringList  getMP3FilesFromDirectory(const QString &pathToDir);
};



#endif //LIBRARYMANAGER_H
