//
// Created by Markus Heming on 03.12.24.
//

#include "libraryManager.h"
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QFile>

void libraryManager::addDirectory() {
    QString dir = QFileDialog::getExistingDirectory(nullptr, "Select Directory", QDir::homePath());

    QFile file("./libraryDirectories.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qWarning() << "Failed to open libraryDirectories.txt for writing";
        return;
    }

    QTextStream stream(&file);
    while (!stream.atEnd())
    {
        QString line = stream.readLine();
        qDebug() << line;
        if (line.compare(dir) == 0)
        {
            qWarning() << "Directory already in libraryDirectories.txt";
            return;
        }
        qDebug() << dir;
    }
    stream << dir << "\n";
    file.close();
}

QStringList libraryManager::getMP3FilesFromDirectory(const QString& pathToDir)
{
    const QDir dir(pathToDir);
    QStringList filters;
    filters << "*.mp3";
    return dir.entryList(filters, QDir::Files);
}

